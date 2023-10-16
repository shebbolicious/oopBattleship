#include "missile.h"
#include "ColumnMissile.h"
#include "grid.h"


rowMissile :: rowMissile(Grid& grid, int x, int y) : grid(grid),x(x), y(y){

    this-> x=x;

    this->y =y;


}