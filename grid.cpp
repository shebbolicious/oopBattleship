#include "StraightShip.h"
#include "Grid.h"
#include "Ship.h"
#include <iostream>
#include "LShapedShip.h"

Grid::Grid() {
    grid.resize(GRID_SIZE, std::vector<char>(GRID_SIZE, ' ')); // Initialize the grid with empty spaces
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

bool Grid::checkHit(int x, int y) {
    for (Ship& ship : ships) {
        if (ship.isHit(x, y)) {
            grid[x][y] = 'X'; // Mark the hit on the grid
            return true;
        }
    }
    grid[x][y] = 'O'; // Mark the miss on the grid
    return false;
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

bool Grid::isGameOver() {
    for (const Ship& ship : ships) {
        if (!ship.isSunk()) {
            return false; // If any ship is not sunk, the game is not over
        }
    }
    return true; // All ships are sunk; the game is over
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
