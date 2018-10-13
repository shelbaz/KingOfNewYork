//
// Created by Shawn Elbaz on 2018-10-11.
//

#include "MonsterCards.h"

MonsterCards::MonsterCards() {

}

MonsterCards::~MonsterCards() {

}

MonsterCards::MonsterCards(MonsterOptions value): MonsterCards() {
    card = value;
}

const char * MonsterCards::getName() {
    return MonsterNames[card];
}