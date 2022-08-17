//
// Created by Tom Penn on 17/08/2022.
//

#include "Bosses/Boss.h"

void Boss::SetName(const string &nameIn) {
    name = nameIn;
}

const string &Boss::GetName() const {
    return name;
}

void Boss::SetId(int idIn) {
    id = idIn;
}

int Boss::GetId() const {
    return id;
}

unique_ptr<Boss> Boss::fromRow(MYSQL_ROW row) {
    auto boss = unique_ptr<Boss>();

    boss->SetId(stoi(row[0]));
    boss->SetName(row[1]);
    string json = row[2];
    boss->stats.ReadJson(json);

    return boss;
}

Stats &Boss::GetStats() {
    return stats;
}
