//
// Created by Tom Penn on 10/08/2022.
//

#ifndef GAMEALPHA_MAINMENU_H
#define GAMEALPHA_MAINMENU_H

#include "BaseMenu.h"

class MainMenu : public BaseMenu {
    using BaseMenu::BaseMenu;

public:
    int Show() override;

    void HandleInput(int &input) override;

    ~MainMenu() override;

protected:
    unique_ptr<class User> CreateNewCharacter();

    unique_ptr<class User> LoadExistingCharacter();
};


#endif //GAMEALPHA_MAINMENU_H
