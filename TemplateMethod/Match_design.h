#pragma once
#ifndef _MatchDesign_H
#define _MatchDesign_H
#include <iostream>
#include <string>
class MatchDesign {
public:
    std::string Time;
    std::string Name;
    std::string Area;
protected:
    void TimeSet() {
        std::cout << "MatchDesign�����������ʱ�䣺";
        std::cin >> Time;
        std::cout << "MatchDesign������ʱ�����趨\n";
    }
    void AreaSet() {
        std::cout << "MatchDesign��������������أ�";
        std::cin >> Area;
        std::cout << "MatchDesign�������������趨\n";
    }
    virtual void NameSet() = 0;
    virtual void PlayerSet() = 0;
    virtual void RuleSet() = 0;
    virtual void ShowInfo() = 0;
public:
    void TemplateMethod() {
        this->NameSet();
        this->TimeSet();
        this->AreaSet();
        this->PlayerSet();
        this->RuleSet();
        this->ShowInfo();
    }

};
#endif