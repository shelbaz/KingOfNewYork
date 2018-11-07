//
// Created by Shawn Elbaz on 2018-11-05.
//

#pragma once

#include "./Graph/Graph.h"
#include "./Graph/SinglyLinkedList.h"
#include "./Graph/SinglyLinkedListNode.h"
#include <string>
#include "Player.h"

using namespace std;

class Map {

public:

    Map();
    explicit Map(Graph<string>* map);
    Map(Graph<string>* map, int numberOfPlayers);
    ~Map();

    void assignMap(Graph<string>* map, int playerCount);
    void move(int regionNumber);
    void isMoveValid(int regionNumber);
    bool checkManhattan();
    void setRegionOwner(int region, Player* player);
    void initRegionOwners();
    bool isRegionFull(int region);
    void showMap();
    Player* getRegionOwner(int region);
    void setPlayerCount(int playerCount);
    void initPlayersList(vector<Player*>* list);

private:

    int playerCount;
    vector<Player*> playersInGame;
    Graph<string>* gameMap; //the game map
    map<int,vector<Player*>> regionOwners; // region can have max 2 owners (outer).



};


