/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "ClientPlaces.h"

returnCP *
callplaces_1_svc(nametypecp *argp, struct svc_req *rqstp)
{
	static returnCP  result;
	airportNodeCP test;
	test.airport.code = "tes\n\0";
	result.returnCP_u.list = &test;
	result.err = 0;
	return &result;
}
