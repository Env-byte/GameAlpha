//
// Created by Tom Penn on 17/08/2022.
//

#ifndef GAMEALPHA_BOSSMANAGER_H
#define GAMEALPHA_BOSSMANAGER_H


#include "Boss.h"
#include "Manager.h"
#include <vector>

using namespace std;
typedef vector<shared_ptr<Boss>> BossList;

class BossManager : public Manager {
public:
    BossManager(MYSQL *dbIn);

    weak_ptr<Boss> Get(const string &name);

    const BossList &GetBossList();

protected:

    void GetAll();


    BossList bossList;
};


#endif //GAMEALPHA_BOSSMANAGER_H
