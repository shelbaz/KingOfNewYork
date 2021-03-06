//
// Created by Shawn Elbaz on 2018-10-10.
//

#include "Dice.h"
#include <random>
#include <ctime>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Dice constructor : init random with seed, maxRolls =3
Dice::Dice() {
    srand((unsigned)time(0));
    numberOfRolls = 3;

    map<DiceOptions, int> DiceValues;
    vector< map < DiceOptions, int> > historyOfRolls;

    vector< map < DiceOptions, int> > ::iterator it;

    // Attach the observer
    attach(new DiceEffectsObserver(this));

}

Dice::~Dice() {

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

    resolveDuringHand();

    storeDiceResult(DiceValues);
    resetDiceValuesMap();
    this->numberOfRolls--;
}

void Dice::resolveDuringHand() {
    string keep;
    int keepNumber;
    string next = "Y";

    if (this->getNumbOfRollsRemaining() == 0) {
        return;
    }
    if (this->getNumbOfRollsRemaining() == 1 && addToCount() == 0) {
        cout << "Selected None on 2nd role, forcing 3rd role and keeping" << endl;
        resetResolvedHand();
        setResolvedHandToDiceValues();
        return;
    }
    if (getNumbOfRollsRemaining() == 2) {
        string answer;
        cout << "Do you want to throw your 1st roll keeps to select more dice on 3rd roll? (Y or N)" << endl;
        cin >> answer;
        if (answer == "Y" || answer == "Yes" || answer == "y") {
            resetResolvedHand();
        }
        else if (addToCount()==6 && (answer == "N" || answer == "n" || answer == "NO" || answer == "No" || answer == "no")){
            return;
        }
    }

    if(getNumbOfRollsRemaining() == 1 && addToCount()==6) {
        next = "N";
    }

    if(getNumbOfRollsRemaining() == 1) {
        showResolvedHand();
        cout << "You must select a total of 6 cards to resolve the hand" << endl;
    }

    while (next == "YES" || next == "Y") {
        if(getNumbOfRollsRemaining() != 1) {
            cout << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << left << "| " << "Which dice do you want to keep?" << endl;
            cout << "------------------------------------------------------------------" << endl;
            cout << left << "| " << "All - Type: All , this will discard roll 2 & 3" << endl;
            cout << left << "| " << "None - Type: None or N, this will force the next roll" << endl;
            cout << left << "| " << "Some - Type first letter of type (Dice Type: Char) Ex= A for Attacks..." << endl;
            cout << "------------------------------------------------------------------" << endl;

        }

        if(getNumbOfRollsRemaining() == 1) {
            cout << "Rest - Type: Rest , this will take the rest of roll 3 and add it to current resolved" << endl;
        }
        cin >> keep;
        transform(keep.begin(), keep.end(), keep.begin(), ::toupper);
        if(keep == "All" || keep == "ALL") {
            if(getNumbOfRollsRemaining() > 1 ) {
                addDiceValuesToResolvedHand();
                break;
            }
            else{
                resetResolvedHand();
                setResolvedHandToDiceValues();
                break;
            }
        }

        if(keep == "NONE" || keep == "None" || keep == "N") {
            next = "N";
            break;
        }
        if ((keep == "Rest" || keep == "rest" || keep == "REST") && getNumbOfRollsRemaining() == 1)  {
            addDiceValuesToResolvedHand();
            next = "N";
            continue;
        }

        else {
            cout << "How many of the selected dice do you want to keep? Ex= 2 for 2 Attacks  " << endl;
            cin >> keepNumber;
            if(DiceValues[diceMap[keep]] < keepNumber)
            {
                cout << "You cannot select more than is currently available" << endl;
                continue;
            }
            resolvedHand[diceMap[keep]] += keepNumber;
            if(getNumbOfRollsRemaining() == 1 && addToCount()==6) {
                next = "N";
                continue;
            }
            cout << "Do you have another selection for dice you wish to keep? Y=Yes, N=No  " << endl;
            cin >> next;
            transform(next.begin(), next.end(), next.begin(), ::toupper);
            if(next == "N" || next == "NO"){
                return;
            }
            if (getNumbOfRollsRemaining() == 1 && addToCount()!=6){
            showResolvedHand();
            cout << "You must select a total of 6 cards to finish with. Please select more cards" << endl;
            next = "Y";
            continue;
            }
        }

    }
}

void Dice::setResolvedHandToDiceValues() {
    resolvedHand[DiceOptions::Attack] = DiceValues[DiceOptions::Attack];
    resolvedHand[DiceOptions::Heal] = DiceValues[DiceOptions::Heal];
    resolvedHand[DiceOptions::Energy] = DiceValues[DiceOptions::Energy];
    resolvedHand[DiceOptions::Ouch] = DiceValues[DiceOptions::Ouch];
    resolvedHand[DiceOptions::Destruction] = DiceValues[DiceOptions::Destruction];
    resolvedHand[DiceOptions::Celebrity] = DiceValues[DiceOptions::Celebrity];
}

void Dice::addDiceValuesToResolvedHand() {
    resolvedHand[DiceOptions::Attack] += DiceValues[DiceOptions::Attack];
    resolvedHand[DiceOptions::Heal] += DiceValues[DiceOptions::Heal];
    resolvedHand[DiceOptions::Energy] += DiceValues[DiceOptions::Energy];
    resolvedHand[DiceOptions::Ouch] += DiceValues[DiceOptions::Ouch];
    resolvedHand[DiceOptions::Destruction] += DiceValues[DiceOptions::Destruction];
    resolvedHand[DiceOptions::Celebrity] += DiceValues[DiceOptions::Celebrity];

}

void Dice::setPlayerNumber(int numb) {
    this->playerNumber = numb;

}

int Dice::rollDiceDetermineStart(){

    DiceOptions value;
    int numbOfAttacks=0;
    for(int i=0; i<8; i++)
    {
        value = randomDiceOption();
        if(value == DiceOptions::Attack)
        {
            numbOfAttacks++;
        }
    }
    return numbOfAttacks;
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

//Store history of dice result in Map of {DiceOption-->value}
void Dice::storeResolvedHand(map<DiceOptions, int> resolvedHand) {
    historyOfResolvedRolls.push_back(resolvedHand);
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

void Dice::resetResolvedHand() {
    resolvedHand[DiceOptions::Heal] = 0;
    resolvedHand[DiceOptions::Attack] = 0;
    resolvedHand[DiceOptions::Celebrity] = 0;
    resolvedHand[DiceOptions::Destruction] = 0;
    resolvedHand[DiceOptions::Energy] = 0;
    resolvedHand[DiceOptions::Ouch] = 0;
}

// Print all historical dice values for player
void Dice::diceHistoricalValues()
{
    cout << "Dice container values for player "<< this->getPlayerNumber() << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (it = historyOfRolls.begin(); it != historyOfRolls.end(); ++it) {
        cout << "| Dice Roll # "<< it - historyOfRolls.begin() +1 << endl;
        cout << "-----------------------------------------------------------------" << endl;

        for (auto mapIt(it->begin()); mapIt != it->end(); ++mapIt) {

            std::cout << left << "| " << "(" << DiceNames[mapIt->first][0] << ") --- " << DiceNames[mapIt->first] << ", " << mapIt->second << std::endl;
        }
        cout << "-----------------------------------------------------------------" << endl;

    }


}

// Print all historical dice values for player
void Dice::diceHistoricalResolvedValues()
{
    cout << "Dice container values for player "<< this->getPlayerNumber() << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (it = historyOfResolvedRolls.begin(); it != historyOfResolvedRolls.end(); ++it) {
        cout << "Dice Roll # "<< it - historyOfResolvedRolls.begin() +1 << endl;
        cout << "-----------------------------------------------------------------" << endl;

        for (auto mapIt(it->begin()); mapIt != it->end(); ++mapIt) {

            std::cout << DiceNames[mapIt->first] << ", " << mapIt->second << std::endl;
        }
        cout << "-----------------------------------------------------------------" << endl;

    }

}



// Print last historical dice values for player
void Dice::lastDiceHistoricalResolvedValues()
{
    cout << "Dice container values for player "<< this->getPlayerNumber() << endl;
    cout << "-----------------------------------------------------------------" << endl;
    for (it = historyOfResolvedRolls.end()-1; it != historyOfResolvedRolls.end(); ++it) {
        cout << "-----------------------------------------------------------------" << endl;

        for (auto mapIt(it->begin()); mapIt != it->end(); ++mapIt) {

            std::cout << DiceNames[mapIt->first] << ", " << mapIt->second << std::endl;
        }
        cout << "-----------------------------------------------------------------" << endl;

    }

}

int Dice::addToCount() {
    int count =0;
    count += resolvedHand[DiceOptions::Attack];
    count += resolvedHand[DiceOptions::Celebrity];
    count += resolvedHand[DiceOptions::Destruction];
    count += resolvedHand[DiceOptions::Ouch];
    count += resolvedHand[DiceOptions::Energy];
    count += resolvedHand[DiceOptions::Heal];
    return count;
}

void Dice::rollDiceSequence() {
    resetDiceRolls();

    cout << "Rolling first hand of dice for player" << this->getPlayerNumber() << "\n";
    cout << "Press enter to continue" << endl;
    cin.ignore();
    this->rollDice(6);
    numberOfRolls--;

    while (getNumbOfRollsRemaining() == 1 || getNumbOfRollsRemaining() == 2) {         // roll 2
        cout << "Sequence number " << getNumbOfRollsRemaining() << endl;
        int count =0;
        count = addToCount();
        cout << "Rolling " << (6-count) << " dice since you saved: " << count << "\n";

        this->rollDice(6-count);
        numberOfRolls--;
    }

    if (getNumbOfRollsRemaining() == 0) {
        cout << "\n No hands left: Resolving ......" << endl;
        storeResolvedHand(resolvedHand);
        resetResolvedHand();
        resetDiceValuesMap();
        historyOfRolls.clear();

        cout << "Resolved Final Values ---------------------------" << endl;
        this->diceHistoricalResolvedValues();
    }


}

void Dice::rollAggressiveComputer(){

    DiceOptions value;
    for(int i=0; i<6; i++)
    {
        value = randomDiceOption();
        this->DiceValues[value] ++;
    }

    this->resolvedHand[Attack] += this->DiceValues[Attack];
    this->resolvedHand[Destruction] += this->DiceValues[Destruction];

    resetDiceValuesMap();

    if(addToCount() <6){
        DiceOptions value;
        for(int i=0; i<6-addToCount(); i++)
        {
            value = randomDiceOption();
            this->DiceValues[value] ++;
        }

        this->resolvedHand[Attack] += this->DiceValues[Attack];
        this->resolvedHand[Destruction] += this->DiceValues[Destruction];
        resetDiceValuesMap();
    }

    if(addToCount() < 6){
        DiceOptions value;
        for(int i=0; i<6-addToCount(); i++)
        {
            value = randomDiceOption();
            this->DiceValues[value] ++;
        }
    }

    addDiceValuesToResolvedHand();
    storeResolvedHand(resolvedHand);

    resetResolvedHand();
    resetDiceValuesMap();

}

void Dice::rollModerateComputer(){

    DiceOptions value;
    for(int i=0; i<6; i++)
    {
        value = randomDiceOption();
        this->DiceValues[value] ++;
    }

    this->resolvedHand[Heal] += this->DiceValues[Heal];
    this->resolvedHand[Energy] += this->DiceValues[Energy];

    resetDiceValuesMap();

    if(addToCount() <6){
        DiceOptions value;
        for(int i=0; i<6-addToCount(); i++)
        {
            value = randomDiceOption();
            this->DiceValues[value] ++;
        }

        this->resolvedHand[Heal] += this->DiceValues[Heal];
        this->resolvedHand[Energy] += this->DiceValues[Energy];
        resetDiceValuesMap();
    }

    if(addToCount() < 6){
        DiceOptions value;
        for(int i=0; i<6-addToCount(); i++)
        {
            value = randomDiceOption();
            this->DiceValues[value] ++;
        }
    }

    addDiceValuesToResolvedHand();
    storeResolvedHand(resolvedHand);

    resetResolvedHand();
    resetDiceValuesMap();

}

//Second and third roll of player, input amount
void Dice::rollDice(int amtOfDice) {

    if(amtOfDice>6) {
        cout << "Invalid number of dice" << endl;
        return;
    }

        DiceOptions value;
        for(int i=0; i<amtOfDice; i++)
        {
            value = randomDiceOption();
            this->DiceValues[value] ++;
        }

        storeDiceResult(DiceValues);

        // Dice Observer
        notify();

        resolveDuringHand();
        resetDiceValuesMap();

}

void Dice::showResolvedHand() {
    int index = 0;
    cout << "Current resolved items -------" << endl;
    for (auto hand : resolvedHand) {
        cout << DiceNames[index] << " : " << hand.second << endl;
        index++;
    }
    cout << "----------------------------" << endl;

}

map<int,int> Dice::getLastResolvedHand() {
    // 0= "Energy", 1="Attack", 2="Destruction", 3="Heal", 4="Celebrity", 5="Ouch"
    map<int,int> tempVal = {{0, 0}, {1, 0}, {2, 0}, {3, 0} , {4, 0} , {5, 0}};

    tempVal[0] = historyOfResolvedRolls[historyOfResolvedRolls.size()-1][DiceOptions::Energy];
    tempVal[1] = historyOfResolvedRolls[historyOfResolvedRolls.size()-1][DiceOptions::Attack];
    tempVal[2] = historyOfResolvedRolls[historyOfResolvedRolls.size()-1][DiceOptions::Destruction];
    tempVal[3] = historyOfResolvedRolls[historyOfResolvedRolls.size()-1][DiceOptions::Heal];
    tempVal[4] = historyOfResolvedRolls[historyOfResolvedRolls.size()-1][DiceOptions::Celebrity];
    tempVal[5] = historyOfResolvedRolls[historyOfResolvedRolls.size()-1][DiceOptions::Ouch];

    return tempVal;
}



