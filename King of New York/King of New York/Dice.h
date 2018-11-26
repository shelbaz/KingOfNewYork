//
// Created by Shawn Elbaz on 2018-10-10.
//

#pragma once

#include <vector>
#include <map>
#include <string>
using namespace std;

class Dice {

    const char * DiceNames[6] = { "Energy", "Attack", "Destruction", "Heal", "Celebrity", "Ouch" };

public:
    enum DiceOptions{Energy, Attack, Destruction, Heal, Celebrity, Ouch, NumOfOptions};

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
    map<string, DiceOptions> diceMap = { {"A",DiceOptions::Attack}, {"E",DiceOptions::Energy}, {"D",DiceOptions::Destruction}, {"H",DiceOptions::Heal}, {"C",DiceOptions::Celebrity}, {"O" ,DiceOptions::Ouch} };



public:

    Dice();

    void rollDiceSequence();
    void rollDice();
    void rollDice(int numbOfDice);
    void rollDice(bool testing);
    void rollAggressiveComputer();
    void rollModerateComputer();

    int rollDiceDetermineStart();
    void storeDiceResult(map<DiceOptions, int> tempDiceValues);
    void storeResolvedHand(map<DiceOptions, int> resolvedHand);
    int getPlayerNumber();
    void setPlayerNumber(int);
    void resetDiceValuesMap();
    void resetResolvedHand();
    void resolveDuringHand();
    int addToCount();
    void resetDiceRolls();
    void diceHistoricalValues();
    void diceHistoricalResolvedValues();
    int getNumbOfRollsRemaining();
    void showResolvedHand();
    void addDiceValuesToResolvedHand();
    void setResolvedHandToDiceValues();
    void lastDiceHistoricalResolvedValues();
    DiceOptions randomDiceOption();

    map<int,int> getLastResolvedHand();




};
