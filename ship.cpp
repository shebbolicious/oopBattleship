// Ship.cpp
#include "Ship.h"

Ship::Ship(int length) : length(length), hits(0) {
}

int Ship::getLength() const {
    return length;
}