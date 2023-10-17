// LShapedShip.cpp
#include "LShapedShip.h"

int LShapedShip::getX() const {
    return x;
}

int LShapedShip::getY() const {
    return y;
}

bool LShapedShip::isVertical() const {
    return vertical;
}

LShapedShip::LShapedShip() : Ship(0), x(0), y(0) {
}

LShapedShip::LShapedShip(int x, int y, int length, bool vertical) : Ship(length) {
    // Initialise properties:
    this->x = x;
    this->y = y;
    this->length = length;
    this->vertical = vertical;
}