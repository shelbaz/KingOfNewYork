////
//// Created by Shawn Elbaz on 2018-10-13.
////

#include "Player.h"
#include "DeckOfBuildinigUnitTiles.h"
#include "DeckOfCards.h"
#include "MonsterCards.h"
#include "GameTokens.h"
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    //Initialize all decks, cards, tokens, buildings.. etc

    DeckOfCards deckOfCards;
    DeckOfBuildingUnitTiles deckOfBuildingUnitTiles;
    DeckOfMonsterCards deckOfMonsterCards;
    DeckOfGameTokens deckOfGameTokens;

    deckOfCards.currentState();
    deckOfBuildingUnitTiles.currentState();
    deckOfGameTokens.currentState();
    deckOfMonsterCards.currentState();

    //Initialize 3 or N players,
    Dice dice1(1);
    Dice dice2(2);
    // Assign dice objects each to player
    Player player1(dice1);
    Player player2(dice2);
    // choose monster card for each player


    player1.assignMonster(deckOfMonsterCards.draw());
    player2.assignMonster(deckOfMonsterCards.draw());
    cout << player1 << endl;
    cout << player2 << endl;

    deckOfMonsterCards.currentState();

    // assign board figures (optional)

    // Own a zone region
    // Add/ own game token (random)
    player1.addGameToken(deckOfGameTokens.draw());
    player2.addGameToken(deckOfGameTokens.draw());
    cout << "Player 1 Details: " << endl;
    cout << player1 << endl;
    cout << "Player 2 Details: " << endl;
    cout << player2 << endl;


//    // Own cards
    player1.addCard(deckOfCards.draw());

    player2.addCard(deckOfCards.draw());

    cout << "Player 1 Cards Details: " << endl;
    for(auto a : player1.getCards()) {
        cout << a << endl;
    }

    // Get player2 cards details
    cout << "Player 2 Cards Details: " << endl;
    for(auto a : player2.getCards()) {
        cout << a << endl;
    }

    // Ability for each player to :
    // RollDice(),

    player1.rollDice();
    player2.rollDice();
//
//    // ResolveDice(),
//    // Move()
//    // BuyCards : Player 1 and Player 2 does not
    player1.addEnergyCubes(10);

    //Peek top card
    char yesno;
    cout << "Peeking top 3 cards" << endl;
    deckOfCards.showTopThreeCards();
    cout << "Player 1: Do you wish to buy the top card?" << endl;
    cin >> yesno ;
    if(yesno == 'y')
    {
        player1.buyCards(deckOfCards.draw());
    }
    cout << "Peeking top 3 cards" << endl;
    deckOfCards.showTopThreeCards();
    cout << "Player 2: Do you wish to buy the top card?" << endl;
    cin >> yesno ;
    if(yesno == 'y')
    {
        player2.buyCards(deckOfCards.draw());
    }

    // Get player1 cards details
    cout << "Player 1 Cards Details: " << endl;
    for(auto a : player1.getCards()) {
        cout << a << endl;
    }

    // Get player2 cards details
    cout << "Player 2 Cards Details: " << endl;
    for(auto a : player2.getCards()) {
        cout << a << endl;
    }
//
//    // Get player1 details
//    cout << "Player 1 Details: " << endl;
//    cout << player1 << endl;
//
//
//    // Get player2 details
//    cout << "Player 2 Details: " << endl;
//    cout << player2 << endl;



    return 0;
}