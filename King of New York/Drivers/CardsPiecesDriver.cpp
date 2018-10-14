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

    shared_ptr<DeckOfCards> deckOfCards = DeckOfCards::getInstance();
    shared_ptr<DeckOfBuildingUnitTiles> deckOfBuildingUnitTiles  = DeckOfBuildingUnitTiles::getInstance();
    shared_ptr<DeckOfMonsterCards> deckOfMonsterCards  = DeckOfMonsterCards::getInstance();
    shared_ptr<DeckOfGameTokens> deckOfGameTokens  = DeckOfGameTokens::getInstance();

    deckOfGameTokens->currentState();
    deckOfMonsterCards->currentState();

    deckOfBuildingUnitTiles->currentState();
    deckOfBuildingUnitTiles->shuffle();
    deckOfBuildingUnitTiles->currentState();

    deckOfCards->currentState();
    deckOfCards->shuffle();
    deckOfCards->currentState();




    return 0;
}