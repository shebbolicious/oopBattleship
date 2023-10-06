
#ifndef GRID_h
#define GRID_h

class grid {

    protected:
//initialise weight and length of grid
    int length;

    int width;

   public:

    int playerOneGrid(int l, int w);

    int playertwoGrid(int l,int w);

//getters and setters

  int get_length();

  void set_length(int l);

  int get_width();

  int set_width(int w);







};
#endif

