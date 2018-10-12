//
//  KingOfNewYork.cpp
//  King of New York
//

#include <iostream>
#include <string>
#include "Region.h"
#include "Map.h"
#include "MapLoader.h"


using namespace std;

void createMap (){

    cout <<"Opening map creator:\n" << endl;

    //Creating a map object for the city of New York
    Map newYork;

    //Regions are being defined here:
    Region* manhattan = new Region("Manhattan");
    Region* bronx = new Region("Bronx");
    Region* queens = new Region("Queens");
    Region* brooklyn = new Region("Brooklyn");
    Region* statenIsland = new Region("Staten Island");

    //Borders are being defined for each region:
    manhattan->addNeighbour(bronx);
    manhattan->addNeighbour(queens);
    manhattan->addNeighbour(brooklyn);
    manhattan->addNeighbour(statenIsland);
    bronx->addNeighbour(manhattan);
    bronx->addNeighbour(queens);
    queens->addNeighbour(bronx);
    queens->addNeighbour(manhattan);
    queens->addNeighbour(brooklyn);
    queens->addNeighbour(brooklyn);
    brooklyn->addNeighbour(queens);
    brooklyn->addNeighbour(statenIsland);
    statenIsland->addNeighbour(brooklyn);
    statenIsland->addNeighbour(manhattan);

}

void loadDriver (){

    cout <<"\nOpening map loader driver:\n" <<endl;
    MapLoader mapL1, mapL2;

    //Load Valid Map
    Map newYork = mapL1.loadMap("GoodMap.map");

    //Load Invalid Map
    Map newYorkBad = mapL2.loadMap("BadMap.map");

}


int main () {

    createMap();
    loadDriver();

    return 0;
}

