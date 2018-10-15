//
// Created by Shawn Elbaz on 2018-10-11.
//

#pragma once
#include <string>
#include <vector>

using namespace std;

class GameTokens {

    // 46 Tokens:  (13 Web, 13 Jinx, 5 Souvenir, 15 Carapace)

    string tokenTypeName[4] = { "Web", "Jinx", "Souvenir", "Carapace" };

public:
    enum TokenTypes{Web=0, Jinx, Souvenir, Carapace, EnumEnd};
    GameTokens();
    GameTokens(TokenTypes name);
    void setGameTokens(TokenTypes name);
    void setIndex(int index);
    int getIndex();
    ~GameTokens() = default;
    string getName();
    friend ostream& operator<<(ostream& os, GameTokens& card);
    friend bool operator== (const GameTokens& p1, const GameTokens& p2) {
        return true;
    }


private:
    TokenTypes token;
    int index=0;
};

class DeckOfGameTokens {

private:
    vector<GameTokens> gameTokens;
    vector<GameTokens>::iterator it;

public:
    DeckOfGameTokens();
    int getCardIndex(GameTokens card);
    void currentState();
    GameTokens draw();
    GameTokens draw(GameTokens card);

};

