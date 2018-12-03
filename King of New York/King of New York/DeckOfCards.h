//
// Created by Shawn Elbaz on 2018-10-12.
//

#pragma once
#include "Cards.h"
#include "GamePieces.h"
#include <vector>
#include <string>
#include "./Graph/StringFunctions.h"
#include "Observer/Subject.h"
#include "Observer/CardEffectsObserver.h"



using namespace std;

class CardEffectsObserver;

class DeckOfCards: public GamePieces {

    const static int NUMBER_OF_SPECIAL_CARDS = 2;			// number of special cards
    const static int NUMBER_OF_CARDS = 64;					// number of cards

private:
    vector<Cards>* deck;
    vector<Cards>* specialDeck;
    vector<Cards>* discardedDeck;
    vector<Cards>::iterator it;

    int index;

public:

    DeckOfCards();
    ~DeckOfCards();

    vector<Cards>* getDeck();
    vector<Cards>* getDiscardedDeck();
    vector<Cards>* getSpecialDeck();

    void shuffle() override;
    void showTopCard();
    void showTopThreeCards();
    Cards peekTopCard();
    vector <Cards> topThreeCards();
    void removeTopThreeCards();
    unsigned int getSize();
    void currentState();
    Cards draw();
    Cards draw(Cards const);
    void setCardFile(ifstream& file, vector<Cards>* deck);
    Cards::CardType stringToType(std::string h);
    void displayCardEffect();



};
