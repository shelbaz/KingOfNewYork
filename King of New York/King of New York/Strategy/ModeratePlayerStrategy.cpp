//
// Created by Shawn on 11/18/2018.
//

#include "ModeratePlayerStrategy.h"

void ModeratePlayerStrategy::execute(Game *game, Player *player)
{

    /*
           The moderate player strategy will have this player profile:
               - During dice rolls : Will reroll anything that is not Health or Energy.
               - Resolve dices : Will just resolve in whatever order the dices are returned.
               - Move : Will always try to move to manhattan whenever he has the occasion.
               - Buy cards: Will try to buy a card.
       */

    //TODO: Implement moderate logic

    player->rollModerate();
    // resolve the dice (mandatory) unordered
    game->resolvePlayer(player, false);

    if(player->getLifePoints() == 0) {
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
            game->getGameMap()->setRegionOwner(2, player);
        }
        else if(player->getZone() == 2) {  // Manhattan Midtown 2-4
            player->setZone(3);
            game->getGameMap()->setRegionOwner(3, player);
        }
        else if(player->getZone() == 3) {  // Manhattan Upper 2-4
            game->getGameMap()->move(player);
        }
        else if(player->getZone() == 4) {  // Manhattan Lower 5-6
            player->setZone(5);
            game->getGameMap()->setRegionOwner(5, player);
        }
        else if(player->getZone() == 5) {  // Manhattan Midtown 5-6
            player->setZone(6);
            game->getGameMap()->setRegionOwner(6, player);
        }
        else if(player->getZone() == 6) {  // Manhattan Upper 5-6

            game->getGameMap()->moveComputer(player, "moderate");
        }


    }
    else { // Not in manhattan
        if(game->getGameMap()->isManhattanEmpty()){ // must move to manhattan if empty
            player->setPhase(Player::Phase::Move);
            if (game->getNumberOfPlayers() < 5){
                player->setZone(1);
                game->getGameMap()->setRegionOwner(1, player);
                cout << "Player : " << player->getPlayerName() << " is in : " << player->getZoneName() << endl;
            }
            else{
                player->setZone(4);
                game->getGameMap()->setRegionOwner(4, player);
                cout << "Player : " << player->getPlayerName() << " is in : " << player->getZoneName() << endl;
            }
        }
        else{ // there is atleast 1 player in manhattan
            game->getGameMap()->moveComputer(player, "moderate");
        }

    }

    // buy cards (optional)
    game->buyCardsComputer(player);
}
