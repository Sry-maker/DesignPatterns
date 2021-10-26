//
//  badmintonEvents.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#ifndef badmintonEvents_h
#define badmintonEvents_h

#include "events.h"
#include <iostream>

// 羽毛球比赛 继承自比赛基类
class BadmintonEvents : public Events {
public:
    
    // 重写相关的函数
    void checkIn() override {
        std::cout << "BadmintonEvents::checkIn : 现在开始羽毛球检录，请各位选手准备好" << std::endl;
    }
    void starting() override {
        std::cout << "BadmintonEvents::starting : 羽毛球比赛正式开始！" << std::endl;
    }
    void ending() override {
        std::cout << "BadmintonEvents::ending : 羽毛球球比赛结束！" << std::endl;
    }
    void awarding() override {
        std::cout << "BadmintonEvents::awarding : 请羽毛球球比赛获奖人员上台领奖" << std::endl;
    }
    void interview() override {
        
    }
};


// 羽毛球比赛的构造器
class BadmintonEventsCreator : public EventsCreator {
public:
    
    // 重写工厂函数
    Events* FactoryMethod() override {
        return new BadmintonEvents();
    }
    
    BadmintonEventsCreator() {
        std::cout << "BadmintonEventsCreator::BadmintonEventsCreator : create a BadmintonEventsCreator"
                  << std::endl;
    }
};

#endif /* badmintonEvents_h */
