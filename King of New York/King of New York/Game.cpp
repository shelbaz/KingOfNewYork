//
// Created by Shawn Elbaz on 2018-11-04.
//
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <boost/predef.h>
#include "Strategy/ModeratePlayerStrategy.h"
#include "Strategy/AggressivePlayerStrategy.h"
#include "Strategy/HumanPlayerStrategy.h"
#include <algorithm>
#include <vector>
#include <climits>


vector<Player*> Game::players;


Game::Game() {
    vector<Player*> playersTemp;
    Map* newYork = new Map();

    numberOfPlayers = 0;
}

Game::~Game() {

}

int Game::init_players() {

    cout << "Enter number of players (2-6 players)" << endl;
    int number_of_players = 0;
    while(!(cin>> number_of_players && number_of_players > 1 && number_of_players < 7)){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "Please re-enter a valid number of players (2-6 players)" << endl;
    }

    numberOfPlayers = number_of_players;

    for (int i = 0; i < number_of_players; i++) {
        Player* player = new Player(new Dice(), i);
        playersTemp.push_back(player);
    }

    return numberOfPlayers;

}

void Game::init_map() {
    mapLoader.setFilePath("map.map");
    Graph<string>* myMap = mapLoader.loadMap();
    newYork = new Map(myMap);
    newYork->showMap();
}

void Game::init_all_decks() {
    cout << "Initializing Deck of Cards .........." << endl;
    DeckOfCards deckOfCards;
    cout << "Deck of Cards Initialized! .........." << endl;
    deckOfCards.shuffle();
    cout << "Deck of Cards Shuffled! .........." << endl;
    cout << "Initializing Deck of Building Unit tiles .........." << endl;
    DeckOfBuildingUnitTiles deckOfBuildingUnitTiles;
    cout << "Deck of Building Unit tiles Initialized! .........." << endl;
    deckOfBuildingUnitTiles.shuffle();
    cout << "Deck of Building unit tiles Shuffled! .........." << endl;
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
    assignMonsters();
    setStartingLocationOfPlayers();
    setPlayerStrategies();
    return numb;
}

void Game::init_game_loop() {
    Player* winner = checkWinCondition();

    while(winner == nullptr) {

        for(Player* player : players){

            cout << "It is Player: " << player->getPlayerName() << "'s Turn .... " << endl;
            if(player->getLifePoints() <= 0) {
                cout << "Player : " << player->getPlayerName() << " died !" << endl;
                newYork->removeRegionOwner(player);
                player->setPlayerName("");
                removePlayer(player);
                continue;
            }
            // roll the dice (up to 3 times)
            player->executeStrategy(this, player);

            cout << "Player : " << player->getPlayerName() << " turn is over " << endl;
            winner = checkWinCondition();

            // end turn
        }

    }

    cout << "PLAYER :" << winner->getPlayerName() << " IS THE WINNER !!! " << endl;
    return;

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

}

void Game::assignMonsters(){
    for(auto player : players){
        vector<int> assigned;
        int option = -1;
        cout << endl;

        while(option < 0 || option >5 || find(assigned.begin(), assigned.end(),option)!=assigned.end()){
            option = -1;
            cout<< "Player :" << player->getPlayerName() << " , please select an UNASSIGNED Monster card (index)" << endl;
            cout << deckOfMonsterCards << endl;
            cin >> option;
        }
        assigned.push_back(option);
        player->assignMonster(deckOfMonsterCards.getDeck()[option]);
    }

    for (int i=0; i< numberOfPlayers; i++){
        cout << players[i] << endl;
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
    players.erase(std::remove( players.begin(), players.end(), player ), players.end());
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

void Game::setStartingLocationOfPlayers() {

    for (auto player : players) {

        bool selected = true;
        while(selected){
            int selection= -1;
            cout << "Which region do you want to start at : " << player->getPlayerName() << "?" << endl;
            newYork->showMapWithOwners();
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
                if(newYork->isRegionFull(selection)) {
                    cout << "The location you selected is full : Has 2 players in it already " << endl;
                }
                else {
                    newYork->setRegionOwner(selection, player);
                    selected = false;

                }

            }

        }
        continue;

   }

}

void Game::resolvePlayer(Player *player, bool ordered) {

    vector<string> order = {"E", "A", "D", "H", "C", "O"};
    // 0= "Energy", 1="Attack", 2="Destruction", 3="Heal", 4="Celebrity", 5="Ouch"
    cout << "Your hand was the following ---------------- " << endl;
    player->getDice()->lastDiceHistoricalResolvedValues();
    map<int, int> currentHand = {{0, 0},
                                 {1, 0},
                                 {2, 0},
                                 {3, 0},
                                 {4, 0},
                                 {5, 0}};
    currentHand = player->getDice()->getLastResolvedHand();
    if(ordered) {


        cout << "\nWhat is the order you wish to resolve ? " << endl;
        cout << "Choose first letter of character (Any order--> X) OR (Ex: Attack--> A)" << endl;
        for(int i=0; i<6; i++){
            if(currentHand[i] <= 0) {continue;}
            string val="";
            cin >> val;
            transform(val.begin(), val.end(), val.begin(), ::toupper);
            if (val == "X"){
                break;
            }
            else{
                order.clear();
                order.push_back(val);
            }
        }
    }

    for(int i=0; i< order.size(); i++){

        if(order[i] == "E" && currentHand[0] > 0){ // Energy option
            player->addEnergyCubes(currentHand[0]);
            cout << "Player: "<< player->getPlayerName() << " added " << currentHand[0] << " energy points" << endl;
        }

        if(order[i] == "A" && currentHand[1] > 0){ // Attack option
            if(player->getZone()>0 && player->getZone() < 7) { // In Manhattan
                for(auto tempPlayer : players){
                    if(tempPlayer->getZone() > 6){ // All players outside manhattan get -1 health
                        tempPlayer->removeLifePoints(currentHand[1]);
                        cout << "Player: "<< tempPlayer->getPlayerName() << " removed " << currentHand[1] << " energy points since he is outside manhattan" << endl;
                    }
                }
            }
            else if(player->getZone() > 6){ // Outside manhattan
                for(auto tempPlayer : players){
                    if(player->getPlayerName() == tempPlayer->getPlayerName()){
                        continue; // skip yourself if you are in manhattan
                    }
                    if(tempPlayer->getZone() > 0 && tempPlayer->getZone() < 7){ // All players inside manhattan get -1 health
                        tempPlayer->removeLifePoints(currentHand[1]);
                        cout << "Player: "<< tempPlayer->getPlayerName() << " removed " << currentHand[1] << " energy points since he is inside manhattan" << endl;
                    }
                }
            }
        }

        if(order[i] == "D" && currentHand[2] > 0) { // Destruction option

        }

        if(order[i] == "H" && currentHand[3] > 0 && player->getZone() >6) { // Heal Option
            player->addLifePoints(static_cast<unsigned int>(currentHand[3]));
            cout << "Player: "<< player->getPlayerName() << " added " << currentHand[3] << " health points" << endl;

        }

        if(order[i] == "C" && currentHand[4] > 0) { // Celebrity Option

        }

        if(order[i] == "O" && currentHand[5] > 0) { // Ouch Option

        }
    }




}

void Game::buyCards(Player* player) {
    bool proceed = true;
    while(proceed){
        cout << "\n Player: " << player->getPlayerName() << " has " << player->getEnergyCubes() << " energy cubes" <<endl;
        deckOfCards.showTopThreeCards();
        cout << "Do you wish to throw the top three cards? (Y | N)" << endl;
        std::string option;
        cin >> option;
        if (option == "Y" || option == "y") {
            bool response;
            response = player->disposeOfCards();
            if(response){
                deckOfCards.removeTopThreeCards();
            }
        }
        else if(option == "N" || option == "n"){
            proceed = false;
        }
    }

    cout << "Current top 3 cards ------- " << endl;
    deckOfCards.showTopThreeCards();
    std::string option;
    cout << "------------------------------------" << endl;
    cout << "Player: "<< player->getPlayerName() << " has " << player->getEnergyCubes() << " energy cubes" << endl;
    cout << "Does Player: " << player->getPlayerName() << " wish to buy cards? (Y | N) ?" << endl;
    cin >> option;
    if (option == "Y" || option == "y") {
        Cards selectedCard;
        selectedCard = deckOfCards.draw();
        player->buyCards(selectedCard);
        cout << player << endl;
        return;
    }
    else return;

}

void Game::buyCardsComputer(Player* player) {
    for(Cards card: deckOfCards.topThreeCards()) {
        if(card.getEnergyCost() < player->getEnergyCubes()){
            deckOfCards.draw(card);
            player->buyCards(card);
            return;
        }
        else{
            cout << "Cannot afford any cards" << endl;
            return;
        }
    }
}


Map* Game::getGameMap() {
    return newYork;
}

void Game::setPlayerStrategies() {

    for (auto player : players) {

        bool selected = true;
        while(selected){
            int selection= -1;
            cout << "Which strategy do you want for : " << player->getPlayerName() << "?" << endl;
            cout << "1) Human Strategy" << endl;
            cout << "2) Moderate Computer" << endl;
            cout << "3) Aggressive Computer" << endl;
            cin >> selection;

            if(selection == 1){  // Manhattan
                player->setStrategy(new HumanPlayerStrategy());
                selected = false;
            }
            else if (selection==2){ // Manhattan subregions
                player->setStrategy(new ModeratePlayerStrategy());
                selected = false;
            }
            else if (selection==3){ // Manhattan subregions
                player->setStrategy(new AggressivePlayerStrategy());
                selected = false;
            }
            else {
                cout << "That is not a valid option" << endl;
            }

        }
    }

}

Player *Game::getPlayerByID(int playerId) {
    for(auto player: players){
        if(player->getPlayerID() == playerId){
            return player;
        }
    }
}





