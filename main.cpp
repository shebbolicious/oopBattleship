#include <iostream>
#include <limits>
#include <string>
#include "Grid.h"
#include "LShapedShip.h"
#include "Missile.h"
#include "StraightShip.h"
#include "StealthShip.h"
#include "MainMenu.h"
#include "BattleshipTests.h"

using namespace std;

int main() {
  
  // Runs the tests set up in the BattleshipTests header file
  BattleshipTests::runAllTests();
    //std::cout << "All tests passed!" << std::endl;

  // Main Menu implementation
  MainMenu menu;
    string pog; // Declare variable for later user input
    while (true) {
        menu.showMenu(); // Calls function from Main Menu class to display menu
        
        int choice; // Declares choice variable
        cin >> choice; // Gets user input

        // Defensive code to prevent infinite loop
        if (cin.fail()) {
            cin.clear(); // Clear the fail state.
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the invalid input.
            cout << "Invalid input. Enter a valid option (1, 2, 3, or 4)." << endl;
            continue;
        } else {
            menu.runChoice(choice); // Runs if input is valid

            if (choice == 1) {
                break; // Breaks out of menu and begins the game
            } else if (choice == 4) {
                return 0; // Stops the program
            }
        }
        // A pause/break to get back to the menu screen when ready
        std::cout << "Enter anything to return to the menu screen." << std::endl;
        std::cin >> pog; // Any input will return to the menu
    }

  // Initialize game objects
  Grid player1Grid;
  Grid player2Grid;

  // Declare and initialise variables including flag variables
  bool validInput = false;
  int ship1[2];
  bool isHorizontal = true;     
  string isHorizontalInput;

  bool playerOneship = true;
  bool playerTwoship = true;

  int playerOnecount = 0;
  int playerTwocount = 0;

  std::vector<StraightShip> ships;
  std::vector<StraightShip> ships2;

  // Player 1 LShapedShip

  // Display message
  cout << "Player ones turn! \n" << endl;

    // Declare and initialise variables and flag variables
    validInput = false;
    isHorizontal = true;
    int Lship1[2];
    
    // Display message
    cout << "Is L ship vertical or horizontal (v or h): " << endl;

while (true) {
    cin >> isHorizontalInput; // Get user input for vertical or horizontal
    
    if (isHorizontalInput == "v" || isHorizontalInput == "h") {
        if (isHorizontalInput == "h") {
            isHorizontal = false; // Sets flag variable based on input
        }
        break; // Exits the loop when valid input is provided
    } else {
        // Error message and loops back through if invalid input
        cout << "Invalid input. Enter 'v' for vertical or 'h' for horizontal: " << endl;
    }
}
    // Display message
    cout << "Enter L ship coordinates (x,y): " << endl;
    while (!validInput) {
    // Gets user input for x and y coordinates
    if (cin >> Lship1[0] >> Lship1[1]) {
    // Defensive coding to stop unwanted errors
    if ((isHorizontalInput == "h" && Lship1[1] == 8) || (isHorizontalInput == "h" && Lship1[1] == 9) || (isHorizontalInput == "v" && Lship1[0] == 9)) {
        cout << "Invalid placement. The ship goes out of bounds. Enter L ship coordinates:" << endl;
        continue;
    } else if (player1Grid.isValidPlacement(Lship1[1], Lship1[0], 3, isHorizontal)) {
            validInput = true; // Sets flag variable if placement is valid
    } else {
        // Error message and loops back through if invalid input
        cout << "Invalid input. Enter L ship coordinates:" << endl;
    }
    } else {
        // Clear the error state and discard the invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter numerical coordinates:" << endl;
    }
    };

    // Creates L Ship object with user inputs
    LShapedShip player1LShip1(Lship1[1], Lship1[0], 3, isHorizontal);

    // Places L Ship on grid
    player1Grid.placeLShip(player1LShip1);

    // Displays player 1 grid
    player1Grid.display();


    // Player 1 StealthShip

    // Declare and initialise variables including flag variables
    validInput = false;
    int stealthship[2];
    isHorizontal = true;
    
    // Display message
    cout << "Is the stealth ship vertical or horizontal (v or h): " << endl;

while (true) {
    cin >> isHorizontalInput; // Gets user input for vertical or horizontal
    
    if (isHorizontalInput == "v" || isHorizontalInput == "h") {
        if (isHorizontalInput == "h") {
            isHorizontal = false; // Sets flag
        }
        break; // Exit the loop when valid input is provided
    } else {
        cout << "Invalid input. Enter 'v' for vertical or 'h' for horizontal: " << endl;
    }
}
    // Display message
    cout << "Enter stealth ships coordinates: " << endl;
    while (!validInput) {
    // Get user input for stealth ship coordinates
    if (cin >> stealthship[0] >> stealthship[1]) {
    // Defensive coding to stop unwanted errors
    if ((isHorizontalInput == "h" && stealthship[1] == 8) || (isHorizontalInput == "h" && stealthship[1] == 9) || (isHorizontalInput == "v" && stealthship[0] == 9)) {
        cout << "Invalid placement. Enter stealth ship coordinates:" << endl;
        continue;
    } else if (player1Grid.isValidPlacement(stealthship[1], stealthship[0], 3, isHorizontal)) {
            validInput = true; // Sets flag
    } else {
         cout << "Invalid input. Enter stealth ship coordinates:" << endl;
    }
    } else {
        // Clear the error state and discard the invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter number coordinates:" << endl;
    }
    };

    // Creates Stealth Ship object with user inputs
    StealthShip player1Stealth(stealthship[1], stealthship[0], 3, isHorizontal);

    // Places Stealth Ship on grid
    player1Grid.placeStealthShip(player1Stealth);

    // Displays player 1 grid
    player1Grid.display();

  // Initialise a loop that asks player 1 and two to set up ships
  while (playerOneship) {
    player1Grid.display();

    // We want to create 4 Straight Ships (from 0 to 3)
    while (playerOnecount < 4) {

      // Declare variables
      validInput = false;
      isHorizontal = true;

      // Display messages
      cout << "Place your Straight Ships:" << endl;
      cout << "Is this ship vertical or horizontal (v or h): " << endl;

      while (true) {
        cin >> isHorizontalInput; // Get user input

        if (isHorizontalInput == "v" || isHorizontalInput == "h") {
          if (isHorizontalInput == "h") {
            isHorizontal = false;
          }
          break;  // Exit the loop when valid input is provided
        } else {
          cout
              << "Invalid input. Enter 'v' for vertical or 'h' for horizontal: "
              << endl;
        }
      }
      // Display message
      cout << "Enter ship " << playerOnecount + 1 << " coordinates (x,y) "
           << endl;
      while (!validInput) {
        if (cin >> ship1[0] >> ship1[1]) { // Get user input
        if (player1Grid.isValidPlacement(ship1[1], ship1[0], 2, isHorizontal)) {
            validInput = true; // Set flag
        } else {
            cout << "Invalid placement. Enter ship coordinates:" << endl;
        }
    } else {
        // Defensive coding to stop infinite loops
        // Clear the error state and discard the invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter numerical coordinates:" << endl;
    }
}
      // Create Straight Ship object with given inputs
      StraightShip Ship(ship1[1], ship1[0], 2, isHorizontal);
      ships.push_back(Ship);

      // Place Straight Ship
      player1Grid.placeShip(ships[playerOnecount]);

      // Display Player 1 grid
      player1Grid.display();

      // Updates/resets variables
      playerOnecount = playerOnecount + 1;
      isHorizontal = true;
      validInput = false;
    };

    playerOneship = false;
  };

  // Create ships for player 2

  // Display message
  cout << "Player twos turn! \n" << endl;

     // Player 2 LShapedShip

    // Declare and initialize variables and flag variables
    validInput = false;
    isHorizontal = true;
    int Lship2[2];
    
    // Display message
    cout << "Is L ship vertical or horizontal (v or h): " << endl;

while (true) {
    cin >> isHorizontalInput; // Get user input for vertical or horizontal
    
    if (isHorizontalInput == "v" || isHorizontalInput == "h") {
        if (isHorizontalInput == "h") {
            isHorizontal = false; // Sets flag variable based on input
        }
        break; // Exits the loop when valid input is provided
    } else {
        // Error message and loops back through if invalid input
        cout << "Invalid input. Enter 'v' for vertical or 'h' for horizontal: " << endl;
    }
}
      // Display message
      cout << "Enter L ship coordinates (x,y): " << endl;
    while (!validInput) {
    // Gets user input for x and y coordinates
    if (cin >> Lship2[0] >> Lship2[1]) {
    // Defensive coding to stop unwanted errors
    if ((isHorizontalInput == "h" && Lship2[1] == 8) || (isHorizontalInput == "h" && Lship2[1] == 9) || (isHorizontalInput == "v" && Lship2[0] == 9)) {
        cout << "Invalid placement. Enter L ship coordinates:" << endl;
        continue;
    } else if (player2Grid.isValidPlacement(Lship2[1], Lship2[0], 3, isHorizontal)) {
            validInput = true;
    } else {
         // Error message and loops back through if invalid input
         cout << "Invalid input. Enter L ship coordinates:" << endl;
    }
    } else {
        // Clear the error state and discard the invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter numerical coordinates:" << endl;
    }
    };

    // Creates L Ship object with user inputs
    LShapedShip player2LShip1(Lship2[1], Lship2[0], 3, isHorizontal);

    // Places L Ship on grid
    player2Grid.placeLShip(player2LShip1);

    // Displays player 2 grid
    player2Grid.display();


    // Player 2 StealthShip

    // Declare and initialize variables including flag variables
    validInput = false;
    int stealthship2[2];
    isHorizontal = true;
    
    // Display message
    cout << "Is the stealth ship vertical or horizontal (v or h): " << endl;

while (true) {
    cin >> isHorizontalInput; // Gets user input for vertical or horizontal
    
    if (isHorizontalInput == "v" || isHorizontalInput == "h") {
        if (isHorizontalInput == "h") {
            isHorizontal = false;
        }
        break; // Exit the loop when valid input is provided
    } else {
        cout << "Invalid input. Enter 'v' for vertical or 'h' for horizontal: " << endl;
    }
}

      // Display message
      cout << "Enter stealth ships coordinates: " << endl;
    while (!validInput) {
    // Get user input for stealth ship coordinates
    if (cin >> stealthship2[0] >> stealthship2[1]) {
    // Defensive coding to stop unwanted errors
    if ((isHorizontalInput == "h" && stealthship2[1] == 8) || (isHorizontalInput == "h" && stealthship2[1] == 9) || (isHorizontalInput == "v" && stealthship2[0] == 9)) {
        cout << "Invalid placement. Enter stealth ship coordinates:" << endl;
        continue;
    } else if (player2Grid.isValidPlacement(stealthship2[1], stealthship2[0], 3, isHorizontal)) {
            validInput = true;
    } else {
         cout << "Invalid input. Enter stealth ship coordinates:" << endl;
    }
    } else {
        // Clear the error state and discard the invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter numerical coordinates:" << endl;
    }
    };

    // Creates Stealth Ship object with user inputs
    StealthShip player2Stealth(stealthship2[1], stealthship2[0], 3, isHorizontal);

    // Places Stealth Ship on grid
    player2Grid.placeStealthShip(player2Stealth);

    // Displays player 2 grid
    player2Grid.display();

    // Create the regular 2 long straight ships for Player 2

    while (playerTwoship) {
    player2Grid.display();

    while (playerTwocount < 4) {
      // char

      validInput = false;
      isHorizontal = true;

      cout << "\nIs this ship vertical or horizontal (v or h): " << endl;

      while (true) {
        cin >> isHorizontalInput;

        if (isHorizontalInput == "v" || isHorizontalInput == "h") {
          if (isHorizontalInput == "h") {
            isHorizontal = false;
          }
          break;  // Exit the loop when valid input is provided
        } else {
          cout
              << "Invalid input. Enter 'v' for vertical or 'h' for horizontal: "
              << endl;
        }
      }

      int ship2[2];

      cout << "Enter ship " << playerTwocount + 1 << " coordinates (x,y) "
           << endl;
      while (!validInput) {
        if (cin >> ship2[0] >> ship2[1]) {
        if (player2Grid.isValidPlacement(ship2[1], ship2[0], 2, isHorizontal)) {
            validInput = true;
        } else {
            cout << "Invalid placement. Enter ship coordinates:" << endl;
        }
    } else {
        // Clear the error state and discard the invalid input
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Enter numerical coordinates:" << endl;
    }
}

      // Create Straight Ship object with given inputs
      StraightShip Ship2(ship2[1], ship2[0], 2, isHorizontal);
      ships2.push_back(Ship2);

      // Place Straight Ship on grid
      player2Grid.placeShip(ships2[playerTwocount]);

      // Display Player 2 grid
      player2Grid.display();

      playerTwocount = playerTwocount + 1;
      isHorizontal = true;
      validInput = false;
    };

    playerTwoship = false;
  };





  int shipcount1= 0;

  int shipcount2 = 0;

  bool gameOver = false;

  Grid playerOneShadow;

  Grid playerTwoShadow;

  bool playerOneTurn=true;

  bool playerTwoTurn = true;

  while (!gameOver){

    while (playerOneTurn){

        playerOneShadow.display();

        if(shipcount1 == 8){

            std::cout<<"Player one wins !"<<endl;

            gameOver= true;

            break;

        }

        int Missle1x,Missle1y;

        cout<< "Enter Missile coordinates (x,y)";

        cin>> Missle1x>>Missle1y;

        Missile missile(playerOneShadow,Missle1x,Missle1y);

        while (!missile.isvalidShot(Missle1x,Missle1y)){

            std::cout<<"invalid input, please reenter coordinates"<<endl;

            cin>> Missle1x>> Missle1y;

        }

        if(player1Grid.Getcell(Missle1x,Missle1y)=='|' || player1Grid.Getcell(Missle1x,Missle1y)=='-' ){

            playerOneShadow.Setcell(Missle1x,Missle1y,'O');

            shipcount1=shipcount1+1;

        } else if (player1Grid.Getcell(Missle1x,Missle1y)=='S') {
            playerOneShadow.Setcell(Missle1x,Missle1y,'X');
            shipcount1=shipcount1+1;

        } else {

            playerOneShadow.Setcell(Missle1x,Missle1y,'X');
;


        }






        }
  }

}






        





    
    
    





    











  



  

  //while (!player1Grid.isGameOver() && !player2Grid.isGameOver()) {
    // Player 1's turn
   // int player1X, player1Y;
    //std::cout << "Player 1's turn! Enter coordinates (x, y): ";
   // std::cin >> player1X >> player1Y;

   // if (player2Grid.checkHit(player1X, player1Y)) {
      //std::cout << "Player 1 hit Player 2's ship!\n";
   // } else {
     // std::cout << "Player 1 missed!\n";
   // }

    // Display grids
   // std::cout << "Player 1's Grid:\n";
   // player1Grid.display();
   // std::cout << "Player 2's Grid:\n";
   // player2Grid.display();

    // Check if Player 1 has won
    //if (player2Grid.isGameOver()) {
     // std::cout << "Player 1 wins!\n";
     // break;
    //}

    // Player 2's turn
    //int player2X, player2Y;
    //std::cout << "Player 2's turn! Enter coordinates (x, y): ";
   // std::cin >> player2X >> player2Y;

    //if (player1Grid.checkHit(player2X, player2Y)) {
   //   std::cout << "Player 2 hit Player 1's ship!\n";
   // } else {
    //  std::cout << "Player 2 missed!\n";
    //}

    // Display grids
    //std::cout << "Player 1's Grid:\n";
   // player1Grid.display();
   // std::cout << "Player 2's Grid:\n";
  //  player2Grid.display();

    // Check if Player 2 has won
   // if (player1Grid.isGameOver()) {
   //   std::cout << "Player 2 wins!\n";
   //   break;
  //  }
 // }

 // return 0;
