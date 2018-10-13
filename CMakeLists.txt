cmake_minimum_required(VERSION 3.12)
project(KingOfNewYork)

set(CMAKE_CXX_STANDARD 14)

include_directories("King of New York/King of New York")

add_executable(KingOfNewYork
        "King of New York/King of New York/Map.cpp"
        "King of New York/King of New York/Map.h"
        "King of New York/King of New York/Region.cpp"
        "King of New York/King of New York/Region.h"
        "King of New York/King of New York/Zone.cpp"
        "King of New York/King of New York/Zone.h" "King of New York/King of New York/MapLoader.cpp" "King of New York/King of New York/MapLoader.h" "King of New York/King of New York/KingOfNewYork.cpp")
