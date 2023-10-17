// StealthShip.h
#ifndef STEALTHSHIP_H
#define STEALTHSHIP_H

#include "StraightShip.h"

class StealthShip : public StraightShip {
private:
    mutable bool firstHit;
public:
    StealthShip();
    StealthShip(int x, int y, int length, bool vertical);
};

#endif
