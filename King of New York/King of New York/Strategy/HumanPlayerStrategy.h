//
// Created by Shawn on 11/18/2018.
//

#pragma once

#include "Strategy.h"
#include "Player.h"
#include "DeckOfCards.h"

class HumanPlayerStrategy: public Strategy {
public:
    void execute(Player* player, DeckOfCards deck);
};




