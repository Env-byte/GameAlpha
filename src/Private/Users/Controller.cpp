//
// Created by Tom Penn on 24/07/2022.
//

#include "../../Public/Users/Controller.h"
#include <cstdlib>
#include <memory>
#include <sstream>


namespace Users {
    unique_ptr<User> Controller::GetUser(const string &name) {

        unique_ptr<User> ThisUser = nullptr;
        MYSQL_RES *rset;
        MYSQL_ROW row;
        stringstream sql;
        sql << "SELECT id, username, level FROM users WHERE username='" << name << "';";
        if (!mysql_query(db, sql.str().c_str())) {
            rset = mysql_use_result(db);
            row = mysql_fetch_row(rset);
            if (row) {
                ThisUser = std::make_unique<User>();
                ThisUser->SetId(atoi(row[0]));
                ThisUser->SetName(row[1]);
                ThisUser->SetLevel(atoi(row[2]));
                return ThisUser;
            }
            mysql_free_result(rset);
        }
        return nullptr;
    }

    unique_ptr<User> Controller::AddUser(const string &name) {
        stringstream ss;
        ss << "INSERT INTO users (username)"
           << "values ('" << name << "')";
        if (mysql_query(db, ss.str().c_str())) {
            throw std::runtime_error(std::string("\nError inserting into users\n") + mysql_error(db));
        }
        return GetUser(name);
    }
}