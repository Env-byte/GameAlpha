//
// Created by Tom Penn on 24/07/2022.
//
#ifndef TESTPROJECTS_USER_H
#define TESTPROJECTS_USER_H

#include <string>
#include<array>

using namespace std;

typedef char **MYSQL_ROW;
typedef array<shared_ptr<class Ability>, 4> AbilityList;

class User {

public:
    void SetName(const string &nameIn);

    const string &GetName() const;

    void SetId(int idIn);

    int GetId() const;

    void SetLevel(int levelIn);

    int GetLevel() const;

    void SetBossNo(int bossNoIn);

    int GetBossNo() const;

    static unique_ptr<User> fromRow(MYSQL_ROW row);

    shared_ptr<Ability> GetAbility(const int &index);

    AbilityList* GetAbilities();

    void AddAbility(shared_ptr<class Ability> ability);

protected:
    int id;
    int level;
    int bossNo;
    string name;
    string stats;

    AbilityList Abilities;
};


#endif //TESTPROJECTS_USER_H
