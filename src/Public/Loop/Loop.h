//
// Created by Tom Penn on 24/07/2022.
//

#ifndef TESTPROJECTS_LOOP_H
#define TESTPROJECTS_LOOP_H

#include <mysql.h>

class Loop {

public:
    explicit Loop(MYSQL *dbIn);

    virtual void Start() = 0;

protected:
    MYSQL *db;
};


#endif //TESTPROJECTS_LOOP_H
