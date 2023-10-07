#include "grid.h"
#include <iostream>

int grid ::playerOneGrid (int l, int w) {
  int playerOne[l][w];

  int num = 0;

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < w; j++) {
      // if(i == 0 ){

      // playerOne[i][j]=5;

      //  playerOne[i][j+1]= num;

      //  num=num+1;

      //  }

      playerOne[i][j] = 0;

      std::cout << playerOne[i][j] << std::endl;
    }
  }

  return playerOne;
}


int grid ::playertwoGrid(int l, int w) {
  int playerTwo[l][w];

  for (int i = 0; i < l; i++) {
    for (int j = 0; j < w; j++) {
      // if(i == 0 ){

      // playerOne[i][j]=5;

      //  playerOne[i][j+1]= num;

      //  num=num+1;

      //  }

      playerTwo[i][j] = 0;

      std::cout << playerTwo[i][j] << std::endl;
    }
  }

  return playerTwo;
}



 void grid ::resetGrid() {
 playerOneGrid(11, 11);

 playertwoGrid(11, 11);
}
