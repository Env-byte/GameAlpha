//
// Created by Tom Penn on 10/08/2022.
//

#ifndef GAMEALPHA_MANGER_H
#define GAMEALPHA_MANGER_H
#endif //GAMEALPHA_MANGER_H

#include <mysql.h>
#include <memory>
#include "Menus/BaseMenu.h"
#include "Users/User.h"
#include <functional>

using namespace std;


enum EMenus {
    EMain,
    EGame,
    EEncounter,
    EShop
};

class MenuManager {

public:
    explicit MenuManager(MYSQL *&db);

    void LoadMenu(EMenus menu);

    void LoadMenu(EMenus menu, const function<void(const weak_ptr<BaseMenu> &Menu)> &OnLoad);

    void SetUser(unique_ptr<User> &userIn);

    shared_ptr<User> GetUser() {
        return user;
    }

    MYSQL *db;
protected:
    shared_ptr<BaseMenu> activeMenu{};

    shared_ptr<BaseMenu> CreateMenu(EMenus menu);

    shared_ptr<User> user;
};
