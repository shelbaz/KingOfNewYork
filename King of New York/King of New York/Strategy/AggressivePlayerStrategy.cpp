//
// Created by Shawn on 11/18/2018.
//

#include "AggressivePlayerStrategy.h"

void AggressivePlayerStrategy::execute(Game *game, Player *player) {

    /*
		The aggressive player strategy will have this player profile:
			- During dice rolls : Will reroll anything that is not Destruction or Attack.
			- Resolve dices : Will just resolve in whatever order the dices are returned.
			- Move : Will always try to get out off manhattan whenever he has the occasion, if not in manhattan will stay same position.
			- Buy cards: Will always try to buy a card.
	*/
    //TODO: Implement aggressive logic

    player->rollDice();
    // resolve the dice (mandatory)
    game->resolvePlayer(player);

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
            game->getGameMap().setRegionOwner(2, player);
        }
        else if(player->getZone() == 2) {  // Manhattan Midtown 2-4
            player->setZone(3);
            game->getGameMap().setRegionOwner(3, player);
        }
        else if(player->getZone() == 3) {  // Manhattan Upper 2-4
            cout << "You are in Upper Manhattan. Do you wish to stay? (Y | N) " << endl;
            cin >> choice;
            if (choice == "N"){
                game->getGameMap().move(player);
            }
        }
        else if(player->getZone() == 4) {  // Manhattan Lower 5-6
            player->setZone(5);
            game->getGameMap().setRegionOwner(5, player);
        }
        else if(player->getZone() == 5) {  // Manhattan Midtown 5-6
            player->setZone(6);
            game->getGameMap().setRegionOwner(6, player);
        }
        else if(player->getZone() == 6) {  // Manhattan Upper 5-6
            cout << "You are in Upper Manhattan. Do you wish to stay? (Y | N) " << endl;
            cin >> choice;
            if (choice == "N"){
                game->getGameMap().move(player);
            }
        }


    }
    else { // Not in manhattan
        if(game->getGameMap().isManhattanEmpty()){ // must move to manhattan if empty
            player->setPhase(Player::Phase::Move);
            if (game->getNumberOfPlayers() < 5){
                player->setZone(1);
                game->getGameMap().setRegionOwner(1, player);
                cout << "Player : " << player->getPlayerName() << " is in : " << player->getZoneName() << endl;
            }
            else{
                player->setZone(4);
                game->getGameMap().setRegionOwner(4, player);
                cout << "Player : " << player->getPlayerName() << " is in : " << player->getZoneName() << endl;
            }
        }
        else{ // there is atleast 1 player in manhattan
            std::string choice;
            cout << "There is another player in Manhattan" << endl;
            cout << "Do you want to move (M) or stay (S) in current location : " << player->getZoneName() << "?" << endl;
            cin >> choice;
            if (choice == "M"){
                game->getGameMap().move(player);
            }

        }

    }

    // buy cards (optional)
    game->buyCards(player);

}
