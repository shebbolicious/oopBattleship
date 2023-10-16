#include "missile.h"
#include "rowMissile.h"
#include "grid.h"


rowMissile :: rowMissile(Grid& grid, int x, int y) : grid(grid),x(x), y(y){

    this-> x=x;

    this->y =y;


}