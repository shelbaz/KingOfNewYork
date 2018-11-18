//
// Created by Shawn on 11/18/2018.
//

#pragma once
#include "Observer.h"
#include "Subject.h"

class GameStatisticsObserver: public Observer {

public:
    void update() override;

};

