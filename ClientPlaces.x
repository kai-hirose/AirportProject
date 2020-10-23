struct place{
	string name<256>;
	string state<2>;
	double lat;
	double lon;
};

struct airportCP{
    string code<5>;
    string name<256>;
    double lat;
    double lon;
    double distance;
};

struct returnCP{
	int error;
	airportCP array[5];
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
		returnCP callPlaces(string) = 1;
	}=1;
}=0x3232077A;