//
// Created by Tom Penn on 24/07/2022.
//

#include "../../Public/Users/User.h"
#include <string>

using std::string;

const string &User::GetName() const {
    return name;
}

void User::SetName(const string &nameIn) {
    name = nameIn;
}

void User::SetId(int idIn) {
    id = idIn;
}

int User::GetId() const {
    return id;
}

void User::SetLevel(int levelIn) {
    level = levelIn;
}

int User::GetLevel() const {
    return level;
}

unique_ptr<User> User::fromRow(MYSQL_ROW row) {
    std::unique_ptr<User> user;

    user->SetId(std::stoi(row[0]));
    user->SetName(row[1]);
    user->SetLevel(std::stoi(row[2]));
    user->SetBossNo(std::stoi(row[3]));
    user->SetStats(row[4]);

    return user;
}

int User::GetBossNo() const {
    return bossNo;
}

void User::SetBossNo(int bossNoIn) {
    bossNo = bossNoIn;
}

const string &User::GetStats() const {
    return stats;
}

void User::SetStats(const string &statsIn) {
    stats = statsIn;
}
