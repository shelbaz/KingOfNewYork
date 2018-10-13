//
// Created by Shawn Elbaz on 2018-10-11.
//

#pragma once
#include <string>
#include <vector>

using namespace std;

enum CardEffects{Energy, Attack, Destruction, Heal, Celebrity, Ouch};

class Cards {

    //64 cards
private:
    string name;
    string description;
    int energyCost;

    vector <CardEffects, int> effect = {{Energy, 0}, {Attack, 0}, {Destruction, 0}, {Heal, 0} , {Celebrity, 0} , {Ouch, 0}};


public:

    Cards();
    ~Cards();
    void setCard(string name, string description, vector <CardEffects, int> playerEffect, int energyCost);
    friend ostream& operator<<(ostream& os, const Cards& card);
    int getEnergyCost();
    string getDescription();
    string getName();


};
