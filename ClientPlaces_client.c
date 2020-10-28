/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "ClientPlaces.h"
#include <string>

void
client_places_prog_1(char* host, std::string city, std::string state)
{
	CLIENT *clnt;
	list_ret  *result_1;
	
	//Format the query
	std::string conc = city+state;
	std::string formattedQuery = "";
	for(int i=0;i<conc.length();i++){
		if (isalpha(conc[i]) && !isspace(conc[i]))
        {
            formattedQuery += toupper(conc[i]);
        }
	}
	
	name  call_places_1_arg = const_cast<char*>(formattedQuery.c_str());

#ifndef	DEBUG
	clnt = clnt_create (host, CLIENT_PLACES_PROG, CLIENT_PLACES_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

	result_1 = call_places_1(&call_places_1_arg, clnt);
	if (result_1 == (list_ret *) NULL) {
		clnt_perror (clnt, "call failed");
	}else{
		//A lat of -999 is an error code we used to signify a location that doesn't exist.
		//-1000 signifies a query that needs to be more refined.
		if(result_1->list_ret_u.list.airport1.lat == -999){
			printf("Location does not exist.\n");
			return;
		}else if (result_1->list_ret_u.list.airport1.lat == -1000){
			printf("Please refine your query.\n");
			return;
		}
		//Printing the results
		printf("Name: %s: Latitude: %f, Longitude: %f\n\n", result_1->list_ret_u.list.name, result_1->list_ret_u.list.coordinate.lat, result_1->list_ret_u.list.coordinate.lon);
		printf("code = %s, name = %s, state = %s, distance = %fmiles\n\n", result_1->list_ret_u.list.airport1.code, result_1->list_ret_u.list.airport1.name, result_1->list_ret_u.list.airport1.state, result_1->list_ret_u.list.airport1.dist);
		printf("code = %s, name = %s, state = %s, distance = %f miles\n\n", result_1->list_ret_u.list.airport2.code, result_1->list_ret_u.list.airport2.name, result_1->list_ret_u.list.airport2.state, result_1->list_ret_u.list.airport2.dist);
		printf("code = %s, name = %s, state = %s, distance = %f miles\n\n", result_1->list_ret_u.list.airport3.code, result_1->list_ret_u.list.airport3.name, result_1->list_ret_u.list.airport3.state, result_1->list_ret_u.list.airport3.dist);
		printf("code = %s, name = %s, state = %s, distance = %f miles\n\n", result_1->list_ret_u.list.airport4.code, result_1->list_ret_u.list.airport4.name, result_1->list_ret_u.list.airport4.state, result_1->list_ret_u.list.airport4.dist);
		printf("code = %s, name = %s, state = %s, distance = %f miles\n\n", result_1->list_ret_u.list.airport5.code, result_1->list_ret_u.list.airport5.name, result_1->list_ret_u.list.airport5.state, result_1->list_ret_u.list.airport5.dist);
	}

	//Free client memory before closing everything.
    clnt_freeres(clnt, (xdrproc_t)xdr_list_ret, result_1);
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char* host;
	std::string city;
	std::string state;

	//Client must provide the right amount of arguments.
	if (argc != 4) {
		printf ("usage: %s placeshost city state\n", argv[0]);
		exit (1);
	}

	//Check for a valid state length.
	if(strlen(argv[3])!=2){
		printf("Please input a two letter abbreviation for the state.\n");
		exit (1);
	}

	host = argv[1];
	city = argv[2];
	state = argv[3];
	client_places_prog_1 (host, city, state);
	
	exit (0);
}
