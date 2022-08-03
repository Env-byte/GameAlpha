//
// Created by Tom Penn on 30/07/2022.
//

#include "../../Public/Loop/GameLoop.h"
#include "../../Public/Statics.h"


GameLoop::GameLoop(MYSQL *dbIn, const shared_ptr<User> &userIn) : Loop(dbIn) {
    thisUser = userIn;
    gameState = EGameState::EMenu;
}

void GameLoop::Start() {
    do {
        Statics::ClearConsole();
        cout << "Character " << thisUser->GetName() << " is level " << thisUser->GetLevel() << endl;
        HandleGameMenu(ShowGameMenu());
    } while (gameState != EExit);
}

short GameLoop::ShowGameMenu() {
    cout << " ---- Menu ---- " << endl;
    cout << thisUser->GetName() << " Lv" << thisUser->GetLevel() << endl;
    cout << "1) Roll Dice for encounter " << endl;
    cout << "2) Stats & Shop" << endl;
    cout << "3) Exit" << endl;
    return Statics::GetInput(1, 3);
}

void GameLoop::HandleGameMenu(const short &Option) {
    switch (Option) {
        case 1:
            break;
        case 2:

            break;
        case 3:
            break;
    }
}




