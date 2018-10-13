//
// Created by Shawn Elbaz on 2018-10-11.
//

#include "GameTokens.h"

const char* GameTokens::getName() const {
    return tokenTypeName[token];
}

GameTokens::GameTokens() {

}

GameTokens::~GameTokens() {

}

GameTokens::GameTokens(TokenTypes name): GameTokens() {
    token = name;
}
