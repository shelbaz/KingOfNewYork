//
// Created by Shawn Elbaz on 2018-10-13.
//

#include "DeckOfBuildinigUnitTiles.h"

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
