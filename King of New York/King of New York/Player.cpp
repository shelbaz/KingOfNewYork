//
// Created by Shawn Elbaz on 2018-10-10.
//

#include "Player.h"
#include <iostream>

int Player::getPlayerID() {
    return playerID;
}

void Player::rollDice(int numbOfDice) {

    this-> dice.rollDice(numbOfDice);

}

void Player::resolveDice() {
}

void Player::move() {

}

void Player::buyCards(Cards card) {

    if(getEnergyCubes() < card.getEnergyCost()){
        cout << "You do not have enough energy cubes to purchase this card" << endl;
        return;
    }
    else{
        addCard(card);
    }

}

void Player::addCard(Cards card) {
    cards.push_back(card);

}

Player::Player() {
    victoryPoints = 0;
    lifePoints= 10;
}

Player::~Player() {

}

Player::Player(MonsterCards m, Dice d): Player() {
    this->monsterCard = m;
    this ->dice = d ;
}

void Player::attack() {

}

int Player::getNumberOfCards() {
    return cards.size();
}

int Player::getLifePoints() {
    return lifePoints;
}

int Player::getVictoryPoints() {
    return victoryPoints;
}

int Player::getEnergyCubes() {
    return energyCubes;
}


void Player::addLifePoints(unsigned int pts) {
    lifePoints += pts ;

}

void Player::addVictoryPoints(unsigned int pts) {
    victoryPoints += pts;
}

void Player::removeLifePoints(int pts) {
    lifePoints -= pts ;

}

void Player::removeVictoryPoints(int pts) {
    victoryPoints -= pts;
}
