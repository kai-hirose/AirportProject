const MAXLEN = 256;
typedef string name<MAXLEN>;
typedef string code<MAXLEN>;
typedef struct kDNode* kDNodePtr;

struct airport{
    code airportcode;
    name airportname;
    double lat;
    double lon;
    double distance;
};

struct airportList{
    name placename;
    airport airport1;
    airport airport2;
    airport airport3;
    airport airport4;
    airport airport5;
};

union list_ret switch (int err) {
	case 0:
        airportList list;
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
    airport airport;
};

program PLACES_AIRPORT_PROG{
    version PLACES_AIRPORT_VERS{
        list_ret CALL_AIRPORTS(coordinate) = 1;
    } = 1;
} = 0x26459329; 