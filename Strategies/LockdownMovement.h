#include "MovementStrategy.h"

class  LockdownMovement : virtual public MovementStrategy{

    public:
    LockdownMovement();
    void set_speed(double speed);
    int get_speed();
    
    

};