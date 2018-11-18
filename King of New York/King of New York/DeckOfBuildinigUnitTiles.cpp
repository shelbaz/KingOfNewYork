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
    vector<BuildingUnitTiles> deck;
    for(int i=0; i< 45; i++) {
        BuildingUnitTiles tile;
        if(i<15) {
            tile.setBuilding(BuildingUnitTiles::Buildings::HighRise);

            if(i<5){
                tile.setDurability(1);
                tile.setUnit(BuildingUnitTiles::Units::Infantry);
                tile.setReward(1);
                tile.setZone(0);
                deck.push_back(tile);
            }
            else if (i<10){
                tile.setDurability(2);
                tile.setUnit(BuildingUnitTiles::Units::Jet);
                tile.setReward(2);
                tile.setZone(2);
                deck.push_back(tile);
            }
            else{
                tile.setDurability(3);
                tile.setUnit(BuildingUnitTiles::Units::Tank);
                tile.setReward(3);
                tile.setZone(3);
                deck.push_back(tile);
            }
        }
        else if(i>14 && i<30){
            tile.setBuilding(BuildingUnitTiles::Buildings::PowerPlant);

            if(i<20){
                tile.setDurability(1);
                tile.setUnit(BuildingUnitTiles::Units::Infantry);
                tile.setReward(1);
                tile.setZone(8);
                deck.push_back(tile);
            }
            else if (i<25){
                tile.setDurability(2);
                tile.setUnit(BuildingUnitTiles::Units::Jet);
                tile.setReward(2);
                tile.setZone(9);
                deck.push_back(tile);
            }
            else {
                tile.setDurability(3);
                tile.setUnit(BuildingUnitTiles::Units::Tank);
                tile.setReward(3);
                tile.setZone(10);
                deck.push_back(tile);
            }
        }
        else if(i>29){
            tile.setBuilding(BuildingUnitTiles::Buildings::Hospital);

            if(i<35){
                tile.setDurability(1);
                tile.setUnit(BuildingUnitTiles::Units::Infantry);
                tile.setReward(1);
                tile.setZone(7);
                deck.push_back(tile);
            }
            else if (i<40){
                tile.setDurability(2);
                tile.setUnit(BuildingUnitTiles::Units::Jet);
                tile.setReward(2);
                tile.setZone(6);
                deck.push_back(tile);
            }
            else{
                tile.setDurability(3);
                tile.setUnit(BuildingUnitTiles::Units::Tank);
                tile.setReward(3);
                tile.setZone(5);
                deck.push_back(tile);
            }

        }
    }
    shuffle();
    shuffle();

}

// random shuffle deck of building tiles
void DeckOfBuildingUnitTiles::shuffle() {
    srand(time(0));
    std::random_shuffle(deck.begin(), deck.end());
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
    for (BuildingUnitTiles i : deck) {
        cout << i << endl;
    }
}

void DeckOfBuildingUnitTiles::flipTile(BuildingUnitTiles *tile) {
    switch (tile->getUnit()) {
        case BuildingUnitTiles::Infantry: tile->setRewardType(BuildingUnitTiles::Heart); break;
        case BuildingUnitTiles::Jet: tile->setRewardType(BuildingUnitTiles::Energy); break;
        case BuildingUnitTiles::Tank: tile->setRewardType(BuildingUnitTiles::Star); break;
    }

    tile->setDurability(tile->getDurability()+1);
    tile->setIsUnit(true);
}

void DeckOfBuildingUnitTiles::burnTile(BuildingUnitTiles *tile) {
    for (int i = 0; i < 45; i++)
    {
        if (&deck[i] == tile)
        {
            tile->setIsDestroyed(true);
            break;
        }
    }
}
