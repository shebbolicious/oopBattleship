// Ship.h
#pragma once

class Ship {
public:
    Ship(int length);
    virtual ~Ship() = default; // Make the base class abstract
    virtual int getLength() const;
    virtual bool isHit(int x, int y) const;
    virtual bool isSunk() const;
protected:
    int length;
    int hits;
};