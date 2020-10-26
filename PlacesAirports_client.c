/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "PlacesAirports.h"


void
places_airport_prog_1(char *host)
{
	CLIENT *clnt;
	list_ret  *result_1;
	coordinate  call_airports_1_arg;
	call_airports_1_arg.lat = 47.441406;
	call_airports_1_arg.lon = -122.293077;
	printf("%f\n", call_airports_1_arg.lat);
#ifndef	DEBUG
	clnt = clnt_create (host, PLACES_AIRPORT_PROG, PLACES_AIRPORT_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = call_airports_1(&call_airports_1_arg, clnt);
	if (result_1 == (list_ret *) NULL) {
		clnt_perror (clnt, "call failed");
	}
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	places_airport_prog_1 (host);
exit (0);
}
