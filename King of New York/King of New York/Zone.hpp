//
//  Zone.hpp
//  King of New York
//


#ifndef Zone_hpp
#define Zone_hpp

#include <stdio.h>

#endif /* Zone_hpp */

#include <iostream>
#include <vector>
#include <string>

class Region;
using std::string;
using std::vector;
// class Player; //Used once a player is defined & implemented

class Zone

{
public:

    Zone ();
    Zone (const string& zoneName);
    Zone (const string& zoneName, Player* p);
    ~Zone ();
    void setZoneName (const string& name);
    string getZoneName();
    void addNeighbour (Zone* zone);
    vector<Zone*> getNeighbours;
    Zone* getNeighbour (const int& index);
    bool isNeighbourOf (Zone* zone);
    // void setOwner (Player* player); //Used once a player is defined & implemented
    // Player* getOwner(); //Used once a player is defined & implemented
    bool belongsToRegion();
    Region* getRegion() const;
    void setRegion (Region* region);
    
private:
    
    string zoneName;
    vector<Zone*> neighbours;
   // Player* owner; //Used once a player is defined & implemented
    Region* region;
};
