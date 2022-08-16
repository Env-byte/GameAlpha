//
// Created by Tom Penn on 15/08/2022.
//

#ifndef GAMEALPHA_ENCOUNTERMENU_H
#define GAMEALPHA_ENCOUNTERMENU_H

#include "BaseMenu.h"

class EncounterMenu : public BaseMenu{
    using BaseMenu::BaseMenu;

public:
    int Show() override;

    void HandleInput(int &input) override;

    ~EncounterMenu() override;
};


#endif //GAMEALPHA_ENCOUNTERMENU_H
