//
// Created by Shawn Elbaz on 2018-11-04.
//

#include "Game.h"
#include <iostream>

Game::Game() {
    vector<Player*> playersTemp;
    vector<Player*> players;

    Map gameMap;
    numberOfPlayers = 0;
}

Game::~Game() {

}

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
    gameMap.assignMap(Game::loadMap());
    gameMap.showMap();
}

void Game::init_all_decks() {
    cout << "Initializing Deck of Cards .........." << endl;
    DeckOfCards deckOfCards;
    cout << "Deck of Cards Initialized! .........." << endl;
    cout << "Initializing Deck of Building Unit tiles .........." << endl;
    DeckOfBuildingUnitTiles deckOfBuildingUnitTiles;
    cout << "Deck of Building Unit tiles Initialized! .........." << endl;
    cout << "Initializing Deck of Monster Cards .........." << endl;
    DeckOfMonsterCards deckOfMonsterCards;
    cout << "Deck of Monster Cards Initialized! .........." << endl;
    cout << "Initializing Deck of Game Tokens .........." << endl;
    DeckOfGameTokens deckOfGameTokens;
    cout << "Deck of Game Tokens Initialized! .........." << endl;
}

int Game::init_game_dependencies() {
    int numb;
    cout << "Initializing Map .........." << endl;
    init_map();
    cout << "Map Of New York Initialized!" << endl;

    cout << "Initializing All Decks .........." << endl;
    init_all_decks();
    cout << "All Decks Initialized! .........." << endl;

    numb = init_players();
    cout << "Determining player order .........." << endl;
    determinePlayerOrder();

    setStartingLocationOfPlayers();
    return numb;
}

void Game::init_game_loop() {
    Player* winner = checkWinCondition();

    int nextTurn;
    int proceed;

    while(winner == nullptr) {

        for(Player* player : players){

            cout << "It is Player: " << player->getPlayerName() << "'s Turn .... " << endl;

            // roll the dice (up to 3 times)
            player->rollDice();
            // resolve the dice (mandatory)
//            player->resolveDice();

            if(player->getLifePoints() == 0) {
                cout << "Player : " << player->getPlayerName() << " died while resolving dice" << endl;
                break;
            }
            // move

            // if player is in manhattan
            if(player->getZone()>0 && player->getZone()<7){
                string choice;
                if(player->getZone() == 1) {  // Manhattan Lower 2-4
                    player->setZone(2);
                    gameMap.setRegionOwner(2, player);
                }
                else if(player->getZone() == 2) {  // Manhattan Midtown 2-4
                    player->setZone(3);
                    gameMap.setRegionOwner(3, player);
                }
                else if(player->getZone() == 3) {  // Manhattan Upper 2-4
                    cout << "You are in Upper Manhattan. Do you wish to stay? (Y | N) " << endl;
                    cin >> choice;
                    if (choice == "N"){
                        gameMap.move(player);
                    }
                }
                else if(player->getZone() == 4) {  // Manhattan Lower 5-6
                    player->setZone(5);
                    gameMap.setRegionOwner(5, player);
                }
                else if(player->getZone() == 5) {  // Manhattan Midtown 5-6
                    player->setZone(6);
                    gameMap.setRegionOwner(6, player);
                }
                else if(player->getZone() == 6) {  // Manhattan Upper 5-6
                    cout << "You are in Upper Manhattan. Do you wish to stay? (Y | N) " << endl;
                    cin >> choice;
                    if (choice == "N"){
                        gameMap.move(player);
                    }
                }


            }
            else { // Not in manhattan
                if(gameMap.isManhattanEmpty()){ // must move to manhattan if empty
                    if (numberOfPlayers < 5){
                        player->setZone(1);
                        gameMap.setRegionOwner(1, player);
                    }
                    else{
                        player->setZone(4);
                        gameMap.setRegionOwner(4, player);
                    }
                }
                else{ // there is atleast 1 player in manhattan
                    string choice;
                    cout << "There is another player in Manhattan" << endl;
                    cout << "Do you want to move (M) or stay (S) in current location?" << endl;
                    cin >> choice;
                    if (choice == "M"){
                        gameMap.move(player);
                    }

                }

            }

            // buy cards (optional)
            player->buyCards(); // TODO
            player->showStats();
            winner = checkWinCondition();
            // end turn
        }

    }
    if(winner != nullptr){
        cout << "PLAYER :" << winner->getPlayerName() << " IS THE WINNER !!! " << endl;
        return;
    }

}

void Game::determinePlayerOrder() {

    int highest=0;
    int highestIndex=0;
    int current=0;
    for (int i = 0; i < numberOfPlayers; i++) {
        cout << "Player " << i << " Rolling dice to determine start" << endl;
        cout << "Press enter to roll" << endl;
        cin.ignore();
        current = playersTemp[i]->rollDiceFirst();
        cout << "Rolled " << current << " Attacks!" << endl;
        if(current > highest) {
            highest = current;
            highestIndex = i;
        }
        cout << "Current Highest Roll: " << highest << endl;
        cout << "Highest Roller - Player " << highestIndex << endl;

    }

    cout << "Final Highest Roller - Player " << highestIndex << endl;


    for (int i=highestIndex; i< numberOfPlayers; i++){
        players.push_back(playersTemp[i]);
    }

    for (int j=0; j< highestIndex; j++){
        if(highestIndex == 0) {continue;}
        players.push_back(playersTemp[j]);
    }

    for (int i=0; i< numberOfPlayers; i++){
        cout << *players[i] << endl;
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
    // use find , do not rely on index
    int index = player->getPlayerID();
    players.erase(players.begin() + index);
    changePlayerIndexes();

}

void Game::changePlayerIndexes() {

    for(int i=0; i<players.size(); i++){
        players[i]->setPlayerID(i);
    }

}

int Game::getNumberOfPlayers() {
    return numberOfPlayers;
}

Graph<string>* Game::loadMap() {
    mapLoader.setFilePath("map.map");
    mapLoader.loadMap();
    return mapLoader.getMap();
}

void Game::setStartingLocationOfPlayers() {

    for (auto player : players) {

        bool selected = true;
        while(selected){
            int selection= -1;
            cout << "Which region do you want to start at : << " << player->getPlayerName() << "?" << endl;
            gameMap.showMapWithOwners();
            cin >> selection;

            if(selection == 0){  // Manhattan
                cout << "You cannot start in Manhattan! " << endl;
            }
            else if (selection> 0 && selection<7){ // Manhattan subregions
                cout << "You cannot start in a Manhattan subregion! " << endl;
            }
            else if (selection < 0){ // Manhattan subregions
                cout << "Must select number between 0-10 !" << endl;
            }
            else {
                if(gameMap.isRegionFull(selection)) {
                    cout << "The location you selected is full : Has 2 players in it already " << endl;
                }
                else {
                    gameMap.setRegionOwner(selection, player);
                    selected = false;

                }

            }

        }
        continue;

   }

}





