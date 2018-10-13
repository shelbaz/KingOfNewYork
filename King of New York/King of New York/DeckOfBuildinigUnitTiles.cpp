//
// Created by Shawn Elbaz on 2018-10-13.
//

#include "DeckOfBuildinigUnitTiles.h"
#include <algorithm>
#include <vector>
#include <iostream>

DeckOfBuildingUnitTiles::DeckOfBuildingUnitTiles() {
    deck.reserve(45);
    for(int i=0; i< 45; i++) {
        BuildingUnitTiles unitTiles;
        unitTiles.setBuildingUnitTiles(i, i, to_string(i));
        deck.push_back(unitTiles);
    }
}

shared_ptr<DeckOfBuildingUnitTiles> DeckOfBuildingUnitTiles::getInstance() {
    static shared_ptr<DeckOfBuildingUnitTiles> instance{new DeckOfBuildingUnitTiles};
    return instance;
}

void DeckOfBuildingUnitTiles::shuffle() {
    srand (time(0));
    std::random_shuffle(deck.begin(), deck.end());
}

BuildingUnitTiles DeckOfBuildingUnitTiles::draw() {
    BuildingUnitTiles pickedCard = deck[deck.size() -1];
    deck.erase(deck.end());
    return pickedCard;
}

int DeckOfBuildingUnitTiles::getSize() {
    return deck.size();
}


void DeckOfBuildingUnitTiles::currentState() {
    for(int i=0; i<deck.size(); i++){
        cout << deck[i] << endl;
    }
}