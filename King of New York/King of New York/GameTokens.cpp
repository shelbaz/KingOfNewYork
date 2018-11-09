//
// Created by Shawn Elbaz on 2018-10-11.
//

#include "GameTokens.h"
#include <iostream>
#include <vector>

using namespace std;

string GameTokens::getName() {
    return tokenTypeName[token];
}

GameTokens::GameTokens() {
    TokenTypes token;
}

GameTokens::GameTokens(TokenTypes name): GameTokens() {
    token = name;
}

void GameTokens::setGameTokens(GameTokens::TokenTypes name) {
    this->token = name;
    this->index++;
}

void GameTokens::setIndex(int index) {
    this->index = index;
}

int GameTokens::getIndex() {
    return this->index;
}

void DeckOfGameTokens::currentState() {
    for(int i=0; i< gameTokens.size(); i++){
        cout << gameTokens[i] << endl;
    }
}

int DeckOfGameTokens::getCardIndex(GameTokens card) {
    auto it = find(gameTokens.begin(), gameTokens.end(), card);

    if (it != gameTokens.end()) {
        int val = distance(gameTokens.begin(), it);
        return val;
    }
    else {
        cout << "Element Not Found" << endl;
        return -1;
    }
}

GameTokens DeckOfGameTokens::draw() {
    GameTokens pickedCard = gameTokens[gameTokens.size() -1];
    gameTokens.erase(gameTokens.end()-1);
    return pickedCard;
}

GameTokens DeckOfGameTokens::draw(GameTokens card) {
    int index = getCardIndex(card);
    if (index > 0) {
        gameTokens.erase(gameTokens.begin() + index);
        return card;
    }
}

ostream& operator<<(ostream& os, GameTokens& card){
    os << "----------------------------------------" << endl;
    os << "Name :" << card.getName() << endl;
    os << "Index :" << card.getIndex() << endl;
    os << "----------------------------------------" << endl;
    return os;
}

// Init DeckOfGameTokens with 46 tokens (13 Web, 13 Jinx, 5 Souvenir, 15 Carapace)
DeckOfGameTokens::DeckOfGameTokens() {

    gameTokens.reserve(46);
    int index=0;
    for(int i=0; i< GameTokens::EnumEnd; i++) {
        GameTokens::TokenTypes current = (GameTokens::TokenTypes) i;
        GameTokens singleCard;
        singleCard.setGameTokens(current);
        switch(current){
            case 0:
                for(int i=0; i< 13; i++){
                    singleCard.setIndex(index++);
                    gameTokens.push_back(singleCard);
                }
                break;
            case 1:
                for(int i=0; i< 13; i++){
                    singleCard.setIndex(index++);
                    gameTokens.push_back(singleCard);
                }
                break;
            case 2:
                for(int i=0; i< 5; i++){
                    singleCard.setIndex(index++);
                    gameTokens.push_back(singleCard);
                }
                break;
            case 3:
                for(int i=0; i< 15; i++){
                    singleCard.setIndex(index++);
                    gameTokens.push_back(singleCard);
                }
                break;
            default:
                break;
        }
    }

}
