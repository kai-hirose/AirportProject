typedef struct TrieNode TrieNode
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

struct returnCP
{
	int error;
	airportCP array[5];
}

struct TrieNode{
	TrieNode* array[26] = {NULL};
	int index;
	double lat;
	double lon;
};

program PLACES_PROG{
	version PLACES_VERS{
		airportList callPlaces(char*) = 1;
	}=1;
}=0x3232077A;
