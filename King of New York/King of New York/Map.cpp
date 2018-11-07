//
// Created by Shawn Elbaz on 2018-11-05.
//

#include "Map.h"

Map::Map() {
    initRegionOwners();
}

Map::Map(Graph<string> *map) : Map() {
    this->gameMap = map;

}

Map::Map(Graph<string>* map, int numberOfPlayers): Map(map){
    this->playerCount = numberOfPlayers;
}

Map::~Map() {

}

void Map::initPlayersList(vector<Player*>* list){
    playersInGame = *list;
}

void Map::assignMap(Graph<string> *map, int playerCount) {
    this->gameMap = map;
    this->playerCount = playerCount;
    this->setRegionOwner(0, nullptr); // Cannot own manhattan, only its subregions

}

void Map::move(int regionNumber) {

    if(isRegionFull(regionNumber)){
        throw "You cannot move to that region, it is occupied";
    }

    if (regionNumber+1 > gameMap->getVertexCount()){
        throw "You cannot select a region more than # vertexes";
    }

    if(gameMap->getVertex(regionNumber)->getData() == "inner"){
        throw "You cannot move to an inner Manhattan region explicitly. Select Manhattan (0)";
    }

    if(gameMap->getVertex(regionNumber)->getData() == "master"){
        if(playerCount >4){
            // allow more than 1 player in manhattan
        }
        else {
            // if all manhattan is empty
            if (checkManhattan()){
                setRegionOwner(1, player); // Manhattan 2-4
            }
        }
        // player move to manhattan master object
        // player move to manhattan objects (2-4 & 5-6 regions)
        // should not be allowed to pick. Should have to pick Manhattan (1)
        // If 5-6 players, and 2-4 space is occupied, must be put in 5-6 space
    }
    if(gameMap->getVertex(regionNumber)->getData() == "outer"){
        setRegionOwner(regionNumber, player);
    }

}

void Map::isMoveValid(int regionNumber) {

}

bool Map::checkManhattan() {
    bool check = true;
    for(int i=0; i< gameMap->getVertexCount(); i++) {
        if (gameMap->getVertex(i)->getData() == "inner") {
            if(isRegionFull(i)) {
                check=false;
            }
        }
    }
    return check;
}

void Map::initRegionOwners() {
    for(int i=0; i< gameMap->getVertexCount(); i++) {
        if(gameMap->getVertex(i)->getData() == "outer") {
            regionOwners.insert({i, {nullptr , nullptr}});
        }
        else if (gameMap->getVertex(i)->getData() == "inner") {
            regionOwners.insert({i, {nullptr}});
        }
        else {
            regionOwners.insert({i, {}});
        }
    }
}

void Map::setRegionOwner(int region, Player* player) {
    if(gameMap->getVertex(region)->getData() == "outer") {

            if(regionOwners[region][0] != nullptr && regionOwners[region][1] != nullptr) {
                cout << "Region is full, cannot move there" << endl;
            }
            else {
                if (regionOwners[region][0]== nullptr) {
                    regionOwners[region][0] = player;
                }
                else if(regionOwners[region][1]== nullptr) {
                    regionOwners[region][1] = player;
                }

            }

    }
    else if (gameMap->getVertex(region)->getData() == "inner") {
        if (regionOwners[region][0]== nullptr) {
            regionOwners[region][0] = player;
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
        return nullptr;
    }
    if(regionOwners[region][0] != nullptr) {
        return regionOwners[region][0];
    }
    else if(gameMap->getVertex(region)->getData() == "outer" && regionOwners[region][1] != nullptr) {
        return regionOwners[region][1];
    }
    else {
        return nullptr;
    };
}

bool Map::isRegionFull(int region) {
    if (region==0) { // Manhattan
        return false;
    }
    if(gameMap->getVertex(region)->getData() == "inner" && regionOwners[region][0] != nullptr) {
        return true;
    }
    else if(gameMap->getVertex(region)->getData() == "outer" && regionOwners[region][0] != nullptr && regionOwners[region][1] != nullptr) {
        return true;
    }
    else {
        return false;
    };
}

void Map::showMap() {
    for (int i = 0; i < gameMap->getVertexCount(); i++)
    {
        cout << (i) << ". " << gameMap->getVertex(i)->toString() << endl;
        // Player can be in all vertices except Manhattan (0) , since it can be in its subvertices
    }
}

void Map::setPlayerCount(int playerCount) {
    Map::playerCount = playerCount;
}








