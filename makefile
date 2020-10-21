# Parameters
CLIENTCP = ClientPlaces_client
SERVERCP = ClientPlaces_server

CLIENTPA = PlacesAirport_client
SERVERPA = PlacesAirport_server

SOURCESCP_CLNT.c = 
SOURCESCP_CLNT.h = 
SOURCESCP_SVC.c = 
SOURCESCP_SVC.h = 
SOURCESCP.x = ClientPlaces.x

SOURCESPA_CLNT.c =
SOURCESPA_CLNT.h =
SOURCESPA_CLNT.c =
SOURCESPA_SVC.h =
SOURCESPA.x = PlacesAirport.x

#ClientPlaces files
TARGETSCP_SVC.c = ClientPlaces_svc.c ClientPlaces_server.c ClientPlaces_xdr.c PlacesAirport_xdr.c PlacesAirport_clnt.c
TARGETSCP_CLNT.c = ClientPlaces_clnt.c ClientPlaces_client.c ClientPlaces_xdr.c 
TARGETSCP = ClientPlaces.h ClientPlaces_xdr.c ClientPlaces_clnt.c ClientPlaces_svc.c ClientPlaces_client.c ClientPlaces_server.c PlacesAirport.h

#PlacesAirport files
TARGETSPA_SVC.c = PlacesAirport_svc.c PlacesAirport_server.c PlacesAirport_xdr.c
TARGETSPA_CLNT.c = PlacesAirport_clnt.c PlacesAirport_client.c PlacesAirport_xdr.c
TARGETSPA = PlacesAirport.h PlacesAirport_xdr.c PlacesAirport_clnt.c PlacesAirport_svc.c PlacesAirport_client.c PlacesAirport_server.c


#ClientPlaces and PlacesAirport objects.
OBJECTSCP_CLNT = $(SOURCESCP_CLNT.c:%.c=%.o)  $(TARGETSCP_CLNT.c:%.c=%.o)
OBJECTSCP_SVC = $(SOURCESCP_SVC.c:%.c=%.o) $(TARGETSCP_SVC.c:%.c=%.o)

OBJECTSPA_CLNT = $(SOURCESPA_CLNT.c:%.c=%.o)$(TARGETSPA_CLNT.c:%.c=%.o)
OBJECTSPA_SVC = $(SOURCESPA_SVC.c:%.c=%.o)$(TARGETSPA_SVC.c:%.c=%.o)

# Compiler flags 

#C++ flag
CC = $(CXX)
#CFLAGS += -g
CFLAGS += -g -I/usr/include/tirpc
#LDLIBS += -lnsl
LDLIBS += -ltirpc
RPCGENFLAGS = 

# Targets 

all : $(CLIENTCP) $(SERVERCP) $(SERVERPA)

#$(TARGETS) : $(SOURCES.x) 
#	rpcgen $(RPCGENFLAGS) $(SOURCES.x)

$(OBJECTSCP_CLNT) :  $(SOURCESCP_CLNT.c) $(SOURCESCP_CLNT.h) $(TARGETSCP_CLNT.c)

$(OBJECTSCP_SVC) : $(SOURCESCP_SVC.c) $(SOURCESCP_SVC.h) $(TARGETSCP_SVC.c) 

$(OBJECTSPA_CLNT) : $(SOURCESPA_CLNT.c) $(SOURCESPA_CLNT.h) $(TARGETSPA_CLNT.c) 

$(OBJECTSPA_SVC) : $(SOURCESPA_SVC.c) $(SOURCESPA_SVC.h) $(TARGETSPA_SVC.c) 

$(CLIENTCP) : $(OBJECTSCP_CLNT) 
	$(LINK.cc) -std=c++11 -o $(CLIENTCP) $(OBJECTSCP_CLNT) $(LDLIBS) 

$(CLIENTPA) : $(OBJECTSPA_CLNT) 
	$(LINK.cc) -std=c++11 -o $(CLIENTPA) $(OBJECTSPA_CLNT) $(LDLIBS) 

$(SERVERCP) : $(OBJECTSCP_SVC) 
	$(LINK.cc) -std=c++11 -o $(SERVERCP) $(OBJECTSCP_SVC) $(LDLIBS)

$(SERVERPA) : $(OBJECTSPA_SVC) 
	$(LINK.cc) -std=c++11 -o $(SERVERPA) $(OBJECTSPA_SVC) $(LDLIBS)
	
clean:
	$(RM) core $(OBJECTSCP_CLNT) $(OBJECTSCP_SVC) $(CLIENTCP) $(SERVERCP) $(OBJECTSPA_CLNT) $(OBJECTSPA_SVC) $(CLIENTPA) $(SERVERPA)