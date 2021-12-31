

//////////////////////////////////////////////////////////////////////
//
// sub_service_networks.cpp: 
//			implementation of the sub_service_networks class.
// SMSC Mediation Engine
// developer - Chandika Nettasinghe
// development - 2003
//
//////////////////////////////////////////////////////////////////////


#include "db_data_containers.h"
#include "defines.h"

bool sub_service_networks::insert(string network_id, int sub_service_id)
{
	pair<SUB_SERVICE_DEF::iterator, bool> p=sub_service_map.insert(make_pair(network_id, sub_service_id));
	if (p.second == false)
	{
		cout<<"ERR: duplicate network number "<<network_id<<endl;
		return false;
	}
	return true;
}

bool sub_service_networks::insert_applications_map(string network_id, int sub_service_id)
{
	pair<SUB_SERVICE_DEF::iterator, bool> p=applications_map.insert(make_pair(network_id, sub_service_id));
	if (p.second == false)
	{
		cout<<"ERR: duplicate network number "<<network_id<<endl;
		return false;
	}
	return true;
}

bool sub_service_networks::insert_sub_service_map(string network_id, int sub_service_id)
{
	pair<SUB_SERVICE_DEF::iterator, bool> p=sub_service_map.insert(make_pair(network_id, sub_service_id));
	if (p.second == false)
	{
		cout<<"ERR: duplicate network number "<<network_id<<endl;
		return false;
	}
	return true;
}


void sub_service_networks::print()
{
	for(SUB_SERVICE_DEF::iterator i=sub_service_map.begin(); i!=sub_service_map.end(); i++)
	{
		cout<<"{"<<(*i).first<<"} {"<<(*i).second<<"}"<<endl;
	}
}

// the call partner string consists of network_no+tel_no
// both are variable length fields try reapeadted matching to locate a valid nework
// starting from the longest template till a string is found (see egrep code)
// 1) 4 char match
// 2) 3 char match
// 3) 2 char match
// 4) 1 char match
bool sub_service_networks::get_partner_network(string call_partner, string &network_no, string &tel_no)
{
	SUB_SERVICE_DEF::iterator i;

	bool found=false;
	int network_no_length;
	
	string possible_network;

	for(int j=4; j>0; j--)
	{
		possible_network = call_partner.substr(0,j);
		i = sub_service_map.find(possible_network);
		found = (i != sub_service_map.end());
		if(found)
		{
			network_no = call_partner.substr(0,j);
			network_no_length = network_no.size();
			tel_no =call_partner.substr(network_no_length, call_partner.size()-network_no_length);
			return found;
		}
	} 
	return found;
}


int sub_service_networks::get_sub_service_id(string network_id)
{
	SUB_SERVICE_DEF::iterator i;

	i = sub_service_map.find(network_id);
	if(i != sub_service_map.end())
		return (*i).second ;
	else
		return 99;			// when sub_service not found 99 returns
}

bool sub_service_networks::is_application(string rate_call_partner)
{
	SUB_SERVICE_DEF::iterator i;

	i = applications_map.find(rate_call_partner);
	if(i != applications_map.end())
		return true ;
	else
		return false;			
}



