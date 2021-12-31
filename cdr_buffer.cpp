

//////////////////////////////////////////////////////////////////////
//
// cdr_buffer.cpp: 
//			implementation of the cdr_buffer class.
// SMSC Mediation Engine
// developer - Chandika Nettasinghe
// development - 2003
//
//////////////////////////////////////////////////////////////////////


#include "cdr.h"
#include "defines.h"



unsigned char bcd_to_int(unsigned char a)
{
	return ((unsigned char) ((((a & 0xf0)>>4)*10) + (a & 0x0f)));
}

unsigned char tbcd_to_int(unsigned char a)
{
	return ((unsigned char) ( ((a & 0xf0)>>4) + ((a & 0x0f)*10) ));
}


// open a vaild file pointer and collects a bit of statistics as well
bool cdr_buffer::read_cdr_file(FILE *fp, cdr_file_statistics *s)
{
	bool found = false;
	// read_cdr_file();
	bytes_read = fread(buffer, sizeof(unsigned char), buffer_size, fp);
	statistics = s;
	statistics->bytes_read = bytes_read;

	if(bytes_read == 0)
	{
		return false;
	}
	else if (bytes_read == buffer_size)
	{
		cout<<"<ERROR> possible cdr buffer overflow "<<bytes_read<<endl;
		return false;
		//exit(1);
	}

	data_end = buffer + bytes_read;
	current =  buffer;

	return found; // all data files read
}


void cdr_buffer::init()
{
	bytes_read		= 0;
	current			= buffer;
	data_end		= buffer;
	cdr_length		= 0;
	cdr_count		= 0;
	cdr_position	= 0;				// location of cdr from start of file

// inialise buffer area, useful for debugging only
//	for(unsigned char* a=buffer; a<end_of_buffer; a++)
//		*a=0x00;
}

// object lives for lifetime of program
cdr_buffer::cdr_buffer(int size)
{
	buffer_size = size;
	buffer = new unsigned char[buffer_size];
	if (!buffer)
	{
		cout<<"ERR: FATAL cant allocate "<<buffer_size/1024<<" KB  for CDR buffer"<<endl;
		exit(1);
	}

	end_of_buffer = buffer+buffer_size;
	init();
}


class cdr_tm
{
public:
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	
	bool check_from_year();
	bool check_from_month();
};


bool cdr_tm::check_from_month()
{
	bool valid = true;
	if ( !(month >=1 && month <= 12))
		valid = false;
	else if ( !(day >=1 && day <= 31))
		valid = false;
	else if (!(hour >= 0 && hour <= 23))
		valid = false;
	else if (!(min >=0 && min <= 59 ))
		valid = false;
	else if (!(sec >= 0 && sec <= 59))
		valid = false;
	
	return valid;
}


bool cdr_tm::check_from_year()
{
	bool valid=check_from_month();

	if (!(year >= 0 && year <= 99))
		valid = false;
	
	return valid;
}


// see Sema SMSC G8.1, USSD v2.1 & USC v2.0
// Traffic Log External Interface Specification 

bool cdr_buffer::get_cdr_start()
{
	// All cdrs are of fixed length of 200 octets
	// The 45th byte of the cdr is 0x05 in case of Traffic Event Type 
	// is "Short Message Delivery"
	
	unsigned char *b_ptr; // buffer pointer

	if(cdr_length ==0)							// for first time entry to loop
		b_ptr = current-2; 						// -1 since b_ptr++ in do-while
	else										// as you enter the while loop 
		b_ptr = current-1 + cdr_length ; 
	
	
	cdr_tm traffic_event_time, accept_time;
	
	do 
	{
		b_ptr++;

		//if(*(b_ptr + START_SIGNATURE_OFFSET) != START_SIGNATURE)		// move along till 0x05 is found
		if(*(b_ptr + START_SIGNATURE_OFFSET) != 0x05)
				continue;
		
		if(data_end >= b_ptr+FIXED_CDR_LENGTH)
		{
			// traffic event time
			traffic_event_time.year	= tbcd_to_int( *(b_ptr+cdr_start_of_traffic_event_time));
			traffic_event_time.month= tbcd_to_int( *(b_ptr+cdr_start_of_traffic_event_time+1));
			traffic_event_time.day	= tbcd_to_int( *(b_ptr+cdr_start_of_traffic_event_time+2));
			traffic_event_time.hour	= tbcd_to_int( *(b_ptr+cdr_start_of_traffic_event_time+3));
			traffic_event_time.min	= tbcd_to_int( *(b_ptr+cdr_start_of_traffic_event_time+4));
			traffic_event_time.sec	= tbcd_to_int( *(b_ptr+cdr_start_of_traffic_event_time+5));
				
			
			if (!traffic_event_time.check_from_year())
			{
				cout << "chk for year failed" << endl;
				continue;
			}

			if (!traffic_event_time.check_from_month())
			{
				cout << "chk for month failed" << endl;
				continue;
			}
			
				
			// accept time
			accept_time.year	= tbcd_to_int( *(b_ptr+cdr_start_of_accept_time));
			accept_time.month	= tbcd_to_int( *(b_ptr+cdr_start_of_accept_time+1));
			accept_time.day		= tbcd_to_int( *(b_ptr+cdr_start_of_accept_time+2));
			accept_time.hour	= tbcd_to_int( *(b_ptr+cdr_start_of_accept_time+3));
			accept_time.min		= tbcd_to_int( *(b_ptr+cdr_start_of_accept_time+4));
			accept_time.sec		= tbcd_to_int( *(b_ptr+cdr_start_of_accept_time+5));
			
			if (!accept_time.check_from_year())
			{
				cout << "chk for year failed" << endl;
				continue;
			}
			
			if (!accept_time.check_from_month())
			{
				cout << "chk for month failed" << endl;
				continue;
			}
			

			// check cdr does not exceed file end
			if(b_ptr+FIXED_CDR_LENGTH > data_end)
			{
				cout<<"WARN ------------PARTIAL CDR----------"<<endl;
				statistics->reject_cdr_count++;
				continue;
			}
				
			//	all dates seem to pass initial sanity check
			current		= b_ptr ;
			cdr_length	= FIXED_CDR_LENGTH; // are we missing a one here ?
			cdr_count++;
			//statistics->valid_cdr_count++;	// may generate 2 cdrs from 1 valid cdr
												// hence commented
			cdr_position = current - buffer +2;

			return true;  // cdr start signature found
		}
	}while (b_ptr < data_end);

	return false;
}


// current must be at start of cdr 
// or else premature exit
void cdr_buffer::print_cdr_in_hex()
{
	int k=0;
	
	for(unsigned char *i=current; i<=current+cdr_length; i++)
	{
		if(i > data_end)
		{
			printf(" ERR: Out of vaild data sequence ");
			return;
		}
		if (!(k%8))
			printf("   ");
		if (!(k%16))
			printf("\n %04x  ",i-buffer);
		printf(" %02x",(int)(*i));
		k++;
	}
	printf("\n");
}

int cdr_buffer::get_cdr_position()
{
	return cdr_position;
}

