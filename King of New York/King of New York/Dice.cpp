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

// Dice constructor : init random with seed, maxRolls =3
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

// Pick random option from DiceOptions Enum
Dice::DiceOptions Dice::randomDiceOption() {
    return static_cast<DiceOptions>(rand() % DiceOptions::NumOfOptions);

}

// Reset dice rolls after player turn back to 3
void Dice::resetDiceRolls() {
    this->numberOfRolls = 3;

}

//First roll dice of player, default to 6 dice
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

//Second and third roll of player, input amount
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

// Dice roll for testing fairness, can roll unlimited times
void Dice::rollDice(bool testing) {

    if(!testing)
    {return;}

    int numbOfDice;
    cout << "How many dice do you want to roll? \n";
    cin >> numbOfDice;
    DiceOptions value;

    for(int i=0; i<numbOfDice; i++)
    {
        value = randomDiceOption();
        this->totalDiceValues[value]++ ;
    }
    double probability=0.00;
    for(int i=0; i<6; i++) {
        probability = double(this->totalDiceValues[i]) / double(numbOfDice) *100.00 ;
        cout << DiceNames[i] << " : " << this->totalDiceValues[i] << ": Probability = " << probability << "%" <<  endl;
    }
}

//Store history of dice result in Map of {DiceOption-->value}
void Dice::storeDiceResult(map<DiceOptions, int> tempDiceValues) {
    historyOfRolls.push_back(tempDiceValues);
}

int Dice::getPlayerNumber() {
    return playerNumber;
}

int Dice::getNumbOfRollsRemaining() {
    return numberOfRolls;
}

// Reset dice values between rolls
void Dice::resetDiceValuesMap() {
    DiceValues[DiceOptions::Heal] = 0;
    DiceValues[DiceOptions::Attack] = 0;
    DiceValues[DiceOptions::Celebrity] = 0;
    DiceValues[DiceOptions::Destruction] = 0;
    DiceValues[DiceOptions::Energy] = 0;
    DiceValues[DiceOptions::Ouch] = 0;
}

// Print all historical dice values for player
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
