//
//  Map.hpp
//  King of New York
//


#ifndef Map_hpp
#define Map_hpp

#include <stdio.h>

#endif /* Map_hpp */

#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Zone.hpp"
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
