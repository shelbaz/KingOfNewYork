//
// Created by Shawn Elbaz on 2018-10-11.
//

#include "MonsterCards.h"
#include <iostream>

using namespace std;

MonsterCards::MonsterCards(MonsterOptions card): MonsterCards() {
    this->card =card;
}

MonsterCards::MonsterCards() {

}

MonsterCards::~MonsterCards() {

}

MonsterCards::MonsterCards(const MonsterCards &p2) {
    card = p2.card;
}

string MonsterCards::getName() const{
    return MonsterNames[card];
}

void MonsterCards::setMonster(MonsterOptions value){
    this->card = value;
}

// Init constructor of deck of monster cards, from first to last enum set 1 of each monster
DeckOfMonsterCards::DeckOfMonsterCards() {
    deck.reserve(6);
    for(int i=0; i< MonsterCards::EnumEnd; i++) {
        MonsterCards::MonsterOptions current = (MonsterCards::MonsterOptions) i;
        MonsterCards singleCard;
        singleCard.setMonster(current);
        deck.push_back(singleCard);
    }
}

//print state of Deck of Monster cards (should be empty if there are 6 players)
void DeckOfMonsterCards::currentState() {
    for(int i=0; i< deck.size(); i++){
        cout << deck[i] << endl;
    }
}

int DeckOfMonsterCards::getCardIndex(MonsterCards card) {
    it = find(deck.begin(), deck.end(), card);

    if (it != deck.end()) {
        return int(distance(deck.begin(), it));
    }
    else {
        cout << "Element Not Found" << endl;
        return -1;
    }
}

// Draw top card in deck of monster cards
MonsterCards DeckOfMonsterCards::draw() {
    MonsterCards pickedCard = deck[deck.size() -1];
    deck.erase(deck.end()-1);
    return pickedCard;
}

// Draw selected card in deck of monster cards
MonsterCards DeckOfMonsterCards::draw(MonsterCards card) {
    int index = getCardIndex(card);
    if (index > 0) {
        deck.erase(deck.begin() + index);
        return card;
    }
}

const vector<MonsterCards> &DeckOfMonsterCards::getDeck() const {
    return deck;
}

// Overloaded cout operator for Card object
ostream& operator<<(ostream& os, const MonsterCards& card){
    os << "----------------------------------------" << endl;
    os << "Name :" << card.getName() << endl;
    os << "----------------------------------------" << endl;
    return os;
}

// Remove top element of deck
void DeckOfMonsterCards::removeTop() {
    deck.erase(deck.end());
}
