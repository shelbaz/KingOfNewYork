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
    os << "Name :" << card.name << endl;
    os << "Description :" << card.description << endl;
    os << "Cost :" << card.energyCost << endl;
    os << "***************" << endl;
    os << "Effect : ";
    os << "Energy =" << card.effect[Energy];
    os << "Attack =" << card.effect[Attack];
    os << "Destruction =" << card.effect[Destruction];
    os << "Heal =" << card.effect[Heal];
    os << "Celebrity =" << card.effect[Celebrity];
    os << "Ouch =" << card.effect[Ouch] << endl;
    os << "----------------------------------------" << endl;
    return os;

}

int Cards::getEnergyCost() {
    return energyCost;
}

string Cards::getDescription() {
    return description;
}

string Cards::getName() {
    return name;
}

Cards::Cards() {

}
