//
// Created by Tom Penn on 24/07/2022.
//

#include "Users/UserManager.h"
#include <memory>
#include <sstream>
#include <vector>

using namespace std;

unique_ptr<User> UserManager::Get(const string &name) {

    unique_ptr<User> ThisUser = nullptr;
    MYSQL_RES *rset;
    MYSQL_ROW row;
    stringstream sql;
    sql << "SELECT id,name,level,bossNo FROM users WHERE name='" << name << "';";
    if (!mysql_query(db, sql.str().c_str())) {
        rset = mysql_use_result(db);
        row = mysql_fetch_row(rset);
        if (row) {
            return User::fromRow(row);
        }
        mysql_free_result(rset);
    }
    return ThisUser;
}

unique_ptr<User> UserManager::AddUser(const string &name) {
    stringstream ss;
    ss << "INSERT INTO users (name)"
       << "values ('" << name << "')";
    if (mysql_query(db, ss.str().c_str())) {
        throw runtime_error(string("\nError inserting into users\n") + mysql_error(db));
    }
    return Get(name);
}

UserList UserManager::GetAll() {
    if (mysql_query(db, "SELECT id,name,level,bossNo FROM `users`")) {
        throw runtime_error(string("\nError getting all from users\n") + mysql_error(db));
    }

    MYSQL_RES *result = mysql_store_result(db);
    unsigned long long numFields = mysql_num_fields(result);

    MYSQL_ROW row;

   UserList users;

    while ((row = mysql_fetch_row(result))) {
        for (auto i = 0; i < numFields; i++) { ;
            users.push_back(unique_ptr<User>(User::fromRow(row)));
        }
    }
    mysql_free_result(result);

    return users;
}

unique_ptr<User> UserManager::GetUserById(const int &id) {
    unique_ptr<User> ThisUser = nullptr;
    MYSQL_RES *rset;
    MYSQL_ROW row;
    stringstream sql;
    sql << "SELECT id,name,level,bossNo FROM users WHERE id='" << id << "';";
    if (!mysql_query(db, sql.str().c_str())) {
        rset = mysql_use_result(db);
        row = mysql_fetch_row(rset);
        if (row) {
            return User::fromRow(row);
        }
        mysql_free_result(rset);
    }
    return ThisUser;
}


