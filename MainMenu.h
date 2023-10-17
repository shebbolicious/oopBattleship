#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>

class MainMenu {
public:
    MainMenu(); // Constructor
    void showMenu(); // Shows the menu in the command window
    void showRules(); // Shows the rules section of menu
    void showStats(); // Shows the statistics section of menu
    int getChoice(); // Gets the user's input as their choice
    void runChoice(int choice); // Runs based on choice
    void saveResults(const std::string& winner, int shots); // Saves winning details

private:
    bool inMainMenu;
};

#endif // MAINMENU_H
