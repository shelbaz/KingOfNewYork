//
// Created by Shawn Elbaz on 2018-10-11.
//

#include "BuildingUnitTiles.h"
#include <iostream>


BuildingUnitTiles::BuildingUnitTiles() {

}

void BuildingUnitTiles::setBuildingUnitTiles(int durability, int reward, string name) {
    this->durability = durability;
    this->reward = reward;
    this->name = name;

}

int BuildingUnitTiles::getDurability() const {
    return durability;
}

int BuildingUnitTiles::getReward() const {
    return reward;
}

const string &BuildingUnitTiles::getName() const {
    return name;
}

ostream & operator<<(ostream & os, const BuildingUnitTiles& tiles){

    os << "----------------------------------------" << endl;
    os << "Name :" << tiles.getName() << endl;
    os << "***************" << endl;
    os << "Durability = " << tiles.getDurability();
    os << "Reward =" << tiles.getReward();
    os << "----------------------------------------" << endl;
    return os;
}




