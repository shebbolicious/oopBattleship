// StraightShip.h
#pragma once
#include "Ship.h"

class StraightShip : public Ship {
public:
    StraightShip();
    StraightShip(int x, int y, int length, bool vertical);
    bool isHit(int x, int y) const override;
    int getX() const;
    int getY() const;
    bool isVertical() const;

protected:
    int x;        // x-coordinate of the ship's starting position
    int y;        // y-coordinate of the ship's starting position
    int length;   // length of the ship
    bool vertical; // true if the ship is oriented vertically, false if horizontal
};
