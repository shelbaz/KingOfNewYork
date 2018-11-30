//
// Created by Shawn Elbaz on 2018-11-29.
//

#pragma once
#include "Observer.h"
#include "Subject.h"
#include "Dice.h"

class DiceEffectsObserver: public Observer {

private:
    Subject* concreteSubject;

public:
    explicit DiceEffectsObserver(Subject*);
    void update() override;

};



