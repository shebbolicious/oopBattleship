#include "Grid.h"
#include "StraightShip.h"
#include "LShapedShip.h"
#include "Missile.h"
#include <iostream>

using namespace std;

int main() {
    // Initialize game objects
    Grid player1Grid;
    Grid player2Grid;

    bool validInput = false;
    int ship1[2];
    bool isHorizontal = true;
    string isHorizontalInput;
    
    cout << "Is ship 1 vertical or horizontal (v or h): " << endl;

while (true) {
    cin >> isHorizontalInput;
    
    if (isHorizontalInput == "v" || isHorizontalInput == "h") {
        if (isHorizontalInput == "h") {
            isHorizontal = false;
        }
        break; // Exit the loop when valid input is provided
    } else {
        cout << "Invalid input. Enter 'v' for vertical or 'h' for horizontal: " << endl;
    }
}

    cout << "Enter ship 1 coordinates: " << endl;
    while (!validInput) {
    cin >> ship1[0] >> ship1[1];
    if (player1Grid.isValidPlacement(ship1[1], ship1[0], 2, isHorizontal) == false) {
        cout << "Invalid input. Enter ship 1 coordinates:" << endl;
    } else if (player1Grid.isValidPlacement(ship1[1], ship1[0], 2, isHorizontal) == true) {
            validInput = true;
            break;
        }
    };

    // Create ships for player 1
    StraightShip player1Ship1(ship1[1], ship1[0], 2, isHorizontal);

    player1Grid.placeShip(player1Ship1);


    validInput = false;
    isHorizontal = true;
    int Lship1[2];
    
    cout << "Is L ship vertical or horizontal (v or h): " << endl;

while (true) {
    cin >> isHorizontalInput;
    
    if (isHorizontalInput == "v" || isHorizontalInput == "h") {
        if (isHorizontalInput == "h") {
            isHorizontal = false;
        }
        break; // Exit the loop when valid input is provided
    } else {
        cout << "Invalid input. Enter 'v' for vertical or 'h' for horizontal: " << endl;
    }
}

    cout << "Enter ship 1 coordinates: " << endl;
    while (!validInput) {
    cin >> Lship1[0] >> Lship1[1];
    if (player1Grid.isValidPlacement(Lship1[1], Lship1[0], 3, isHorizontal) == false) {
        cout << "Invalid input. Enter ship 1 coordinates:" << endl;
    } else if (player1Grid.isValidPlacement(Lship1[1], Lship1[0], 3, isHorizontal) == true) {
            validInput = true;
            break;
        }
    };

    LShapedShip player1LShip1(Lship1[1], Lship1[0], 3, isHorizontal);

    player1Grid.placeLShip(player1LShip1);




    StraightShip player1Ship2(0, 8, 3, true);
    StraightShip player1Ship3(2, 2, 4, false);
    StraightShip player1Ship4(3, 3, 5, true);

    // Place player 1's ships on their grid
    
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
