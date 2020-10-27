/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "PlacesAirports.h"
#include "KDTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <rpc/pmap_clnt.h>
#include <string.h>
#include <memory.h>
#include <sys/socket.h>
#include <netinet/in.h>

#ifndef SIG_PF
#define SIG_PF void(*)(int)
#endif

static void
places_airport_prog_1(struct svc_req *rqstp, register SVCXPRT *transp)
{
	union {
		coordinate call_airports_1_arg;
	} argument;
	char *result;
	xdrproc_t _xdr_argument, _xdr_result;
	char *(*local)(char *, struct svc_req *);

	switch (rqstp->rq_proc) {
	case NULLPROC:
		(void) svc_sendreply (transp, (xdrproc_t) xdr_void, (char *)NULL);
		return;

	case CALL_AIRPORTS:
		_xdr_argument = (xdrproc_t) xdr_coordinate;
		_xdr_result = (xdrproc_t) xdr_list_ret;
		local = (char *(*)(char *, struct svc_req *)) call_airports_1_svc;
		break;

	default:
		svcerr_noproc (transp);
		return;
	}
	memset ((char *)&argument, 0, sizeof (argument));
	if (!svc_getargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		svcerr_decode (transp);
		return;
	}
	result = (*local)((char *)&argument, rqstp);
	if (result != NULL && !svc_sendreply(transp, (xdrproc_t) _xdr_result, result)) {
		svcerr_systemerr (transp);
	}
	if (!svc_freeargs (transp, (xdrproc_t) _xdr_argument, (caddr_t) &argument)) {
		fprintf (stderr, "%s", "unable to free arguments");
		exit (1);
	}
	return;
}

char* airportPath;

KDTree tree1;

int
main (int argc, char **argv)
{
	//Build the tree
	if (argc < 2) {
		printf ("usage: %s airportfilepath\n", argv[0]);
		exit (1);
	}
	airportPath = argv[1];
	tree1.buildAirportTree(airportPath);
	register SVCXPRT *transp;

	pmap_unset (PLACES_AIRPORT_PROG, PLACES_AIRPORT_VERS);

	transp = svcudp_create(RPC_ANYSOCK);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create udp service.");
		exit(1);
	}
	if (!svc_register(transp, PLACES_AIRPORT_PROG, PLACES_AIRPORT_VERS, places_airport_prog_1, IPPROTO_UDP)) {
		fprintf (stderr, "%s", "unable to register (PLACES_AIRPORT_PROG, PLACES_AIRPORT_VERS, udp).");
		exit(1);
	}

	transp = svctcp_create(RPC_ANYSOCK, 0, 0);
	if (transp == NULL) {
		fprintf (stderr, "%s", "cannot create tcp service.");
		exit(1);
	}
	if (!svc_register(transp, PLACES_AIRPORT_PROG, PLACES_AIRPORT_VERS, places_airport_prog_1, IPPROTO_TCP)) {
		fprintf (stderr, "%s", "unable to register (PLACES_AIRPORT_PROG, PLACES_AIRPORT_VERS, tcp).");
		exit(1);
	}

	svc_run ();
	fprintf (stderr, "%s", "svc_run returned");
	exit (1);
	/* NOTREACHED */
}
