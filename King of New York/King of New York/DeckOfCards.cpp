#include <random>

//
// Created by Shawn Elbaz on 2018-10-12.
//

#include "DeckOfCards.h"
#include "Cards.h"
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

// Init properties later with a CSV File ****
// Push 66 cards onto the deck
DeckOfCards::DeckOfCards() {
    deck = new vector<Cards>();
    discardedDeck = new vector<Cards>();
    specialDeck = new vector<Cards>();
    vector<Cards>::iterator it;
    deck->reserve(64); // 64 regular
    specialDeck->reserve(2); //2 special cards

    std::string  fileName= "cards.csv";
    ifstream file(fileName);
    std::string  id, name, lineNum, cost, rewardType, description;

    if(file) {
        for(int j=0; j<NUMBER_OF_SPECIAL_CARDS; j++){
            setCardFile(file,specialDeck);
        }
        while (file.peek()!=EOF)
        {
            setCardFile(file,deck);
        }
        file.close();
    }
    else{
        cout << "Error: Cards File failed to open " << endl;
        exit(1);
    }
    shuffle();
    shuffle();
}

DeckOfCards::~DeckOfCards() {
    delete deck;
    delete discardedDeck;
    delete specialDeck;
    deck=NULL;
    discardedDeck=NULL;
    specialDeck=NULL;
}

//shuffle card deck with random fcn
void DeckOfCards::shuffle() {
    srand(time(0));
    std::random_shuffle(deck->begin(), deck->end());
}

// draw card and remove it from deck and then return it
Cards DeckOfCards::draw() {
    Cards pickedCard = deck->back();
    deck->erase(deck->end()-1);
    discardedDeck->push_back(pickedCard);
    return pickedCard;
}

Cards DeckOfCards::draw(Cards pickedCard) {
    it = std::find(deck->begin(), deck->end(), pickedCard);
//    if(it != deck->end()){
//        auto size = distance(deck->begin(), it);
//        deck->erase(deck->end()-size);
//        discardedDeck->push_back(pickedCard);
//        return pickedCard;
//    }
//    else {
//        cout << "Not in deck" << endl;
//    }
}

unsigned int DeckOfCards::getSize() {
    return unsigned(deck->size());
}

//show current visual state of deck
void DeckOfCards::currentState() {
    for (Cards i : *deck) {
        cout << i << endl;
    }
}

// return top card, does not remove it
Cards DeckOfCards::peekTopCard() {
    Cards pickedCard = deck->back();
    return pickedCard;
}

// print out top card, does not remove it
void DeckOfCards::showTopCard() {
    Cards top = deck->back();
    cout << "Top Card : " << top << endl;
}

// print out top 3 cards, does not remove them
void DeckOfCards::showTopThreeCards() {
    Cards one = deck->back();
    Cards two = deck->at(deck->size() -2);
    Cards three = deck->at(deck->size() -3);
    cout << "Card 1 : " << one << endl;
    cout << "Card 2 : " << two << endl;
    cout << "Card 3 : " << three << endl;
}

// return top 3 cards, does not remove it
vector<Cards> DeckOfCards::topThreeCards() {
    vector <Cards> topCards;
    topCards.reserve(3);
    for(int i=0; i<3; i++) {
        topCards.push_back(deck->at(deck->size()-(i-1)));
    }

    return topCards;
}

// remove top 3 cards
void DeckOfCards::removeTopThreeCards() {
    for(int i=0; i<3; i++) {
        Cards pickedCard = deck->back();
        deck->pop_back();
        specialDeck->push_back(pickedCard);
    }
}

vector<Cards>* DeckOfCards::getDeck() {
    return deck;
}

vector<Cards> *DeckOfCards::getDiscardedDeck() {
    return discardedDeck;
}

vector<Cards> *DeckOfCards::getSpecialDeck() {
    return specialDeck;
}

void DeckOfCards::setCardFile(ifstream& file, vector<Cards>* deck) {
    std::string  name, lineNum, cost, rewardType, description;
    Cards card;
    getline(file, lineNum, ',');
    getline(file, name, ',');
    getline(file, cost, ',');
    getline(file, rewardType, ',');
    getline(file, description);
    card.setCard(stoi(lineNum), name, stoi(cost), stringToType(rewardType), description);
    deck->push_back(card);
}

Cards::CardType DeckOfCards::stringToType(std::string  h) {
    int x = stoi(h);
    switch (x) {
        case 0: return Cards::Empty;
        case 1: return Cards::Goal;
        case 2: return Cards::Keep;
        default: return Cards::Discard;
    }
}






