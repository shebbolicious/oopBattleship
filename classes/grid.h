
#ifndef GRID_h
#define GRID_h
#include <vector>
class grid {

    private:
//initialise weight and length of grid
    int length;

    int width;

   public:

    grid();

    grid(int l, int w); // 
 

    std::vector<std::vector<int>> playerOneGrid();// function used if there are single player game mode so only one gird is created

    std::vector<std::vector<int>> playerTwoGrid();

   
    void resetGrid(std::vector<std::vector<int>> &playerOne,std::vector<std::vector<int>>&playerTwo);

//getters and setters

  int get_length();

  void set_length(int l);

  int get_width();

  void set_width(int w);




};
#endif






