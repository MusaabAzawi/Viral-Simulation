#include "MovementStrategy.h"
#include "RegularMovement.h"

namespace Strategies
{
// Set this speed when class object is created
    RegularMovement::RegularMovement(){
    }

    double RegularMovement::set_speed(){
        return 2.50;
    }

}