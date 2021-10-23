//
//  factoryMethod.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#ifndef factoryMethod_h
#define factoryMethod_h


#include "pingpongEvents.h"
#include "badmintonEvents.h"

// 工厂设计模式测试接口函数
void factoryMethodTest(){
    EventsCreator* creator1 = new PingpongEventsCreator();
    std::cout << "执行乒乓球比赛流程：" << std::endl;
    creator1->EventsOperation();
    EventsCreator* creator2 = new BadmintonEventsCreator();
    std::cout << "执行羽毛球比赛流程：" << std::endl;
    creator2->EventsOperation();
    
    delete creator1;
    
}


#endif /* factoryMethod_h */
