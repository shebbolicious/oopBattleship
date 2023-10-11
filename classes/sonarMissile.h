#ifndef sMISSLE_H
#define sMISSLE_H
#include "missile.h"
#include "grid.h"

class sonarMissile : public missile {  
    private:
    int areaScan;

    public:
    int get_areaScan() { return areaScan; }
    int set_areaScan( int new_areaScan ) { areaScan = new_areaScan; return areaScan;}

    //function to reveal the location of ships in certain area
    void revealShips();
};

#endif
