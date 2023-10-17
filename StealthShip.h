// StealthShip.h
#ifndef STEALTHSHIP_H
#define STEALTHSHIP_H

#include "StraightShip.h"

// Inherits from StraightShip Class
class StealthShip : public StraightShip {
private:
    mutable bool firstHit;
public:
    StealthShip(); // Default constructor
    StealthShip(int x, int y, int length, bool vertical); // Constructor
};

#endif
