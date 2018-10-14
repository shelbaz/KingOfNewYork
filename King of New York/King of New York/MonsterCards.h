//
// Created by Shawn Elbaz on 2018-10-11.
//

#pragma once
#include <string>
#include <vector>

using namespace std;

class MonsterCards {
    string MonsterNames[6] = { "CaptainFish", "Sheriff", "Kong", "Mantis", "Rob", "Drakonis" };

public:

    enum MonsterOptions{CaptainFish=0, Sheriff, Kong, Mantis, Rob, Drakonis, EnumEnd};
    MonsterCards();
    ~MonsterCards();

    string getName();
    void setMonster(MonsterOptions value);
    friend ostream& operator<<(ostream& os, MonsterCards& card);
    friend bool operator== (const MonsterCards& p1, const MonsterCards& p2) {
        return true;
    }


private:
    MonsterOptions card;

};

class DeckOfMonsterCards {

private:
    DeckOfMonsterCards();
    vector<MonsterCards> deck;
    vector<MonsterCards>::iterator it;

public:

    static shared_ptr<DeckOfMonsterCards> getInstance();

    DeckOfMonsterCards(DeckOfMonsterCards const&) = delete;
    DeckOfMonsterCards& operator=(DeckOfMonsterCards const&) = delete;

    void currentState();
    MonsterCards draw();
    MonsterCards draw(MonsterCards card);
    int getCardIndex(MonsterCards card);

};
