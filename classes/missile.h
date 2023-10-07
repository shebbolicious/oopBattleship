#ifndef MISSLE_H
#define MISSLE_H

#include "grid.h"

//#include "grid.h"

class missle {  
    private:
        int x , y; // to place the missles

    public:
        //getters
        int get_x() { return x; }
        int get_y() { return y; }

        //setters
        int set_x( int newX ) { x = newX; }
        int set_Y( int newY ) { y = newY; }
    
        //memeber functions

        bool isFired(); //determines if has been fired. should be useful in while loops or something    

        bool isHit(); //determines if the missile hit ship or not



};

#endif
