//
// Created by Tom Penn on 24/07/2022.
//

#ifndef TESTPROJECTS_USER_H
#define TESTPROJECTS_USER_H

#include <string>

using namespace std;

namespace Users {

    class User {

    public:
        void SetName(const string &nameIn);

        string GetName() const;

        void SetId(int idIn);

        int GetId() const;

        void SetLevel(int levelIn);

        int GetLevel() const;

    protected:
        int id;
        int level;
        string name;
    };

} // Users

#endif //TESTPROJECTS_USER_H
