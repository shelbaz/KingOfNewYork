//
// Created by Shawn Elbaz on 2018-10-11.
//

#pragma once

#import "GamePieces.h"
#import <string>
using namespace std;

class BuildingUnitTiles {

public:
    enum Buildings { HighRise, PowerPlant, Hospital };			// types of buildings
    enum Units { Infantry, Jet, Tank };							// types of units
    enum Rewards { Star, Heart, Energy };						// types of rewards

    // 45 building unit tiles
private:
    Buildings building;
    Units unit;
    int zone;
    int durability;
    int reward;
    Rewards rewardType;
    bool isUnit;
    bool isDestroyed;

public:

    BuildingUnitTiles();
    BuildingUnitTiles(Buildings, Units, int, int, int, Rewards, bool);

    void setBuildingUnitTiles(Buildings, Units, int, int, int, Rewards, bool);
    friend ostream& operator<<(ostream& os, const BuildingUnitTiles& tile);

    Buildings getBuilding() const;

    void setBuilding(Buildings building);

    Units getUnit() const;

    void setUnit(Units unit);

    int getZone() const;

    void setZone(int zone);

    int getDurability() const;

    void setDurability(int durability);

    int getReward() const;

    void setReward(int reward);

    Rewards getRewardType() const;

    void setRewardType(Rewards rewardType);

    bool isIsUnit() const;

    void setIsUnit(bool isUnit);

    bool isIsDestroyed() const;

    void setIsDestroyed(bool isDestroyed);
};
