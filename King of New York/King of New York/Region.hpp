//
//  Region.hpp
//  King of New York
//


#ifndef Region_hpp
#define Region_hpp

#include <stdio.h>

#endif /* Region_hpp */

#pragma once
#include <iostream>
#include <vector>
#include <string>

class Zone;
class Map;

class Region
{
public:
    
    Region();
    ~Region();
    
    std::string getName() const;
    void setName (std::string regionName);
    void addZone (Zone* newZone);
    int getZoneCount() const;
    bool containsZone(Zone* zone);
    void setMap (Map*map);
    std::vector <Zone*> getZone() const;
    
private:
    
    std::string regionName;
    std::vector<Zone*> regionZones;
    Map* map;
};
