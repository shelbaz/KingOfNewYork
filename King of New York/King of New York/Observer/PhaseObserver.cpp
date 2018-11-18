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
        cout << dynamic_cast<Player*>(concreteSubject)->getPlayerName() << " is moving." << endl;
    } else if (currentPhase == Player::Phase::Buy) {
        cout << dynamic_cast<Player*>(concreteSubject)->getPlayerName() << " is buying cards." << endl;
    } else if (currentPhase == Player::Phase::Roll){
        cout << dynamic_cast<Player*>(concreteSubject)->getPlayerName() << " is rolling." << endl;
    }

}
