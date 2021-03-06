//
// Created by Shawn on 11/18/2018.
//

#include "HumanPlayerStrategy.h"

void HumanPlayerStrategy::execute(Game *game, Player *player)
{

    player->rollDice();
    // resolve the dice (mandatory) ordered
    game->resolvePlayer(player, true);

    if(player->getLifePoints() <= 0) {
        cout << "Player : " << player->getPlayerName() << " died while resolving dice" << endl;
        return;
    }
    // move

    // if player is in manhattan
    if(player->getZone()>0 && player->getZone()<7){
        player->setPhase(Player::Phase::Move);
        std::string choice;
        if(player->getZone() == 1) {  // Manhattan Lower 2-4
            player->setZone(2);
            game->getGameMap()->removeRegionOwner(player);
            game->getGameMap()->setRegionOwner(2, player);
        }
        else if(player->getZone() == 2) {  // Manhattan Midtown 2-4
            player->setZone(3);
            game->getGameMap()->removeRegionOwner(player);
            game->getGameMap()->setRegionOwner(3, player);
        }
        else if(player->getZone() == 3) {  // Manhattan Upper 2-4
            cout << "You are in Upper Manhattan. Do you wish to stay? (Y | N) " << endl;
            cin >> choice;
            if (choice == "N"){
                game->getGameMap()->removeRegionOwner(player);
                game->getGameMap()->move(player);
            }
        }
        else if(player->getZone() == 4) {  // Manhattan Lower 5-6
            player->setZone(5);
            game->getGameMap()->removeRegionOwner(player);
            game->getGameMap()->setRegionOwner(5, player);
        }
        else if(player->getZone() == 5) {  // Manhattan Midtown 5-6
            player->setZone(6);
            game->getGameMap()->removeRegionOwner(player);
            game->getGameMap()->setRegionOwner(6, player);
        }
        else if(player->getZone() == 6) {  // Manhattan Upper 5-6
            cout << "You are in Upper Manhattan. Do you wish to stay? (Y | N) " << endl;
            cin >> choice;
            if (choice == "N"){
                game->getGameMap()->removeRegionOwner(player);
                game->getGameMap()->move(player);
            }
        }


    }
    else { // Not in manhattan
        if(game->getGameMap()->isManhattanEmpty()){ // must move to manhattan if empty
            player->setPhase(Player::Phase::Move);
            if (game->getNumberOfPlayers() < 5){
                player->setZone(1);
                game->getGameMap()->removeRegionOwner(player);
                game->getGameMap()->setRegionOwner(1, player);
                cout << "Player : " << player->getPlayerName() << " is in : " << player->getZoneName() << endl;
            }
            else{
                player->setZone(4);
                game->getGameMap()->removeRegionOwner(player);
                game->getGameMap()->setRegionOwner(4, player);
                cout << "Player : " << player->getPlayerName() << " is in : " << player->getZoneName() << endl;
            }
        }
        else{ // there is atleast 1 player in manhattan
            std::string choice;
            cout << "There is another player in Manhattan" << endl;
            cout << "Do you want to move (M) or stay (S) in current location : " << player->getZoneName() << "?" << endl;
            cin >> choice;
            if (choice == "M"){
                game->getGameMap()->removeRegionOwner(player);
                game->getGameMap()->move(player);
            }

        }

    }

    // buy cards (optional)
    game->buyCards(player);
}
