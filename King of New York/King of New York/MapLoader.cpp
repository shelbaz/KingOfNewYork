//
//  MapLoader.cpp
//  King of New York
//

#include "MapLoader.h"
#include <string>
#include <iostream>
#include "MapLoader.h"

using namespace std;

Map MapLoader::loadMap(string readMapText) {
cout << 'test' << endl;
    ifstream readMap;
    readMap.open(readMapText, ios::in);
    cout << "Loading file " <<readMapText<<" as map ..."<< endl;
    int regQuantity;
    readMap >> regQuantity;
    cout << "Number of regions: " << regQuantity << endl;
    for (int i = 0; i < regQuantity; i++) {
        string name;
        readMap >> name;
        cout << i+1 << ". " << name << " " << endl;
        regions.push_back(new Region(name));
    }

    for(auto & region : regions) {

        int neighbourQuantity;
        readMap >> neighbourQuantity;
        cout << region->getName() << " has " << neighbourQuantity << " neighbours ..." << endl;
        for (int j =0; j < neighbourQuantity; j++) {

            string nameOfNeighbour;
            readMap >> nameOfNeighbour;
            for (int k = 0; k < regions.size(); k++) {
                if ((*regions[k]).getName() == nameOfNeighbour) {
                    cout << "Setting " << ((*regions[k]).getName()) << " as a neighbor of " << region->getName() << endl;
                    (*region).addNeighbour(regions[k]);
                }
            }
        }
    }

    for(auto & region : regions) {

        int zoneQuantity;
        readMap >> zoneQuantity;
        cout << region->getName() << " has " << zoneQuantity << " zones ..." << endl;
        for (int j =0; j < zoneQuantity; j++) {

            string zoneName;
            readMap >> zoneName;
            Zone* zone = new Zone(zoneName);
            cout << "Created zone " << zone->getZoneName() << endl;
            region->addZone(zone);
            cout << "Added " << zone->getZoneName() << " as a zone of region " << region->getRegionName() << endl;
        }
    }

    Map newYork(regions);
    regions.clear();
    return newYork;

}

MapLoader::MapLoader() {
}

MapLoader::~MapLoader() {
}