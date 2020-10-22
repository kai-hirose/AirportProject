struct place{
	char* name;
	char state[2];
	double lat;
	double lon;
};

struct airportCP{
    int code;
    char* name;
    double lat;
    double lon;
    double distance;
};

struct returnCP{
	int error;
	airportCP array[5];
};

struct coordinateCP{
    double lat;
    double lon;
};

typedef struct tNode *tNodePtr;
struct tNode{
	tNodePtr array[26];
	int index;
	double lat;
	double lon;
};

program PLACES_PROG{
	version PLACES_VERS{
		returnCP callPlaces(char*) = 1;
	}=1;
}=0x3232077A;