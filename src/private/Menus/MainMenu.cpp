//
// Created by Tom Penn on 10/08/2022.
//

#include "Menus/MainMenu.h"
#include "Menus/MenuManger.h"

#include "Users/User.h"
#include "Users/UserManager.h"
#include "Statics.h"
#include <iostream>
#include <vector>

using namespace std;

int MainMenu::Show() {
    BaseMenu::Show();
    cout << " ---- Menu ---- " << endl;
    cout << "1) Create New Character" << endl;
    cout << "2) Use Existing" << endl;
    cout << "3) Exit" << endl;
    return Statics::GetInput(1, 3);
}

void MainMenu::HandleInput(int &input) {
    switch (input) {
        case 1: {
            auto user = CreateNewCharacter();
            if (user) {
                menuManager->SetUser(user);
                menuManager->LoadMenu(EMenus::EGame);
                return;
            }
            break;
        }
        case 2: {
            auto user = LoadExistingCharacter();
            if (user) {
                menuManager->SetUser(user);
                menuManager->LoadMenu(EMenus::EGame);
                return;
            }
        }
            break;
        case 3:
            cout << "Exiting" << endl;
            return;
    }

    menuManager->LoadMenu(EMenus::EMain);
}

MainMenu::~MainMenu() {
    cout << "Destroying MainMenu" << endl;
}

unique_ptr<User> MainMenu::CreateNewCharacter() {
    unique_ptr<UserManager> Manager(new UserManager(menuManager->db));
    cout << "Please Enter your name" << endl;
    string name;
    cin >> name;
    return Manager->AddUser(name);
}

unique_ptr<User> MainMenu::LoadExistingCharacter() {
    unique_ptr<UserManager> Manager(new UserManager(menuManager->db));
    auto users = Manager->GetAll();
    if (users.empty()) {
        cout << "No characters have been created." << endl;
        return nullptr;
    }
    unique_ptr<User> userOut{nullptr};

    for (unsigned long i = 0, iL = users.size(); i < iL; i++) {
        cout << " ---- Menu ---- " << endl;
        cout << i + 1 << ") " << users[i]->GetName() << " lv " << users[i]->GetLevel() << endl;
    }
    cout << users.size() + 1 << ") Back" << endl;

    bool isValid;
    do {
        isValid = false;

        int input = Statics::GetInput(1, users.size() + 1);
        if (users.size() + 1 == input) {
            return nullptr;
        } else if (input < users.size()) {
            userOut = std::move(users[input - 1]);
            isValid = true;
        } else {
            cout << "Invalid Input" << endl;
        }
    } while (!isValid);

    return userOut;
}
