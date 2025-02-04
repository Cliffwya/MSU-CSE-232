#include <iostream>

double Centrifuge(int & time, int & ore, double * u_238){
    double u_235{0};
    int max_time_cycle{time/12};
    int max_ore_cycle{ore/10};
    int max_cycle{0};

    if(max_ore_cycle<max_time_cycle){
        max_cycle = max_ore_cycle;
    } else{
        max_cycle = max_time_cycle;
    }

    time-=(max_cycle*12);
    ore-=(max_cycle*10);
    *u_238+=(max_cycle*0.993);
    u_235+=(max_cycle*0.007);

    return u_235;
}