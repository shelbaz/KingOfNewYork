//
// Created by Shawn Elbaz on 2018-10-11.
//

#pragma once
#include <string>
#include <vector>

using namespace std;


class Cards {

    enum CardEffects{Energy=0, Attack, Destruction, Heal, Celebrity, Ouch};
    //64 cards
private:
    string name;
    string description;
    int energyCost;

    //                 E,  A , D,  H,  C,  O
    vector <int> effect = {0,0,0,0,0,0};
    vector <int> ::iterator it;

public:

    Cards();

    void setCard(string name, string description, vector <int> playerEffect, int energyCost);
    friend ostream& operator<<(ostream& os, const Cards& card);

    int getEnergyCost() const;

    string getName() const;

    string getDescription() const;

    vector<int> getEffect();


};
