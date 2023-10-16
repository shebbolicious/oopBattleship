// Grid.h
#pragma once
#include <vector>
#include "StraightShip.h"
#include "LShapedShip.h"
#include "StealthShip.h"

class Ship;

class Grid {
public:
    Grid();
    void display();
    bool placeShip(const StraightShip& ship);
    bool placeLShip(const LShapedShip& ship);
    bool placeStealthShip(const StealthShip& ship);
    bool checkHit(int x, int y);
    bool isGameOver();
    bool isValidPlacement(int x, int y, int length, bool vertical);

    void Setcell(int x, int y, char poop);

    char Getcell(int x, int y)const;
private:
    static const int GRID_SIZE = 10;
    std::vector<std::vector<char>> grid;
    std::vector<Ship> ships;
};