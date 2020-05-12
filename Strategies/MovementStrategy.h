
#pragma once

class MovementStrategy
{

public:
int speed;
virtual void set_speed(double speed)= 0;
virtual int get_speed()= 0;


};
