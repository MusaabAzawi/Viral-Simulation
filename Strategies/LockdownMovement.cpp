#include "MovementStrategy.h"
#include "LockdownMovement.h"

LockdownMovement::LockdownMovement(){
   this->set_speed(0);
}

void LockdownMovement::set_speed(double speed){
   this->speed = speed;
}

int LockdownMovement::get_speed(){
   return this->speed;
}