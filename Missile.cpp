// Missile.cpp
#include "Missile.h"
#include <string>
#include "ship.h"
#include "grid.h"

Missile::Missile(Grid& grid, int x, int y) : grid(grid),x(x), y(y) {

    std::string name;

    this-> x = x;

    this-> y =y;

    // Initialize missile properties
}


bool Missile ::isvalidShot(int x, int y){  

    if((x>=0 && x< 10) && (y>=0 && y<10)&&grid.Getcell(x,y)==' '){

        return true;
    }else{

        return false;
    }




}



void Missile :: setY(int ycoords){

   y =  ycoords;


}



void Missile :: setX(int xcoords){

    x = xcoords ;

}

int Missile::getX() {
    return x;
}

int Missile::getY() {
    return y;
}