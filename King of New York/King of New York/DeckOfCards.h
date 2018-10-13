//
// Created by Shawn Elbaz on 2018-10-12.
//

#pragma once
#include "Cards.h"
#include "GamePieces.h"
#include <vector>
#include <string>


using namespace std;

class DeckOfCards: public GamePieces {

private:
    vector<Cards> deck;
    DeckOfCards();
    int index;

public:

    // guarantee that the singleton will not be destroyed until all your static objects that use the singleton no longer need it.
    static shared_ptr<DeckOfCards> getInstance();

    DeckOfCards(DeckOfCards const&) = delete;
    DeckOfCards& operator=(DeckOfCards const&) = delete;

    void shuffle();
    int getSize();
    void currentState();
    Cards draw();


};
