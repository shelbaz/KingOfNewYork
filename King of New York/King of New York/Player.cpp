//
// Created by Shawn Elbaz on 2018-10-10.
//

#include "Player.h"
#include <iostream>

Player::Player() {
    victoryPoints = 0;
    lifePoints= 10;

    Dice dice;
    MonsterCards monsterCard;
    BoardFigures boardFigure;
    vector <Cards> cards;
    vector <GameTokens> gameTokens;
    vector <BuildingUnitTiles> buildingUnitTiles;
}

Player::~Player() {

}

Player::Player(Dice d): Player() {
    this ->dice = d ;
}

int Player::getPlayerID() const {
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
        this->removeEnergyCubes(card.getEnergyCost());
        this->addCard(card);
    }

}

void Player::addCard(Cards card) {
    cards.push_back(card);

}

void Player::attack() {

}

int Player::getNumberOfCards() {
    return cards.size();
}

int Player::getLifePoints() const {
    return lifePoints;
}

int Player::getVictoryPoints() const {
    return victoryPoints;
}

int Player::getEnergyCubes() const {
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

void Player::removeEnergyCubes(int pts) {
    energyCubes -= pts;
}

void Player::addEnergyCubes(int pts) {
    energyCubes += pts;
}

ostream & operator<<(ostream & os, const Player& player){

    os << "----------------------------------------" << endl;
    os << "ID :" << player.getPlayerID() << endl;
    os << "***************" << endl;
    os << "Victory Points :" << player.getVictoryPoints() << endl;
    os << "Life Points :" << player.getLifePoints() << endl;
    os << "Energy Cubes :" << player.getEnergyCubes() << endl;
    os << "----------------------------------------" << endl;
    return os;

}

void Player::addGameToken(GameTokens token) {
    gameTokens.push_back(token);
}

void Player::addBuildingUnitTiles(BuildingUnitTiles tile) {
    buildingUnitTiles.push_back(tile);
}

void Player::assignMonster(MonsterCards card) {
    this->monsterCard = card;
}

void Player::assignBoardFigure(BoardFigures figure) {
    this->boardFigure = figure;
}

void Player::assignDiceObject(Dice dice) {
    this->dice = dice;
}
