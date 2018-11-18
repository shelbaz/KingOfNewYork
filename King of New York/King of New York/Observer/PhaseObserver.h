//
// Created by Shawn on 11/18/2018.
//

#pragma once

#include "Observer.h"
#include "Subject.h"

class PhaseObserver: public Observer {

public:
    PhaseObserver(Subject*);
    void update() override;
private:
    Subject* concreteSubject;
};


