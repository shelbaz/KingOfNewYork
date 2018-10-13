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


Dice::Dice() {
    srand((unsigned)time(0));
    numberOfRolls = 3;

    map<DiceOptions, int> DiceValues;
    vector< map < DiceOptions, int> > historyOfRolls;

    vector< map < DiceOptions, int> > ::iterator it;
}


Dice::Dice(int playerVal): Dice() {

    playerNumber = playerVal;

}

Dice::DiceOptions Dice::randomDiceOption() {
    return static_cast<DiceOptions>(rand() % DiceOptions::NumOfOptions);

}

void Dice::resetDiceRolls() {
    this->numberOfRolls = 3;

}

void Dice::rollDice(){

    DiceOptions value;
    for(int i=0; i<6; i++)
    {
        value = randomDiceOption();
        this->DiceValues[value] ++;
    }
    storeDiceResult(DiceValues);
    resetDiceValuesMap();
    this->numberOfRolls--;
}

void Dice::rollDice(int amtOfDice) {

    if(this->numberOfRolls == 0 || amtOfDice>6) {
        cout << "No rolls left or invalid number of dice" << endl;
        return;
    }

    else if(this->numberOfRolls == 3) {
        rollDice();
    }
    else{
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

}

void Dice::rollDice(bool testing) {

    if(!testing)
    {return;}

    int numbOfDice;
    cout << "How many dice do you want to roll? \n";
    cin >> numbOfDice;
    this->rollDice(true);

    DiceOptions value;
    for(int i=0; i<numbOfDice; i++)
    {
        value = randomDiceOption();
        this->totalDiceValues[value]++;
    }
    for(int i=0; i<6; i++) {
        cout << this->totalDiceValues[i] << endl;
    }
}

void Dice::storeDiceResult(map<DiceOptions, int> tempDiceValues) {
    historyOfRolls.push_back(tempDiceValues);

}



int Dice::getPlayerNumber() {
    return playerNumber;
}

int Dice::getNumbOfRollsRemaining() {
    return numberOfRolls;
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
