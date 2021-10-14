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
void factoryMethod(){
    EventsCreator* creator1 = new PingpongEventsCreator();
    creator1->EventsOperation();
    
    EventsCreator* creator2 = new BadmintonEventsCreator();
    creator2->EventsOperation();
    
    delete creator1;
    
}


#endif /* factoryMethod_h */