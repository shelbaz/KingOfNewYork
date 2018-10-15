//
//  Region.cpp
//  King of New York
//

#include <assert.h>
#include "Region.h"
#include "Zone.h"
#include "Map.h"

using namespace std;

Region::Region(string name) : regionName(name), map(NULL) {
}

Region::~Region(){

}

string Region::getName() const {

    return regionName;
}

void Region::setName(string name){

    regionName = name;
}

int Region::getZoneCount() const {

    return regionZones.size();
}

string Region::getRegionName() const{
    return regionName;
}

void Region::addNeighbour(Region *&region) {
    neighbours.push_back(region);
}

void Region::addZone(Zone *newZone) {
    regionZones.push_back(newZone);
}


void Region::setMap(Map *newMap) {

    if (map == NULL) {

        map = newMap;
    }
}

vector<Zone*> Region::getZone() const {

    return regionZones;

}

Region::Region() {

}

vector<Region*> Region::getNeighbours() {
    return neighbours;
}
