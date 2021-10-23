#pragma once
#ifndef _Permit_H
#define _Permit_H
#include "visitor.h"
class Permit {
    Permit(){
        std::cout << "Permit::Permit : created a Permit\n"; 
    }
public:
    virtual void Accept(Visitor* visitor) = 0;
};
class Customer_ticket : public Permit {
    Customer_ticket(){
        std::cout << "Customer_ticket::Customer_ticket : Permit name is Customer_ticket\n"; 
    }
public:
    void Accept(Visitor* visitor) override {
        std::cout << "Customer_ticket::Accept : Customer_ticket accept Visitor\n"; 
        visitor->Visit(this);
    }
    std::string Method_Customer_ticket() {
        return "观众凭证";
    }
};

class Athlete_pass : public Permit {
    Athlete_pass(){
        std::cout << "Athlete_pass::Athlete_pass : Permit name is Athlete_pass\n"; 
    }
public:
    void Accept(Visitor* visitor) override {
        std::cout << "Athlete_pass::Accept : Athlete_pass accept Visitor\n"; 
        visitor->Visit(this);
    }
    std::string Method_Athlete_pass() {
        return "运动员凭证";
    }
};

class Referee_evidence : public Permit {
    Referee_evidence(){
        std::cout << "Referee_evidence::Referee_evidence : Permit name is Referee_evidence\n"; 
    }
public:
    void Accept(Visitor* visitor) override {
        std::cout << "Referee_evidence::Accept : Referee_evidence accept Visitor\n"; 
        visitor->Visit(this);
    }
    std::string Method_Referee_evidence() {
        return "裁判凭证";
    }
};
#endif