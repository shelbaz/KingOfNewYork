//
// Created by Shawn Elbaz on 2018-10-13.
//

#pragma once

#import <vector>
#import "BuildingUnitTiles.h"

class DeckOfBuildingUnitTiles: public GamePieces {

private:
    vector<BuildingUnitTiles> deck;
    DeckOfBuildingUnitTiles();

public:
    static shared_ptr<DeckOfBuildingUnitTiles> getInstance();

    DeckOfBuildingUnitTiles(DeckOfBuildingUnitTiles const&) = delete;
    DeckOfBuildingUnitTiles& operator=(DeckOfBuildingUnitTiles const&) = delete;

    void shuffle() override;
    BuildingUnitTiles draw();
    int getSize();
    void currentState();
};

