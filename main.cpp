#include "Grid.h"
#include "StraightShip.h"
#include "LShapedShip.h"
#include "Missile.h"
#include <iostream>

int main() {
    // Initialize game objects
    Grid player1Grid;
    Grid player2Grid;

    StraightShip player1StraightShip;
    StraightShip player2StraightShip;

    LShapedShip player1LShapedShip;
    LShapedShip player2LShapedShip;

    // Place Player 1's ships
    std::cout << "Player 1, place your ships:\n";
    player1Grid.placeShip(2, 3, player1StraightShip.getLength(), true);
    player1Grid.placeShip(7, 5, player1LShapedShip.getLength(), false);

    // Place Player 2's ships
    std::cout << "Player 2, place your ships:\n";
    player2Grid.placeShip(4, 6, player2StraightShip.getLength(), true);
    player2Grid.placeShip(1, 2, player2LShapedShip.getLength(), false);

    while (!player1Grid.isGameOver() && !player2Grid.isGameOver()) {
        // Player 1's turn
        int player1X, player1Y;
        std::cout << "Player 1's turn! Enter coordinates (x, y): ";
        std::cin >> player1X >> player1Y;

        if (player2Grid.checkHit(player1X, player1Y)) {
            std::cout << "Player 1 hit Player 2's ship!\n";
        } else {
            std::cout << "Player 1 missed!\n";
        }

        // Display grids
        std::cout << "Player 1's Grid:\n";
        player1Grid.display();
        std::cout << "Player 2's Grid:\n";
        player2Grid.display();

        // Check if Player 1 has won
        if (player2Grid.isGameOver()) {
            std::cout << "Player 1 wins!\n";
            break;
        }

        // Player 2's turn
        int player2X, player2Y;
        std::cout << "Player 2's turn! Enter coordinates (x, y): ";
        std::cin >> player2X >> player2Y;

        if (player1Grid.checkHit(player2X, player2Y)) {
            std::cout << "Player 2 hit Player 1's ship!\n";
        } else {
            std::cout << "Player 2 missed!\n";
        }

        // Display grids
        std::cout << "Player 1's Grid:\n";
        player1Grid.display();
        std::cout << "Player 2's Grid:\n";
        player2Grid.display();

        // Check if Player 2 has won
        if (player1Grid.isGameOver()) {
            std::cout << "Player 2 wins!\n";
            break;
        }
    }

    return 0;
}
