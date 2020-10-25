typedef string nametypepa<256>;
typedef string codetypepa<5>;
typedef struct airportNodePA* airportListPA;
typedef struct kDNode *kDNodePtr;

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

struct coordinate{
    double lat;
    double lon;
};

struct kDNode{
    kDNodePtr right;
    kDNodePtr left;
    airportPA airport;
};

program PLACESAIRPORT_PROG{
    version PLACESAIRPORT_VERS{
        returnPA callAirport(coordinate) = 1;
    }=1;
}=0x32320780;