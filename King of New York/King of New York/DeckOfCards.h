//
// Created by Shawn Elbaz on 2018-10-12.
//

#pragma once
#include "Cards.h"
#include "GamePieces.h"
#include <vector>
#include <string>


using namespace std;

class DeckOfCards: public GamePieces {

    const static int NUMBER_OF_SPECIAL_CARDS = 2;			// number of special cards
    const static int NUMBER_OF_CARDS = 64;					// number of cards

private:
    vector<Cards>* deck;
    vector<Cards>* specialDeck;
    vector<Cards>* discardedDeck;
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
    void setCardFile(ifstream& file, vector<Cards>* deck);
    Cards::CardType stringToType(std::string  h);



};
