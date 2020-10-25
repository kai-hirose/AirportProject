const NAMETYPECPSIZE = 256;
const STATETYPECPSIZE = 2;
const CODETYPECPSIZE = 3;
typedef string nametypecp<NAMETYPECPSIZE>;
typedef string statetypecp<STATETYPECPSIZE>;
typedef string codetypecp<CODETYPECPSIZE>;
typedef struct airportNodeCP* airportListCP;
typedef struct tNode* tNodePtr;

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

struct coordinateCP{
    double lat;
    double lon;
};

struct tNode{
	tNodePtr array;
	int index;
	double lat;
	double lon;
};

program CLIENT_PLACES_PROG{
    version CLIENT_PLACES_VERS{
        returnCP CALLPLACES(nametypecp) = 1;
    } = 1;
} = 0x61320779;