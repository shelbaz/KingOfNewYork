//
// Created by Shawn Elbaz on 2018-10-11.
//

#pragma once
#include <string>
using namespace std;

class MonsterCards {
    enum MonsterOptions{CaptainFish=0, Sheriff, Kong, Mantis, Rob, Drakonis};
    const char * MonsterNames[6] = { "CaptainFish", "Sheriff", "Kong", "Mantis", "Rob", "Drakonis" };

private:
    MonsterOptions card;

public:

    MonsterCards();
    ~MonsterCards();

    explicit MonsterCards(MonsterOptions);
    const char * getName();

};
