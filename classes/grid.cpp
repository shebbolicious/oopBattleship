#include "grid.h"

#include <iostream>
#include <vector>
using namespace std;

grid ::grid(int l, int w) {
  // grid sets the l and w inputted into variables lenth and width
  length = l;

  width = w;
}

// initialises a grid for player one
std::vector<std::vector<int>> grid ::playerOneGrid() {
  // initialise zeros based on length and width

  std::vector<std::vector<int>> playerOne(length, std::vector<int>(width, 0));

  return playerOne;
}

// inititialises a grid for player two
std::vector<std::vector<int>> grid ::playerTwoGrid() {
  std::vector<std::vector<int>> playerTwo(length, std::vector<int>(width, 0));

  return playerTwo;
}

// resets a grid for

void grid ::resetGrid(std::vector<std::vector<int>> &playerOne,std::vector<std::vector<int>>&playerTwo){

  for (int i = 0; i < length; i++) {
    for (int x = 0; x < width; x++) {
      playerOne[i][x] = 0;

      playerTwo[i][x] = 0;
    }
  }
}

// setters and getters

int grid::get_length() { return length; }

void grid ::set_length(int l) { length = l; }

void grid ::set_width(int w) { width = w; }

int grid ::get_width() { return width; }
