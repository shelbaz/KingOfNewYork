//
//  KingOfNewYork.cpp
//  King of New York
//

#include <iostream>
#include <string>
#include "Region.h"
#include "Map.h"
#include "Zone.h"
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

    //Defining zones for Manhattan
    Zone* lower1 = new Zone ("Lower1");
    Zone* lower2 = new Zone ("Lower2");
    Zone* midTown1 = new Zone ("Midtown1");
    Zone* midTown2 = new Zone ("Midtown2");
    Zone* upper1 = new Zone ("Upper1");
    Zone* upper2 = new Zone ("Upper2");

    //Setting up zones inside of Manhattan
    manhattan->addZone(lower1);
    manhattan->addZone(lower2);
    manhattan->addZone(midTown1);
    manhattan->addZone(midTown2);
    manhattan->addZone(upper1);
    manhattan->addZone(upper2);

    //cout<<lower1->getZoneName()<<endl;

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
    brooklyn->addNeighbour(queens);
    brooklyn->addNeighbour(statenIsland);
    statenIsland->addNeighbour(brooklyn);
    statenIsland->addNeighbour(manhattan);

    //Zone* manhattan = new Zone

    //cout <<queens->getName() <<endl;
    //cout <<manhattan->getZone   <<endl;

    vector<Zone*> zone=manhattan->getZone();

    //cout<<zone.size();

    for(int i=0;i<zone.size();i++)
    {
        cout<<zone[i]->getZoneName()<<endl;

    }


}

void loadDriver (){

    cout <<"\nOpening map loader driver:\n" <<endl;
    MapLoader ml;

    //Load Valid Map
    Map newYork = ml.loadMap("/Users/shayan/Xcode Projects/KingOfNewYork/King of New York/King of New York/GoodMap.txt");


}


int main () {

   createMap();
   loadDriver();

    return 0;
}

