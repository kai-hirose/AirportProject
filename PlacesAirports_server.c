/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "PlacesAirports.h"
#include "KDTree.h"

list_ret *
call_airports_1_svc(coordinate *argp, struct svc_req *rqstp)
{
	static list_ret  result;
	KDTree myTree("airport-locations.txt");
	
	return &result;
}