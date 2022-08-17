//
// Created by Tom Penn on 17/08/2022.
//

#ifndef GAMEALPHA_BOSS_H
#define GAMEALPHA_BOSS_H

#include <string>
#include <array>
#include "Structs/Stats.h"

using namespace std;

typedef char **MYSQL_ROW;
typedef array<shared_ptr<class Ability>, 4> AbilityList;

class Boss {
public:
    void SetName(const string &nameIn);

    const string &GetName() const;

    void SetId(int idIn);

    int GetId() const;

    Stats& GetStats();

    static unique_ptr<Boss> fromRow(MYSQL_ROW row);

protected:
    int id;
    string name;
    Stats stats;
};


#endif //GAMEALPHA_BOSS_H
