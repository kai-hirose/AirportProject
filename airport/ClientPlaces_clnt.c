/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include <memory.h> /* for memset */
#include "ClientPlaces.h"

/* Default timeout can be changed using clnt_control() */
static struct timeval TIMEOUT = { 25, 0 };

returnCP *
callplaces_1(nametypecp *argp, CLIENT *clnt)
{
	static returnCP clnt_res;

	memset((char *)&clnt_res, 0, sizeof(clnt_res));
	if (clnt_call (clnt, CALLPLACES,
		(xdrproc_t) xdr_nametypecp, (caddr_t) argp,
		(xdrproc_t) xdr_returnCP, (caddr_t) &clnt_res,
		TIMEOUT) != RPC_SUCCESS) {
		return (NULL);
	}
	return (&clnt_res);
}
