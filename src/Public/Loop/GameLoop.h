//
// Created by Tom Penn on 30/07/2022.
//

#ifndef GAMEALPHA_GAMELOOP_H
#define GAMEALPHA_GAMELOOP_H

#include "../../Public/Loop/Loop.h"
#include "../../Public/Loop/MainLoop.h"
#include <iostream>

enum EGameState {
    EMenu,
    EEncounter,
    EShop,
    EExit
};

class GameLoop : public Loop {


public:
    explicit GameLoop(MYSQL *dbIn, const shared_ptr<User> &userIn);

    void Start() override;

protected:
    short ShowGameMenu();

    shared_ptr<User> thisUser;

    void HandleGameMenu(const short &Option);

    EGameState gameState;
};


#endif //GAMEALPHA_GAMELOOP_H
