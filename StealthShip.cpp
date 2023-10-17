// StealthShip.cpp
#include "StealthShip.h"

StealthShip::StealthShip() : StraightShip(), firstHit(false) {
}

StealthShip::StealthShip(int x, int y, int length, bool vertical) : StraightShip(x, y, length, vertical), firstHit(false) {
}
