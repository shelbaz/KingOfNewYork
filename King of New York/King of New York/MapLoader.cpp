//
//  MapLoader.cpp
//  King of New York
//

#include "MapLoader.h"
#include <string>
#include <iostream>

using namespace std;

Map MapLoader::loadMap(string mapFileLocation) {

    ifstream mapFile;
    mapFile.open(mapFileLocation, ios::in);
    cout <<"Loading" <<mapFileLocation<<"as map ..."<< endl;
    int numZones;
    mapFile >> numZones;
    for (int i = 0; i < numZones; i++) {
        string name;
        cout << name <<""<<endl;
        regionPointers.push_back(new Region(name));
    }

}

MapLoader::MapLoader() {
}

MapLoader::~MapLoader() {
}