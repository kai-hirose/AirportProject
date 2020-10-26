const MAXLEN = 256;
typedef string name<MAXLEN>;
typedef string code<MAXLEN>;
typedef string state<MAXLEN>;

struct airport{
    code code;
    name name;
    state state;
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

program PLACES_AIRPORT_PROG{
    version PLACES_AIRPORT_VERS{
        list_ret CALL_AIRPORTS(coordinate) = 1;
    } = 1;
} = 0x66454320; 