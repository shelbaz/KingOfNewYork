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

class Map
{
    
public:

    Map();
    ~Map();
    void addRegionToMap (Region* newRegion);
    void removeRegionFromMap (Region* region);
    int getRegionCount () const;
    std::vector<Region*> getMapRegion () const;
    std::vector<Zone*> getAllZones () const;
    
private:
    
    std::vector<Region*> mapRegions;
};
