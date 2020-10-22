struct airportPA{
    int code;
    char* name;
    double lat;
    double lon;
    double distance;
};

struct returnPA{
	int error;
	airportPA array[5];
};

struct coordinatePA{
    double lat;
    double lon;
};

typedef struct kDNode *kDNodePtr;
struct kDNode{
    kDNodePtr right;
    kDNodePtr left;
    double lat;
    double lon;
};

program AIRPORT_PROG{
    version AIRPORT_VERS{
        returnPA callAirport(coordinatePA) = 1;
    }=1;
}=0x3232077B;