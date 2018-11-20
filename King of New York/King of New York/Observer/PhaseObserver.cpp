//
// Created by Shawn on 11/18/2018.
//

#include "PhaseObserver.h"
#include "Player.h"
#include <iostream>

using namespace std;

PhaseObserver::PhaseObserver(Subject* subject) {
    concreteSubject = subject;
}

void PhaseObserver::update() {
    cout << "It is " << dynamic_cast<Player *>(concreteSubject)->getPlayerName() << "'s turn" << endl;

    Player::Phase currentPhase = (dynamic_cast<Player *>(concreteSubject)->getPhase());

    if (currentPhase == Player::Phase::Move) {
        cout << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
        cout << "| PHASE: " << dynamic_cast<Player*>(concreteSubject)->getPlayerName() << " is rolling. |" << endl;
        cout << "---------------------------------------------------------------------------------------" << endl;
        cout << endl;
    } else if (currentPhase == Player::Phase::Buy) {
        cout << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;
        cout << "| PHASE: " << dynamic_cast<Player*>(concreteSubject)->getPlayerName() << " is buying cards. |" << endl;
        cout << "--------------------------------------------------------------------------------------------" << endl;
        cout << endl;
    } else if (currentPhase == Player::Phase::Roll){
        cout << endl;
        cout << "-----------------------------------" << endl;
        cout << "| PHASE: " << dynamic_cast<Player*>(concreteSubject)->getPlayerName() << " is rolling. |" << endl;
        cout << "-----------------------------------" << endl;
        cout << endl;


    }

}
