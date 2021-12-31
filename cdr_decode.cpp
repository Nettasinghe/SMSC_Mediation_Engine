

//////////////////////////////////////////////////////////////////////
//
// cdr_decode.cpp: 
//			implementation of the cdr_decode class.
// SMSC Mediation Engine
// developer - Chandika Nettasinghe
// development - 2003
//
//////////////////////////////////////////////////////////////////////


#include "cdr.h"
#include "defines.h"
#include "functions.h"


void cdr_decode::init()
{
	// init all buffers

	destination_address[0]			='\0';			
	originating_address[0]			='\0';			
	traffic_event_time[0]			='\0';			
	accept_time[0]					='\0';					
	duplicate_message_behaviour[0]	='\0';
	SME_reference_number[0]			='\0';		
	destination_IMSI[0]				='\0';					
	closed_user_group[0]			='\0';			
	CUG_type[0]						='\0';						
	originating_IMSI[0]				='\0';				
	source_node_SCCP_address[0]		='\0';	
	destination_node_SCCP_address[0]='\0';

	valid = true;
}


bool cdr_decode::init_var_length_field(unsigned char *s)
{
	position_to_decode_from = s;
	record_length = *position_to_decode_from;
	checked_record_length = record_length;
	return true;
}

int  cdr_decode::get_read_field_length()
{
	return checked_record_length;
}

int  cdr_decode::get_move_field_length()
{
	return record_length;
}


int  cdr_decode::adjust_read_field_length(int a)
{
	checked_record_length=a;
	valid=false;
	return checked_record_length;
}


bool cdr_decode::is_over_run(int a)
{
	bool over_run = false;

	if (record_length > a)
	{
		over_run = true;
		statistics->error_count++;
	}
	return (over_run);
}


// ------------------------------ Fixed length---------------------------------
/*
bool cdr_decode::get_circuit_allocation_time_stamp()
{
	U.get_BCD((cdr_start+cdr_start_of_circuit_allocation_time_stamp),
		circuit_allocation_time_stamp_LENGTH, circuit_allocation_time_stamp);

	// sieve for max and min cdr times in file (adds 5% extra to decode time)
	string min_max_time=circuit_allocation_time_stamp;

	// y2k
	if(min_max_time.substr(0,2) < "50")
		min_max_time = "20"+min_max_time;
	else
		min_max_time = "19"+min_max_time;

	if (min_max_time < statistics->first_cdr_date)
		statistics->first_cdr_date = min_max_time;
	
	if (min_max_time > statistics->last_cdr_date)
		statistics->last_cdr_date = min_max_time;

	return true;
}


bool cdr_decode::get_end_of_call_time_stamp()
{
	U.get_BCD( (cdr_start+cdr_start_of_end_of_call_time_stamp), end_of_call_time_stamp_LENGTH, 
		end_of_call_time_stamp);

	return true;
}



// ------------------------ variable length fields ----------------------------

bool cdr_decode::skip_mobile_station_identity()
{
	init_var_length_field(cdr_start+mobile_station_identity_POSITION);
	move_to_next_record(get_move_field_length());
	return true;
}


bool cdr_decode::skip_list_of_service_complements()
{
	init_var_length_field(position_to_decode_from);
	move_to_next_record(get_move_field_length());
	return true;
}


bool cdr_decode::skip_link_information()
{
	init_var_length_field(position_to_decode_from);
	move_to_next_record(get_move_field_length());
	return true;
}


bool cdr_decode::skip_mobile_subscriber_identity()
{
	init_var_length_field(position_to_decode_from);
	move_to_next_record(get_move_field_length());
	return true;
}


bool cdr_decode::get_msc_identity() // Mobile switching center
{
	init_var_length_field(position_to_decode_from);

	if(is_over_run(msc_identity_LENGTH))
	{
		cout<<"WARN  msc_identity  overflow (truncated)"<<endl;
		adjust_read_field_length(msc_identity_LENGTH);
		valid=false;
	}

	if(get_read_field_length())
		U.get_TBCD(position_to_decode_from+1+1, get_read_field_length()-1, msc_identity);

	move_to_next_record(get_move_field_length());

	return true;
}



bool cdr_decode::get_called_party_number()  
{
	init_var_length_field(position_to_decode_from);

	if(is_over_run(called_party_number_LENGTH))
	{
		cout<<"WARN  called_party_number  overflow (truncated)"<<endl;
		adjust_read_field_length(called_party_number_LENGTH);
		valid=false;
	}

	called_party_number_noai = *(position_to_decode_from+1);
	// *$$$ ****
	// get the  3 $ bits, mask out the 5 * bits
	called_party_number_noai = ( called_party_number_noai >> 4 ) & 0x07;

	if(get_read_field_length())
	{
		U.get_TBCD(position_to_decode_from+1+1, get_read_field_length()-1, called_party_number);
	}
	move_to_next_record(get_move_field_length());


	return true;
}



bool cdr_decode::get_calling_party_number()  
{
	init_var_length_field(position_to_decode_from);
	
	if(is_over_run(calling_party_number_LENGTH))
	{
		cout<<"WARN  ms_location_identity  overflow (truncated)"<<endl;
		adjust_read_field_length(calling_party_number_LENGTH);
		valid=false;
	}

	calling_party_number_noai = *(position_to_decode_from+1);
	// *$$$ ****

	// get the  3 $ bits, mask out the 5 * bits
	calling_party_number_noai = ( calling_party_number_noai >> 4 ) & 0x07;
	
	U.get_TBCD(position_to_decode_from+1+1, get_read_field_length()-1, calling_party_number);

	move_to_next_record(get_move_field_length());
	
	return true;
}



bool cdr_decode::skip_ms_location_identity_extension() 
{
	init_var_length_field(position_to_decode_from);
	move_to_next_record(get_move_field_length());
	return true;
}



bool cdr_decode::get_outgoing_trunk_group() 
{
	init_var_length_field(position_to_decode_from);

	if(is_over_run(outgoing_trunk_group_LENGTH))
	{
		cout<<"WARN  outgoing_trunk_group  overflow (truncated)"<<endl;
		adjust_read_field_length(outgoing_trunk_group_LENGTH);
		valid=false;
	}

	if(get_read_field_length()>1)
		U.get_ASCII((position_to_decode_from+1), get_read_field_length(), outgoing_trunk_group);

	move_to_next_record(get_move_field_length());

	return true;
}


bool cdr_decode::get_incoming_trunk_group() 
{
	init_var_length_field(position_to_decode_from);

	if(is_over_run(incoming_trunk_group_LENGTH))
	{
		//cout<<"WARN  incoming_trunk_group  overflow (truncated)"<<endl;
		adjust_read_field_length(incoming_trunk_group_LENGTH);
		valid=false;
	}

	if(get_read_field_length()>1)
		U.get_ASCII((position_to_decode_from+3), (5), incoming_trunk_group);

	move_to_next_record(get_move_field_length());

	return true;
}
*/

// very crude 
int cdr_decode::get_two_byte_binary(unsigned char * a) 
{
	return a[0]*256+a[1];
}

int cdr_decode::get_three_byte_binary(unsigned char * a) 
{
	return a[0]*256*256+a[1]*256+a[2];
}

int cdr_decode::get_four_byte_binary(unsigned char * a) 
{
	return a[0]*256*256*256+a[1]*256*256+a[2]*256+a[3];
}



// all the stuff is in the fixed length portion of the cdr
bool cdr_decode::get_all_fields() 
{
	/*
	U.get_BCD((cdr_start+cdr_start_of_message_source),
		message_source_LENGTH, message_source);
		*/
	
	/*
	int mes_source = U.get_bin((cdr_start+cdr_start_of_message_source),
		message_source_LENGTH);

	myitoa(mes_source, message_source);

	cout << message_source << "|" << endl;
	*/

	U.get_hex((cdr_start+cdr_start_of_message_source),
		message_source_LENGTH, message_source);

	//sub_logical_sme =  ( ( (cdr_start+cdr_start_of_message_source+1)[0]*256 ) +  (cdr_start+cdr_start_of_message_source)[0] ) / 100;
	sub_logical_sme =  ( ( (cdr_start+cdr_start_of_message_source+1)[0]*256 ) +  (cdr_start+cdr_start_of_message_source)[0]   + ( (cdr_start+cdr_start_of_message_source+2)[0]*256*256 )       ) / 100;

	//if (sub_logical_sme != 0 )
		//cout << sub_logical_sme << endl;
	
	

	U.get_TBCD((cdr_start+cdr_start_of_traffic_event_time),
		traffic_event_time_LENGTH, traffic_event_time);
	U.get_TBCD((cdr_start+cdr_start_of_accept_time),
		accept_time_LENGTH, accept_time);


	string min_max_time=accept_time;

	// y2k
	if(min_max_time.substr(0,2) < "50")
		min_max_time = "20"+min_max_time;
	else
		min_max_time = "19"+min_max_time;

	if (min_max_time < statistics->first_cdr_date)
		statistics->first_cdr_date = min_max_time;
	
	if (min_max_time > statistics->last_cdr_date)
		statistics->last_cdr_date = min_max_time;

	traffic_event_type				= U.get_BIN( *(cdr_start+cdr_start_of_traffic_event_type));				
	destination_logical_SME			= U.get_BIN( *(cdr_start+cdr_start_of_destination_logical_SME));		
	first_in_batch					= U.get_BIN( *(cdr_start+cdr_start_of_first_in_batch));					
	call_direction					= U.get_BIN( *(cdr_start+cdr_start_of_call_direction));					 
	distribution					= U.get_BIN( *(cdr_start+cdr_start_of_distribution));						
	first_network_operation			= U.get_BIN( *(cdr_start+cdr_start_of_first_network_operation));			
	first_delivery_network			= U.get_BIN( *(cdr_start+cdr_start_of_first_delivery_network));			
	second_network_operation		= U.get_BIN( *(cdr_start+cdr_start_of_second_network_operation));				 
	second_delivery_network			= U.get_BIN( *(cdr_start+cdr_start_of_second_delivery_network));			
	second_network_failure_type		= U.get_BIN( *(cdr_start+cdr_start_of_second_network_failure_type));		
	second_network_error_returned	= get_two_byte_binary( (cdr_start+cdr_start_of_second_network_error_returned));	
	second_network_failure_cause	= U.get_BIN( *(cdr_start+cdr_start_of_second_network_failure_cause));	
	second_delivery_failure_reason	= U.get_BIN( *(cdr_start+cdr_start_of_second_delivery_failure_reason));	
	priority						= U.get_BIN( *(cdr_start+cdr_start_of_priority));							
	protocol_id						= U.get_BIN( *(cdr_start+cdr_start_of_protocol_id));						
	SMSC_reference_number			= get_four_byte_binary( (cdr_start+cdr_start_of_SMSC_reference_number));			
	billing_flags					= U.get_BIN( *(cdr_start+cdr_start_of_billing_flags));
	
	U.get_ASCII_without_space(cdr_start+cdr_start_of_destination_address, destination_address_LENGTH, destination_address);
	U.get_ASCII_without_space (cdr_start+cdr_start_of_originating_address, originating_address_LENGTH, originating_address);

	U.get_ASCII(cdr_start+cdr_start_of_destination_IMSI, destination_IMSI_LENGTH, destination_IMSI);
	U.get_ASCII(cdr_start+cdr_start_of_originating_IMSI, originating_IMSI_LENGTH, originating_IMSI);

	U.get_THEX(cdr_start+cdr_start_of_source_node_SCCP_address+1, *(cdr_start+cdr_start_of_source_node_SCCP_address), source_node_SCCP_address);
	U.get_THEX(cdr_start+cdr_start_of_destination_node_SCCP_address+1, *(cdr_start+cdr_start_of_destination_node_SCCP_address), destination_node_SCCP_address);

	return true;
}


bool cdr_decode::move_to_next_record(int length)
{
	position_to_decode_from += (length+1);

	// check if length of CDR is exceded
	// asssumes linear address space 
	if(position_to_decode_from > (cdr_start+cdr_length))
	{
		//cout<<"CDR Overun ERROR {"<<hex<<(int)position_to_decode_from<<"} {"<<(int)(cdr_start+cdr_length)<<"}"<<dec<<endl;
	}
	return true;
}



void cdr_decode::set_statistics_collector(cdr_file_statistics *s)
{
	statistics = s;
}



int cdr_decode::decode(unsigned char *buf) //imsi_filter *F
{
	init();  // all the variables
	cdr_start	= buf;
	cdr_length	= FIXED_CDR_LENGTH;
	
	get_all_fields();
	
	return 1;
}



ostream& operator<<(ostream& out, cdr_decode x)
{
	// fixed length data
	/*
	out<<"type of msc       = {"<<x.type_of_msc<<"}"<<endl;
	out<<"type of call      = {"<<hex<<x.type_of_call<<"}"<<dec<<endl;
	out<<"termination type  = {"<<hex<<x.call_termination_type<<"}"<<dec<<endl;
	out<<"origin of call ind= {"<<x.origin_of_call_indicator<<"}"<<endl;
	//out<<"charging indicator= {"<<x.charging_indicator<<"}"<<endl;
	//out<<"tele service      = {"<<hex<<x.required_tele_service<<"}"<<dec<<endl;
	//out<<"bearer service    = {"<<x.required_bearer_service<<"}"<<endl;
	out<<"cir time          = {"<<x.circuit_allocation_time_stamp<<"}"<<endl;
	out<<"call duration     = {"<<x.call_duration<<"}"<<endl;
	out<<"end of call time  = {"<<x.end_of_call_time_stamp<<"}"<<endl;
	//out<<"calldata format no= {"<<x.call_data_format_number<<"}"<<endl;
	
	// Variable length Arrays
	out<<"msc				= {"<<x.msc_identity<<"}"<<endl;		
	out<<"called party      = {"<<x.called_party_number<<"}"<<endl;
	out<<"called party noai = {"<<x.called_party_number_noai<<"}"<<endl;
	out<<"calling party     = {"<<x.calling_party_number<<"}"<<endl;
	out<<"called party noai = {"<<x.calling_party_number_noai<<"}"<<endl;
	out<<"out trunk group   = {"<<x.outgoing_trunk_group<<"}"<<endl;
	out<<"in trunk group    = {"<<x.incoming_trunk_group<<"}"<<endl;
	*/

	return out;
}








