//
// Created by Shawn Elbaz on 2018-10-10.
//

#pragma once

#include <vector>
#include <map>
#include <string>
using namespace std;

class Dice {

    enum DiceOptions{Energy, Attack, Destruction, Heal, Celebrity, Ouch, NumOfOptions};
    const char * DiceNames[6] = { "Energy", "Attack", "Destruction", "Heal", "Celebrity", "Ouch" };

private:
    int playerNumber;
    int numberOfRolls;
    map<DiceOptions, int> DiceValues = {{Energy, 0}, {Attack, 0}, {Destruction, 0}, {Heal, 0} , {Celebrity, 0} , {Ouch, 0}};
    map<DiceOptions, int>::iterator mapIt;
    map<DiceOptions, int> resolvedHand = {{Energy, 0}, {Attack, 0}, {Destruction, 0}, {Heal, 0} , {Celebrity, 0} , {Ouch, 0}};
    vector< map < DiceOptions, int> > historyOfResolvedRolls;
    vector< map < DiceOptions, int> > historyOfRolls;
    vector< map < DiceOptions, int> > ::iterator it;
    int totalDiceValues[6] = {0,0,0,0,0,0};



public:
    Dice();

    void rollDice();
    void rollDice(int amtOfDice);
    void rollDice(bool testing);
    int rollDiceDetermineStart();
    void storeDiceResult(map<DiceOptions, int> tempDiceValues);
    int getPlayerNumber();
    void setPlayerNumber(int numb);
    void resetDiceValuesMap();
    void resetDiceRolls();
    void diceHistoricalValues();
    int getNumbOfRollsRemaining();
    DiceOptions randomDiceOption();




};
