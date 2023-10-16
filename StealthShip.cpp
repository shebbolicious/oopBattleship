// StealthShip.cpp
#include "StealthShip.h"

StealthShip::StealthShip() : StraightShip(), firstHit(false) {
    // Additional initialization for StealthShip if needed
}

StealthShip::StealthShip(int x, int y, int length, bool vertical) : StraightShip(x, y, length, vertical), firstHit(false) {
    // Additional initialization for StealthShip if needed
}

bool StealthShip::isHit(int x, int y) const {
    // For the first hit, consider it as a miss
    if (!firstHit && isHitFirstTime(x, y)) {
        firstHit = true;
        return false; // First hit is a miss
    }

    // For subsequent hits, use the standard hit logic
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

bool StealthShip::isHitFirstTime(int x, int y) const {
    // Define your logic for the first hit here
    // For example, you can check if the coordinates match the ship's position
    if (vertical) {
        return x == this->x && y == this->y;
    } else {
        return y == this->y && x == this->x;
    }
}
