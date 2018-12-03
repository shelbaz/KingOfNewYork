
#include "Player.h"
#include "DeckOfBuildinigUnitTiles.h"
#include "DeckOfCards.h"
#include "MonsterCards.h"
#include "GameTokens.h"
#include "Game.h"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    Game game;
    // Choose all computers if you want to have tournament of comps playing against each other
    game.init_game_dependencies();
    game.init_game_loop();
    cout << "Game is over. Thanks for playing" << endl;
    return 0;
}
