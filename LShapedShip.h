#ifndef LSHAPED_SHIP_H
#define LSHAPED_SHIP_H

#include "Ship.h"

// Inherits from Ship Class
class LShapedShip : public Ship {
public:
    LShapedShip(); // Default constructor
    LShapedShip(int x, int y, int length, bool vertical); // Constructor
    int getX() const; // Getter for x
    int getY() const; // Getter for y
    bool isVertical() const; // Vertical or horizontal

private:
    int x;        // x coordinate of the ship's starting position
    int y;        // y coordinate of the ship's starting position
};

#endif // L_SHAPED_SHIP_H