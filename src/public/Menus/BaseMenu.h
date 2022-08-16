//
// Created by Tom Penn on 10/08/2022.
//

#ifndef GAMEALPHA_BASEMENU_H
#define GAMEALPHA_BASEMENU_H

#include <memory>

using namespace std;

class MenuManager;

class BaseMenu {
public:

    explicit BaseMenu(MenuManager *menuManager);

    virtual int Show();

    virtual void HandleInput(int &input) = 0;

    virtual ~BaseMenu();


protected:
    MenuManager *menuManager;
};


#endif //GAMEALPHA_BASEMENU_H
