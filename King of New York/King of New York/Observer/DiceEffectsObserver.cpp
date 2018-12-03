//
// Created by Shawn Elbaz on 2018-11-29.
//

#include "DiceEffectsObserver.h"
#include "Dice.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
using namespace std;


DiceEffectsObserver::DiceEffectsObserver(Subject* subject) {
    concreteSubject = subject;
}

void DiceEffectsObserver::update() {

    dynamic_cast<Dice*>(concreteSubject)->diceHistoricalValues();

    auto currentPlayer = Game::getPlayerByID(dynamic_cast<Dice*>(concreteSubject)->getPlayerNumber());

    map<Dice::DiceOptions, int> unresolvedHand = currentPlayer->getDice()->DiceValues;

    cout << "\n****************************************************************************" << endl;

    cout << "-------------------- CARD EFFECT OBSERVER ----------------------------------"

    cout << "****************************************************************************" << endl;
    cout << "The potential effect of your roll is  : " << endl;

    if(unresolvedHand[Dice::Energy] > 0){ // Energy option
        cout << "Player: "<< currentPlayer->getPlayerName() << " added " << unresolvedHand[Dice::Energy] << " energy points" << endl;
    }

    if(unresolvedHand[Dice::Attack] > 0){ // Attack option
        if(currentPlayer->getZone()>0 && currentPlayer->getZone() < 7) { // In Manhattan
            for(auto tempPlayer : Game::players){
                if(tempPlayer->getZone() > 6){ // All players outside manhattan get -1 health
                    cout << "Player: "<< tempPlayer->getPlayerName() << " removed " << unresolvedHand[Dice::Attack] << " energy points since he is outside manhattan" << endl;
                }
            }
        }
        else if(currentPlayer->getZone() > 6){ // Outside manhattan
            for(auto tempPlayer : Game::players){
                if(tempPlayer->getZone() > 0 && tempPlayer->getZone() < 7){ // All players inside manhattan get -1 health
                    cout << "Player: "<< tempPlayer->getPlayerName() << " removed " << unresolvedHand[Dice::Attack] << " energy points since he is inside manhattan" << endl;
                }
            }
        }
    }

    if(unresolvedHand[Dice::Destruction] > 0) { // Destruction option

    }

    if(unresolvedHand[Dice::Heal] > 0 && currentPlayer->getZone() >6) { // Heal Option
        cout << "Player: "<< currentPlayer->getPlayerName() << " can add " << unresolvedHand[Dice::Heal] << " health points" << endl;

    }

    if(unresolvedHand[Dice::Celebrity] > 0) { // Celebrity Option

    }

    if(unresolvedHand[Dice::Ouch] > 0) { // Ouch Option

    }
    cout << "****************************************************************************" << endl;

}


