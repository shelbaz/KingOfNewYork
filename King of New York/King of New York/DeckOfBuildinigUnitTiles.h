//
// Created by Shawn Elbaz on 2018-10-13.
//

#pragma once

#include <vector>
#include "BuildingUnitTiles.h"

class DeckOfBuildingUnitTiles: public GamePieces {

private:
    vector<BuildingUnitTiles> deck;
    int currentTile;

public:
    DeckOfBuildingUnitTiles();
    void shuffle() override;
    BuildingUnitTiles draw();
    int getSize();
    void currentState();
    void flipTile(BuildingUnitTiles *tile);
    void burnTile(BuildingUnitTiles *tile);
};

