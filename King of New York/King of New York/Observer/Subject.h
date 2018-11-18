//
// Created by Shawn on 11/18/2018.
//

#pragma once


#include "Observer.h"
#include <list>

using namespace std;

class Subject {

public:

    Subject();
    ~Subject();
    virtual void attach(Observer* observer);
    virtual void detach(Observer* observer);
    virtual void notify();
    list<Observer*>* getListOfObservers();
private:
    list<Observer*>* listOfObservers;
};


