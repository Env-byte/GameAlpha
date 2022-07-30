//
// Created by Tom Penn on 24/07/2022.
//

#include "../../Public/Users/User.h"
#include <string>

using std::string;
namespace Users {
    string User::GetName() const {
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
}