//
// Created by Tom Penn on 24/07/2022.
//

#ifndef TESTPROJECTS_BASECONTROLLER_H
#define TESTPROJECTS_BASECONTROLLER_H

#include <mysql.h>

class BaseController {
public:
     explicit BaseController(MYSQL *dbIn);

protected:
    MYSQL *db;
};


#endif //TESTPROJECTS_BASECONTROLLER_H
