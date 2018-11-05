//
// Created by Shawn Elbaz on 2018-11-05.
//

#pragma once

#include "./Graph/Graph.h"
#include <string>
using namespace std;

class Map {

public:

    Map();
    ~Map();

    void assignMap(Graph<string>* map);
    void move();
    void isMoveValid();
    void assignPlayerToZone();
    void assignPlayerToRegion();
    void isNodeFull(); // has 2 players


private:

    int* playerPositions;
    Graph<string>* gameMap; //the game map



};


