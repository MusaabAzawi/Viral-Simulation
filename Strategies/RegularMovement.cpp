#include "MovementStrategy.h"
#include "RegularMovement.h"

// Set this speed when class object is created
RegularMovement::RegularMovement(){
    this->set_speed(1000/100);
}

void RegularMovement::set_speed(double speed){
    this->speed = speed;
}

int  RegularMovement::get_speed(){
    return this->speed;
}
