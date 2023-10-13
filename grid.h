// Grid.h
#pragma once
#include <vector>
#include "StraightShip.h"

class Ship;

class Grid {
public:
    Grid();
    void display();
    bool placeShip(const StraightShip& ship);
    bool checkHit(int x, int y);
    bool isGameOver();
    bool isValidPlacement(int x, int y, int length, bool vertical);
private:
    static const int GRID_SIZE = 10;
    std::vector<std::vector<char>> grid;
    std::vector<Ship> ships;
};
