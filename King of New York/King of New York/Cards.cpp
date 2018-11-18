#include <utility>

//
// Created by Shawn Elbaz on 2018-10-11.
//

#include "Cards.h"
#include <iostream>

std::string card_type[4] = { "Empty", "Goal", "Keep", "Discard" };


void Cards::setCard(int id, std::string name, int energyCost, CardType type, std::string description) {
    this->id = id;
    this->name = std::move(name);
    this->description = std::move(description);
    this->type = type;
    this->energyCost = energyCost;
}

ostream & operator<<(ostream & os, const Cards& card){

    os << "----------------------------------------" << endl;
    os << "ID :" << card.getId() << endl;
    os << "Name :" << card.getName() << endl;
    os << "RewardType: " << card_type[card.getType()] << endl;
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
    name = "";
    energyCost = -1;
    type = CardType::Empty;
    effect = {0,0,0,0,0,0};
}

std::string Cards::getName() const {
    return name;
}

std::string Cards::getDescription() const {
    return description;
}

vector<int> Cards::getEffect() {
    return effect;
}

Cards::CardType Cards::getType() const {
    return type;
}

void Cards::setName(const std::string &name) {
    Cards::name = name;
}

void Cards::setDescription(const std::string&description) {
    Cards::description = description;
}

void Cards::setType(CardType type) {
    Cards::type = type;
}

void Cards::setEnergyCost(int energyCost) {
    Cards::energyCost = energyCost;
}

void Cards::setEffect(const vector<int> &effect) {
    Cards::effect = effect;
}

int Cards::getId() const {
    return id;
}

void Cards::setId(int id) {
    Cards::id = id;
}






