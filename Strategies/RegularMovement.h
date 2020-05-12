#include "MovementStrategy.h"

// Add virtual keyword to avoid unnecessary obj instantiation
class RegularMovement : virtual public MovementStrategy{

    public:
    RegularMovement();
    void set_speed(double speed);
    int get_speed();
    
};