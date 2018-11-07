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

using namespace std;

class Game {

public:

    int init_players();
    void init_map();
    void init_all_decks();

    void init_game_dependencies();

    void init_game_loop();
    Player* checkWinCondition();

    vector<Player*> getGamePlayers() const { return playersTemp;}
    vector<Player*> getGamePlayersAfter() { return players;}
    DeckOfCards* getGameDeck() {return &deckOfCards;}
    DeckOfGameTokens* getGameTokensDeck() {return &deckOfGameTokens;}
    DeckOfBuildingUnitTiles* getBuildingUnitTilesDeck() {return &deckOfBuildingUnitTiles;}

    void removePlayer(Player* player);
    void changePlayerIndexes();

    void determinePlayerOrder();

    int getNumberOfPlayers();


private:

    vector<Player*> playersTemp;
    vector<Player*> players;

    //    Map game_map;
    DeckOfCards deckOfCards;
    DeckOfGameTokens deckOfGameTokens;
    DeckOfMonsterCards deckOfMonsterCards;
    DeckOfBuildingUnitTiles deckOfBuildingUnitTiles;

    int numberOfPlayers;


};


