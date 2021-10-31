#pragma once
#ifndef _Permit_H
#define _Permit_H
#include "visitor.h"
//入场凭证父类
class Permit {
public:
    Permit(){
        std::cout << "Permit::Permit : created a Permit\n"; 
    }
    //接受访问者
    virtual void Accept(Visitor* visitor) = 0;
};

//观众入场凭证
class Customer_ticket : public Permit {
public:
    Customer_ticket(){
        std::cout << "Customer_ticket::Customer_ticket : Permit name is Customer_ticket\n"; 
    }
    //接受访问者
    void Accept(Visitor* visitor) override {
        std::cout << "Customer_ticket::Accept : Customer_ticket accept Visitor\n"; 
        visitor->Visit(this);
    }
    //访问接口方法
    std::string Method_Customer_ticket() {
        return "观众凭证";
    }
};

//运动员入场凭证
class Athlete_pass : public Permit {
public:
    Athlete_pass(){
        std::cout << "Athlete_pass::Athlete_pass : Permit name is Athlete_pass\n"; 
    }
    //接受访问者
    void Accept(Visitor* visitor) override {
        std::cout << "Athlete_pass::Accept : Athlete_pass accept Visitor\n"; 
        visitor->Visit(this);
    }
    //访问接口方法
    std::string Method_Athlete_pass() {
        return "运动员凭证";
    }
};

//工作人员入场凭证
class Referee_evidence : public Permit {
public:
    Referee_evidence(){
        std::cout << "Referee_evidence::Referee_evidence : Permit name is Referee_evidence\n"; 
    }
    //接受访问者
    void Accept(Visitor* visitor) override {
        std::cout << "Referee_evidence::Accept : Referee_evidence accept Visitor\n"; 
        visitor->Visit(this);
    }
    //访问接口方法
    std::string Method_Referee_evidence() {
        return "裁判凭证";
    }
};
#endif