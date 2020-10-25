/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _CLIENTPLACES_H_RPCGEN
#define _CLIENTPLACES_H_RPCGEN

#include <rpc/rpc.h>


#ifdef __cplusplus
extern "C" {
#endif

#define NAMETYPECPSIZE 256
#define STATETYPECPSIZE 2
#define CODETYPECPSIZE 3

typedef char *nametypecp;

typedef char *statetypecp;

typedef char *codetypecp;

typedef struct airportNodeCP *airportListCP;

typedef struct tNode *tNodePtr;

struct place {
	nametypecp name;
	statetypecp state;
	double lat;
	double lon;
};
typedef struct place place;

struct airportCP {
	codetypecp code;
	nametypecp name;
	double lat;
	double lon;
	double distance;
};
typedef struct airportCP airportCP;

struct airportNodeCP {
	airportCP airport;
	airportListCP next;
};
typedef struct airportNodeCP airportNodeCP;

struct returnCP {
	int err;
	union {
		airportListCP list;
	} returnCP_u;
};
typedef struct returnCP returnCP;

struct tNode {
	tNodePtr array;
	int index;
	double lat;
	double lon;
};
typedef struct tNode tNode;

#define CLIENT_PLACES_PROG 0x61320779
#define CLIENT_PLACES_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define CALLPLACES 1
extern  returnCP * callplaces_1(nametypecp *, CLIENT *);
extern  returnCP * callplaces_1_svc(nametypecp *, struct svc_req *);
extern int client_places_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define CALLPLACES 1
extern  returnCP * callplaces_1();
extern  returnCP * callplaces_1_svc();
extern int client_places_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_nametypecp (XDR *, nametypecp*);
extern  bool_t xdr_statetypecp (XDR *, statetypecp*);
extern  bool_t xdr_codetypecp (XDR *, codetypecp*);
extern  bool_t xdr_airportListCP (XDR *, airportListCP*);
extern  bool_t xdr_tNodePtr (XDR *, tNodePtr*);
extern  bool_t xdr_place (XDR *, place*);
extern  bool_t xdr_airportCP (XDR *, airportCP*);
extern  bool_t xdr_airportNodeCP (XDR *, airportNodeCP*);
extern  bool_t xdr_returnCP (XDR *, returnCP*);
extern  bool_t xdr_tNode (XDR *, tNode*);

#else /* K&R C */
extern bool_t xdr_nametypecp ();
extern bool_t xdr_statetypecp ();
extern bool_t xdr_codetypecp ();
extern bool_t xdr_airportListCP ();
extern bool_t xdr_tNodePtr ();
extern bool_t xdr_place ();
extern bool_t xdr_airportCP ();
extern bool_t xdr_airportNodeCP ();
extern bool_t xdr_returnCP ();
extern bool_t xdr_tNode ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CLIENTPLACES_H_RPCGEN */
