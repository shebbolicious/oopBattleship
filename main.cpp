#include <iostream>
#include <limits>
#include <string>

#include "Grid.h"
#include "LShapedShip.h"
#include "Missile.h"
#include "StraightShip.h"
#include "StealthShip.h"
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

  bool playerTwoship = true;
  int playerOnecount = 0;

  int playerTwocount = 0;

  std::vector<StraightShip> ships;

  std::vector<StraightShip> ships2;

  // initialise a loop that asks player 1 and two to set up ships

  while (playerOneship) {
    cout << "player ones turn! \n" << endl;
    player1Grid.display();

    while (playerOnecount < 4) {
      // char

      cout << "\n Is this ship vertical or horizontal (v or h): " << endl;

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

      cout << "Enter ship " << playerOnecount + 1 << " coordinates (y,x) "
           << endl;
      while (!validInput) {
        cin >> ship1[0] >> ship1[1];
        if (player1Grid.isValidPlacement(ship1[0], ship1[1], 2, isHorizontal) ==
            false) {
          cout << "Ship is out of bounds or overlaps. Please reenter ship  "
                  "coordinates:"
               << endl;
        } else if (player1Grid.isValidPlacement(ship1[0], ship1[1], 2,
                                                isHorizontal) == true) {
          validInput = true;
          break;
        }
      };

      StraightShip Ship(ship1[0], ship1[1], 2, isHorizontal);
      ships.push_back(Ship);

      player1Grid.placeShip(ships[playerOnecount]);

      player1Grid.display();

      playerOnecount = playerOnecount + 1;
      isHorizontal = true;
      validInput = false;
    };

    playerOneship = false;
  };


  // Player 1 LShapedShip

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

    player1Grid.display();


    // Player 1 StealthShip

    validInput = false;
    int stealthship[2];
    isHorizontal = true;
    
    cout << "Is the stealth ship vertical or horizontal (v or h): " << endl;

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

    cout << "Enter stealth ships coordinates: " << endl;
    while (!validInput) {
    cin >> ship1[0] >> ship1[1];
    if (player1Grid.isValidPlacement(ship1[1], ship1[0], 3, isHorizontal) == false) {
        cout << "Invalid input. Enter ship 1 coordinates:" << endl;
    } else if (player1Grid.isValidPlacement(ship1[1], ship1[0], 3, isHorizontal) == true) {
            validInput = true;
            break;
        }
    };

    StealthShip player1Stealth(ship1[1], ship1[0], 3, isHorizontal);

    player1Grid.placeStealthShip(player1Stealth);

    player1Grid.display();



  // Create ships for player 2

    while (playerTwoship) {
    player2Grid.display();

    cout << "player twos turn! \n" << endl;

    while (playerTwocount < 4) {
      // char

      cout << "/n Is this ship  vertical or horizontal (v or h): " << endl;

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

      cout << "Enter ship " << playerTwocount + 1 << " coordinates (y,x) "
           << endl;
      while (!validInput) {
        cin >> ship1[0] >> ship1[1];
        if (player2Grid.isValidPlacement(ship1[0], ship1[1], 2, isHorizontal) ==
            false) {
          cout << "Ship is out of bounds or overlaps. please reenter ships "
                  "coordinates:"
               << endl;
        } else if (player2Grid.isValidPlacement(ship1[0], ship1[1], 2,
                                                isHorizontal) == true) {
          validInput = true;
          break;
        }
      };

      StraightShip Ship(ship1[0], ship1[1], 2, isHorizontal);
      ships2.push_back(Ship);

      player2Grid.placeShip(ships2[playerOnecount]);

      player2Grid.display();

      playerTwocount = playerTwocount + 1;
      isHorizontal = true;
      validInput = false;
    };

    playerTwoship = false;
  };

   // Player 2 LShapedShip

    validInput = false;
    isHorizontal = true;
    int Lship2[2];
    
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
    cin >> Lship2[0] >> Lship2[1];
    if (player2Grid.isValidPlacement(Lship2[1], Lship2[0], 3, isHorizontal) == false) {
        cout << "Invalid input. Enter ship 1 coordinates:" << endl;
    } else if (player2Grid.isValidPlacement(Lship2[1], Lship2[0], 3, isHorizontal) == true) {
            validInput = true;
            break;
        }
    };

    LShapedShip player2LShip1(Lship2[1], Lship2[0], 3, isHorizontal);

    player2Grid.placeLShip(player2LShip1);

    player2Grid.display();


    // Player 2 StealthShip

    validInput = false;
    int stealthship2[2];
    isHorizontal = true;
    
    cout << "Is the stealth ship vertical or horizontal (v or h): " << endl;

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

    cout << "Enter stealth ships coordinates: " << endl;
    while (!validInput) {
    cin >> stealthship2[0] >> stealthship2[1];
    if (player2Grid.isValidPlacement(stealthship2[1], stealthship2[0], 3, isHorizontal) == false) {
        cout << "Invalid input. Enter ship 1 coordinates:" << endl;
    } else if (player2Grid.isValidPlacement(stealthship2[1], stealthship2[0], 3, isHorizontal) == true) {
            validInput = true;
            break;
        }
    };

    StealthShip player2Stealth(stealthship2[1], stealthship2[0], 3, isHorizontal);

    player2Grid.placeStealthShip(player2Stealth);

    player2Grid.display();




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
