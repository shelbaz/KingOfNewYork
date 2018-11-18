//
// Created by Shawn on 11/18/2018.
//

#include "GameStatisticsObserver.h"
#include <iostream>
#include <iomanip>
#include "../Player.h"
#include "../Game.h"
using namespace std;

void GameStatisticsObserver::update() {

    int width = 25;
    cout << "Player" ;
    cout << setw(width) << "Owned Zone";
    cout << setw(width) << "Energy Cubes" ;
    cout << setw(width) << "Victory Points" ;
    cout << setw(width) << "Life Points" << endl;
    cout << "--------------------------------------------------------------------------------------------------------------" << endl;

    for(Player* player : Game::players){

        cout << right << setfill(' ') << player->getPlayerName();
        cout << right << setw(width) << player->getZoneName();
        cout << right << setw(width) << player->getEnergyCubes();
        cout << right << setw(width) << player->getVictoryPoints();
        cout << right << setw(width) << player->getLifePoints() << endl;
    }
    cout << endl;
}


