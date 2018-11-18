//
// Created by Shawn Elbaz on 2018-10-11.
//

#pragma once
#include <string>
#include <vector>

using namespace std;

class MonsterCards {
    std::string  MonsterNames[6] = { "CaptainFish", "Sheriff", "Kong", "Mantis", "Rob", "Drakonis" };

public:

    enum MonsterOptions{CaptainFish=0, Sheriff, Kong, Mantis, Rob, Drakonis, EnumEnd};
    MonsterCards();
    explicit MonsterCards(MonsterOptions value);
    MonsterCards(const MonsterCards &p2);
    ~MonsterCards();

    std::string  getName() const;
    void setMonster(MonsterOptions value);
    friend ostream& operator<<(ostream& os, const MonsterCards& card);
    friend bool operator== (const MonsterCards& p1, const MonsterCards& p2) {
        return true;
    }


private:
    MonsterOptions card;

};

class DeckOfMonsterCards {

private:
    vector<MonsterCards> deck;
    vector<MonsterCards>::iterator it;

public:
    DeckOfMonsterCards();
    void currentState();
    MonsterCards draw();
    MonsterCards draw(MonsterCards card);
    int getCardIndex(MonsterCards card);
    const vector<MonsterCards> &getDeck() const;
    void removeTop();

};
