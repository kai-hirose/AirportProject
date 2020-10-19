struct airportList{
    int error;
    airport array[5];
};

struct airport{
    int code;
    char* name;
    double lat;
    double lon;
    double distance;
};

program AIRPORT_PROG{
    version AIRPORT_VERS{
        airportList callAirport(airport) = 1;
    }=1;
}=0x32320776;
