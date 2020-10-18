struct airportList{
    int error;
    airport array[5];
};

program AIRPORT_PROG{
    version AIRPORT_VERS{
        airportList callAirport(double,double) = 1;
    }=1;
}=0x32320776;