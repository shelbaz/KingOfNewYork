//
// Created by Shawn Elbaz on 2018-10-10.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Dice.h"

using namespace std;

int main(int argc, const char * argv[]) {

    // create two dice objects for player 1 and player 2
    Dice dice1(1);
    Dice dice2(2);

    // while loop to ask players how many dice they want to roll
    //if they want to keep rolling
    // and stores each dice value
    char keepGoing = 'y';
    int numbOfDice=6;
    while (keepGoing == 'y')
    {

        cout << "Rolling first hand of dice for player" << dice1.getPlayerNumber() << "\n";
        dice1.rollDice(6);
        dice1.diceHistoricalValues();

        while(dice1.getNumbOfRollsRemaining() > 0 || numbOfDice != 0)
        {
            cout << "How many dice do you want to roll? \n";
            cin >> numbOfDice;
            dice1.rollDice(numbOfDice);
            dice1.diceHistoricalValues();

        }
        numbOfDice == 6;

        cout << "Rolling first hand of dice for player" << dice2.getPlayerNumber() << "\n";
        dice2.rollDice(6);
        dice2.diceHistoricalValues();

        while(dice2.getNumbOfRollsRemaining() > 0 || numbOfDice != 0)
        {
            cout << "How many dice do you want to roll? \n";
            cin >> numbOfDice;
            dice2.rollDice(numbOfDice);
            dice1.diceHistoricalValues();

        }
        cout << "Do you want to roll again? type y to continue or n to exit \n";
        cin >> keepGoing;
        cout << "\n";

    }

    cout << "thanks for rolling! players " << dice1.getPlayerNumber() << " & "  << dice2.getPlayerNumber() << "\n" <<endl;

    return 0;
}
