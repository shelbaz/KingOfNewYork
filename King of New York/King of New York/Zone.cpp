//
//  Zone.cpp
//  King of New York
//

#include "Zone.h"

Zone::Zone(){
    zoneName ="";
}

Zone::Zone(const string &zoneName1) {
    zoneName=zoneName1;

}

Zone::Zone(const string &zoneName1, string p, const int& i) {

    zoneName = zoneName1;
    owner = p;

}

void Zone::setZoneName(const string &zoneName1) {

    zoneName = zoneName1;
}

string Zone::getZoneName() {
    return zoneName;
}


void Zone::setOwner(string player) {

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