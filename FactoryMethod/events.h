//
//  events.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#ifndef events_h
#define events_h

// 比赛项目基类
class Events {
protected:
    
    // 比赛的一般流程
    virtual void checkIn() = 0;
    virtual void starting() = 0;
    virtual void ending() = 0;
    virtual void awarding() = 0;
public:
    
    // 执行比赛的一般流程
    void excuteEvent(){
        checkIn();
        starting();
        ending();
        awarding();
    }
    virtual ~Events() {}
};

// 项目的构造器
class EventsCreator {
protected:
    virtual Events* FactoryMethod() = 0;
public:
    
    // 通过new一个比赛来执行流程
    void EventsOperation() {
        Events * event = this->FactoryMethod();
        event->excuteEvent();
        delete event;
    }
    virtual ~EventsCreator(){}
};


#endif /* events_h */
