//
// Created by Shawn on 11/18/2018.
//

#pragma once

#include <iostream>
#include "Game.h"
#include "Player.h"
#include "DeckOfCards.h"

using namespace std;

class Strategy {
public:
    virtual void execute(Game *game, Player *player) = 0;
};


