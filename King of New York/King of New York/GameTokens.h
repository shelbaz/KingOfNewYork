//
// Created by Shawn Elbaz on 2018-10-11.
//

#pragma once
#include <string>

using namespace std;

class GameTokens {

    // 46 Tokens:  (13 Web, 13 Jinx, 5 Souvenir, 15 Carapace)

    enum TokenTypes{Web=0, Jinx, Souvenir, Carapace};
    const char * tokenTypeName[4] = { "Web", "Jinx", "Souvenir", "Carapace" };

private:
    TokenTypes token;

public:
    GameTokens();
    GameTokens(TokenTypes name);
    ~GameTokens();
    const char * getName() const;

};

