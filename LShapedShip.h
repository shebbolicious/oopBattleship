// LShapedShip.h
#pragma once
#include "Ship.h"

class LShapedShip : public Ship {
public:
    LShapedShip();
    LShapedShip(int x, int y, int length, bool vertical);
    bool isHit(int x, int y) const override;
    void setPosition(int x, int y);
    int getX() const;
    int getY() const;
    bool isVertical() const;

private:
    int x;        // x-coordinate of the ship's starting position
    int y;        // y-coordinate of the ship's starting position
    int length;   // length of the ship
    bool vertical; // true if the ship is oriented vertically, false if horizontal
};