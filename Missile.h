// Missile.h
#pragma once
#include <string>
#include "grid.h"

class Missile {
public:
    Missile(Grid& grid, int x, int y);

    bool isvalidShot(int x, int y);
    //setters and getters

    void setX(int xcoords);
    void setY(int ycoords);

    int getX();
    int getY();
    
private:
    std::string name;

    Grid& grid;

    int x;
    int y;
};