
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "MapLoader.h"

using namespace std;

int main(int argc, const char * argv[]) {

    MapLoader ml;
    ml.setFilePath("map.map");
    ml.loadMap();
    cout << ml.getMap()->toString() << endl;
    ml.getMap()->getVertex(3)->setOwner("player 1");

    for (int i = 0; i < ml.getMap()->getVertexCount(); i++)
    {
        /*
        The player will be shown each node, but only the outer and master nodes are valid choices
        */
        cout << (i + 1) << ". " << ml.getMap()->getVertex(i)->toString() << endl;
        // Player can be in all vertices except Manhattan (0) , since it can be in its subvertices

    }
    return 0;
}
