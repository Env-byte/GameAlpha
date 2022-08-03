//
// Created by Tom Penn on 24/07/2022.
//
#include <cstdio>
#include <cstdlib>
#include <mysql.h>

#ifndef TESTPROJECTS_DB_H
#define TESTPROJECTS_DB_H


class DbConfig {
public:
    static MYSQL* init();

    static void CloseConnection(MYSQL *conn);
};


#endif //TESTPROJECTS_DB_H
