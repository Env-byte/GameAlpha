//
// Created by Tom Penn on 30/07/2022.
//

#include "../../Public/Loop/MainLoop.h"
#include "../../Public/Users/UserManager.h"
#include "../../Public/Statics.h"
#include "../../Public/Loop/GameLoop.h"
#include "../../Public/Globals.h"

#include <iostream>
#include <vector>

using namespace std;

void MainLoop::Start() {
    loopState = ELooping;
    do {
        Statics::ClearConsole();
        shared_ptr<User> user = nullptr;
        HandleMainMenu(ShowMainMenu(), user);
        if (user) {
            unique_ptr<GameLoop> loop(new GameLoop(db, user));
        }
    } while (loopState != EEnd);
}

short MainLoop::ShowMainMenu() {
    cout << " ---- Menu ---- " << endl;
    cout << "1) Create New Character" << endl;
    cout << "2) Use Existing" << endl;
    cout << "3) Exit" << endl;
    return Statics::GetInput(1, 3);
}

void MainLoop::HandleMainMenu(const short &option, shared_ptr<User> &userOut) {
    switch (option) {
        case 1: {
            cout << "Please Enter your name" << endl;
            string name;
            cin >> name;
            userOut = std::move(g_UserManager.AddUser(name));
            break;
        }
        case 2: {

            auto users = g_UserManager.GetAll();
            if (users.empty()) {
                cout << "No characters have been created." << endl;
                return;
            }


            for (unsigned long i = 0, iL = users.size(); i < iL; i++) {
                cout << " ---- Menu ---- " << endl;
                cout << i + 1 << ") " << users[i]->GetName() << " lv " << users[i]->GetLevel() << endl;
            }
            cout << users.size() + 1 << ") Back" << endl;

            bool isValid;
            do {
                isValid = false;

                short input = Statics::GetInput(1, 3);
                if (users.size() + 1 == input) {
                    return;
                } else if (input < users.size()) {
                    userOut = std::move(users[input - 1]);
                    isValid = true;
                } else {
                    cout << "Invalid Input" << endl;
                }
            } while (!isValid);
            break;
        }
        case 3: {
            loopState = EEnd;
            break;
        }
    }
}

