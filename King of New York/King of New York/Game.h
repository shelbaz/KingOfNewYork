//
// Created by Shawn Elbaz on 2018-11-04.
//

#pragma once

#include "Player.h"
#include "DeckOfBuildinigUnitTiles.h"
#include "DeckOfCards.h"
#include "MonsterCards.h"
#include "GameTokens.h"
#include "Dice.h"
#include "MapLoader.h"
#include "Map.h"
#include "Observer/Subject.h"

using namespace std;
class Player;
class Map;

class Game: public Subject {

public:

    Game();
    ~Game();

    int init_players();
    void init_map();
    void init_all_decks();

    int init_game_dependencies();

    void init_game_loop();
    Player* checkWinCondition();

    static Player* getPlayerByID(int playerId);
    vector<Player*> getGamePlayers() { return playersTemp;}
    static vector<Player*> getGamePlayersAfter() { return players;}
    DeckOfCards* getGameDeck() {return &deckOfCards;}
    DeckOfGameTokens* getGameTokensDeck() {return &deckOfGameTokens;}
    DeckOfBuildingUnitTiles getBuildingUnitTilesDeck() {return deckOfBuildingUnitTiles;}

    void resolvePlayer(Player*, bool);
    void removePlayer(Player*);
    void changePlayerIndexes();
    void determinePlayerOrder();
    int getNumberOfPlayers();
    void setStartingLocationOfPlayers();

    void buyCards(Player*);
    void buyCardsComputer(Player*);

    Map* getGameMap();
    void setPlayerStrategies();
    void assignMonsters();

    static void cardRules(Player*, int);

    static vector<Player*> players;


protected:
    Map* newYork;

    vector<Player*> playersTemp;

    MapLoader mapLoader;
    DeckOfCards deckOfCards;
    DeckOfGameTokens deckOfGameTokens;
    DeckOfMonsterCards deckOfMonsterCards;
    DeckOfBuildingUnitTiles deckOfBuildingUnitTiles;

    int numberOfPlayers;


};


