//
// Created by Shawn Elbaz on 2018-10-11.
//

#pragma once

#import <string>
using namespace std;

class BuildingUnitTiles {

    // 45 building unit tiles
private:
    int durability;
    int reward;
    string name;

public:
    BuildingUnitTiles();
    ~BuildingUnitTiles();

    void setBuildingUnitTiles(int durability, int reward, string name);


};
