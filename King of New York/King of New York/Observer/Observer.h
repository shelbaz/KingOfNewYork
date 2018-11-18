//
// Created by Shawn on 11/18/2018.
//

#pragma once


class Observer {

public:
    Observer();
    ~Observer();
    virtual void update() = 0;
private:

};

