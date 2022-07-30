//
// Created by Tom Penn on 24/07/2022.
//

#ifndef TESTPROJECTS_LOOP_H
#define TESTPROJECTS_LOOP_H

#include <mysql.h>
#include "../Public/Users/User.h"

class Loop {

public:
    explicit Loop(MYSQL *dbIn);

    void start();

protected:
    MYSQL *db;

    shared_ptr<Users::User> ThisUser;

    void DoLogin();

    int ShowMenu();
};


#endif //TESTPROJECTS_LOOP_H
