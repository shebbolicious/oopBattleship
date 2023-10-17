#ifndef MAINMENU_H
#define MAINMENU_H

#include <string>

class MainMenu {
public:
    MainMenu();
    void showMenu();
    void showRules();
    void showStats();
    int getChoice();
    void handleChoice(int choice);

private:
    bool inMainMenu;
};

#endif
