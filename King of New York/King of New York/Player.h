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
    BoardFigures boardFigure;
    vector <Cards> cards;
    vector <GameTokens> gameTokens;
    vector <BuildingUnitTiles> buildingUnitTiles;
    int victoryPoints;
    int lifePoints;
    int energyCubes;

public:

    Player();
    ~Player();

    Player(Dice d);

    int getPlayerID() const;
    void rollDice(int numbOfDice);
    void resolveDice();
    void move();
    void buyCards(Cards card);
    void attack();

    void addCard(Cards card);
    void addGameToken(GameTokens token);
    void addBuildingUnitTiles(BuildingUnitTiles tile);
    void assignMonster(MonsterCards card);
    void assignBoardFigure(BoardFigures figure);
    void assignDiceObject(Dice dice);

    int getLifePoints() const;
    int getVictoryPoints() const;
    int getEnergyCubes() const;
    int getNumberOfCards();
    void addLifePoints(unsigned int pts);
    void addVictoryPoints(unsigned int pts);
    void removeLifePoints(int pts);
    void removeVictoryPoints(int pts);
    void removeEnergyCubes(int pts);
    void addEnergyCubes(int pts);

    friend ostream & operator<<(ostream & os, const Player& player);

};
