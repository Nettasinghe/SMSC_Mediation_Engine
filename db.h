

//////////////////////////////////////////////////////////////////////
//
// db.h: 
// header file for smsc mediation database access methods
// SMSC Mediation Engine
// developer - Chandika Nettasinghe
// development - 2003
//
//////////////////////////////////////////////////////////////////////



void	db_connect(char *in_login); 
void	db_disconnect(); 
//void	db_insert_decoded_cdr();
void	db_insert_decoded_cdr(int cdr_count);
void	db_insert_air_cdr(int cdr_count);






