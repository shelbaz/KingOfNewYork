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

using namespace std;

class Region
{
public:

    Region();
    Region(string regionName);
    ~Region();

    std::string getName() const;
    void setName (std::string regionName);
    void addZone (Zone* newZone);
    int getZoneCount() const;
    //bool containsZone(Zone* zone);
    void setMap (Map*map);
    vector <Zone*> getZone() const;
    void addNeighbour(Region* &region);
    vector<Region*> getNeighbours ();
    vector<Region*> neighbours;
    string getRegionName() const;
    
private:

    string regionName;
    vector<Zone*> regionZones;
    Map* map;
};
