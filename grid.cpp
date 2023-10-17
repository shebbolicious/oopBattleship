#include "StraightShip.h"
#include "Grid.h"
#include "Ship.h"
#include <iostream>
#include "LShapedShip.h"
#include "StealthShip.h"

Grid::Grid() {
    grid.resize(GRID_SIZE, std::vector<char>(GRID_SIZE, ' ')); // Initialize the grid with empty spaces
}

char Grid :: Getcell(int x, int y)const {

    if(x>=0&&x<10 && y>=0 &&y<10){

        return grid[x][y];
    }

    return 0;

}

void Grid ::Setcell(int x, int y, char poop){

      if(x>=0&&x<10 && y>=0 &&y<10){

         grid[x][y]= poop;
    }



}



void Grid::display() {
    // Display the grid with labels
    std::cout << "  ";
    for (char xLabel = 'A'; xLabel < 'A' + GRID_SIZE; ++xLabel) {
        std::cout << xLabel << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < GRID_SIZE; ++i) {
        std::cout << i << " "; // Change this for number (i + 1 = 0****)
        for (int j = 0; j < GRID_SIZE; ++j) {
            std::cout << grid[i][j] << " ";
        }
        std::cout << "\n";
    }
}

bool Grid::placeShip(const StraightShip& ship) {
    int x = ship.getX();
    int y = ship.getY();
    int length = ship.getLength();
    bool vertical = ship.isVertical(); // Use the getter method

    if (isValidPlacement(x, y, length, vertical)) {
        // Place the ship on the grid
        char shipSymbol = (vertical) ? '|' : '-';
        for (int i = 0; i < length; ++i) {
            if (vertical) {
                grid[x + i][y] = shipSymbol;
            } else {
                grid[x][y + i] = shipSymbol;
            }
        }

        // Add the ship to the list
        ships.push_back(ship);
        return true;
    }
    return false;
}

bool Grid::placeLShip(const LShapedShip& ship) {
    int x = ship.getX();
    int y = ship.getY();
    bool vertical = ship.isVertical(); // Use the getter method

    if (isValidPlacement(x, y, 3, vertical) && isValidPlacement(x + 2, y + 1, 1, vertical)) {
        // Place the ship on the grid
        char shipSymbol = (vertical) ? '|' : '-';
        
        if (vertical) {
            for (int i = 0; i < 3; ++i) {
                grid[x + i][y] = shipSymbol;
            }
            grid[x + 2][y + 1] = shipSymbol;
        } else {
            for (int j = 0; j < 3; ++j) {
                grid[x][y + j] = shipSymbol;
            }
            grid[x + 1][y + 2] = shipSymbol;
        }

        // Add the ship to the list
        ships.push_back(ship);
        return true;
    }
    return false;
}

bool Grid::placeStealthShip(const StealthShip& ship) {
    int x = ship.getX();
    int y = ship.getY();
    int length = ship.getLength();
    bool vertical = ship.isVertical(); // Use the getter method

    if (isValidPlacement(x, y, length, vertical)) {
        // Place the ship on the grid
        char shipSymbol = (vertical) ? 'S' : 'S';
        for (int i = 0; i < length; ++i) {
            if (vertical) {
                grid[x + i][y] = shipSymbol;
            } else {
                grid[x][y + i] = shipSymbol;
            }
        }

        // Add the ship to the list
        ships.push_back(ship);
        return true;
    }
    return false;
}

bool Grid::isValidPlacement(int x, int y, int length, bool vertical) {
    if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
        return false; // Invalid starting coordinates
    }

    if (vertical) {
        if (x + length > GRID_SIZE) {
            return false; // Ship goes out of bounds
        }

        for (int i = x; i < x + length; ++i) {
            if (grid[i][y] != ' ') {
                return false; // Collision with another ship
            }
        }
    } else {
        if (y + length > GRID_SIZE) {
            return false; // Ship goes out of bounds
        }

        for (int j = y; j < y + length; ++j) {
            if (grid[x][j] != ' ') {
                return false; // Collision with another ship
            }
        }
    }

    return true;
}