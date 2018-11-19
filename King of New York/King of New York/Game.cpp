//
// Created by Shawn Elbaz on 2018-11-04.
//

#include "Game.h"
#include <iostream>
#include <boost/predef.h>

vector<Player*> Game::players;

Game::Game() {
    vector<Player*> playersTemp;

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

    setStartingLocationOfPlayers();
    return numb;
}

void Game::init_game_loop() {
    Player* winner = checkWinCondition();

    while(winner == nullptr) {

        for(Player* player : players){

            cout << "It is Player: " << player->getPlayerName() << "'s Turn .... " << endl;

            // roll the dice (up to 3 times)
            player->rollDice();
            // resolve the dice (mandatory)
            resolvePlayer(player);

            if(player->getLifePoints() == 0) {
                cout << "Player : " << player->getPlayerName() << " died while resolving dice" << endl;
                break;
            }
            // move

            // if player is in manhattan
            if(player->getZone()>0 && player->getZone()<7){
                player->setPhase(Player::Phase::Move);
                std::string choice;
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
                    player->setPhase(Player::Phase::Move);
                    if (numberOfPlayers < 5){
                        player->setZone(1);
                        gameMap.setRegionOwner(1, player);
                        cout << "Player : " << player->getPlayerName() << " is in : " << player->getZoneName() << endl;
                    }
                    else{
                        player->setZone(4);
                        gameMap.setRegionOwner(4, player);
                        cout << "Player : " << player->getPlayerName() << " is in : " << player->getZoneName() << endl;
                    }
                }
                else{ // there is atleast 1 player in manhattan
                    std::string choice;
                    cout << "There is another player in Manhattan" << endl;
                    cout << "Do you want to move (M) or stay (S) in current location : " << player->getZoneName() << "?" << endl;
                    cin >> choice;
                    if (choice == "M"){
                        gameMap.move(player);
                    }

                }

            }

            // buy cards (optional)
            buyCards(player);

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

    mapLoader.setFilePath("C:\\Users\\Shawn\\Desktop\\Repos\\KingOfNewYork\\King of New York\\King of New York\\map.map");
    mapLoader.loadMap();
    return mapLoader.getMap();
}

void Game::setStartingLocationOfPlayers() {

    for (auto player : players) {

        bool selected = true;
        while(selected){
            int selection= -1;
            cout << "Which region do you want to start at : " << player->getPlayerName() << "?" << endl;
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

void Game::resolvePlayer(Player *player) {

     int order[5];
    // 0= "Energy", 1="Attack", 2="Destruction", 3="Heal", 4="Celebrity", 5="Ouch"
    map<int, int> currentHand = {{0, 0}, {1, 0}, {2, 0}, {3, 0} , {4, 0} , {5, 0}};
    currentHand = player->getDice().getLastResolvedHand();
    cout << "Your hand was the following ---------------- " << endl;
    player->getDice().lastDiceHistoricalResolvedValues();
//  cout << "What is the order you wish to resolve ?" << endl;
//  cin >> order[0] >> order[1] >> order[2] >> order[3] >> order[4];


    if(currentHand[0] > 0){ // Energy option
        player->addEnergyCubes(currentHand[0]);
        cout << "Player: "<< player->getPlayerName() << " added " << currentHand[0] << " energy points" << endl;
    }

    if(currentHand[1] > 0){ // Attack option
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
                if(tempPlayer->getZone() > 0 && tempPlayer->getZone() < 7){ // All players inside manhattan get -1 health
                    tempPlayer->removeLifePoints(currentHand[1]);
                    cout << "Player: "<< tempPlayer->getPlayerName() << " removed " << currentHand[1] << " energy points since he is inside manhattan" << endl;
                }
            }
        }
    }

    if(currentHand[2] > 0) { // Destruction option

    }

    if(currentHand[3] > 0 && player->getZone() >6) { // Heal Option
        player->addLifePoints(static_cast<unsigned int>(currentHand[3]));
        cout << "Player: "<< player->getPlayerName() << " added " << currentHand[3] << " health points" << endl;

    }

    if(currentHand[4] > 0) { // Celebrity Option

    }

    if(currentHand[5] > 0) { // Ouch Option

    }


}

void Game::buyCards(Player* player) {
    bool proceed = true;
    while(proceed){
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
    cout << "Does Player: " << player->getPlayerName() << " wish to buy cards? (Y | N)" << endl;
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

Map &Game::getGameMap() {
    return gameMap;
}





