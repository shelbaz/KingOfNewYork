//
// Created by Shawn Elbaz on 2018-10-11.
//

#include "Cards.h"
#include <iostream>

void Cards::setCard(string name, string description, string type, vector<int> playerEffect, int cost) {
    this->name = name;
    this->description = description;
    this->type = type;
    this->effect = playerEffect;
    this->energyCost = cost;
}

ostream & operator<<(ostream & os, const Cards& card){

    os << "----------------------------------------" << endl;
    os << "Name :" << card.getName() << endl;
    os << "Type :" << card.getType() << endl;
    os << "Description :" << card.getDescription() << endl;
    os << "Cost :" << card.getEnergyCost() << endl;
    os << "***************" << endl;
    os << "Effect : " << endl;
    os << "Energy = " << card.effect[Cards::Energy];
    os << ", Attack = " << card.effect[Cards::Attack];
    os << ", Destruction = " << card.effect[Cards::Destruction];
    os << ", Heal = " << card.effect[Cards::Heal];
    os << ", Celebrity = " << card.effect[Cards::Celebrity];
    os << ", Ouch = " << card.effect[Cards::Ouch] << endl;
    os << "----------------------------------------" << endl;
    return os;

}

int Cards::getEnergyCost() const{
    return energyCost;
}

Cards::Cards() {
    vector <int> effect;
    vector <int> ::iterator it;
}

string Cards::getName() const {
    return name;
}

string Cards::getDescription() const {
    return description;
}

vector<int> Cards::getEffect() {
    return effect;
}

string Cards::getType() const {
    return type;
}



