#ifndef LSHAPED_SHIP_H
#define LSHAPED_SHIP_H

#include "Ship.h"

class LShapedShip : public Ship {
public:
    LShapedShip();
    LShapedShip(int x, int y, int length, bool vertical);
    int getX() const;
    int getY() const;
    bool isVertical() const;

private:
    int x;        // x-coordinate of the ship's starting position
    int y;        // y-coordinate of the ship's starting position
    int length;   // length of the ship
    bool vertical; // true if the ship is oriented vertically, false if horizontal
};

#endif // L_SHAPED_SHIP_H