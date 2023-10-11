#ifndef SHIP_H

#define SHIP_H

#include<iostream>

#include<string>

#include "grid.h"

//double grid for ech player; use switch statement for the alphabetical parts;use if statemetn to check for availabiltiy of ships in that spcae
class ship {

    private:

    std::string name;

    int length;

    int width;

    int xcoords;

    int ycoords;

    int numHits;

    bool isValid;


    public:

    ship();

    ship(std::string name,int widths, int lengths, int xcoords,int ycoords);

    int numberOfhits();

    virtual void placeShip( grid& shipGrid);

    

    //getters and setters



   int get_length();

   int get_width();

   int get_ycoords();

   int get_xcoords();

   void set_NumHits(int hitnum);

   void set_length(int lengths);

   void set_width(int widths );

   void set_ycoords(int y);

   void set_xcoords(int x);






};






#endif
