//
// Created by Shawn Elbaz on 2018-10-12.
//

#include "DeckOfCards.h"
#include "Cards.h"
#include <algorithm>
#include <vector>
#include <iostream>

shared_ptr<DeckOfCards> DeckOfCards::getInstance() {

    static shared_ptr<DeckOfCards> instance{new DeckOfCards};
    return instance;
}


DeckOfCards::DeckOfCards() {
    deck.reserve(64 + 2); // 64 regular + 2 special cards
    for(int i=0; i< 66; i++) {
        Cards card;
//        vector<CardEffects, int> effect;
//        card.setCard(to_string(i), "some description" ,effect, 1);
        deck.push_back(card);
    }

}

void DeckOfCards::shuffle() {
    srand (time(0));
    std::random_shuffle(deck.begin(), deck.end());
}

Cards DeckOfCards::draw() {
    Cards pickedCard = deck[deck.size() -1];
    deck.erase(deck.end());
    return pickedCard;
}

unsigned int DeckOfCards::getSize() {
    return deck.size();
}


void DeckOfCards::currentState() {
    for(int i=0; i<deck.size(); i++){
//        cout << deck[i] << endl;
    }

}




