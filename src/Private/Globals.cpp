//
// Created by Tom Penn on 02/08/2022.
//

#include "../Public/Globals.h"
#include "../Public/Abilities/AbilityManager.h"
#include "../Public/Encounter/EncounterManager.h"
#include "../Public/Enemy/EnemyManager.h"
#include "../Public/Users/UserManager.h"

AbilityManager g_AbilityManger = AbilityManager();
EncounterManager g_EncounterManager = EncounterManager();
EnemyManager g_EnemyManager = EnemyManager();
UserManager g_UserManager = UserManager();

void InitManagers(MYSQL *db) {
    g_AbilityManger.SetDb(db);
    g_AbilityManger.Init();

    g_EncounterManager.SetDb(db);
    g_EncounterManager.Init();

    g_EnemyManager.SetDb(db);
    g_EnemyManager.Init();

    g_UserManager.SetDb(db);
    g_UserManager.Init();
}