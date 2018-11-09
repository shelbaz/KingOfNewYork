#include <random>

//
// Created by Shawn Elbaz on 2018-10-13.
//

#include "DeckOfBuildinigUnitTiles.h"
#include <algorithm>
#include <vector>
#include <iostream>

// Push 45 unit tiles to Deck (vector): generic name, value, index
DeckOfBuildingUnitTiles::DeckOfBuildingUnitTiles() {
    deck.reserve(45);
    for(int i=0; i< 45; i++) {
        BuildingUnitTiles unitTile;
        unitTile.setBuildingUnitTiles(i, i, to_string(i));
        deck.push_back(unitTile);
    }
}

// random shuffle deck of building tiles
void DeckOfBuildingUnitTiles::shuffle() {
    srand (static_cast<unsigned int>(time(0)));
    std::shuffle(deck.begin(), deck.end(), std::mt19937(std::random_device()()));
}

// draw building card/tile and remove it from deck and then return it
BuildingUnitTiles DeckOfBuildingUnitTiles::draw() {
    BuildingUnitTiles pickedCard = deck[deck.size() -1];
    deck.erase(deck.end()-1);
    return pickedCard;
}

int DeckOfBuildingUnitTiles::getSize() {
    return static_cast<int>(deck.size());
}

// Print entire state of deck
void DeckOfBuildingUnitTiles::currentState() {
    for (const auto &i : deck) {
        cout << i << endl;
    }
}