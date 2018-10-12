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

    for (vector<Zone*>::iterator it = regionZones.begin(); it != regionZones.end(); it++) {

        delete *it;
        *it = NULL;
    }

    regionZones.clear();

}

string Region::getName() const {

    return regionName;
}

void Region::setName(string name){

    regionName = name;
}

void Region::addZone(Zone *newZone) {

    assert(newZone != NULL);

    if (!containsZone(newZone) && !newZone->belongsToRegion()) {

        regionZones.push_back(newZone);
        newZone->setRegion(this);
    }
}

int Region::getZoneCount() const {

    return regionZones.size();
}

bool Region::containsZone(Zone *zone) {

    vector<Zone*>::iterator it = find(regionZones.begin(), regionZones.end(), zone);

    return it != regionZones.end();
}

void Region::setMap(Map *newMap) {

    if (map == NULL) {

        map = newMap;
    }
}

vector<Zone*> Region::getZone() const {

    return regionZones;

}
