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

        bool playerOneship = true;

        bool playerTwoship =true;
        int playerOnecount =0;

        int playerTwocount=0;

        std::vector<StraightShip> ships;

        std::vector<StraightShip> ships2;


        //initialise a loop that asks player 1 and two to set up ships

        while(playerOneship){

            cout<<"player ones turn!"<<endl;

            while( playerOnecount<4){

               // char

                

                
    cout << "Is this ship vertical or horizontal (v or h): " << endl;

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

        cout << "Enter ship "<< playerOnecount +1<< " coordinates (y,x) ": " << endl;
        while (!validInput) {
        cin >> ship1[0] >> ship1[1];
        if (player1Grid.isValidPlacement(ship1[0], ship1[1], 2, isHorizontal) == false) {
            cout << "Ship is out of bounds or overlaps. Please reEnter ship  coordinates:" << endl;
        } else if (player1Grid.isValidPlacement(ship1[0], ship1[1], 2, isHorizontal) == true) {
                validInput = true;
                break;
        }
        };


            StraightShip Ship(ship1[0], ship1[1], 2, isHorizontal);
            ships.push_back(Ship);

        player1Grid.placeShip(ships[playerOnecount]);

        player1Grid.display();


        playerOnecount= playerOnecount+1;
        isHorizontal = true;
        validInput = false;



        };

        playerOneship=false;

        };

    // Create ships for player 2

    
        while(playerTwoship){

            cout<<"player twos turn!"<<endl;

            while( playerTwocount<4){

               // char

                



        cout << "Is this ship  vertical or horizontal (v or h): " << endl;

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

        cout << "Enter ship "<<playerTwocount+1<< " coordinates (y,x) " << endl;
        while (!validInput) {
        cin >> ship1[0] >> ship1[1];
        if (player2Grid.isValidPlacement(ship1[0], ship1[1], 2, isHorizontal) == false) {
            cout << "Ship is out of bounds or overlaps. please reenter ships coordinates:" << endl;
        } else if (player2Grid.isValidPlacement(ship1[0], ship1[1], 2, isHorizontal) == true) {
                validInput = true;
                break;
        }
        };


            StraightShip Ship(ship1[0], ship1[1], 2, isHorizontal);
            ships2.push_back(Ship);

        player2Grid.placeShip(ships2[playerOnecount]);

        player2Grid.display();


        playerTwocount= playerTwocount+1;
        isHorizontal = true;
        validInput = false;



        };

        playerTwoship=false;

        };

   


    

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
