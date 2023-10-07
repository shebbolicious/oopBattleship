#ifndef SHIP_H

#define SHIP_H

#include<iostream>

#include<string>

class ship {

    private:

    std::string name;

    int length;

    int width;



    public:

    int numberOfhits();

    virtual void placeShip();


};






#endif
