//
// Created by Shawn Elbaz on 2018-10-10.
//

#pragma once
#include "Dice.h"
using namespace std;

class Player {

private:
    Dice dice;
    int playerID;

public:
    int getPlayerID();
    void rollDice();
    void resolveDice();
    void move();
    void buyCards();

};
