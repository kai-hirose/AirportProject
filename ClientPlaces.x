struct place{
	char* name;
	char state[2];
	double lat;
	double lon;
};

struct airport{
    int code;
    char* name;
    double lat;
    double lon;
    double distance;
};

struct airportList{
    int error;
    airport array[5];
};

struct TrieNode{
    TrieNode* TN;
    int index;
    double lat;
    double lon;
};

struct coordinate {
	double lat;
	double lon;
};

program PLACES_PROG{
    version PLACES_VERS{
        airportList callPlaces(char*) = 1;
    }=1;
}=0x3232077A;
