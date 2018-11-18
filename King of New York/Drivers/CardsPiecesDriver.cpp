//
// Created by Shawn Elbaz on 2018-10-13.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "Cards.h"
#include "DeckOfCards.h"
#include "DeckOfBuildinigUnitTiles.h"
#include "BuildingUnitTiles.h"
#include "GameTokens.h"
#include "MonsterCards.h"

using namespace std;

int main(int argc, const char * argv[]) {

    DeckOfCards deckOfCards;
//    DeckOfBuildingUnitTiles deckOfBuildingUnitTiles;
//    DeckOfMonsterCards deckOfMonsterCards;
//    DeckOfGameTokens deckOfGameTokens;

    deckOfCards.currentState();
    deckOfCards.shuffle();
    deckOfCards.currentState();

//    deckOfBuildingUnitTiles.currentState();
//    deckOfBuildingUnitTiles.shuffle();
//    deckOfBuildingUnitTiles.currentState();
//
//    deckOfGameTokens.currentState();
//    deckOfMonsterCards.currentState();

    return 0;
}