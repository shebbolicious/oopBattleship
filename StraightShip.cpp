// StraightShip.cpp
#include "StraightShip.h"
#include "grid.h"
#include "ship.h"

int StraightShip::getX() const {
    return x;
}

int StraightShip::getY() const {
    return y;
}

bool StraightShip::isVertical() const {
    return vertical;
}

int StraightShip::getLength() const {
    return length;
}

StraightShip::StraightShip() : Ship(0), x(0), y(0) {
}

StraightShip::StraightShip(int x, int y, int length, bool vertical) : Ship(length) {
    // Initialize properties using the provided values
    this->x = x;
    this->y = y;
    this->length = length;
    this->vertical = vertical;
    // Additional initialization if needed
}