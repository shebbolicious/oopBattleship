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

LShapedShip::LShapedShip() : Ship(0), x(0), y(0), length(0), vertical(false) {
    // Initialize properties here
}

LShapedShip::LShapedShip(int x, int y, int length, bool vertical) : Ship(length) {
    // Initialize properties using the provided values
    this->x = x;
    this->y = y;
    this->length = length;
    this->vertical = vertical;
}