typedef string nametypecp<256>;
typedef string statetypecp<2>;
typedef string codetypecp<3>;
typedef struct airportNodeCP* airportListCP;
typedef struct tNode *tNodePtr;

struct place{
	nametypecp name;
	statetypecp state;
	double lat;
	double lon;
};

struct airportCP{
    codetypecp code;
    nametypecp name;
    double lat;
    double lon;
    double distance;
};

struct airportNodeCP{
    airportCP airport;
    airportListCP next;
};

union returnCP switch (int err) {
	case 0:
        airportListCP list;
    default: 
        void;
};

struct tNode{
	tNodePtr array;
	int index;
	double lat;
	double lon;
};

program CLIENTPLACES_PROG{
    version CLIENTPLACES_VERS{
        returnCP callPlaces(nametypecp) = 1;
    }=1;
}=0x32320779;