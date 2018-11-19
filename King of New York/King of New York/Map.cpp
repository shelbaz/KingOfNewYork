//
// Created by Shawn Elbaz on 2018-11-05.
//

#include "Map.h"

Player* nullPlayer = new Player("X");
Player* emptyPlayer = new Player("");

Map::Map() {
    vector<pair<Player*, Player*>> regionOwners;
    regionOwners.reserve(11);
    Graph<string>* gameMap;

}

Map::Map(Graph<string> *map) : Map() {
    this->gameMap = map;
    initRegionOwners();
}

Map::~Map() {
}

void Map::assignMap(Graph<string> *map) {
    gameMap = map;
    initRegionOwners();
}

bool Map::move(Player* player) {
    bool success = false;
    bool proceed = true;
    int regionNumber = -1;

    do {
        cout << "Which region do you want to move to ?" << endl;
        showMapWithOwners();
        cin >> regionNumber;

        if (regionNumber < 0){
            cout << "Invalid region, select greater than 0" << endl;
            continue;
        }

        if (regionNumber+1 > gameMap->getVertexCount()){
            cout << "You cannot select a region more than # vertexes" << endl;
            continue;
        }

        if(gameMap->getVertex(regionNumber)->getData() == "inner"){
            cout << "You cannot move to an inner Manhattan region explicitly. Select Manhattan (0)" << endl;
            continue;
        }

        if(isRegionFull(regionNumber)){
            cout << "You cannot move to that region, it is occupied" << endl;
            continue;
        }

        if(gameMap->getVertex(regionNumber)->getData() == "master"){
            // if all manhattan is empty
            setRegionOwner(1, player); // Manhattan 2-4
            player->addVictoryPoints(1); // if move to manhattan, increase victory point of player
            proceed = false;
        }
        // player move to manhattan master object
        // player move to manhattan objects (2-4 & 5-6 regions)
        // should not be allowed to pick. Should have to pick Manhattan (1)
        // If 5-6 players, and 2-4 space is occupied, must be put in 5-6 space

        if(gameMap->getVertex(regionNumber)->getData() == "outer"){
            setRegionOwner(regionNumber, player);
            proceed = false;
            success = true;
        }

    } while(proceed);

    return success;

}

// if returns true, then no one in manhattan
// else manhattan is full = false
bool Map::isManhattanEmpty() {
    bool check = true;
    for(int j=1; j<7; j++){
        if(regionOwners[j].first->getPlayerName() != ""){
            check=false;
        }
    }
    return check;
}

void Map::initRegionOwners() {
    Player* nullPlayer = new Player("X");
    Player* emptyPlayer = new Player("");

    for(int i=0; i< gameMap->getVertexCount(); i++) {
        if(gameMap->getVertex(i)->getData() == "outer") {
            regionOwners.push_back({emptyPlayer, emptyPlayer});
        }
        else if(gameMap->getVertex(i)->getData() == "master") {
            regionOwners.push_back({nullPlayer, nullPlayer});
        }
        else{
            regionOwners.push_back({emptyPlayer, nullPlayer});
        }

    }
}

void Map::setRegionOwner(int region, Player* player) {
    if(gameMap->getVertex(region)->getData() == "outer") {

            if(regionOwners[region].first->getPlayerName() != "" && regionOwners[region].second->getPlayerName() != "") {
                cout << "Region is full, cannot move there" << endl;
            }
            else {
                if (regionOwners[region].first->getPlayerName() == "") {
                    removeRegionOwner(player);
                    regionOwners[region].first = player;
                    player->setZone(region);
                }
                else if(regionOwners[region].second->getPlayerName() == "") {
                    removeRegionOwner(player);
                    regionOwners[region].second = player;
                    player->setZone(region);
                }

            }

    }
    else if (gameMap->getVertex(region)->getData() == "inner") {
        if (regionOwners[region].first->getPlayerName() == "") {
            removeRegionOwner(player);
            regionOwners[region].first = player;
            player->setZone(region);
        }
        else {
            cout << "Region is full, cannot move there" << endl;
        }
    }
    else if (gameMap->getVertex(region)->getData() == "master") {
        cout << "Cannot explicitly move to Manhattan (top level)" << endl;
    }
}

Player* Map::getRegionOwner(int region){
    if (region==0) { // Manhattan
        return regionOwners[0].first;
    }
    else if(gameMap->getVertex(region)->getData() == "outer" && regionOwners[region].second->getPlayerName() != "") {
        return regionOwners[region].second;
    }
    else if(regionOwners[region].first->getPlayerName() != "") {
        return regionOwners[region].first;
    }
    else {
        return regionOwners[region].first;
    };
}



bool Map::isRegionFull(int region) {
    if (region==0) { // Manhattan
        return false;
     }
    if(gameMap->getVertex(region)->getData() == "inner" && regionOwners[region].first->getPlayerName() != "") {
        cout << "Inner manhattan is taken by: "<< regionOwners[region].first->getPlayerName() << endl;
        return true;
    }
    else if(gameMap->getVertex(region)->getData() == "outer")
        return regionOwners[region].first->getPlayerName() != "" && regionOwners[region].second->getPlayerName() != "";
}

void Map::showMap() {
    for (int i = 0; i < gameMap->getVertexCount(); i++)
    {
        cout << (i) << ". " << gameMap->getVertex(i)->toString() << endl;
        // Player can be in all vertices except Manhattan (0) , since it can be in its subvertices
    }
}

void Map::showMapWithOwners() {
    for (int i = 0; i < gameMap->getVertexCount(); i++)
    {
        cout << (i) << ". " << gameMap->getVertex(i)->toString() << " --> {" << regionOwners[i].first->getPlayerName() << " , " << regionOwners[i].second->getPlayerName() << "}" << endl;
        // Player can be in all vertices except Manhattan (0) , since it can be in its subvertices
    }
}

void Map::removeRegionOwner(Player* player) {
    Player* emptyPlayer = new Player("");
    int currentRegion = player->getZone();

    if(currentRegion >0 && currentRegion <7) { // Manhattan
        regionOwners[currentRegion].first = emptyPlayer;
    }
    else if (currentRegion > 6) { // Rest of NY
        if(regionOwners[currentRegion].first == player){ // in first spot
            regionOwners[currentRegion].first = emptyPlayer;
        }
        else if (regionOwners[currentRegion].second == player) { // in second spot
            regionOwners[currentRegion].second = emptyPlayer;
        }
    }
}









