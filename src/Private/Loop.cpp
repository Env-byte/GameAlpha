//
// Created by Tom Penn on 24/07/2022.
//
#include "../Public/Loop.h"
#include "../Public/Users/Controller.h"
#include <cstdlib>
#include <iostream>

using namespace std;
using namespace Users;

void Loop::start() {
    cout << "Welcome" << std::endl;
    DoLogin();
    int input;
    do {
        cout << "Hello" << ThisUser->GetName() << ". Your are level " << ThisUser->GetLevel() << endl;
        input = ShowMenu();
    } while (input == 3);
}

void Loop::DoLogin() {
    cout << "Please Enter your name" << endl;
    string name;
    cin >> name;

    unique_ptr<Controller> UsersController(new Controller(db));
    ThisUser = shared_ptr<User>(UsersController->GetUser(name));
    if (!ThisUser) {
        ThisUser = UsersController->AddUser(name);
    }
}


Loop::Loop(MYSQL *dbIn) {
    db = dbIn;
}

int Loop::ShowMenu() {

    cout << " ---- Menu ---- " << endl;
    cout << ThisUser->GetName() << " Lv" << ThisUser->GetLevel() << endl;
    cout << "1) Roll Dice for encounter " << endl;
    cout << "2) Stats & Shop" << endl;
    cout << "3) Exit" << endl;
    string input;
    cin >> input;
    return atoi(input.c_str());
}


