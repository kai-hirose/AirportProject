/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#include "PlacesAirport.h"

bool_t
xdr_airport (XDR *xdrs, airport *objp)
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
xdr_airportList (XDR *xdrs, airportList *objp)
{
	register int32_t *buf;

	int i;
	 if (!xdr_int (xdrs, &objp->error))
		 return FALSE;
	 if (!xdr_vector (xdrs, (char *)objp->array, 5,
		sizeof (airport), (xdrproc_t) xdr_airport))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_KDNode (XDR *xdrs, KDNode *objp)
{
	register int32_t *buf;

	 if (!xdr_pointer (xdrs, (char **)&objp->right, sizeof (KDNode), (xdrproc_t) xdr_KDNode))
		 return FALSE;
	 if (!xdr_pointer (xdrs, (char **)&objp->left, sizeof (KDNode), (xdrproc_t) xdr_KDNode))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->lat))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->lon))
		 return FALSE;
	return TRUE;
}

bool_t
xdr_coordinate (XDR *xdrs, coordinate *objp)
{
	register int32_t *buf;

	 if (!xdr_double (xdrs, &objp->lat))
		 return FALSE;
	 if (!xdr_double (xdrs, &objp->lon))
		 return FALSE;
	return TRUE;
}
