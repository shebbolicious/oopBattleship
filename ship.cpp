// Ship.cpp
#include "Ship.h"

Ship::Ship(int length) : length(length), hits(0) {
    // Initialize ship properties
}

int Ship::getLength() const {
    return length;
}