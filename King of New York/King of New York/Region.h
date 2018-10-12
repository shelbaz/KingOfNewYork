//
//  Region.h
//  King of New York
//

#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Zone;
class Map;

class Region
{
public:

    Region(std::string regionName);
    ~Region();

    std::string getName() const;
    void setName (std::string regionName);
    void addZone (Zone* newZone);
    int getZoneCount() const;
    bool containsZone(Zone* zone);
    void setMap (Map*map);
    std::vector <Zone*> getZone() const;
    void addNeighbour(Region* &region);
    vector<Region*> getNeighbours ();
    vector<Region*> neighbours;
    
private:

    std::string regionName;
    std::vector<Zone*> regionZones;
    Map* map;
};
