struct airportPA{
    string code<5>;
    string name<256>;
    double lat;
    double lon;
    double distance;
};

struct returnPA{
	int error;
	airportPA array[5];
};

struct coordinate{
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
        returnPA callAirport(coordinate) = 1;
    }=1;
}=0x3232077B;