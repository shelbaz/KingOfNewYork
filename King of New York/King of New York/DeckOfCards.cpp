//
// Created by Shawn Elbaz on 2018-10-12.
//

#include "DeckOfCards.h"
#include "Cards.h"
#include <algorithm>
#include <vector>
#include <iostream>


DeckOfCards::DeckOfCards() {
    deck.reserve(64 + 2); // 64 regular + 2 special cards
    for(int i=0; i< 66; i++) {
        Cards card;
        vector<int> effect = {1, 1, 1, 1, 1, 1};
        card.setCard(to_string(i), "some description" ,effect, 1);
        deck.push_back(card);
    }

}

void DeckOfCards::shuffle() {
    srand (time(0));
    std::random_shuffle(deck.begin(), deck.end());
}

Cards DeckOfCards::draw() {
    Cards pickedCard = deck[deck.size() -1];
    deck.erase(deck.end()-1);
    return pickedCard;
}

unsigned int DeckOfCards::getSize() {
    return unsigned(deck.size());
}


void DeckOfCards::currentState() {
    for (int i = 0; i < deck.size(); i++) {
        cout << deck[i] << endl;
    }
}

Cards DeckOfCards::peekTopCard() {
    Cards pickedCard = deck[deck.size() -1];
    return pickedCard;
}

void DeckOfCards::showTopCard() {
    Cards one = deck[deck.size() -1];
    cout << "Top Card : " << one << endl;
}

void DeckOfCards::showTopThreeCards() {
    Cards one = deck[deck.size() -1];
    Cards two = deck[deck.size() -2];
    Cards three = deck[deck.size() -3];
    cout << "Card 1 : " << one << endl;
    cout << "Card 2 : " << two << endl;
    cout << "Card 3 : " << three << endl;
}

vector<Cards> DeckOfCards::topThreeCards() {
    vector <Cards> topCards;
    for(int i=0; i<3; i++) {
        topCards.push_back(deck[deck.size()-(i-1)]);
    }

    return topCards;
}

void DeckOfCards::removeTopThreeCards() {
    vector <Cards> topCards;
    for(int i=0; i<3; i++) {
        deck.erase(deck.end());
    }
}

void DeckOfCards::insertBackInDeckBottom(Cards card) {
    deck.insert(deck.begin(), card);
}




