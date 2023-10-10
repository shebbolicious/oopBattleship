// LShapedShip.h
#pragma once
#include "Ship.h"

class LShapedShip : public Ship {
public:
    LShapedShip();
    bool isHit(int x, int y) const override;
    void setPosition(int x, int y);
};