#include "mainmenu.h"
#include <iostream>
#include <fstream>
#include <string>

MainMenu::MainMenu() : inMainMenu(true) {}

void MainMenu::showMenu() {
    // Displays the different menu choices
    std::cout << "   Main Menu" << std::endl;
    std::cout << "1) Start Game" << std::endl;
    std::cout << "2) Game Rules" << std::endl;
    std::cout << "3) Statistics" << std::endl;
    std::cout << "4) Quit" << std::endl;
}

// Gets the user's choice
int MainMenu::getChoice() {
    int choice;
    std::cin >> choice;
    return choice;
}

// Runs based on user's choice
void MainMenu::runChoice(int choice) {
    switch (choice) {
        case 1:
            // Start Game
            std::cout << "Starting the game..." << std::endl;
            break;
        case 2:
            // Show Game Rules Page
            showRules();
            break;
        case 3:
            // Show Statistics Page
            showStats();
            break;
        case 4:
            // Quit
            std::cout << "Quitting..." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Enter respective number." << std::endl;
            break;
    }
}

// Shows the games rules section of menu
void MainMenu::showRules() {
// Retrieves data/text from external txt file
std::ifstream inputFile("rules.txt");

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cout << "Unable to open the Game Rules file." << std::endl;
    }
}

void MainMenu::showStats() {
    std::ifstream inputFile("statistics.txt");

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cout << "No statistics available." << std::endl;
    }
}
