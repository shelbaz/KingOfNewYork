//
//  Zone.cpp
//  King of New York
//


#include "Zone.hpp"

Zone::Zone (){
    zoneName ="";
}

Zone::Zone(const string &zoneName1) {
    zoneName=zoneName1;

}

Zone::Zone(const string &zoneName1, Player* p, const int& i) {

    zoneName = zoneName1;
    owner = p;

}

void Zone::setZoneName(const string &zoneName1) {

    zoneName = zoneName1;
}

string Zone::getZoneName() {
    return zoneName;
}

void <Zone*> Zone* Zone::getNeighbour() {
    return neighbours;
}

bool Zone::isNeighbourOf(Zone *zone) {
    if (neighbours.empty()) {

        return false;

    }

    vector<Zone*> iterator it = find(neighbours.begin(), neighbours.end(), zone);

    return it != neighbours.end();
}

void Zone::setOwner(Player* player) {

    owner=player;
}

bool Zone::belongsToRegion() {

    return region != NULL;
}

Region* Zone::getRegion() const {

    return region;
}

void Zone::setRegion(Region *region1) {

    if (region == NULL) {

        region = region1;
    }
}