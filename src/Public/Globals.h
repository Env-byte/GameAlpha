//
// Created by Tom Penn on 02/08/2022.
//

#ifndef GAMEALPHA_GLOBALS_H
#define GAMEALPHA_GLOBALS_H

#include <mysql.h>

extern class AbilityManager g_AbilityManger;

extern class EncounterManager g_EncounterManager;

extern class EnemyManager g_EnemyManager;

extern class UserManager g_UserManager;

extern void InitManagers(MYSQL *db);

#endif //GAMEALPHA_GLOBALS_H
