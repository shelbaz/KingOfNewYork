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
// class Player; //Used once a player is defined & implemented

class Zone

{
public:

    Zone();
    Zone(const string &zoneName1, string p, const int& i);
    Zone(string zoneName);
    Zone (const string& zoneName);
    //Zone (const string& zoneName, Player* p);
    ~Zone ();
    void setZoneName (const string& name);
    string getZoneName();
    void setOwner (string player);
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


