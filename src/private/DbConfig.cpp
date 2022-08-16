//
// Created by Tom Penn on 24/07/2022.
//

#include "DbConfig.h"
#include <string>
#include <stdexcept>

MYSQL *DbConfig::init() {

    // Initialize Connection
    MYSQL *conn;
    if (!(conn = mysql_init(nullptr))) {
        throw std::runtime_error(std::string("unable to initialize connection struct\n"));
    }

    // Connect to the database
    if (!mysql_real_connect(
            conn,                 // Connection
            "localhost", // Host
            "root",            // User account
            "123",   // User password
            "GameAlpha",               // Default database
            3306,                 // Port number
            nullptr,                 // Path to socket file
            0                     // Additional options
    )) {
        CloseConnection(conn);
        throw std::runtime_error(std::string("\nError connecting to Server: \n") + mysql_error(conn));
    }


    return conn;

}

void DbConfig::CloseConnection(MYSQL *conn) {
    // Close the Connection
    mysql_close(conn);
}
