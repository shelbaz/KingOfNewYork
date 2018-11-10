//
// Created by Shawn Elbaz on 2018-10-10.
//
//
//#include <iostream>
//#include <string>
//#include <cstdlib>
//#include <ctime>
//#include "Dice.h"
//
//using namespace std;
//
//void DiceDriver() {
//
//    // create two dice objects for player 1 and player 2
//    Dice dice1;
//
//    // while loop to ask players how many dice they want to roll
//    //if they want to keep rolling
//    // and stores each dice value
//    int selection;
//    cout << "Select from the following options:" << endl;
//    cout << "1) Normal Player sequence" << endl;
//    cout << "2) Roll N number of rolls to see fairness" << endl;
//    cin >> selection ;
//
//    switch(selection){
//        case 1:
//        {
//
//            dice1.rollDiceSequence();
//
//            cout << "thanks for rolling!" << endl;
//        }
//            break;
//        case 2:
//        {
//            char keepGoing = 'y';
//            while (keepGoing == 'y')
//            {
//                dice1.rollDice(true);
//
//                cout << "Do you want to roll again? type y to continue or n to exit \n";
//                cin >> keepGoing;
//                cout << "\n";
//
//            }
//
//            cout << "thanks for rolling! " <<endl;
//        }
//            break;
//        default:
//            break;
//    }
//}
