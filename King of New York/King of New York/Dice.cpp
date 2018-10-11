//
// Created by Shawn Elbaz on 2018-10-10.
//

#include "Dice.h"
#include <random>
#include <ctime>
#include <vector>
#include <iostream>
#include <string>
using namespace std;


Dice::Dice(int playerVal) {
    srand((unsigned)time(0));

    playerNumber = playerVal;
    numberOfRolls = 3;

    map<DiceOptions, int> DiceValues;
    vector< map < DiceOptions, int> > historyOfRolls;

    vector< map < DiceOptions, int> > ::iterator it;

}

Dice::DiceOptions Dice::randomDiceOption() {
    return static_cast<DiceOptions>(rand() % DiceOptions::NumOfOptions);

}

void Dice::resetDiceRolls() {
    this->numberOfRolls = 3;

}

void Dice::rollDice(int amtOfDice=6) {

    if(this->numberOfRolls == 0)
    {
        return;
    }

    if(this->numberOfRolls == 3)
    {
        amtOfDice=6;
    }

    DiceOptions value;
    for(int i=0; i<amtOfDice; i++)
    {
        value = randomDiceOption();
        this->DiceValues[value] ++;
    }
    storeDiceResult(DiceValues);
    resetDiceValuesMap();
    this->numberOfRolls--;

}

void Dice::storeDiceResult(map<DiceOptions, int> tempDiceValues) {
    historyOfRolls.push_back(tempDiceValues);

}

int Dice::getPlayerNumber() {
    return playerNumber;
}

void Dice::resetDiceValuesMap() {
    DiceValues[DiceOptions::Heal] = 0;
    DiceValues[DiceOptions::Attack] = 0;
    DiceValues[DiceOptions::Celebrity] = 0;
    DiceValues[DiceOptions::Destruction] = 0;
    DiceValues[DiceOptions::Energy] = 0;
    DiceValues[DiceOptions::Ouch] = 0;
}


void Dice::diceHistoricalValues()
{
    cout << "Dice container values for player "<< this->playerNumber  << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (it = historyOfRolls.begin(); it != historyOfRolls.end(); ++it) {
        cout << "Dice Roll # "<< it - historyOfRolls.begin() +1 << endl;
        cout << "-----------------------------------------------------------------" << endl;

        for (map<DiceOptions, int>::iterator mapIt(it->begin()); mapIt != it->end(); ++mapIt) {

            std::cout << DiceNames[mapIt->first] << ", " << mapIt->second << std::endl;
        }
        cout << "-----------------------------------------------------------------" << endl;

    }


}
