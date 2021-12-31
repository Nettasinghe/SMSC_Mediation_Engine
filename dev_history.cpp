
/*

Any note worthy changes with warts and all.


12-december-2003 ver 1.0.1 
	1) Decoded and Accomodated sub_logical_sme field

16-december-2003 ver 1.0.2 
	1) Added accept_time field
	2) Changed call_time field as follows
		if rate_call_type=='ORIGIN' then call_time = accept_time
		if rate_call_type=='TERMI' then call_time = traffic_event_time
	3) Amalgamated with Primary Log Reader (#define PRIMARY)

19-december-2003 ver 1.0.3
	1) Decoding of sub_logical_sme changed from 2 bytes to 3 bytes

20-february-2004 ver 1.0.4
	1) In Primary Log Reader (#define PRIMARY) the config file changed to
		smsc_primary_cdr_eng.config

23-feb-2004 ver 1.0.5
1) Insertion of mediated_time to DYN_7_UDR
2) db logging of cdrs changed to insert any partial block size before updating sys_smsc_dump_files 

09-march-2004 ver 1.0.6
1) Filtered out AIR sms messages sent through the SEMA SMSC
	(1) call_type_id = Originating
	(2) source_node_SCCP_address.substr(14, 10) !=  9477000003 (Dialog service center numbers from med_dialog_service_centers.)

10-march-2004 ver 1.0.7
1) Above Filtered out AIR sms messages logged to DYN_7_AIR_UDR

12-march-2004 ver 1.0.8
1) Filtering of AIR sms criteria changed to 
	origin_cdr->source_node_SCCP_address.substr(14, 4) == "9477"

11-may-2004 ver 1.0.9
1) Since source_node_SCCP_address can be null, assert the length is grtate than or equal to 4 before compare it with "9477".
  ( origin_cdr->source_node_SCCP_address.size() >= 4 ) && ( origin_cdr->source_node_SCCP_address.substr(14, 4) == "9477" )





=================================================================================

Scripts:


CREATE TABLE DYN_7_UDR ( 
  DESTINATION_ADDRESS            VARCHAR2 (30), 
  ORIGINATING_ADDRESS            VARCHAR2 (30)  NOT NULL, 
  TRAFFIC_EVENT_TYPE             NUMBER (9), 
  TRAFFIC_EVENT_TIME             DATE, 
  DESTINATION_LOGICAL_SME        NUMBER (9), 
  SME_REFERENCE_NUMBER           VARCHAR2 (30), 
  CALL_DIRECTION                 NUMBER (9), 
  DISTRIBUTION                   NUMBER (9), 
  DESTINATION_IMSI               VARCHAR2 (30), 
  ORIGINATING_IMSI               VARCHAR2 (30), 
  FIRST_NETWORK_OPERATION        NUMBER (9), 
  FIRST_DELIVERY_NETWORK         NUMBER (9), 
  SECOND_NETWORK_OPERATION       NUMBER (9), 
  SECOND_DELIVERY_NETWORK        NUMBER (9), 
  PRIORITY                       NUMBER (9), 
  SMSC_REFERENCE_NUMBER          NUMBER (9), 
  SOURCE_NODE_SCCP_ADDRESS       VARCHAR2 (30), 
  DESTINATION_NODE_SCCP_ADDRESS  VARCHAR2 (30), 
  RATE_ADDRESS                   VARCHAR2 (30), 
  RATE_CALL_PARTNER              VARCHAR2 (30)  NOT NULL, 
  RATE_CALL_TYPE_ID              VARCHAR2 (10)  NOT NULL, 
  RATE_SUB_SERVICE_TYPE          NUMBER (2)    NOT NULL, 
  MESSAGE_SOURCE                 VARCHAR2 (10), 
  SERVICE_TYPE_ID                NUMBER (3)    DEFAULT 4 NOT NULL, 
  FILE_ID                        NUMBER (9)    NOT NULL, 
  FILE_POS                       NUMBER (9)    NOT NULL, 
  CALL_TIME                      DATE          NOT NULL, 
  SUB_LOGICAL_SME                NUMBER (9), 
  ACCEPT_TIME                    DATE, 
  MEDIATED_TIME                  DATE)

CREATE TABLE DYN_7_AIR_UDR ( 
  DESTINATION_ADDRESS            VARCHAR2 (30), 
  ORIGINATING_ADDRESS            VARCHAR2 (30)  NOT NULL, 
  TRAFFIC_EVENT_TYPE             NUMBER (9), 
  TRAFFIC_EVENT_TIME             DATE, 
  DESTINATION_LOGICAL_SME        NUMBER (9), 
  SME_REFERENCE_NUMBER           VARCHAR2 (30), 
  CALL_DIRECTION                 NUMBER (9), 
  DISTRIBUTION                   NUMBER (9), 
  DESTINATION_IMSI               VARCHAR2 (30), 
  ORIGINATING_IMSI               VARCHAR2 (30), 
  FIRST_NETWORK_OPERATION        NUMBER (9), 
  FIRST_DELIVERY_NETWORK         NUMBER (9), 
  SECOND_NETWORK_OPERATION       NUMBER (9), 
  SECOND_DELIVERY_NETWORK        NUMBER (9), 
  PRIORITY                       NUMBER (9), 
  SMSC_REFERENCE_NUMBER          NUMBER (9), 
  SOURCE_NODE_SCCP_ADDRESS       VARCHAR2 (30), 
  DESTINATION_NODE_SCCP_ADDRESS  VARCHAR2 (30), 
  RATE_ADDRESS                   VARCHAR2 (30), 
  RATE_CALL_PARTNER              VARCHAR2 (30)  NOT NULL, 
  RATE_CALL_TYPE_ID              VARCHAR2 (10)  NOT NULL, 
  RATE_SUB_SERVICE_TYPE          NUMBER (2)    NOT NULL, 
  MESSAGE_SOURCE                 VARCHAR2 (10), 
  SERVICE_TYPE_ID                NUMBER (3)    DEFAULT 4 NOT NULL, 
  FILE_ID                        NUMBER (9)    NOT NULL, 
  FILE_POS                       NUMBER (9)    NOT NULL, 
  CALL_TIME                      DATE          NOT NULL, 
  SUB_LOGICAL_SME                NUMBER (9), 
  ACCEPT_TIME                    DATE, 
  MEDIATED_TIME                  DATE)

CREATE TABLE SYS_SMSC_PRIMARY_DUMP_FILES ( 
  FILE_NAME           VARCHAR2 (100), 
  VALID_CDR_COUNT     NUMBER (7), 
  ERROR_COUNT         NUMBER (7), 
  BYTES_READ          NUMBER (9), 
  FIRST_CDR_DATE      DATE, 
  LAST_CDR_DATE       DATE, 
  CDR_FILE_ID_NO      NUMBER (9), 
  CDR_FILE_DATE       DATE, 
  TRANSFER_DATE       DATE, 
  RATING_DURATION     NUMBER (5), 
  RATING_START_DATE   DATE, 
  DECODED_DATE        DATE, 
  ARCHIVE_DATE        DATE, 
  ARCHIVE_PURGE_DATE  DATE)


CREATE TABLE SYS_SMSC_SECONDARY_DUMP_FILES ( 
  FILE_NAME           VARCHAR2 (100), 
  VALID_CDR_COUNT     NUMBER (7), 
  ERROR_COUNT         NUMBER (7), 
  BYTES_READ          NUMBER (9), 
  FIRST_CDR_DATE      DATE, 
  LAST_CDR_DATE       DATE, 
  CDR_FILE_ID_NO      NUMBER (9), 
  CDR_FILE_DATE       DATE, 
  TRANSFER_DATE       DATE, 
  RATING_DURATION     NUMBER (5), 
  RATING_START_DATE   DATE, 
  DECODED_DATE        DATE, 
  ARCHIVE_DATE        DATE, 
  ARCHIVE_PURGE_DATE  DATE)



rate_sub_service_type formulation :
---------------------------------

  (1)	if ( strncmp(cdr->destination_address, "94", 2) == 0 )
			rate_sub_service_type = 0;		// local

  (2)	else if there is an exact match of call_partner with network_id of MEDV_SMSC_NETWORKS where sub_service_id=2
			then rate_sub_service_type = 2;		// application
  
  (3)	else if there is a call_partner_network_id match with network_id of MEDV_SMSC_NETWORKS where sub_service_id=1
			then rate_sub_service_type = 1;		// international

  (4)	else rate_sub_service_type = 99;		// non of the above


call_time formulation :
---------------------

	if rate_call_type=='ORIGIN' then call_time = accept_time
	if rate_call_type=='TERMI' then call_time = traffic_event_time
*/




