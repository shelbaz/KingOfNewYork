cmake_minimum_required(VERSION 3.12)
project(KingOfNewYork)

set(CMAKE_CXX_STANDARD 14)

include_directories("King of New York/King of New York")

add_executable(KingOfNewYork
        "King of New York/King of New York/Map.cpp"
        "King of New York/King of New York/Map.h"
        "King of New York/King of New York/Dice.cpp"
        "King of New York/King of New York/Dice.h"
        "King of New York/Drivers/DiceDriver.cpp"
        "King of New York/King of New York/Player.cpp"
        "King of New York/King of New York/Player.h"
        "King of New York/King of New York/GamePieces.h"
        "King of New York/King of New York/Cards.cpp"
        "King of New York/King of New York/Cards.h"
        "King of New York/King of New York/MonsterCards.cpp"
        "King of New York/King of New York/MonsterCards.h"
        "King of New York/King of New York/GameTokens.cpp"
        "King of New York/King of New York/GameTokens.h"
        "King of New York/King of New York/BuildingUnitTiles.cpp"
        "King of New York/King of New York/BuildingUnitTiles.h"
        "King of New York/King of New York/BoardFigures.h"
        "King of New York/King of New York/DeckOfCards.cpp"
        "King of New York/King of New York/DeckOfCards.h"
        "King of New York/King of New York/DeckOfBuildinigUnitTiles.cpp"
        "King of New York/King of New York/DeckOfBuildinigUnitTiles.h"
        "King of New York/King of New York/Region.cpp"
        "King of New York/King of New York/Region.h"
        "King of New York/King of New York/Zone.cpp"
        "King of New York/King of New York/Zone.h"
        "King of New York/King of New York/MapLoader.cpp"
        "King of New York/King of New York/MapLoader.h"
        "King of New York/Drivers/MapDriver.cpp"
        "King of New York/Drivers/PlayerDriver.cpp"
        "King of New York/Drivers/CardsPiecesDriver.cpp"
        )
