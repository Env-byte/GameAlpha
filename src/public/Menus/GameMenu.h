//
// Created by Tom Penn on 15/08/2022.
//

#ifndef GAMEALPHA_GAMEMENU_H
#define GAMEALPHA_GAMEMENU_H

#include "BaseMenu.h"


class GameMenu : public BaseMenu {
    using BaseMenu::BaseMenu;

public:
    int Show() override;

    void HandleInput(int &input) override;

    ~GameMenu() override;
};


#endif //GAMEALPHA_GAMEMENU_H
