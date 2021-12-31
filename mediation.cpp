

///////////////////////////////////////////////////////////////////////////////////////////
// 
// Telco Switch Mediation Engine for Sema SMSC (SMSC Mediation Engine) –
// --------------------------------------------------------------------------
// Telecom Switches such as MSCs, GGSNs, SMSCs and VAS servers store subscribers Call Detail 
// Record (CDR) data in encoded formats of either proprietary or ASN.1. Switch Mediation Engine
// functions as the intermediary between the Telco Network and the Billing System by decoding 
// the CDRs and transforming (amalgamating, stitching and enhancing) them to the input format 
// expected by the Billing System.
// SMSC Mediation Engine decodeds Sema SMSC CDRs in a proprietary binary format.
//
///////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////
//
// mediation.cpp
// SMSC Mediation Engine
// main method contains here
// developer - Chandika Nettasinghe
// development - 2003
//
//////////////////////////////////////////////////////////////////////



#include "defines.h"
#include "cdr.h"
#include "db.h"
#include "db_data_containers.h"

#include <time.h>

cdr_buffer *cdr_store;

char debug_option[128];
bool debug = false;
int array_insert_size;

ofstream f_log("./logs/SMSC_Mediation.log", ios::out | ios::app);


	//decoded_cdr		*gsm_decoded_cdr;
	decoded_cdr		*origin_cdr;
	decoded_cdr		*termi_cdr;
	decoded_cdr		*gsm_cdr_block;
	decoded_cdr		*air_cdr_block;

	sub_service_networks *gsm_sub_service_networks;
	//med_dialog_service_centers *gsm_med_dialog_service_centers;

	cdr_decode raw_cdr;			// all the methods to extract data from a cdr
	int global_cdr_counter;

#ifdef PRIMARY
	reng_date_time	cdr_start_timestamp, cdr_end_timestamp;	
#endif

int main(int argc,char *argv[])
{
	char *ver = "1.0.9";

#ifdef PRIMARY
	cout<<"CDR Decoding  Engine for SMSC Primary Logs "<<ver<<endl;
#else
	cout<<"CDR Decoding  Engine for SMSC "<<ver<<endl;
#endif
	cout<<"Build Time "<<__DATE__<<" at "<<__TIME__<<endl
	<<"Millennium IT"<<endl
	<<"Colombo, Sri Lanka"<<endl<<endl;

#ifdef PRIMARY
	if (argc != 3 )
	{
		cout << "bad number of command line arguments" << endl;
		cout << "usage - smsc_mediation_engine <cdr_start_timestamp> <cdr_end_timestamp>" << endl;
		cout << "eg : " << endl;
		cout << "smsc_mediation_engine 20030105020202 20030105060606" << endl;
		exit(0);
	}
	else
	{
		time_chk tc;
		tc.check_date_time(argv[1]);
		tc.check_date_time(argv[2]);

		cdr_start_timestamp.set_date_time(argv[1]);
		cdr_end_timestamp.set_date_time(argv[2]);
	}
#endif

	// Log start time
	char zTime[30];
	/*------- get time -------*/
	time_t t;
	time(&t);
	/*------- get time -------*/
	strftime(zTime, 30, "%Y%B%d%H%M%S", localtime(&t));
	f_log << " start time :" << zTime << endl;
	// Log start time -end



	// db data containers memory allocation startarray_insert_size
	cdr_store					= new cdr_buffer(1024*1024*70); // allocate space in memory for binary read of whole cdr file
	//gsm_decoded_cdr				= new decoded_cdr;
	origin_cdr					= new decoded_cdr;
	termi_cdr					= new decoded_cdr;
	gsm_sub_service_networks	= new sub_service_networks;
	//gsm_med_dialog_service_centers = new med_dialog_service_centers;
	// db data containers memory allocation end
	
	// allocate space in memory for binary read of whole cdr file
	cdr_files cdr_f;

	//-------------- database logins and print file location -----------------------
	FILE *login;
	char cdr_login[128];
	char cdr_dump_location[128];

#ifdef PRIMARY
	// get config data
	if( (login  = fopen( "./smsc_primary_cdr_eng.config", "r" )) == NULL )
	{
		printf( "The file 'smsc_primary_cdr_eng.config' was not opened\n" );
		exit(0);
	}
#else
	// get config data
	if( (login  = fopen( "./smsc_cdr_eng.config", "r" )) == NULL )
	{
		printf( "The file 'smsc_cdr_eng.config' was not opened\n" );
		exit(0);
	}
#endif

	fscanf( login, "%s", cdr_login );
	fscanf( login, "%s", cdr_dump_location );
	fscanf( login, "%s", debug_option );
	fscanf( login, "%d", &array_insert_size );

	if( fclose( login ) )
		printf( "The file 'smsc_cdr_eng.config' was not closed\n" );

	if ( (strcmp(debug_option,"ON"))==0 )
		debug = true;

	gsm_cdr_block				= new decoded_cdr[array_insert_size]; // memory allocated after reading array_insert_size from file
	air_cdr_block				= new decoded_cdr[array_insert_size];

//-------------- database logins and print file location -----------------------


	// login to cdr database
	cout <<"Debug Option = " <<debug_option << endl; 
	cout << "array_insert_size = " << array_insert_size << endl;

	
	printf("\nReady to connect to cdr data base\n");

	db_connect(cdr_login);

	//cdr_f.db_read();		// read in list of cdrs files to be rated from database
	gsm_sub_service_networks->db_read();
	//gsm_med_dialog_service_centers->db_read();

#ifdef PRIMARY
	cdr_f.db_read_primary();
#else
	cdr_f.db_read_secondary();
#endif
	//cdr_f.print();

	cdr_f.init(cdr_dump_location);
	

	// cdr decoder performance measurement defs

	
		
	int	total_cdrs_decoded = 0;	// cumilative for this run over all cdr files
	int cdrs_pending_insert = 0;// must allways be less than block size
	int air_cdrs_pending_insert = 0;
	int cdrs_inserted = 0;		// must allways be less than block size
	int air_cdrs_inserted = 0;



	FILE *fp;
	cdr_file_statistics *s;		// the stuff is stored in a map so dont allocate storage,
								// this gives access to storage area in map, but must assign!!
	


	while(cdr_f.get_next_file(&fp,&s))			// get handle of cdr file
	{
		global_cdr_counter = 0;

		cdr_store->read_cdr_file(fp,s);			// read in whole file to buffer
		cout <<" cdr data "<<s->file_id<<endl;
		f_log <<" cdr data "<<s->file_id<<endl;
		raw_cdr.set_statistics_collector(s);	// direct statistics to file statistics area
		
		while(cdr_store->get_cdr_start())		// look for start of a cdr in the file
		{
			raw_cdr.decode(cdr_store->current);
		
			//gsm_decoded_cdr->init(s->file_id, cdr_store->get_cdr_position());

			//gsm_decoded_cdr->unpack(&raw_cdr);			// extract all the info from the file format rec
 
#ifdef CDR_PRINT
			cout << raw_cdr << endl;
#endif
			origin_cdr->init(s->file_id, cdr_store->get_cdr_position());

			if (  origin_cdr->unpack_origin(&raw_cdr) ) 
			{
				//if ( gsm_med_dialog_service_centers->is_dialog_service_center(origin_cdr->source_node_SCCP_address.substr(14, 10) ) )
				if ( ( origin_cdr->source_node_SCCP_address.size() >= 4 ) && ( origin_cdr->source_node_SCCP_address.substr(14, 4) == "9477" )  )
				{
#ifdef PRIMARY
					if ( (cdr_start_timestamp < origin_cdr->d_call_time) && (origin_cdr->d_call_time< cdr_end_timestamp) )
					{
#endif
						s->valid_cdr_count++;
						total_cdrs_decoded++;
						//gsm_cdr_block[cdrs_pending_insert] = (*gsm_decoded_cdr);
						gsm_cdr_block[cdrs_pending_insert] = (*origin_cdr);
						cdrs_pending_insert++;
						global_cdr_counter++;
#ifdef PRIMARY
					}
#endif
				}
				else
				{
#ifdef PRIMARY
					if ( (cdr_start_timestamp < origin_cdr->d_call_time) && (origin_cdr->d_call_time< cdr_end_timestamp) )
					{
#endif
						//s->valid_cdr_count++;
						//total_cdrs_decoded++;
						//gsm_cdr_block[cdrs_pending_insert] = (*gsm_decoded_cdr);
						air_cdr_block[air_cdrs_pending_insert] = (*origin_cdr);
						air_cdrs_pending_insert++;
						//global_cdr_counter++;
#ifdef PRIMARY
					}
#endif
				}


				
				if (array_insert_size == cdrs_pending_insert)
				{
					cdrs_inserted += cdrs_pending_insert;
					#ifdef DBLOG
					db_insert_decoded_cdr(cdrs_pending_insert);
					#endif
					cdrs_pending_insert = 0;	// must allways be after the insert!!
				}

				if (array_insert_size == air_cdrs_pending_insert)
				{
					air_cdrs_inserted += air_cdrs_pending_insert;
					#ifdef DBLOG
					db_insert_air_cdr(air_cdrs_pending_insert);
					#endif
					air_cdrs_pending_insert = 0;	// must allways be after the insert!!
				}
			}

			
			termi_cdr->init(s->file_id, cdr_store->get_cdr_position());

			if ( termi_cdr->unpack_termi(&raw_cdr) )
			{
#ifdef PRIMARY
				if ( (cdr_start_timestamp < termi_cdr->d_call_time) && (termi_cdr->d_call_time< cdr_end_timestamp) )
				{
#endif
					s->valid_cdr_count++;
					total_cdrs_decoded++;
					//gsm_cdr_block[cdrs_pending_insert] = (*gsm_decoded_cdr);
					gsm_cdr_block[cdrs_pending_insert] = (*termi_cdr);
					cdrs_pending_insert++;
					global_cdr_counter++;
#ifdef PRIMARY
				}
#endif
				
				if (array_insert_size == cdrs_pending_insert)
				{
					cdrs_inserted += cdrs_pending_insert;
					#ifdef DBLOG
					db_insert_decoded_cdr(cdrs_pending_insert);
					#endif
					cdrs_pending_insert = 0;	// must allways be after the insert!!
				}
			}
		}

//------------------------------------------------------------------------------------------------
		
		if(fclose(fp))
			cout<<"<ERROR> cant close cdr file"<<endl; // only valid files get here

		if (cdrs_pending_insert > 0)
		{
			cdrs_inserted += cdrs_pending_insert;
#ifdef DBLOG
			db_insert_decoded_cdr(cdrs_pending_insert);
#endif
			cdrs_pending_insert = 0;	// must allways be after the insert!!
		}

		if (air_cdrs_pending_insert > 0)
		{
			air_cdrs_inserted += air_cdrs_pending_insert;
#ifdef DBLOG
			db_insert_air_cdr(air_cdrs_pending_insert);
#endif
			air_cdrs_pending_insert = 0;	// must allways be after the insert!!
		}

		//cdr_f.db_update(*s);
#ifdef PRIMARY
		cdr_f.db_update_primary(*s);
#else
		cdr_f.db_update_secondary(*s);
#endif
		if(s->error_count > 0)
			cout<<"         Error count "<<s->error_count<<endl;
		cdr_store->init(); // rest all pointers
	};

#ifdef DBLOG
	// get any partial block size inserts
	if(cdrs_pending_insert > 0)
		db_insert_decoded_cdr(cdrs_pending_insert);
#endif
	
	db_disconnect();

		// Log end time
	/*------- get time -------*/
	//time_t t;
	time(&t);
	/*------- get time -------*/
	strftime(zTime, 30, "%Y%B%d%H%M%S", localtime(&t));
	f_log << " end time :" << zTime << endl;
	// Log start time -end

	return 0;

}


