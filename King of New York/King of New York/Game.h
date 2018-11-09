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

using namespace std;

class Game {

public:

    Game();
    ~Game();

    int init_players();
    void init_map();
    void init_all_decks();

    int init_game_dependencies();

    void init_game_loop();
    Player* checkWinCondition();

    vector<Player*> getGamePlayers() { return playersTemp;}
    vector<Player*> getGamePlayersAfter() { return players;}
    DeckOfCards* getGameDeck() {return &deckOfCards;}
    DeckOfGameTokens* getGameTokensDeck() {return &deckOfGameTokens;}
    DeckOfBuildingUnitTiles* getBuildingUnitTilesDeck() {return &deckOfBuildingUnitTiles;}

    void removePlayer(Player* player);
    void changePlayerIndexes();
    Graph<string>* loadMap();
    void determinePlayerOrder();
    int getNumberOfPlayers();
    void setStartingLocationOfPlayers();


private:

    vector<Player*> playersTemp;
    vector<Player*> players;

    Map gameMap;
    MapLoader mapLoader;
    DeckOfCards deckOfCards;
    DeckOfGameTokens deckOfGameTokens;
    DeckOfMonsterCards deckOfMonsterCards;
    DeckOfBuildingUnitTiles deckOfBuildingUnitTiles;

    int numberOfPlayers;


};


