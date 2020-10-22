/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "PlacesAirport.h"

bool_t
xdr_airportPA (XDR *xdrs, airportPA *objp)
{
	register int32_t *buf;

	 if (!xdr_int (xdrs, &objp->code))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->name, sizeof (char), (xdrproc_t) xdr_char))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->lat))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->lon))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->distance))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_returnPA (XDR *xdrs, returnPA *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->error))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->array, 5,
		sizeof (airportPA), (xdrproc_t) xdr_airportPA))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_coordinatePA (XDR *xdrs, coordinatePA *objp)
{
	register int32_t *buf;

	 if (!xdr_double (xdrs, &objp->lat))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->lon))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_kDNodePtr (XDR *xdrs, kDNodePtr *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)objp, sizeof (struct kDNode), (xdrproc_t) xdr_kDNode))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_kDNode (XDR *xdrs, kDNode *objp)
{
	register int32_t *buf;

	 if (!xdr_kDNodePtr (xdrs, &objp->right))
		 return FALSE;
	 if (!xdr_kDNodePtr (xdrs, &objp->left))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->lat))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->lon))
		 return FALSE;
	return TRUE;
}
