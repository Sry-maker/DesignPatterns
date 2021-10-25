#pragma once
#ifndef _Visitor_H
#define _Visitor_H
#include <iostream>
#include <string>
//预声明入场凭证
class Customer_ticket;
class Athlete_pass;
class Referee_evidence;
//访问者父类
class Visitor {
    Visitor(){
        std::cout << "Visitor::Visitor : created a Visitor\n"; 
    }
public:
    //各种访问内容
    virtual void Visit(Customer_ticket* element) = 0;
    virtual void Visit(Athlete_pass* element) = 0;
    virtual void Visit(Referee_evidence* element) = 0;
};
#endif