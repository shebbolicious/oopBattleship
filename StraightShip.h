#ifndef STRAIGHTSHIP_H
#define STRAIGHTSHIP_H
#include "Ship.h"

// Inherits from Ship Class
class StraightShip : public Ship {
public:
    StraightShip(); // Default constructor
    StraightShip(int x, int y, int length, bool vertical); // Constructor
    int getX() const; // Getter for x
    int getY() const; // Getter for y
    bool isVertical() const; // Vertical or horizontal
    int getLength() const override; // Getter for length

protected:
    int x;        // x coordinate of the ship's starting position
    int y;        // y coordinate of the ship's starting position
};
#endif // STRAIGHTSHIP_H