﻿//
//  factoryMethod.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#ifndef factoryMethod_h
#define factoryMethod_h


#include "pingpongEvents.h"
#include "badmintonEvents.h"
#include "DivingEvents.h"

// 工厂设计模式测试接口函数
void factoryMethodTest(){
    std::cout << "***************  以下为FactoryMethod(工厂方法)设计模式  **************************************" << std::endl << std::endl;
    EventsCreator* creator1 = new PingpongEventsCreator();
    std::cout << "执行乒乓球比赛流程：" << std::endl;
    creator1->EventsOperation();
    EventsCreator* creator2 = new DivingEventsCreator();
    std::cout << "执行跳水比赛流程：" << std::endl;
    creator2->EventsOperation();
    
    std::cout << std::endl << "***************  FactoryMethod(工厂方法)设计模式结束  **************************************" << std::endl << std::endl;
    delete creator1;
    
}


#endif /* factoryMethod_h */
