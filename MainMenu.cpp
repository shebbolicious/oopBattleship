#include "mainmenu.h"
#include <iostream>
#include <fstream>
#include <string>

MainMenu::MainMenu() : inMainMenu(true) {}

void MainMenu::showMenu() {
    std::cout << "   Main Menu" << std::endl;
    std::cout << "1) Start Game" << std::endl;
    std::cout << "2) Game Rules" << std::endl;
    std::cout << "3) Statistics" << std::endl;
    std::cout << "4) Quit" << std::endl;
}

int MainMenu::getChoice() {
    int choice;
    std::cin >> choice;
    return choice;
}

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

void MainMenu::showRules() {
std::ifstream inputFile("rules.txt");

    if (inputFile.is_open()) {
        std::string line;
        while (std::getline(inputFile, line)) {
            std::cout << line << std::endl;
        }
        inputFile.close();
    } else {
        std::cout << "Error: Unable to open the instructions file." << std::endl;
    }
}

void MainMenu::showStats() {
// Read in from text
}