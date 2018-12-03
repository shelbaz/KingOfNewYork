//
// Created by Shawn Elbaz on 2018-12-03.
//

#include "CardEffectsObserver.h"
#include "DeckOfCards.h"
#include "Cards.h"
#include "Game.h"
#include <iostream>
using namespace std;

CardEffectsObserver::CardEffectsObserver(Subject *subject) {
    concreteSubject = subject;
}

void CardEffectsObserver::update() {

    cout << "\n****************************************************************************" << endl;

    cout << "-------------------- CARD EFFECT OBSERVER ----------------------------------" << endl;

    cout << "****************************************************************************" << endl;
    const vector<Cards> topThree =  dynamic_cast<Game*>(concreteSubject)->getGameDeck()->topThreeCards();

    Cards one = topThree[0];
    Cards two = topThree[1];
    Cards three = topThree[2];
    cout << "Card 1 : " << one << endl;
    cout << "Card 2 : " << two << endl;
    cout << "Card 3 : " << three << endl;


    for (const auto card: topThree){
        cout << "****************************************************************************" << endl;
        cout << "***********   The potential effect of card" << card.getName() << " is : **********************" << endl;
        cout << "****************************************************************************" << endl;
        switch(card.getId()){
            case 0:
                cout << "Player will add 3 victory points IF he rolls more than 2 Ouches" << endl;
                break;
            case 1:

                break;
            case 2:
                cout << "Player will removed 1 energy cube" << endl;
                break;
            case 3:
                cout << "Player will take 4 damage" << endl;
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:
                cout << "Player will add 1 energy cube IF he is in Manhattan" << endl;
                cout << "Player will add 2 victory pts" << endl;
                break;
            case 18:
                cout << "Player will add 1 energy cube IF he is in Brooklyn" << endl;
                cout << "Player will add 3 victory pts" << endl;
                break;
        }
    }


}
