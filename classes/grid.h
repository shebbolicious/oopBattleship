
#ifndef GRID_h
#define GRID_h

class grid {

    private:
//initialise weight and length of grid
    int length;

    int width;

   public:

    grid();

    grid(int l, int w); // 
 

    int playerOneGrid();// function used if there are single player game mode so only one gird is created

    int playerTwoGrid();

   
    void resetGrid();

//getters and setters

  int get_length();

  void set_length(int l);

  int get_width();

  int set_width(int w);




};
#endif

