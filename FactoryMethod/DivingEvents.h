//
// Created by WuHaotian on 2021/10/30.
//

#ifndef MYDESIGNPATTERNS_DIVINGEVENTS_H
#define MYDESIGNPATTERNS_DIVINGEVENTS_H

#include "events.h"
#include "Decorator/decoratorTest.h"
#include <iostream>

class DivingEvents : public Events {
public:

    void checkIn() override {
        std::cout << "DivingEvents::checkIn : 现在开始跳水检录，请各位选手准备好" << std::endl;
    }

    void starting() override {
        std::cout << "DivingEvents::starting : 跳水比赛正式开始！" << std::endl << std::endl;
        decoratorTest();
    }

    void ending() override {
        std::cout << std::endl << "DivingEvents::ending : 跳水比赛结束！" << std::endl;
    }

    void awarding() override {
        std::cout << "DivingEvents::awarding : 请跳水比赛获奖人员上台领奖" << std::endl;
    }

    void interview() override {

    }

};

class DivingEventsCreator : public EventsCreator {
public:
    Events *FactoryMethod() override {
        return new DivingEvents();
    }

    DivingEventsCreator() {
        std::cout << "DivingEventsCreator::DivingEventsCreator : create a DivingEventsCreator"
                  << std::endl;
    }
};

#endif //MYDESIGNPATTERNS_DIVINGEVENTS_H
