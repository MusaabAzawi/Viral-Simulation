#include "MovementStrategy.h"

namespace Strategies
{
// Add virtual keyword to avoid unnecessary obj instantiation
class RegularMovement : virtual public MovementStrategy{

    public:
    RegularMovement();
    double set_speed();
   
    
};
}