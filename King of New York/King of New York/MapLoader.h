//
//  MapLoader.h
//  King of New York
//

#pragma once

#include "Map.h"
#include "Region.h"
#include <fstream>

class MapLoader {


    public:

    Map loadMap(string readMapText);
    MapLoader();
    ~MapLoader();

    private:

    vector<Region*> regions;
};