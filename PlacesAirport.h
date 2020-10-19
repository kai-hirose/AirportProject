/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _PLACESAIRPORT_H_RPCGEN
#define _PLACESAIRPORT_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif


struct airport {
	int code;
	char *name;
	double lat;
	double lon;
	double distance;
};
typedef struct airport airport;

struct airportList {
	int error;
	airport array[5];
};
typedef struct airportList airportList;

struct KDNode {
	struct KDNode *right;
	struct KDNode *left;
	double lat;
	double lon;
};
typedef struct KDNode KDNode;

struct coordinate {
	double lat;
	double lon;
};
typedef struct coordinate coordinate;

#define AIRPORT_PROG 0x3232077B
#define AIRPORT_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define callAirport 1
extern  airportList * callairport_1(airport *, CLIENT *);
extern  airportList * callairport_1_svc(airport *, struct svc_req *);
extern int airport_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define callAirport 1
extern  airportList * callairport_1();
extern  airportList * callairport_1_svc();
extern int airport_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_airport (XDR *, airport*);
extern  bool_t xdr_airportList (XDR *, airportList*);
extern  bool_t xdr_KDNode (XDR *, KDNode*);
extern  bool_t xdr_coordinate (XDR *, coordinate*);

#else /* K&R C */
extern bool_t xdr_airport ();
extern bool_t xdr_airportList ();
extern bool_t xdr_KDNode ();
extern bool_t xdr_coordinate ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_PLACESAIRPORT_H_RPCGEN */