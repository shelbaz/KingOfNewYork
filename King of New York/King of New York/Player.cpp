//
// Created by Shawn Elbaz on 2018-10-10.
//

#include "Player.h"
#include <iostream>

Player::Player() {
    victoryPoints = 0;
    lifePoints= 10;

    Dice dice; // Player dice obj
    MonsterCards monsterCard; // Player monster card
    BoardFigures boardFigure; // Player board fig
    vector <Cards> cards; //List of all deck cards assigned to player (purchased)
    vector <GameTokens> gameTokens; // List of all game tokens assigned to player
    vector <BuildingUnitTiles> buildingUnitTiles; // List of all building tiles assigned to player
}

Player::~Player() {

}

Player::Player(Dice d): Player() {
    this ->dice = d ;
}

int Player::getPlayerID() const {
    return playerID;
}

// Roll dice scenario for all rolls, called by player
void Player::rollDice() {
    // Implement keeping certain number of dice, erasing diceHistorical values past 3
    // Then sum the values for the resolveDice step, total 6 dice
    int numbOfDice=0;
    cout << "Rolling first dice for player, Press enter to confirm" << endl;
    cin.ignore();
    //Roll first dice
    this-> dice.rollDice();
    this-> dice.diceHistoricalValues();
    cout << "How many dice do you want to roll next?" << endl;
    cin >> numbOfDice;
    this->dice.rollDice(numbOfDice);
    this-> dice.diceHistoricalValues();
    cout << "How many dice do you want to roll next?" << endl;
    cin >> numbOfDice;
    this->dice.rollDice(numbOfDice);
    this-> dice.diceHistoricalValues();
    cout << "Player turn is over" << endl;
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

void Player::disposeOfCards() {
    if(getEnergyCubes()>2)
    {
        removeEnergyCubes(3);
        //cards.clear(); // Replace with clear top 3 of deck
    }
    else{
        cout << "You do not have enough energy cubes to dispose of your cards" << endl;
    }
}


void Player::attack() {

}

int Player::getNumberOfCards() {
    return int(cards.size());
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

// Overload print operator for vector of Cards
ostream& operator<<(ostream& os, vector<Cards> v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

// Overload print operator for vector of gameTokens
ostream& operator<<(ostream& os, vector<GameTokens> v)
{
    os << "[";
    for (int i = 0; i < v.size(); ++i) {
        os << v[i];
        if (i != v.size() - 1)
            os << ", ";
    }
    os << "]\n";
    return os;
}

// Overload print operator for Player object
ostream & operator<<(ostream & os, Player& player){

    os << "----------------------------------------" << endl;
    os << "ID :" << player.getPlayerID() << endl;
    os << "***************" << endl;
    os << "Victory Points: " << player.getVictoryPoints() << endl;
    os << "Life Points: " << player.getLifePoints() << endl;
    os << "Energy Cubes: " << player.getEnergyCubes() << endl;
    os << "Monster Card: \n " << player.getMonsterCard() << endl;
    os << "Game Tokens: \n"  << player.getGameTokens() << endl;
    os << "Game Cards: \n"  << player.getCards() << endl;
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

const MonsterCards &Player::getMonsterCard() const {
    return monsterCard;
}

const BoardFigures &Player::getBoardFigure() const {
    return this->boardFigure;
}

const vector<Cards> &Player::getCards() const {
    return this->cards;
}

const vector<GameTokens> &Player::getGameTokens() const {
    return this->gameTokens;
}

void Player::getGameTokensState() {
    for(int i=0; i< gameTokens.size(); i++){
        cout << gameTokens[i] << endl;
    }
}
