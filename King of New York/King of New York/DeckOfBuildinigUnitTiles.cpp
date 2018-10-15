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
        BuildingUnitTiles unitTile;
        unitTile.setBuildingUnitTiles(i, i, to_string(i));
        deck.push_back(unitTile);
    }
}

void DeckOfBuildingUnitTiles::shuffle() {
    srand (time(0));
    std::random_shuffle(deck.begin(), deck.end());
}

BuildingUnitTiles DeckOfBuildingUnitTiles::draw() {
    BuildingUnitTiles pickedCard = deck[deck.size() -1];
    deck.erase(deck.end()-1);
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