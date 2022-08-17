//
// Created by Tom Penn on 17/08/2022.
//

#include "Bosses/BossManager.h"
#include <memory>

using namespace std;

BossManager::BossManager(MYSQL *dbIn) : Manager(dbIn) {
    GetAll();
}

void BossManager::GetAll() {
    if (mysql_query(db, "SELECT id,boss,stat,value FROM `boss_info`")) {
        throw runtime_error(string("\nError getting all from users\n") + mysql_error(db));
    }

    MYSQL_RES *result = mysql_store_result(db);
    unsigned long long numFields = mysql_num_fields(result);

    MYSQL_ROW row;
    bossList.clear();

    while ((row = mysql_fetch_row(result))) {
        for (auto i = 0; i < numFields; i++) {
            bossList.push_back(unique_ptr<Boss>(Boss::fromRow(row)));
        }
    }

    mysql_free_result(result);
}

const BossList &BossManager::GetBossList() {
    return bossList;
}

weak_ptr<Boss> BossManager::Get(const string &name) {
    for (const auto &boss: bossList) {
        if (name == boss->GetName()) {
            return boss;
        }
    }
    return shared_ptr<Boss>(nullptr);
}
