//
// Created by Tom Penn on 24/07/2022.
//

#ifndef TESTPROJECTS_CONTROLLER_H
#define TESTPROJECTS_CONTROLLER_H

#include "User.h"
#include "../BaseController.h"

namespace Users {

    class Controller : public BaseController {
        using BaseController::BaseController;
    public:
        unique_ptr<User> GetUser(const string &name);

        unique_ptr<User> AddUser(const string &name);
    };

} // Users

#endif //TESTPROJECTS_CONTROLLER_H
