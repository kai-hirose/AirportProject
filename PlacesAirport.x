typedef struct KDNode KDNode
struct airportPA{
    int code;
    char* name;
    double lat;
    double lon;
    double distance;
};

struct returnPA {
	int error;
	airportPA array[5];
}

struct KDNode{
    KDNode* right;
    KDNode* left;
    double lat;
    double lon;
};

program AIRPORT_PROG{
    version AIRPORT_VERS{
        airportList callAirport(airport) = 1;
    }=1;
}=0x3232077B;
