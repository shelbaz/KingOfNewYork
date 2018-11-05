//
// Created by Shawn Elbaz on 2018-11-04.
//

#include "Player.h"
#include "DeckOfBuildinigUnitTiles.h"
#include "DeckOfCards.h"
#include "MonsterCards.h"
#include "GameTokens.h"
#include "Game.h"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    Game game;
    game.init_all_decks();
    int numbOfPlayers = game.init_players();
    vector<Player*> players = game.getGamePlayers();

//    for (int i=0; i< numbOfPlayers; i++){
//        cout << *players[i];
//    }
    game.determinePlayerOrder();
    players = game.getGamePlayersAfter();
    for (int i=0; i< players.size(); i++){
        cout << *players[i];
    }


    cout << "NEW PLAYER ORDER ----------------------------------" << endl;

    for (int i=0; i< players.size(); i++){
        cout << *players[i];
    }

    game.removePlayer(players[3]);
    players = game.getGamePlayersAfter();

    cout << "removed player ----------------------------------" << endl;


    for (int i=0; i< players.size(); i++){
        cout << *players[i];
    }


    return 0;
}
