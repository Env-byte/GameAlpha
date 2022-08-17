#include <iostream>
#include "DbConfig.h"
#include <stdexcept>
#include "Menus/MenuManger.h"

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

    auto *menu = new MenuManager(db);
    menu->LoadMenu(EMenus::EMain);

    DbConfig::CloseConnection(db);
    delete menu;
    return 0;
}
