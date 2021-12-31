

//////////////////////////////////////////////////////////////////////
//
// db_data_containers.h: 
// header file for smsc mediation classe definitions
// SMSC Mediation Engine
// developer - Chandika Nettasinghe
// development - 2003
//
//////////////////////////////////////////////////////////////////////


#pragma warning(disable:4786)

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <stdio.h>

using namespace std;


static const int MIN_YEAR = 1949;
static const int MAX_YEAR = 2051;

typedef enum {T_UNDEF, T_ON, T_OFF} e_token_state;



class reng_time;

class reng_time
{
public:
	int hour;
	int min;
	int second;
	bool set_time(int h, int m, int s=0);
	bool set_time(char *t);
	bool set_h_m(const char *t);
	bool set_from_db(char *t, int secs);

	bool operator < (const reng_time  &s) const;
	reng_time operator+ (int s) const;
	void Print();
	void init();
};


ostream& operator<<(ostream& out, reng_time x);

class reng_date
{
public:
	int year;
	int month;
	int day;
	bool operator < (const reng_date  &s) const;
	bool set_date(int y, int m, int d);
	bool set_date(char *d);
	void init();
};

ostream& operator<<(ostream& out, reng_date x);


class reng_date_time
{
public:
	reng_date date;
	reng_time time;
	bool set_date_time(char *d);
	bool operator < (const reng_date_time  &s) const;
};

ostream& operator<<(ostream& out, reng_date_time x);

class time_chk
{
public:
	void check_date(char *dte);
	void check_date_time(char *dte_time);
};


// CDR -- begin ---------------------------------------------------------------
class cdr_decode;

class decoded_cdr
{
public:
	bool vaild;

	int file_id;			// the number of the file
	int file_pos;			// the bytes from start of cdr where file started

	// call detail
	string	message_source;
	string	destination_address;			
	string	originating_address;			
	int		traffic_event_type;				
	string	traffic_event_time;			// The time at which this record was written to Traffic/Trace Log.				
	int		destination_logical_SME;		
	string	accept_time;				// The time that the SM was accepted into the Sema SMSC
										// message store. When combined with the destination address
										// of the message this field can be used to uniquely identify 
										// a message.
	
	string	duplicate_message_behaviour;	
	string	SME_reference_number;			
	int		first_in_batch;					
	int		call_direction;					 
	int		distribution;						
	string	destination_IMSI;					
	string	closed_user_group;			
	string	CUG_type;							
	string	originating_IMSI;					
	int		first_network_operation;			
	int		first_delivery_network;			
	int		second_network_operation;				 
	int		second_delivery_network;			
	int		second_network_failure_type;		
	int		second_network_error_returned;	
	int		second_network_failure_cause;	
	int		second_delivery_failure_reason;	
	int		priority;							
	int		protocol_id;						
	int		SMSC_reference_number;			
	string	source_node_SCCP_address;		
	string	destination_node_SCCP_address;
	int		billing_flags;	
	int		sub_logical_sme;			

	bool unpack(cdr_decode *a);
	bool unpack_origin(cdr_decode *a);
	bool unpack_termi(cdr_decode *a);
	void init(int f_id, int f_pos);

	reng_time d_traffic_event_time_time;
	reng_date d_traffic_event_time_date;

	reng_time d_accept_time_time;
	reng_date d_accept_time_date;

	reng_date_time d_call_time;

	// generated data
	string	rate_address;
	string	rate_call_partner;
	string	rate_call_type;
	int		rate_sub_service_type;
	string	call_time;			// if rate_call_type=='ORIGIN' then call_time = accept_time
								// if rate_call_type=='TERMI' then call_time = traffic_event_time

};


class token
{
public:
	e_token_state token_state;
	string file_name;
	string token_text;

	FILE *token_file;

	bool set_token(e_token_state a);
	token(string f_name);
	bool is_runable(void);
	e_token_state code_token(string a);
	string decode_token(e_token_state a);
};

// sub-service formulation

typedef map<string, int, less<string> > SUB_SERVICE_DEF;


class sub_service_networks
{
public:
	SUB_SERVICE_DEF sub_service_map;	// International Country Codes - sub_service_id = 1
	SUB_SERVICE_DEF applications_map;	// Applications	- sub_service_id = 2
	bool insert(string network_id, int sub_service_id);
	bool insert_sub_service_map(string network_id, int sub_service_id);
	bool insert_applications_map(string network_id, int sub_service_id);
	bool get_partner_network(string call_partner, string &network_no, string &tel_no);
	int	 get_sub_service_id(string network_id);
	bool is_application(string rate_call_partner);
	void db_read();
	void print();
};

// med_dialog_service_centers

typedef set<string> CERVICE_CENTERS_DEF;

class med_dialog_service_centers
{
public:
	CERVICE_CENTERS_DEF service_center_map;
	
	bool insert_dialog_service_centers(string service_center);
	bool is_dialog_service_center(string cdr_service_center);
	void db_read();
};






