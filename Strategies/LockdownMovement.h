#include "MovementStrategy.h"

namespace Strategies
{
    // Add virtual keyword to avoid unnecessary obj instantiation
class  LockdownMovement : virtual public MovementStrategy{

    public:
    LockdownMovement();
    double set_speed();
    
    

};
}