//
// Created by Shawn Elbaz on 2018-10-11.
//

#include "BuildingUnitTiles.h"
#include <iostream>

std::string Building[3] = { "High-Rise", "Power Plant", "Hospital" };		// std::string representation of buildings enum
std::string Unit[3] = { "Infantry", "Jet", "Tank" };						// std::string representation of unit enum
std::string Reward[3] = { "Star", "Heart", "Energy" };					// std::string representation of reward enum
std::string zoneNames[12] = {"Manhattan", "Manhattan Lower 2-4", "Manhattan Midtown 2-4", "Manhattan Upper 2-4",
                                  "Manhattan Lower 5-6", "Manhattan Midtown 5-6", "Manhattan Upper 5-6", "Bronx", "Queens",
                                  "Staten Island", "Brooklyn", "None"};

BuildingUnitTiles::BuildingUnitTiles() {
    building = HighRise;
    unit = Infantry;
    zone = 0;
    durability = 1;
    reward = 1;
    rewardType = Rewards::Energy;
    isUnit = false;
    isDestroyed = false;
}

BuildingUnitTiles::BuildingUnitTiles(BuildingUnitTiles::Buildings b, BuildingUnitTiles::Units u, int zone, int durability, int reward,
                                     BuildingUnitTiles::Rewards rewardType, bool isUnit) {
    this->building = b;
    this->unit = u;
    this->zone = zone;
    this->durability = durability;
    this->reward = reward;
    this->rewardType = rewardType;
    this->isUnit = isUnit;

}

void BuildingUnitTiles::setBuildingUnitTiles(BuildingUnitTiles::Buildings b, BuildingUnitTiles::Units u, int zone, int durability, int reward,
                                             BuildingUnitTiles::Rewards rewardType, bool isUnit) {
    this->building = b;
    this->unit = u;
    this->zone = zone;
    this->durability = durability;
    this->reward = reward;
    this->rewardType = rewardType;
    this->isUnit = isUnit;
}

ostream & operator<<(ostream & os, const BuildingUnitTiles& tiles){

    os << "----------------------------------------" << endl;
    os << "Building = " << Building[tiles.getBuilding()] << endl;
    os << "Unit = " << Unit[tiles.getUnit()] << endl;
    os << "Zone = " << zoneNames[tiles.getZone()] << endl;
    os << "***************" << endl;
    os << "Durability = " << tiles.getDurability() << endl;
    os << "Reward =" << tiles.getReward() << endl;
    if (tiles.getReward() > 1)
        cout << "  Reward: " << tiles.getReward() << " " << Reward[tiles.getReward()] << "s\n";
    else
        cout << "  Reward: " << tiles.getReward() << " " << Reward[tiles.getReward()] << endl;
    cout << " Unit Tile: " <<  std::boolalpha << tiles.isUnit << endl;
    cout << " Destroyed: " << std::boolalpha << tiles.isDestroyed << endl;
    os << "----------------------------------------" << endl;
    return os;
}

BuildingUnitTiles::Buildings BuildingUnitTiles::getBuilding() const {
    return building;
}

void BuildingUnitTiles::setBuilding(BuildingUnitTiles::Buildings building) {
    BuildingUnitTiles::building = building;
}

BuildingUnitTiles::Units BuildingUnitTiles::getUnit() const {
    return unit;
}

void BuildingUnitTiles::setUnit(BuildingUnitTiles::Units unit) {
    BuildingUnitTiles::unit = unit;
}

int BuildingUnitTiles::getZone() const {
    return zone;
}

void BuildingUnitTiles::setZone(int zone) {
    BuildingUnitTiles::zone = zone;
}

int BuildingUnitTiles::getDurability() const {
    return durability;
}

void BuildingUnitTiles::setDurability(int durability) {
    BuildingUnitTiles::durability = durability;
}

int BuildingUnitTiles::getReward() const {
    return reward;
}

void BuildingUnitTiles::setReward(int reward) {
    BuildingUnitTiles::reward = reward;
}

BuildingUnitTiles::Rewards BuildingUnitTiles::getRewardType() const {
    return rewardType;
}

void BuildingUnitTiles::setRewardType(BuildingUnitTiles::Rewards rewardType) {
    BuildingUnitTiles::rewardType = rewardType;
}

bool BuildingUnitTiles::isIsUnit() const {
    return isUnit;
}

void BuildingUnitTiles::setIsUnit(bool isUnit) {
    BuildingUnitTiles::isUnit = isUnit;
}

bool BuildingUnitTiles::isIsDestroyed() const {
    return isDestroyed;
}

void BuildingUnitTiles::setIsDestroyed(bool isDestroyed) {
    BuildingUnitTiles::isDestroyed = isDestroyed;
}








