#pragma once
#ifndef _Permit_verify_Visitor_H
#define _Permit_verify_Visitor_H
#include "visitor.h"
#include "permit.h"
//核实入场凭证的访问者子类
class Permit_verify_Visitor : public Visitor {
public:
    Permit_verify_Visitor(){
        std::cout << "Permit_verify_Visitor::Permit_verify_Visitor : Visitor name is Permit_verify_Visitor\n"; 
    }
    //不同类型入场凭证的访问
    void Visit(Customer_ticket* element) override {
        std::cout << "Permit_verify_Visitor::Visit : " << element->Method_Customer_ticket() << " 核实\n";
    }

    void Visit(Athlete_pass* element) override {
        std::cout << "Permit_verify_Visitor::Visit : " << element->Method_Athlete_pass() << " 核实\n";
    }

    void Visit(Referee_evidence* element) override {
        std::cout << "Permit_verify_Visitor::Visit : " << element->Method_Referee_evidence() << " 核实\n";
    }
};
#endif