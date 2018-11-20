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
class Player;

class Map {

public:

    Map();
    explicit Map(Graph<string>* map);
    ~Map();

    void assignMap(Graph<string>* map);
    bool move(Player* player);
    bool moveComputer(Player* player, string type);
    bool isManhattanEmpty();
    void setRegionOwner(int region, Player* player);
    void removeRegionOwner(Player* player);
    void initRegionOwners();
    bool isRegionFull(int region);
    void showMap();
    void showMapWithOwners();
    Player* getRegionOwner(int region);

private:

    Graph<std::string>* gameMap; //the game map
    vector<pair<Player*, Player*>> regionOwners;
    Player* nullPlayer;
    Player* emptyPlayer;




};


