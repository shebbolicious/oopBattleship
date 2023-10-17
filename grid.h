#ifndef GRID_H
#define GRID_H

#include <vector>
#include "StraightShip.h"
#include "LShapedShip.h"
#include "StealthShip.h"

class Ship;

class Grid {
public:
    Grid(); // Constructor
    void display(); // Displays grid
    bool placeShip(const StraightShip& ship); // Places Straight ship on grid
    bool placeLShip(const LShapedShip& ship); // Places LShaped ship on grid
    bool placeStealthShip(const StealthShip& ship); // Places Stealth ship on grid
    bool isValidPlacement(int x, int y, int length, bool vertical); // Checks for valid placement
    void Setcell(int x, int y, char poop); // Sets cell value
    char Getcell(int x, int y)const; // Getter for cell value
private:
    static const int GRID_SIZE = 10; // Grid size of 10 (10x10)
    std::vector<std::vector<char>> grid; // Creates grid vector
    std::vector<Ship> ships; // Creates ships vector
};

#endif // GRID_H