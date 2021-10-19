#pragma once
#ifndef _Permit_verify_Visitor_H
#define _Permit_verify_Visitor_H
#include "visitor.h"
#include "permit.h"
class Permit_verify_Visitor : public Visitor {
public:
    void Visit(Customer_ticket* element) override {
        std::cout << "Permit_verify_Visitor:" << element->Method_Customer_ticket() << " 核实\n";
    }

    void Visit(Athlete_pass* element) override {
        std::cout << "Permit_verify_Visitor:" << element->Method_Athlete_pass() << " 核实\n";
    }

    void Visit(Referee_evidence* element) override {
        std::cout << "Permit_verify_Visitor:" << element->Method_Referee_evidence() << " 核实\n";
    }
};
#endif