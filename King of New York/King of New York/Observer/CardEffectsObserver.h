//
// Created by Shawn Elbaz on 2018-12-03.
//

#pragma once

#include "Observer.h"
#include "Subject.h"

class CardEffectsObserver: public Observer {
private:
    Subject* concreteSubject;

public:
    explicit CardEffectsObserver(Subject*);
    void update() override;
};



