#include <random>

//
// Created by Shawn Elbaz on 2018-10-12.
//

#include "DeckOfCards.h"
#include "Cards.h"
#include <algorithm>
#include <vector>
#include <iostream>

// Init properties later with a CSV File ****
// Push 66 cards onto the deck
DeckOfCards::DeckOfCards() {
    deck.reserve(64 + 2); // 64 regular + 2 special cards
    for(int i=0; i< 66; i++) {
        Cards card;
        vector<int> effect = {1, 1, 1, 1, 1, 1}; // generic effect vector, will sub in random realistic values later
        card.setCard(to_string(i), "some description" ,effect, 1);
        deck.push_back(card);
    }

}

//shuffle card deck with random fcn
void DeckOfCards::shuffle() {
    srand (static_cast<unsigned int>(time(0)));
    std::shuffle(deck.begin(), deck.end(), std::mt19937(std::random_device()()));
}

// draw card and remove it from deck and then return it
Cards DeckOfCards::draw() {
    Cards pickedCard = deck[deck.size() -1];
    deck.erase(deck.end()-1);
    return pickedCard;
}

unsigned int DeckOfCards::getSize() {
    return unsigned(deck.size());
}

//show current visual state of deck
void DeckOfCards::currentState() {
    for (const auto &i : deck) {
        cout << i << endl;
    }
}

// return top card, does not remove it
Cards DeckOfCards::peekTopCard() {
    Cards pickedCard = deck[deck.size() -1];
    return pickedCard;
}

// print out top card, does not remove it
void DeckOfCards::showTopCard() {
    Cards one = deck[deck.size() -1];
    cout << "Top Card : " << one << endl;
}

// print out top 3 cards, does not remove them
void DeckOfCards::showTopThreeCards() {
    Cards one = deck[deck.size() -1];
    Cards two = deck[deck.size() -2];
    Cards three = deck[deck.size() -3];
    cout << "Card 1 : " << one << endl;
    cout << "Card 2 : " << two << endl;
    cout << "Card 3 : " << three << endl;
}

// return top 3 cards, does not remove it
vector<Cards> DeckOfCards::topThreeCards() {
    vector <Cards> topCards;
    topCards.reserve(3);
    for(int i=0; i<3; i++) {
        topCards.push_back(deck[deck.size()-(i-1)]);
    }

    return topCards;
}

// remove top 3 cards
void DeckOfCards::removeTopThreeCards() {
    vector <Cards> topCards;
    for(int i=0; i<3; i++) {
        deck.erase(deck.end());
    }
}

//Insert card back into deck on bottom
void DeckOfCards::insertBackInDeckBottom(Cards card) {
    deck.insert(deck.begin(), card);
}




