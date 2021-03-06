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

#define MAXLEN 256

typedef char *name;

typedef char *code;

typedef char *state;

typedef struct tNode *tNodePtr;

struct place {
	name name;
	state state;
	double lat;
	double lon;
};
typedef struct place place;

#ifndef AIRPORT
#define AIRPORT
struct airport {
	code code;
	name name;
	state state;
	double lat;
	double lon;
	double dist;
};
typedef struct airport airport;
#endif

#ifndef COORDINATE
#define COORDINATE
struct coordinate {
	double lat;
	double lon;
};
typedef struct coordinate coordinate;
#endif

#ifndef AIRPORTLIST
#define AIRPORTLIST
struct airportList {
	name name;
	coordinate coordinate;
	airport airport1;
	airport airport2;
	airport airport3;
	airport airport4;
	airport airport5;
};
typedef struct airportList airportList;
#endif

#ifndef LIST_RET
#define LIST_RET
struct list_ret {
	int err;
	union {
		airportList list;
	} list_ret_u;
};
typedef struct list_ret list_ret;
#endif

struct tNode {
	tNodePtr array;
	int index;
	double lat;
	double lon;
};
typedef struct tNode tNode;

#define CLIENT_PLACES_PROG 0x66454323
#define CLIENT_PLACES_VERS 1

#if defined(__STDC__) || defined(__cplusplus)
#define CALL_PLACES 1
extern  list_ret * call_places_1(name *, CLIENT *);
extern  list_ret * call_places_1_svc(name *, struct svc_req *);
extern int client_places_prog_1_freeresult (SVCXPRT *, xdrproc_t, caddr_t);

#else /* K&R C */
#define CALL_PLACES 1
extern  list_ret * call_places_1();
extern  list_ret * call_places_1_svc();
extern int client_places_prog_1_freeresult ();
#endif /* K&R C */

/* the xdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t xdr_name (XDR *, name*);
extern  bool_t xdr_code (XDR *, code*);
extern  bool_t xdr_state (XDR *, state*);
extern  bool_t xdr_tNodePtr (XDR *, tNodePtr*);
extern  bool_t xdr_place (XDR *, place*);
extern  bool_t xdr_airport (XDR *, airport*);
extern  bool_t xdr_airportList (XDR *, airportList*);
extern  bool_t xdr_list_ret (XDR *, list_ret*);
extern  bool_t xdr_coordinate (XDR *, coordinate*);
extern  bool_t xdr_tNode (XDR *, tNode*);

#else /* K&R C */
extern bool_t xdr_name ();
extern bool_t xdr_code ();
extern bool_t xdr_state ();
extern bool_t xdr_tNodePtr ();
extern bool_t xdr_place ();
extern bool_t xdr_airport ();
extern bool_t xdr_airportList ();
extern bool_t xdr_list_ret ();
extern bool_t xdr_coordinate ();
extern bool_t xdr_tNode ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_CLIENTPLACES_H_RPCGEN */
