//
// Created by Shawn Elbaz on 2018-10-10.
//

#pragma once
#include "Dice.h"
#include "MonsterCards.h"
#include "Cards.h"
#include "GameTokens.h"
#include "BoardFigures.h"
#include "BuildingUnitTiles.h"
#include "DeckOfCards.h"


using namespace std;

class Player {

private:
    int playerID=0;
    Dice dice;
    MonsterCards monsterCard;
    vector <Cards> cards;
//    vector <GameTokens, int> gameTokens;
    BoardFigures boardFigure;
//    vector <BuildingUnitTiles, int> buildingUnitTiles;
    int victoryPoints;
    int lifePoints;
    int energyCubes;

public:

    Player();
    ~Player();

    Player(MonsterCards m, Dice d);

    int getPlayerID() const;
    void rollDice(int numbOfDice);
    void resolveDice();
    void move();
    void buyCards(Cards card);
    void attack();
    int getNumberOfCards();

    void addCard(Cards card);
    int getLifePoints() const;
    int getVictoryPoints() const;
    int getEnergyCubes() const;
    void addLifePoints(unsigned int pts);
    void addVictoryPoints(unsigned int pts);
    void removeLifePoints(int pts);
    void removeVictoryPoints(int pts);

    friend ostream & operator<<(ostream & os, const Player& player);

};
