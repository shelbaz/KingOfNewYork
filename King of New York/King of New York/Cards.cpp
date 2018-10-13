//
// Created by Shawn Elbaz on 2018-10-11.
//

#include "Cards.h"
#include <iostream>

void Cards::setCard(string name, string description, vector<CardEffects, int> playerEffect, int cost) {
    this->name = name;
    this->description = description;
    this->effect = playerEffect;
    this->energyCost = cost;
}

ostream & operator<<(ostream & os, const Cards& card){

    os << "----------------------------------------" << endl;
    os << "Name :" << card.getName() << endl;
    os << "Description :" << card.getDescription() << endl;
    os << "Cost :" << card.getEnergyCost() << endl;
    os << "***************" << endl;
    os << "Effect : ";
    os << "Energy =" << card.getEffect()[Energy];
    os << "Attack =" << card.getEffect()[Attack];
    os << "Destruction =" << card.getEffect()[Destruction];
    os << "Heal =" << card.getEffect()[Heal];
    os << "Celebrity =" << card.getEffect()[Celebrity];
    os << "Ouch =" << card.getEffect()[Ouch] << endl;
    os << "----------------------------------------" << endl;
    return os;

}

int Cards::getEnergyCost() const{
    return energyCost;
}

Cards::Cards() {

}

const string &Cards::getName() const {
    return name;
}

const string &Cards::getDescription() const {
    return description;
}

const vector<CardEffects, int> &Cards::getEffect() const {
    return effect;
}
