# Parameters

CC = $(CXX)

CLIENT = ClientPlaces_client PlaceAirport_client
SERVER = ClientPlaces_server PlacesAirport_server

SOURCES_CLNT.c = 
SOURCES_CLNT.h = 
SOURCES_SVC.c = 
SOURCES_SVC.h = 
SOURCES.x = ClientPlaces.x

TARGETS_SVC.c = ClientPlaces_svc.c ClientPlaces_server.c ClientPlaces_xdr.c PlacesAirport_svc.c PlacesAirport_server.c PlacesAirport_xdr.c 
TARGETS_CLNT.c = ClientPlaces_clnt.c ClientPlaces_client.c ClientPlaces_xdr.c PlacesAirport_clnt.c PlacesAirport_client.c PlacesAirport_xdr.c 
TARGETS = ClientPlaces.h ClientPlaces_xdr.c ClientPlaces_clnt.c ClientPlaces_svc.c ClientPlaces_client.c ClientPlaces_server.c

OBJECTS_CLNT = $(SOURCES_CLNT.c:%.c=%.o) $(TARGETS_CLNT.c:%.c=%.o)
OBJECTS_SVC = $(SOURCES_SVC.c:%.c=%.o) $(TARGETS_SVC.c:%.c=%.o)
# Compiler flags 

CFLAGS += -g -I/usr/include/tirpc
#LDLIBS += -lnsl
LDLIBS += -ltirpc
RPCGENFLAGS = 

# Targets 

all : $(CLIENT) $(SERVER)

#$(TARGETS) : $(SOURCES.x) 
#	rpcgen $(RPCGENFLAGS) $(SOURCES.x)

$(OBJECTS_CLNT) : $(SOURCES_CLNT.c) $(SOURCES_CLNT.h) $(TARGETS_CLNT.c) 

$(OBJECTS_SVC) : $(SOURCES_SVC.c) $(SOURCES_SVC.h) $(TARGETS_SVC.c) 

$(CLIENT) : $(OBJECTS_CLNT) 
	$(LINK.c) -o $(CLIENT) $(OBJECTS_CLNT) $(LDLIBS) 

$(SERVER) : $(OBJECTS_SVC) 
	$(LINK.c) -o $(SERVER) $(OBJECTS_SVC) $(LDLIBS)

 clean:
	 $(RM) core $(OBJECTS_CLNT) $(OBJECTS_SVC) $(CLIENT) $(SERVER)

