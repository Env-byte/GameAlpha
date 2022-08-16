//
// Created by Tom Penn on 10/08/2022.
//
#include "Menus/MenuManger.h"
#include "Menus/MainMenu.h"
#include "Menus/GameMenu.h"
#include "Menus/EncounterMenu.h"
#include "Menus/ShopMenu.h"
#include <mysql.h>
#include <memory>

using namespace std;

void MenuManager::LoadMenu(EMenus menu) {
    LoadMenu(menu,  ([](const weak_ptr<BaseMenu> &Menu) {}));
}

void MenuManager::LoadMenu(EMenus menu, const function<void(const weak_ptr<BaseMenu> &Menu)> &OnLoad) {
    activeMenu.reset();
    activeMenu = CreateMenu(menu);

    OnLoad(activeMenu);

    int input = activeMenu->Show();
    activeMenu->HandleInput(input);
}

shared_ptr<BaseMenu> MenuManager::CreateMenu(EMenus menu) {
    switch (menu) {
        case EMain:
            return make_shared<MainMenu>(this);
        case EGame:
            return make_shared<GameMenu>(this);
        case EEncounter:
            return make_shared<EncounterMenu>(this);
        case EShop:
            return make_shared<ShopMenu>(this);

    }

    return nullptr;
}

MenuManager::MenuManager(MYSQL *&db) {
    this->db = db;
}

void MenuManager::SetUser(unique_ptr<User> &userIn) {
    this->user = std::move(userIn);
}
