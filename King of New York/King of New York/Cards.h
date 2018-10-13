//
// Created by Shawn Elbaz on 2018-10-11.
//

#pragma once
#include <string>
#include <vector>
#include <map>

using namespace std;


class Cards {
    enum CardEffects{Energy=0, Attack, Destruction, Heal, Celebrity, Ouch};

    //64 cards
private:
    string name;
    string description;
    int energyCost;

//    map <CardEffects, int> effect = {{Energy, 0}, {Attack, 0}, {Destruction, 0}, {Heal, 0} , {Celebrity, 0} , {Ouch, 0}};


public:

    Cards();
//    void setCard(string name, string description, map <CardEffects, int> playerEffect, int energyCost);
//    friend ostream& operator<<(ostream& os, const Cards& card);
    int getEnergyCost() const;

    const string &getName() const;

    const string &getDescription() const;

//    const vector<CardEffects, int> &getEffect() const;


};
