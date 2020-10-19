struct airport{
    int code;
    char* name;
    double lat;
    double lon;
    double distance;
};

struct airportList{
    int error;
    airport array[5];
};

struct KDNode{
    KDNode* right;
    KDNode* left;
    double lat;
    double lon;
};

struct coordinate {
	double lat;
	double lon;
};

program AIRPORT_PROG{
    version AIRPORT_VERS{
        airportList callAirport(airport) = 1;
    }=1;
}=0x3232077B;
