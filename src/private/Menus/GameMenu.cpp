//
// Created by Tom Penn on 15/08/2022.
//

#include "Menus/GameMenu.h"
#include "Menus/MenuManger.h"
#include "Statics.h"
#include <iostream>

using namespace std;

int GameMenu::Show() {

    auto user = menuManager->GetUser();

    cout << " ---- Menu ---- " << endl;
    cout << user->GetName() << " Lv" << user->GetLevel() << endl;
    cout << "1) Roll Dice for encounter " << endl;
    cout << "2) Stats & Shop" << endl;
    cout << "3) Return to Main Menu" << endl;
    cout << "4) Exit" << endl;

    return Statics::GetInput(1, 3);
}

void GameMenu::HandleInput(int &input) {
    switch (input) {
        case 1:
            menuManager->LoadMenu(EMenus::EEncounter, ([](const weak_ptr<BaseMenu> &menu) {
                //roll dice here and set encounter
            }));
            break;
        case 2:
            menuManager->LoadMenu(EMenus::EShop);
            break;
        case 3:
            menuManager->LoadMenu(EMenus::EMain);
            break;
        case 4:
            return;
    }
}

GameMenu::~GameMenu() {
    cout << "Destroying GameMenu" << endl;
}
