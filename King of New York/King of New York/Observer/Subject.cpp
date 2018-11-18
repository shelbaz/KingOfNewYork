//
// Created by Shawn on 11/18/2018.
//

#include "Subject.h"

Subject::Subject() {

    listOfObservers = new list<Observer*>;
}

Subject::~Subject() {
delete listOfObservers;
}

void Subject::attach(Observer* observer) {
listOfObservers->push_back(observer);
}

void Subject::detach(Observer* observer) {
    listOfObservers->remove(observer);
}

void Subject::notify() {
    for(Observer* observer: *listOfObservers){
        observer->update();
    }
}

list<Observer*>* Subject::getListOfObservers() {
    return listOfObservers;
}
