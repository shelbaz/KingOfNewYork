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

    explicit Player(Dice d);

    int getPlayerID() const;

    void rollDice();
    void resolveDice();
    void move();
    void attack();

    void buyCards(Cards card);
    void addCard(Cards card);
    void disposeOfCards();
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

    friend ostream & operator<<(ostream & os, Player& player);
    friend ostream& operator<<(ostream& os, vector<GameTokens> v);
    friend ostream& operator<<(ostream& os, vector<Cards> v);

    const MonsterCards &getMonsterCard() const;

    const BoardFigures &getBoardFigure() const;

    const vector<Cards> &getCards() const;

    const vector<GameTokens> &getGameTokens() const;

    void getGameTokensState();

};
