//
// Created by Shawn Elbaz on 2018-11-04.
//

#include "Game.h"
#include <iostream>

int Game::init_players() {

    cout << "Enter number of players (2-6 players)" << endl;

    int number_of_players = 0;
    cin >> number_of_players;
    while (number_of_players < 2 || number_of_players > 6) {
        cout << "Please re-enter a valid number of players (2-6 players)" << endl;
        cin >> number_of_players;
    }

    numberOfPlayers = number_of_players;

    for (int i = 0; i < number_of_players; i++) {
        Dice dice;
        Player* player = new Player(dice, i);
        player->assignMonster(deckOfMonsterCards.draw());
        playersTemp.push_back(player);
    }

    return numberOfPlayers;

}

void Game::init_map() {

}

void Game::init_all_decks() {

    DeckOfCards deckOfCards;
    DeckOfBuildingUnitTiles deckOfBuildingUnitTiles;
    DeckOfMonsterCards deckOfMonsterCards;
    DeckOfGameTokens deckOfGameTokens;

}

void Game::init_game_dependencies() {

}

void Game::init_game_loop() {
    Player* winner = checkWinCondition();

    int nextTurn;
    int proceed;

    while(winner == nullptr) {

        for(Player* player : players){
            // roll the dice (up to 3 times)
            // resolve the dice (mandatory)
            // move
            // buy cards (optional)
            // end turn

        }

        winner = checkWinCondition();

    }

}

void Game::determinePlayerOrder() {

    int highest=0;
    int highestIndex=NULL;
    int current=0;
    for (int i = 0; i < numberOfPlayers; i++) {
        current = playersTemp[i]->rollDiceFirst();
        cout << "Current " << current << endl;
        if(current > highest) {
            highest = current;
            highestIndex = i;
        }
        cout << "Highest: " << highest << endl;
        cout << "Highest Index: " << highestIndex << endl;

    }

    cout << "Final Highest index " << highestIndex << endl;


    for (int i=highestIndex; i< numberOfPlayers; i++){
        players.push_back(players[i]);
    }

    for (int j=0; j< highestIndex; j++){
        if(highestIndex == 0) {continue;}
        players.push_back(players[j]);
    }


}

Player *Game::checkWinCondition() {
    for(Player* player : players) {

        if(players.size() == 1 || player->getVictoryPoints() >= 20){
            return player;
        }

    }

    return nullptr;
}



void Game::removePlayer(Player *player) {
    int index = player->getPlayerID();
    players.erase(players.begin() + index);
    changePlayerIndexes();

}

void Game::changePlayerIndexes() {

    for(int i=0; i<players.size(); i++){
        players[i]->setPlayerID(i);
    }

}
