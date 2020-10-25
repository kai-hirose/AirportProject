const NAMETYPEPASIZE = 256;
const CODETYPEPASIZE = 3;
typedef string nametypepa<NAMETYPEPASIZE>;
typedef string codetypepa<CODETYPEPASIZE>;
typedef struct airportNodePA* airportListPA;
typedef struct kDNode* kDNodePtr;

struct airportPA{
    codetypepa code;
    nametypepa name;
    double lat;
    double lon;
    double distance;
};

struct airportNodePA{
    airportPA airport;
    airportListPA next;
};

union returnPA switch (int err) {
	case 0:
        airportListPA list;
    default: 
        void;
};

struct coordinatePA{
    double lat;
    double lon;
};

struct kDNode{
    kDNodePtr right;
    kDNodePtr left;
    airportPA airport;
};

program PLACES_AIRPORT_PROG{
    version PLACES_AIRPORT_VERS{
        returnPA CALLAIRPORTS(coordinate) = 1;
    } = 1;
} = 0x51320780;