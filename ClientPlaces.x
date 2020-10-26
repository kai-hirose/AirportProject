const MAXLEN = 256;
typedef string name<MAXLEN>;
typedef string code<MAXLEN>;
typedef string state<MAXLEN>;
typedef struct tNode* tNodePtr;

struct place{
	name name;
	state state;
	double lat;
	double lon;
};

struct airport{
    code code;
    name name;
    double lat;
    double lon;
    double dist;
};

struct airportList{
    name name;
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

struct tNode{
	tNodePtr array;
	int index;
	double lat;
	double lon;
};

program CLIENT_PLACES_PROG{
    version CLIENT_PLACES_VERS{
        list_ret CALL_PLACES(name) = 1;
    } = 1;
} = 0x66454323; 