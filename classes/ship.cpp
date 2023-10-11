#include "ship.h"

#include <iostream>
#include <string>

ship ::ship() {
  name = "";

  length = 0;

  width = 0;

  xcoords = 0;

  ycoords = 0;

  numHits = 0;
}

ship ::ship(std::string name, int lengths, int widths, int xcoords,
            int ycoords) {
  this->name = name;

  length = lengths;

   width = widths;

  this->xcoords = xcoords;

  this->ycoords = ycoords;

  numHits = 0;
}

int ship ::numberOfhits() { return numHits; }

void ship::placeShip(grid &shipGrid) {
  // check if the ships out of bounds

  int LengthGrid = shipGrid.get_length();

  int WidthGrid = shipGrid.get_width();

  

  bool isValid =((width + xcoords) <= WidthGrid && (length + ycoords) <= LengthGrid);

  if (isValid) {
    for (int i = ycoords; i < ycoords + length; i++) {
      for (int j = xcoords; j < xcoords + width; j++) {
        if (shipGrid.playerOneGrid()[i][j]!=0) {
          isValid = false;

          break;
        }
      }

      if (!isValid) {
        break;
      }
    }

    if (isValid) {
      for (int i = ycoords; i < ycoords + length; i++) {
        for (int j = xcoords; j < xcoords + length; j++) {
          shipGrid.playerOneGrid()[i][j] = 1;
        }
      }

    } else {
    std::cout << "invalid ship place!" << std::endl;
    }
  }
}

//getters adn setter

 int ship:: get_length(){

    return length;



 };

   int ship:: get_width(){

    return width;




   };

  int ship :: get_ycoords(){


    return ycoords;
  };

   int ship:: get_xcoords(){


    return xcoords;
   };

   void ship:: set_NumHits(int hitnum){

    numHits= hitnum;



   };

   void ship ::set_length(int lengths){


    length=lengths;



   };

   void ship:: set_width(int widths ){

    width=widths;



   };

   void ship :: set_ycoords(int y){


    ycoords=y;
   };

   void ship::set_xcoords(int x){

    xcoords=x;
   };
