#pragma once
#ifndef _Permit_verify_Visitor_H
#define _Permit_verify_Visitor_H
#include "Visitor.h"
#include "Permit.h"
class Permit_verify_Visitor : public Visitor {
public:
    void Visit(Customer_ticket* element) override {
        std::cout << "Permit_verify_Visitor:" << element->Method_Customer_ticket() << " ��ʵ\n";
    }

    void Visit(Athlete_pass* element) override {
        std::cout << "Permit_verify_Visitor:" << element->Method_Athlete_pass() << " ��ʵ\n";
    }

    void Visit(Referee_evidence* element) override {
        std::cout << "Permit_verify_Visitor:" << element->Method_Referee_evidence() << " ��ʵ\n";
    }
};
#endif