//
//  Zone.h
//  King of New York
//

#pragma once

#include <iostream>
#include <vector>
#include <string>

class Region;
using std::string;
using std::vector;

//Implements the functionality of a zone on the map.

class Zone

{
public:

    Zone();
    Zone(string zoneName);
    ~Zone ();
    void setZoneName (const string& name);
    string getZoneName();
    void setOwner (string player);
    string getOwner (string player);
    // Player* getOwner(); //Used once a player is defined & implemented
    bool belongsToRegion();
    Region* getRegion() const;
    void setRegion (Region* region);
    vector<Zone*> neighbour;

private:

    string player; //change to player once shawn adds his stuff
    string owner; //change to player once shawn adds his stuff
    string zoneName;
   // Player* owner; //Used once a player is defined & implemented
    Region* region;
};