//
// Created by Tom Penn on 10/08/2022.
//

#include "Menus/BaseMenu.h"
#include "Statics.h"
using namespace std;

BaseMenu::BaseMenu(MenuManager *menuManager) {
    this->menuManager = menuManager;
}

int BaseMenu::Show() {
    Statics::ClearConsole();
    return 0;
}

BaseMenu::~BaseMenu() {
}







