// StraightShip.cpp
#include "StraightShip.h"

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
    // Implement hit logic for straight ships
    // Check if the hit coordinates match the ship's position
    // and update the hits count if hit
    return false; // Implement this logic
}