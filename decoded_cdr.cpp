

//////////////////////////////////////////////////////////////////////
//
// decoded_cdr.cpp: 
//			implementation of the decoded_cdr class.
// SMSC Mediation Engine
// developer - Chandika Nettasinghe
// development - 2003
//
//////////////////////////////////////////////////////////////////////


#include "cdr.h"
#include "db_data_containers.h"
#include "defines.h"


extern 	cdr_decode raw_cdr;			// all the methods to extract data from a cdr
extern	sub_service_networks *gsm_sub_service_networks;


void decoded_cdr::init(int f_id, int f_pos)
{
	vaild=true;

	// cdr management
	file_id		= f_id;				// the number of the file
	file_pos	= f_pos;			// the bytes from start of cdr where file started

	// CDR values
	//	All int values are set to 0xff=255, initially
	
	destination_address				= "";			
	originating_address				= "";			
	traffic_event_type				= 0xff;				
	traffic_event_time				= "";				
	destination_logical_SME			= 0xff;		
	accept_time						= "";					
	duplicate_message_behaviour		= "";	
	SME_reference_number			= "";			
	first_in_batch					= 0xff;					
	call_direction					= 0xff;					 
	distribution					= 0xff;						
	destination_IMSI				= "";					
	closed_user_group				= "";			
	CUG_type						= "";							
	originating_IMSI				= "";					
	first_network_operation			= 0xff;			
	first_delivery_network			= 0xff;			
	second_network_operation		= 0xff;				 
	second_delivery_network			= 0xff;			
	second_network_failure_type		= 0xff;		
	second_network_error_returned	= 0xff;	
	second_network_failure_cause	= 0xff;	
	second_delivery_failure_reason	= 0xff;	
	priority						= 0xff;							
	protocol_id						= 0xff;						
	SMSC_reference_number			= 0xff;			
	source_node_SCCP_address		= "";		
	destination_node_SCCP_address	= "";
	billing_flags					= 0xff;	
	
	// generated data
	rate_address					= "";
	rate_call_partner				= "";
	rate_call_type					= "";
	rate_sub_service_type			= 0xff;	
	sub_logical_sme					= 0;
	call_time						= "";
};

// unpack the bits
bool decoded_cdr::unpack(cdr_decode *cdr)
{
	destination_address				= cdr->destination_address;			
	originating_address				= cdr->originating_address;			
	traffic_event_type				= cdr->traffic_event_type;				
	traffic_event_time				= cdr->traffic_event_time;				
	destination_logical_SME			= cdr->destination_logical_SME;		
	accept_time						= cdr->accept_time;					
	duplicate_message_behaviour		= cdr->duplicate_message_behaviour;	
	SME_reference_number			= cdr->SME_reference_number;			
	first_in_batch					= cdr->first_in_batch;					
	call_direction					= cdr->call_direction;					 
	distribution					= cdr->distribution;						
	destination_IMSI				= cdr->destination_IMSI;					
	closed_user_group				= cdr->closed_user_group;			
	CUG_type						= cdr->CUG_type;							
	originating_IMSI				= cdr->originating_IMSI;					
	first_network_operation			= cdr->first_network_operation;			
	first_delivery_network			= cdr->first_delivery_network;			
	second_network_operation		= cdr->second_network_operation;				 
	second_delivery_network			= cdr->second_delivery_network;			
	second_network_failure_type		= cdr->second_network_failure_type;		
	second_network_error_returned	= cdr->second_network_error_returned;	
	second_network_failure_cause	= cdr->second_network_failure_cause;	
	second_delivery_failure_reason	= cdr->second_delivery_failure_reason;	
	priority						= cdr->priority;							
	protocol_id						= cdr->protocol_id;						
	SMSC_reference_number			= cdr->SMSC_reference_number;			
	source_node_SCCP_address		= cdr->source_node_SCCP_address;		
	destination_node_SCCP_address	= cdr->destination_node_SCCP_address;
	billing_flags					= cdr->billing_flags;	
	sub_logical_sme					= cdr->sub_logical_sme;	



	// make Y2K compliant 50-99 in 1900 00-49 in 2000 
	if(traffic_event_time.substr(0,2) < "50")
		traffic_event_time = "20"+traffic_event_time;
	else
	{
		traffic_event_time = "19"+traffic_event_time;
	}
	
	// after Y2K fix YYYYMMDDHHMISS
	d_traffic_event_time_time.set_time((char*)traffic_event_time.c_str()+8);
	d_traffic_event_time_date.set_date((char*)traffic_event_time.c_str());

	// make Y2K compliant 50-99 in 1900 00-49 in 2000 
	if(accept_time.substr(0,2) < "50")
		accept_time = "20"+accept_time;
	else
	{
		accept_time = "19"+accept_time;
	}
	
	// after Y2K fix YYYYMMDDHHMISS
	d_accept_time_time.set_time((char*)accept_time.c_str()+8);
	d_accept_time_date.set_date((char*)accept_time.c_str());
	
	return true;
}


bool decoded_cdr::unpack_origin(cdr_decode *cdr)
{
	// check for a Dialog number
	if ( strncmp(cdr->originating_address, "9477", 4) != 0 )
		return false;
	
	message_source					= cdr->message_source;

	string	t_destination_address		= cdr->destination_address;
	string	t_originating_address		= cdr->originating_address;

	if ( strncmp(cdr->destination_address, "94", 2) != 0 )
		destination_address				= cdr->destination_address;	
	else
		destination_address				= t_destination_address.substr(2, (t_destination_address.size()-2));		

	originating_address				= t_originating_address.substr(2, (t_originating_address.size()-2));
	
	traffic_event_type				= cdr->traffic_event_type;				
	traffic_event_time				= cdr->traffic_event_time;				
	destination_logical_SME			= cdr->destination_logical_SME;		
	accept_time						= cdr->accept_time;					
	duplicate_message_behaviour		= cdr->duplicate_message_behaviour;	
	SME_reference_number			= cdr->SME_reference_number;			
	first_in_batch					= cdr->first_in_batch;					
	call_direction					= cdr->call_direction;					 
	distribution					= cdr->distribution;						
	destination_IMSI				= cdr->destination_IMSI;					
	closed_user_group				= cdr->closed_user_group;			
	CUG_type						= cdr->CUG_type;							
	originating_IMSI				= cdr->originating_IMSI;					
	first_network_operation			= cdr->first_network_operation;			
	first_delivery_network			= cdr->first_delivery_network;			
	second_network_operation		= cdr->second_network_operation;				 
	second_delivery_network			= cdr->second_delivery_network;			
	second_network_failure_type		= cdr->second_network_failure_type;		
	second_network_error_returned	= cdr->second_network_error_returned;	
	second_network_failure_cause	= cdr->second_network_failure_cause;	
	second_delivery_failure_reason	= cdr->second_delivery_failure_reason;	
	priority						= cdr->priority;							
	protocol_id						= cdr->protocol_id;						
	SMSC_reference_number			= cdr->SMSC_reference_number;			
	source_node_SCCP_address		= cdr->source_node_SCCP_address;		
	destination_node_SCCP_address	= cdr->destination_node_SCCP_address;
	billing_flags					= cdr->billing_flags;
	sub_logical_sme					= cdr->sub_logical_sme;	


	// make Y2K compliant 50-99 in 1900 00-49 in 2000 
	if(traffic_event_time.substr(0,2) < "50")
		traffic_event_time = "20"+traffic_event_time;
	else
	{
		traffic_event_time = "19"+traffic_event_time;
	}
	
	// after Y2K fix YYYYMMDDHHMISS
	d_traffic_event_time_time.set_time((char*)traffic_event_time.c_str()+8);
	d_traffic_event_time_date.set_date((char*)traffic_event_time.c_str());

	// make Y2K compliant 50-99 in 1900 00-49 in 2000 
	if(accept_time.substr(0,2) < "50")
		accept_time = "20"+accept_time;
	else
	{
		accept_time = "19"+accept_time;
	}
	
	// after Y2K fix YYYYMMDDHHMISS
	d_accept_time_time.set_time((char*)accept_time.c_str()+8);
	d_accept_time_date.set_date((char*)accept_time.c_str());

	// For 'ORIGIN' cdrs, call_time is the accept_time
	// For time range check in main() for Primary Log Reader
	accept_time[14] = '\0';
	d_call_time.set_date_time((char *)accept_time.c_str());



	// generated data

	// For 'ORIGIN' cdrs, call_time is the traffic_event_time
	// For log to db 
	reng_date d= d_accept_time_date;
	reng_time t= d_accept_time_time;
	char buf[100];
	buf[0] = '\0';
	sprintf(buf,"%02d%s%02d%s%04d%s%02d%s%02d%s%02d",d.day,"/",d.month,"/",d.year," ",t.hour,":",t.min,":",t.second); 
	call_time= buf;

	rate_address					= originating_address;
	rate_call_partner				= destination_address;
	rate_call_type					= "ORIGIN";

	if ( strncmp(cdr->destination_address, "94", 2) == 0 )
		rate_sub_service_type = 0;		// local
	else if ( gsm_sub_service_networks->is_application(rate_call_partner) )
	{
		rate_sub_service_type = 2;		// application
	}
	else 
	{
		string network_no, tel_no;
		gsm_sub_service_networks->get_partner_network(rate_call_partner, network_no, tel_no);
		rate_sub_service_type = gsm_sub_service_networks->get_sub_service_id(network_no);
	}

	source_node_SCCP_address		= cdr->source_node_SCCP_address;		
	destination_node_SCCP_address	= cdr->destination_node_SCCP_address;

	return true;
}


bool decoded_cdr::unpack_termi(cdr_decode *cdr)
{
	// check for a Dialog number
	if ( strncmp(cdr->destination_address, "9477", 4) != 0 )
		return false;

	message_source					= cdr->message_source;

	string	t_destination_address		= cdr->destination_address;
	string	t_originating_address		= cdr->originating_address;

	destination_address				= t_destination_address.substr(2, (t_destination_address.size()-2));		
	
	if ( strncmp(cdr->originating_address, "94", 2) != 0 )
		originating_address				= cdr->originating_address;
	else
		originating_address				= t_originating_address.substr(2, (t_originating_address.size()-2));
	
	traffic_event_type				= cdr->traffic_event_type;				
	traffic_event_time				= cdr->traffic_event_time;				
	destination_logical_SME			= cdr->destination_logical_SME;		
	accept_time						= cdr->accept_time;					
	duplicate_message_behaviour		= cdr->duplicate_message_behaviour;	
	SME_reference_number			= cdr->SME_reference_number;			
	first_in_batch					= cdr->first_in_batch;					
	call_direction					= cdr->call_direction;					 
	distribution					= cdr->distribution;						
	destination_IMSI				= cdr->destination_IMSI;					
	closed_user_group				= cdr->closed_user_group;			
	CUG_type						= cdr->CUG_type;							
	originating_IMSI				= cdr->originating_IMSI;					
	first_network_operation			= cdr->first_network_operation;			
	first_delivery_network			= cdr->first_delivery_network;			
	second_network_operation		= cdr->second_network_operation;				 
	second_delivery_network			= cdr->second_delivery_network;			
	second_network_failure_type		= cdr->second_network_failure_type;		
	second_network_error_returned	= cdr->second_network_error_returned;	
	second_network_failure_cause	= cdr->second_network_failure_cause;	
	second_delivery_failure_reason	= cdr->second_delivery_failure_reason;	
	priority						= cdr->priority;							
	protocol_id						= cdr->protocol_id;						
	SMSC_reference_number			= cdr->SMSC_reference_number;			
	source_node_SCCP_address		= cdr->source_node_SCCP_address;		
	destination_node_SCCP_address	= cdr->destination_node_SCCP_address;
	billing_flags					= cdr->billing_flags;
	sub_logical_sme					= cdr->sub_logical_sme;	


	// make Y2K compliant 50-99 in 1900 00-49 in 2000 
	if(traffic_event_time.substr(0,2) < "50")
		traffic_event_time = "20"+traffic_event_time;
	else
	{
		traffic_event_time = "19"+traffic_event_time;
	}
	
	// after Y2K fix YYYYMMDDHHMISS
	d_traffic_event_time_time.set_time((char*)traffic_event_time.c_str()+8);
	d_traffic_event_time_date.set_date((char*)traffic_event_time.c_str());

	// For 'TERMI' cdrs, call_time is the traffic_event_time
	// For time range check in main() for Primary Log Reader
	traffic_event_time[14] = '\0';
	d_call_time.set_date_time((char *)traffic_event_time.c_str());

	// make Y2K compliant 50-99 in 1900 00-49 in 2000 
	if(accept_time.substr(0,2) < "50")
		accept_time = "20"+accept_time;
	else
	{
		accept_time = "19"+accept_time;
	}
	
	// after Y2K fix YYYYMMDDHHMISS
	d_accept_time_time.set_time((char*)accept_time.c_str()+8);
	d_accept_time_date.set_date((char*)accept_time.c_str());


	// generated data

	// For 'TERMI' cdrs, call_time is the traffic_event_time
	// For log to db 
	reng_date d= d_traffic_event_time_date;
	reng_time t= d_traffic_event_time_time;
	char buf[100];
	buf[0] = '\0';
	sprintf(buf,"%02d%s%02d%s%04d%s%02d%s%02d%s%02d",d.day,"/",d.month,"/",d.year," ",t.hour,":",t.min,":",t.second); 
	call_time = buf;

	rate_address					= destination_address;
	rate_call_partner				= originating_address;
	rate_call_type					= "TERMI";

	if ( strncmp(cdr->originating_address, "94", 2) == 0 )
		rate_sub_service_type = 0;		// local
	else if ( gsm_sub_service_networks->is_application(rate_call_partner) )
		rate_sub_service_type = 2;		// application
	else 
	{
		string network_no, tel_no;
		gsm_sub_service_networks->get_partner_network(rate_call_partner, network_no, tel_no);
		rate_sub_service_type = gsm_sub_service_networks->get_sub_service_id(network_no);
	}

	source_node_SCCP_address		= cdr->source_node_SCCP_address;		
	destination_node_SCCP_address	= cdr->destination_node_SCCP_address;

	return true;
}


