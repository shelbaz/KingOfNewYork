cmake_minimum_required(VERSION 3.12)
project(KingOfNewYork)

FIND_PACKAGE( Boost )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

set(CMAKE_CXX_STANDARD 14)

include_directories("King of New York/King of New York")

add_executable(KingOfNewYork
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
        "King of New York/King of New York/Game.cpp"
        "King of New York/King of New York/Game.h"
        "King of New York/King of New York/MapLoader.cpp"
        "King of New York/King of New York/MapLoader.h"
        "King of New York/Drivers/PlayerDriver.cpp"
        "King of New York/Drivers/CardsPiecesDriver.cpp"
        "King of New York/Drivers/GameDriver.cpp"
        "King of New York/Drivers/MapDriver.cpp"
        "King of New York/King of New York/Graph/StringFunctions.h"
        "King of New York/King of New York/Map.cpp"
        "King of New York/King of New York/Map.h"
        "King of New York/Drivers/Assignment2.cpp"
        "King of New York/King of New York/Observer/Observer.h"
        "King of New York/King of New York/Observer/Subject.cpp"
        "King of New York/King of New York/Observer/Subject.h"
        "King of New York/King of New York/Observer/Observer.cpp"
        "King of New York/King of New York/Observer/GameStatisticsObserver.cpp"
        "King of New York/King of New York/Observer/GameStatisticsObserver.h"
        "King of New York/King of New York/Observer/PhaseObserver.cpp"
        "King of New York/King of New York/Observer/PhaseObserver.h" "King of New York/King of New York/Strategy/Strategy.h" "King of New York/King of New York/Strategy/AggressivePlayerStrategy.cpp" "King of New York/King of New York/Strategy/AggressivePlayerStrategy.h" "King of New York/King of New York/Strategy/ModeratePlayerStrategy.cpp" "King of New York/King of New York/Strategy/ModeratePlayerStrategy.h" "King of New York/King of New York/Strategy/HumanPlayerStrategy.cpp" "King of New York/King of New York/Strategy/HumanPlayerStrategy.h")

TARGET_LINK_LIBRARIES( KingOfNewYork LINK_PUBLIC ${Boost_LIBRARIES} )
