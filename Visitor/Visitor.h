#pragma once
#ifndef _Visitor_H
#define _Visitor_H
#include <iostream>
#include <string>
class Customer_ticket;
class Athlete_pass;
class Referee_evidence;
class Visitor {
public:
    virtual void Visit(Customer_ticket* element) = 0;
    virtual void Visit(Athlete_pass* element) = 0;
    virtual void Visit(Referee_evidence* element) = 0;
};
#endif