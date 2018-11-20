//
// Created by Shawn Elbaz on 2018-10-10.
//

#pragma once

#include <Observer/Subject.h>
#include <Observer/Observer.h>
#include <Observer/GameStatisticsObserver.h>
#include <Observer/PhaseObserver.h>
#include <Strategy/Strategy.h>

#include "Dice.h"
#include "MonsterCards.h"
#include "Cards.h"
#include "GameTokens.h"
#include "BoardFigures.h"
#include "BuildingUnitTiles.h"
#include "DeckOfCards.h"
#include "Game.h"

using namespace std;
class Game;
class Strategy;

class Player: public Subject {

public:
    enum Phase
    {
        Roll,
        Move,
        Buy
    };

private:
    int playerID;
    std::string  playerName;
    Dice dice;
    MonsterCards monsterCard;
    BoardFigures boardFigure;
    vector <Cards> cards;
    vector <GameTokens> gameTokens;
    vector <BuildingUnitTiles> buildingUnitTiles;
    int victoryPoints;
    int lifePoints;
    int energyCubes;
    int ownedZone;
    enum Phase phase;
    Strategy *strategy;
    const vector<std::string > zoneNames = {"Manhattan", "Manhattan Lower 2-4", "Manhattan Midtown 2-4", "Manhattan Upper 2-4",
                               "Manhattan Lower 5-6", "Manhattan Midtown 5-6","Manhattan Upper 5-6", "Bronx", "Queens",
                               "Staten Island", "Brooklyn", "None"};
public:
    Dice &getDice();

    Player();
    ~Player();

    Player(Dice d, int i);
    explicit Player(std::string  s);

    int getPlayerID() const;
    void setPlayerID(int playerId);
    const std::string  &getPlayerName() const;
    void setPlayerName(const std::string  &playerName);

    void rollDice();
    int rollDiceFirst();
    void rollAggressive();
    void attack();

    enum Phase getPhase();
    void setPhase(enum Phase);

    void showStats();
    void buyCards(Cards card);
    void addCard(Cards card);
    bool disposeOfCards();
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

    int getZone();
    void setZone(int zone);
    std::string  getZoneName();

    friend ostream& operator<<(ostream & os, Player* player);
    friend ostream& operator<<(ostream& os, vector<GameTokens> v);
    friend ostream& operator<<(ostream& os, vector<Cards> v);

    const MonsterCards &getMonsterCard() const;

    const BoardFigures &getBoardFigure() const;

    const vector<Cards> &getCards() const;

    const vector<GameTokens> &getGameTokens() const;

    void getGameTokensState();

    void executeStrategy(Game*, Player*);
    void setStrategy(Strategy*);

};
