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

struct KDNode{
    KDNode* right;
    KDNode* left;
    double lat;
    double lon;
};

struct TrieNode{
    TrieNode* TN;
    int index;
    double lat;
    double lon;
};

program AIRPORT_PROG{
    version AIRPORT_VERS{
        airportList callPlaces(char*) = 1;
    }=1;
}=0x32320776;
