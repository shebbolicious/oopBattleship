#ifndef SHIP_H
#define SHIP_H

class Ship {
public:
    Ship(int length);
    virtual ~Ship() = default; // Make the base class abstract
    virtual int getLength() const;
protected:
    int length;
    int hits;
    bool vertical;
};

#endif // SHIP_H
