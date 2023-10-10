// Ship.cpp
#include "Ship.h"

Ship::Ship(int length) : length(length), hits(0) {
    // Initialize ship properties
}

int Ship::getLength() const {
    return length;
}

bool Ship::isHit(int x, int y) const {
    // Implement this in derived classes
    return false;
}

bool Ship::isSunk() const {
    return hits >= length;
}
