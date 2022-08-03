//
// Created by Tom Penn on 24/07/2022.
//

#ifndef TESTPROJECTS_BASECONTROLLER_H
#define TESTPROJECTS_BASECONTROLLER_H

#include <mysql.h>

class Manager {
public:
    explicit Manager(MYSQL *dbIn);

    explicit Manager();

    void SetDb(MYSQL *dbIn);

    virtual void Init() = 0;

protected:
    MYSQL *db;
};


#endif //TESTPROJECTS_BASECONTROLLER_H
