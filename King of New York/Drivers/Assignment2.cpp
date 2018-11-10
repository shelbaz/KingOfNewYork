//
// Created by Shawn Elbaz on 2018-11-09.
//
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

void move(Player* player, Map gameMap, int numberOfPlayers) {
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
                cout << "Player : " << player->getPlayerName() << " is in : " << player->getZoneName() << endl;
            }
            else{
                player->setZone(4);
                gameMap.setRegionOwner(4, player);
                cout << "Player : " << player->getPlayerName() << " is in : " << player->getZoneName() << endl;
            }
        }
        else{ // there is atleast 1 player in manhattan
            string choice;
            cout << "There is another player in Manhattan" << endl;
            cout << "Do you want to move (M) or stay (S) in current location : " << player->getZoneName() << "?" << endl;
            cin >> choice;
            if (choice == "M"){
                gameMap.move(player);
            }

        }

    }
}

void diceDriver() {

    // create two dice objects for player 1 and player 2
    Dice dice1;

    // while loop to ask players how many dice they want to roll
    //if they want to keep rolling
    // and stores each dice value
    int selection;
    cout << "Select from the following options:" << endl;
    cout << "1) Normal Player sequence" << endl;
    cout << "2) Roll N number of rolls to see fairness" << endl;
    cin >> selection ;

    switch(selection){
        case 1:
        {

            dice1.rollDiceSequence();

            cout << "thanks for rolling!" << endl;
        }
            break;
        case 2:
        {
            char keepGoing = 'y';
            while (keepGoing == 'y')
            {
                dice1.rollDice(true);

                cout << "Do you want to roll again? type y to continue or n to exit \n";
                cin >> keepGoing;
                cout << "\n";

            }

            cout << "thanks for rolling! " <<endl;
        }
            break;
        default:
            break;
    }
}


int main(int argc, const char * argv[]) {
    Game game;
    int option;
    cout << "Welcome to Assignment 2. Select from the following options : " << endl;
    cout << "1) Game Start" << endl;
    cout << "2) Game Play : Startup phase" << endl;
    cout << "3) Game Play : main loop" << endl;
    cout << "4) Game Play : main loop - roll and resolve dice" << endl;
    cout << "5) Game Play : move" << endl;
    cin >> option;
    switch(option) {
        case 1:
            game.init_game_dependencies();
            game.getGameDeck()->currentState();
            game.getGameTokensDeck()->currentState();
            break;
        case 2:
            game.init_game_dependencies();
            game.getGameDeck()->currentState();
            for (auto player: game.getGamePlayersAfter()){
                cout << *player << endl;
            }
            break;
        case 3:
            game.init_game_dependencies();
            game.init_game_loop();
            break;
        case 4:
            diceDriver();
            break;
        case 5:
            int numberOfPlayers = 0;
            numberOfPlayers = game.init_game_dependencies();
            bool something =  true;
            while(something){
                string answer;
                for (auto player: game.getGamePlayers()){
                    move(player, game.getGameMap(), numberOfPlayers);
                }
                cout << "continue?" << endl;
                cin >> answer ;
                if (answer == "Y" || answer == "y"){
                    continue;
                }
                else if (answer == "N"){
                    something = false;
                    break;
                }
            }
            break;
    }

    return 0;
}


