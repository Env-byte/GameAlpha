//
// Created by Tom Penn on 17/08/2022.
//

#include "Structs/Stats.h"
#include "json/reader.h"
#include <iostream>

using namespace std;

void Stat::add(const float &val, const function<bool(const float &newVal)> &beforeChange) {
    float tempNew = currentVal + val;
    if (beforeChange(tempNew)) {
        oldVal = currentVal;
        currentVal = tempNew;
    }
}

void Stat::subtract(const float &val, const function<bool(const float &newVal)> &beforeChange) {
    //prevent val being negative
    float tempNew = currentVal - val;
    if (beforeChange(tempNew)) {
        oldVal = currentVal;
        if (currentVal <= val) {
            currentVal = 0.f;
        } else {
            currentVal = tempNew;
        }
    }
}

void Stats::ReadJson(string &json) {
    Json::Value root;
    Json::Reader reader;
    bool parsingSuccessful = reader.parse(json, root);
    //parse process
    if (!parsingSuccessful) {
        cout << "Failed to parse" << reader.getFormattedErrorMessages();
    }

    maxHealth.currentVal = root.get("health", "0").asFloat();
    currentHealth.currentVal = root.get("health", "0").asFloat();
    magical.currentVal = root.get("magical", "0").asFloat();
    physical.currentVal = root.get("physical", "0").asFloat();
    defense.currentVal = root.get("defense", "0").asFloat();
    luck.currentVal = root.get("luck", "0").asFloat();
}
