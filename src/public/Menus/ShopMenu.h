//
// Created by Tom Penn on 15/08/2022.
//

#ifndef GAMEALPHA_SHOPMENU_H
#define GAMEALPHA_SHOPMENU_H

#include "BaseMenu.h"

class ShopMenu : public BaseMenu {
    using BaseMenu::BaseMenu;

public:
    int Show() override;

    void HandleInput(int &input) override;

    ~ShopMenu() override;
};


#endif //GAMEALPHA_SHOPMENU_H
