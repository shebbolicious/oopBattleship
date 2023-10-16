// StraightShip.cpp
#include "StraightShip.h"
#include "grid.h"

int StraightShip::getX() const {
    return x;
}

int StraightShip::getY() const {
    return y;
}

bool StraightShip::isVertical() const {
    return vertical;
}

StraightShip::StraightShip() : Ship(0), x(0), y(0), length(0), vertical(false) {
    // Initialize properties here
}

StraightShip::StraightShip(int x, int y, int length, bool vertical) : Ship(length) {
    // Initialize properties using the provided values
    this->x = x;
    this->y = y;
    this->length = length;
    this->vertical = vertical;
    // Additional initialization if needed
}

bool StraightShip::isHit(int x, int y) const {
    // Check if the hit coordinates match the ship's position
    if (vertical) {
        if (x == this->x && y >= this->y && y < this->y + length) {
            return true;
        }
    } else {
        if (y == this->y && x >= this->x && x < this->x + length) {
            return true;
        }
    }
    return false;
}