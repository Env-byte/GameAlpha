//
// Created by Tom Penn on 24/07/2022.
//

#ifndef TESTPROJECTS_CONTROLLER_H
#define TESTPROJECTS_CONTROLLER_H

#include "User.h"
#include "Manager.h"

using namespace std;

typedef vector<unique_ptr<User>> UserList;

class UserManager : public Manager {
    using Manager::Manager;
public:
    unique_ptr<User> Get(const string &name);

    unique_ptr<User> GetUserById(const int &id);

    unique_ptr<User> AddUser(const string &name);

    UserList GetAll();
};


#endif //TESTPROJECTS_CONTROLLER_H
