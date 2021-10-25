//
//  pingpongEvents.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#ifndef pingpongEvents_h
#define pingpongEvents_h

#include "events.h"
#include <iostream>

// 乒乓球比赛 继承自比赛基类
class PingpongEvents : public Events {
public:
    
    // 重写相关的函数
    void checkIn() override {
        std::cout << "PingpongEvents::checkIn : 现在开始乒乓球检录，请各位选手准备好" << std::endl;
    }
    void starting() override {
        std::cout << "PingpongEvents::starting : 乒乓球比赛正式开始！" << std::endl;
    }
    void ending() override {
        std::cout << "PingpongEvents::ending : 乒乓球比赛结束！" << std::endl;
    }
    void awarding() override {
        std::cout << "PingpongEvents::awarding : 请乒乓球比赛获奖人员上台领奖" << std::endl;
    }
};


// 乒乓球比赛的构造器
class PingpongEventsCreator : public EventsCreator {
public:
    
    // 重写工厂函数
    Events* FactoryMethod() override{
        return new PingpongEvents();
    }
    
    PingpongEventsCreator(){
        std::cout << "PingpongEventsCreator::PingpongEventsCreator : create a PingpongEventsCreator"
                  << std::endl;
    }
};
#endif /* pingpongEvents_h */
