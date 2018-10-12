//
//  MapLoader.h
//  King of New York
//

#pragma once

#include "Map.h"
#include "Region.h"
#include <fstream>

class MapLoader {

    private:

    vector<Region*> regionPointers;

    public:

    Map loadMap(string mapFileLocation);
    MapLoader();
    ~MapLoader();
};