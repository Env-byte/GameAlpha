//
// Created by Tom Penn on 24/07/2022.
//

#include "../Public/Manager.h"

Manager::Manager(MYSQL *dbIn) {
    db = dbIn;
}

void Manager::SetDb(MYSQL *dbIn) {
    db = dbIn;
}

Manager::Manager() {

}
