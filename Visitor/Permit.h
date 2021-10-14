#pragma once
#ifndef _Permit_H
#define _Permit_H
#include "Visitor.h"
class Permit {
public:
    virtual ~Permit() {}
    virtual void Accept(Visitor* visitor) = 0;
};
class Customer_ticket : public Permit {
public:
    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }
    std::string Method_Customer_ticket() {
        return "����ƾ֤";
    }
};

class Athlete_pass : public Permit {
public:
    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }
    std::string Method_Athlete_pass() {
        return "�˶�Աƾ֤";
    }
};

class Referee_evidence : public Permit {
public:
    void Accept(Visitor* visitor) override {
        visitor->Visit(this);
    }
    std::string Method_Referee_evidence() {
        return "����ƾ֤";
    }
};
#endif