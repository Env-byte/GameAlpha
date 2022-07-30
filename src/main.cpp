#include <iostream>
#include "Public/DbConfig.h"
#include "Public/Loop.h"
#include <stdexcept>

using namespace std;

int main() {
    DbConfig database = DbConfig();
    MYSQL *db;

    try {
        db = database.init();
    } catch (std::runtime_error &e) {
        cerr << e.what() << endl;
        return -1;
    }
    cout << "Connected to database" << std::endl;

    unique_ptr<Loop> loop(new Loop(db));
    loop->start();

    database.CloseConnection(db);

    return 0;
}
