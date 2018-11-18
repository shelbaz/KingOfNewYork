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
        if(i<15) {
            deck[i].setBuilding(BuildingUnitTiles::Buildings::HighRise);

            if(i<5){
                deck[i].setDurability(1);
                deck[i].setUnit(BuildingUnitTiles::Units::Infantry);
                deck[i].setReward(1);
                deck[i].setZone(0);
            }
            else if (i<10){
                deck[i].setDurability(2);
                deck[i].setUnit(BuildingUnitTiles::Units::Jet);
                deck[i].setReward(2);
                deck[i].setZone(2);
            }
            else{
                deck[i].setDurability(3);
                deck[i].setUnit(BuildingUnitTiles::Units::Tank);
                deck[i].setReward(3);
                deck[i].setZone(3);
            }
        }
        else if(i>14 && i<30){
            deck[i].setBuilding(BuildingUnitTiles::Buildings::PowerPlant);

            if(i<20){
                deck[i].setDurability(1);
                deck[i].setUnit(BuildingUnitTiles::Units::Infantry);
                deck[i].setReward(1);
                deck[i].setZone(8);
            }
            else if (i<25){
                deck[i].setDurability(2);
                deck[i].setUnit(BuildingUnitTiles::Units::Jet);
                deck[i].setReward(2);
                deck[i].setZone(9);
            }
            else {
                deck[i].setDurability(3);
                deck[i].setUnit(BuildingUnitTiles::Units::Tank);
                deck[i].setReward(3);
                deck[i].setZone(10);
            }
        }
        else if(i>29){
            deck[i].setBuilding(BuildingUnitTiles::Buildings::Hospital);

            if(i<35){
                deck[i].setDurability(1);
                deck[i].setUnit(BuildingUnitTiles::Units::Infantry);
                deck[i].setReward(1);
                deck[i].setZone(7);
            }
            else if (i<40){
                deck[i].setDurability(2);
                deck[i].setUnit(BuildingUnitTiles::Units::Jet);
                deck[i].setReward(2);
                deck[i].setZone(6);
            }
            else{
                deck[i].setDurability(3);
                deck[i].setUnit(BuildingUnitTiles::Units::Tank);
                deck[i].setReward(3);
                deck[i].setZone(5);
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
    for (const auto &i : deck) {
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
