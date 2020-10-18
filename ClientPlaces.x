struct airport{
  int code;
  char* name;
  double lat;
  double long;
  double distance;
}

struct airportList{
  int error;
  airport array[5];
}

struct KDNode{
  *KDNode right;
  *KDNode left;
  double lat;
  double long;
}

struct TrieNode{
  *TrieNode;
  int index;
  double lat;
  double long;
}

program AIRPORT_PROG{
  version AIRPORT_VERS{
    airportList callPlaces(char*) = 1;
  }=1;
}=0x32320776;
