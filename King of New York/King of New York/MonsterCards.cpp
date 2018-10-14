//
// Created by Shawn Elbaz on 2018-10-11.
//

#include "MonsterCards.h"
#include <iostream>

using namespace std;

MonsterCards::MonsterCards() {
    MonsterOptions card;
}

MonsterCards::~MonsterCards() {

}

string MonsterCards::getName(){
    return MonsterNames[card];
}

void MonsterCards::setMonster(MonsterOptions value){
    this->card = value;
}

DeckOfMonsterCards::DeckOfMonsterCards() {
    deck.reserve(6);
    for(int i=0; i< MonsterCards::EnumEnd; i++) {
        MonsterCards::MonsterOptions current = (MonsterCards::MonsterOptions) i;
        MonsterCards singleCard;
        singleCard.setMonster(current);
        deck.push_back(singleCard);
    }
}

shared_ptr<DeckOfMonsterCards> DeckOfMonsterCards::getInstance() {

    static shared_ptr<DeckOfMonsterCards> instance{new DeckOfMonsterCards};
    return instance;
}

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

MonsterCards DeckOfMonsterCards::draw() {
    MonsterCards pickedCard = deck[deck.size() -1];
    deck.erase(deck.end());
    return pickedCard;
}

MonsterCards DeckOfMonsterCards::draw(MonsterCards card) {
    int index = getCardIndex(card);
    if (index > 0) {
        deck.erase(deck.begin() + index);
        return card;
    }
}

ostream& operator<<(ostream& os, MonsterCards& card){
    os << "----------------------------------------" << endl;
    os << "Name :" << card.getName() << endl;
    os << "----------------------------------------" << endl;
    return os;
}
