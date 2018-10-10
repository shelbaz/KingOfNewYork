//
//  Map.cpp
//  King of New York
//


#include "Map.hpp"
#include "Region.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

Map::Map() {
    
}

Map::~Map() {
    
    for (vector<Region*>::iterator it = mapRegions.begin(); it != mapRegions.end(); it++) {
        
        delete *it;
        *it = NULL;
    }
    mapRegions.clear();
}

void Map::addRegionToMap(Region *newRegion) {
    
    vector<Region*>::iterator it = find(mapRegions.begin(), mapRegions.end(), newRegion);
    if (it == mapRegions.end()) {
        
        mapRegions.push_back(newRegion);
        newRegion->setMap(this);
    }
}

void Map::removeRegionFromMap(Region *region) {
    
    vector<Region*>::iterator it = find(mapRegions.begin(), mapRegions.end(), region);
    if (it != mapRegions.end()) {
        
        mapRegions.erase(it);
        region->setMap(NULL);
    }
    
}

int Map::getRegionCount() const {
    
    return mapRegions.size();
}

vector<Region*> Map::getMapRegion() const {
    
    return mapRegions;
}

vector<Zone*> Map::getAllZones() const {
    
    vector<Zone*> allZ;
    for (int i=0; i<mapRegions.size(); i++) {
        
        for (int j=0; j < mapRegions[i]->getZone().size(); j++) {
            
            allZ.push_back(mapRegions [i]->getZone()[j]);
        }
    }
    return allZ;
}
