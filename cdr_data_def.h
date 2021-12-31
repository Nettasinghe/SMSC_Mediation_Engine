

//////////////////////////////////////////////////////////////////////
//
// cdr_data_defs.h: 
// header file for smsc mediation constants
// SMSC Mediation Engine
// developer - Chandika Nettasinghe
// development - 2003
//
//////////////////////////////////////////////////////////////////////


// All the constants that are required for the CDR Broker



#define				START_SIGNATURE = 0x05;				// Traffic Event Type - Short Message Delivery  
static const int	START_SIGNATURE_OFFSET = 45;		// cdr_start_of_traffic_event_type


// All CDRs are fo fixed length of 200 bytes
static const int  FIXED_CDR_LENGTH = 200;



// CDR field positions
//static const int  cdr_start_of_message_source					=	4;	
static const int  cdr_start_of_message_source					=	1;	
static const int  cdr_start_of_destination_address				=	7;	
static const int  cdr_start_of_originating_address				=	25;	
static const int  cdr_start_of_traffic_event_type				=	45;		 
static const int  cdr_start_of_traffic_event_time				=	46;		 
static const int  cdr_start_of_destination_logical_SME			=	53;	
static const int  cdr_start_of_accept_time						=	54;	
static const int  cdr_start_of_duplicate_message_behaviour		=	61; 
static const int  cdr_start_of_SME_reference_number				=	65;	
static const int  cdr_start_of_first_in_batch					=	69;	
static const int  cdr_start_of_call_direction					=	70;		 
static const int  cdr_start_of_distribution						=	71;	
static const int  cdr_start_of_destination_IMSI					=	72;	
static const int  cdr_start_of_closed_user_group				=	88;		 
static const int  cdr_start_of_CUG_type							=	92;	
static const int  cdr_start_of_originating_IMSI					=	93;	
static const int  cdr_start_of_first_network_operation			=	119;		 
static const int  cdr_start_of_first_delivery_network			=	120;	
static const int  cdr_start_of_second_network_operation			=	121;		 	 
static const int  cdr_start_of_second_delivery_network			=	122;	
static const int  cdr_start_of_second_network_failure_type		=	123;	
static const int  cdr_start_of_second_network_error_returned	=	125;		 
static const int  cdr_start_of_second_network_failure_cause		=	126;		 
static const int  cdr_start_of_second_delivery_failure_reason	=	127;	
static const int  cdr_start_of_priority							=	128;	
static const int  cdr_start_of_protocol_id						=	129;		 
static const int  cdr_start_of_SMSC_reference_number			=	130;	
//static const int  cdr_start_of_source_node_SCCP_address			=	134;
static const int  cdr_start_of_source_node_SCCP_address			=	124;	
//static const int  cdr_start_of_destination_node_SCCP_address	=	155;	
static const int  cdr_start_of_destination_node_SCCP_address	=	145;	
static const int  cdr_start_of_billing_flags					=	176;	


// CDR field lengths
//static const int  message_source_LENGTH					=	3;	
static const int  message_source_LENGTH					=	4;	
static const int  destination_address_LENGTH			=	16;	
static const int  originating_address_LENGTH			=	20;	
static const int  traffic_event_type_LENGTH				=	1;		 
//static const int  traffic_event_time_LENGTH				=	7;
static const int  traffic_event_time_LENGTH				=	6;		 
static const int  destination_logical_SME_LENGTH		=	1;	
//static const int  accept_time_LENGTH					=	7;	
static const int  accept_time_LENGTH					=	6;	
static const int  duplicate_message_behaviour_LENGTH	=	4; 
static const int  SME_reference_number_LENGTH			=	4;	
static const int  first_in_batch_LENGTH					=	1;	
static const int  call_direction_LENGTH					=	1;		 
static const int  distribution_LENGTH					=	1;	
static const int  destination_IMSI_LENGTH				=	16;	
static const int  closed_user_group_LENGTH				=	4;		 
static const int  CUG_type_LENGTH						=	1;	
static const int  originating_IMSI_LENGTH				=	16;	
static const int  first_network_operation_LENGTH		=	1;	 
static const int  first_delivery_network_LENGTH			=	1;	
static const int  second_network_operation_LENGTH		=	1;		 	 
static const int  second_delivery_network_LENGTH		=	1;
static const int  second_network_failure_type_LENGTH	=	1;
static const int  second_network_error_returned_LENGTH	=	2;	 
static const int  second_network_failure_cause_LENGTH	=	1;		 
static const int  second_delivery_failure_reason_LENGTH	=	1;	
static const int  priority_LENGTH						=	1;	
static const int  protocol_id_LENGTH					=	1;	 
static const int  SMSC_reference_number_LENGTH			=	4;
static const int  source_node_SCCP_address_LENGTH		=	21;
static const int  destination_node_SCCP_address_LENGTH	=	21;	
static const int  billing_flags_LENGTH					=	1;	


