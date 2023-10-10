// Grid.h
#pragma once
#include <vector>

class Ship;

class Grid {
public:
    Grid();
    void display();
    bool placeShip(int x, int y, int length, bool vertical);
    bool checkHit(int x, int y);
    bool isGameOver();
private:
    static const int GRID_SIZE = 10;
    std::vector<std::vector<char>> grid;
    std::vector<Ship> ships;

    bool isValidPlacement(int x, int y, int length, bool vertical);
};
