#pragma once

#include "./Graph/Graph.h"
#include <string>
using namespace std;

//this header file contains the definition for the map loader class, which provides methods for loading map files
//into the game and outputs a graph that contains the data in the map file

class MapLoader
{
  public:
    MapLoader();
    ~MapLoader();
    Graph<string>* loadMap(); //loads a .map file from a directory into the static graph field of the class
    void setFilePath(string);
    string getFilePath();
    Graph<string>* getMap(); //get the graph containing the game board

  private:
    bool fileIsValid(); //check if the file at the passed file path is valid or not
    int nodeCount; //this is required for creating the graph as we need to know how many nodes are in it
    string filePath; //the file path
    Graph<string>* map; //the game map
};
