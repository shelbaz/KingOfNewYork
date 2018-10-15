//
//  Map.h
//  King of New York
//

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Zone.h"

class Region;

using namespace std;

// Implements the functionality of King Of New York board game (Functions as a connected graph).

class Map
{
    
public:

    // testing
    Map();
    Map(vector<Region*> newRegions);
    ~Map();
    void addRegionToMap (Region* newRegion);
    void removeRegionFromMap (Region* region);
    int getRegionCount () const;
    void checkNode(Region & currentNode);
    bool isConnected();
    vector<Region*> getMapRegion () const;
    vector<Zone*> getAllZones () const;
    void displayRegionList();
    vector<Region*> mapRegions;
    
private:

    vector<string> visited;
};
