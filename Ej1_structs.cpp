#include <iostream>
/*
 This program shows the basic of structs
 Structs are like classes with the only difference they have by default
 all its members public.
*/
struct Body{
    bool is_dynamic;
    bool is_sensor;
    
    float mass;
    float lin_vel_x;
    float lin_vel_y;
    float ang_vel_x;
    float ang_vel_y;
};

int main(int argc, char **args){
    Body objBody;
    Body bodies[10];

    for(int i=0; i<10; i++){
        objBody.mass = i;
        bodies[i] = objBody;
    }

    for(int i=0; i<10; i++){
        std::cout << bodies[i].mass << std::endl;
    }

    return 0;
}