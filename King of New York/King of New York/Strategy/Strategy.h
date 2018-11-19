//
// Created by Shawn on 11/18/2018.
//

#pragma once

#include <iostream>
#include "Player.h"
#include "DeckOfCards.h"

using namespace std;

class Strategy {
public:
    virtual void execute(Player* player, DeckOfCards* deck) = 0;
};


