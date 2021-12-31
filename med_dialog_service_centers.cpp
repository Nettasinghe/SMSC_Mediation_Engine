

//////////////////////////////////////////////////////////////////////
//
// med_dialog_service_centers.cpp: 
// implementation of the med_dialog_service_centers class.
// SMSC Mediation Engine
// developer - Chandika Nettasinghe
// development - 2003
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"


bool med_dialog_service_centers::insert_dialog_service_centers(string service_center)
{
	pair<CERVICE_CENTERS_DEF::iterator, bool> p = service_center_map.insert(service_center);

	if (p.second == false)
	{
		cout<<"ERR: duplicate med_dialog_service_centers number"<<service_center<<endl;
		return false;
	}
	return true;
}


bool med_dialog_service_centers::is_dialog_service_center(string cdr_service_center)
{
	CERVICE_CENTERS_DEF::iterator i;

	i = service_center_map.find(cdr_service_center);
	if(i == service_center_map.end())
	{
		return false;		
	}
	return true;
}
