#include <iostream>
#include "Public/DbConfig.h"
#include "Public/Loop/MainLoop.h"
#include "Public/Globals.h"
#include <stdexcept>

using namespace std;

int main() {
    MYSQL *db;
    try {
        db = DbConfig::init();
    } catch (std::runtime_error &e) {
        cerr << e.what() << endl;
        return -1;
    }
    cout << "Connected to database" << std::endl;
    InitManagers(db);
    unique_ptr<MainLoop> loop(new MainLoop(db));
    loop->Start();

    DbConfig::CloseConnection(db);

    delete db;

    return 0;
}
