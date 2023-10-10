#include "Grid.h"
#include "StraightShip.h"
#include "LShapedShip.h"
#include "Missile.h"
#include <iostream>

int main() {
    // Initialize game objects
    Grid player1Grid;
    Grid player2Grid;

    // Create ships for player 1
    StraightShip player1Ship1(0, 0, 2, false);
    StraightShip player1Ship2(1, 1, 3, true);
    StraightShip player1Ship3(2, 2, 4, false);
    StraightShip player1Ship4(3, 3, 5, true);

    // Place player 1's ships on their grid
    player1Grid.placeShip(player1Ship1);
    player1Grid.placeShip(player1Ship2);
    player1Grid.placeShip(player1Ship3);
    player1Grid.placeShip(player1Ship4);

    StraightShip player1StraightShip;
    StraightShip player2StraightShip;

    LShapedShip player1LShapedShip;
    LShapedShip player2LShapedShip;

    player1Grid.display();

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
