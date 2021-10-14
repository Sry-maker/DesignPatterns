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
        std::cout << "MatchDesign：请输入比赛时间：";
        std::cin >> Time;
        std::cout << "MatchDesign：比赛时间已设定\n";
    }
    void AreaSet() {
        std::cout << "MatchDesign：请输入比赛场地：";
        std::cin >> Area;
        std::cout << "MatchDesign：比赛场地已设定\n";
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