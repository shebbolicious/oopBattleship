#ifndef STRAIGHTSHIP_H
#define STRAIGHTSHIP_H
#include "Ship.h"

class StraightShip : public Ship {
public:
    StraightShip();
    StraightShip(int x, int y, int length, bool vertical);
    int getX() const;
    int getY() const;
    bool isVertical() const;
    int getLength() const override;

protected:
    int x;        // x-coordinate of the ship's starting position
    int y;        // y-coordinate of the ship's starting position
};
#endif // STRAIGHTSHIP_H