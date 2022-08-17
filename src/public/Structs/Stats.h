//
// Created by Tom Penn on 17/08/2022.
//

#ifndef GAMEALPHA_STATS_H
#define GAMEALPHA_STATS_H

#include <string>

using namespace std;

struct Stat {
    Stat() {}

    float oldVal = 0.f;
    float currentVal = 0.f;
    string name = "";

    void add(const float &val, const function<bool(const float &newVal)> &beforeChange);

    void subtract(const float &val, const function<bool(const float &newVal)> &beforeChange);

private:
    Stat(const Stat &);

    Stat &operator=(const Stat &);
};

struct Stats {
    Stat currentHealth;
    Stat maxHealth;
    Stat defense;
    Stat magical;
    Stat physical;
    Stat luck;

    void ReadJson(string& json);

private:
    Stats();

    Stats(const Stat &);

    Stats &operator=(const Stat &);
};

#endif //GAMEALPHA_STATS_H
