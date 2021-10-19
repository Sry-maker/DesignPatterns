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
    void TimeSet(std::string time) {
        std::cout << "MatchDesign：请输入比赛时间：";
        Time=time;
        std::cout << "MatchDesign：比赛时间已设定\n";
    }
    void AreaSet(std::string area) {
        std::cout << "MatchDesign：请输入比赛场地：";
        Area=area;
        std::cout << "MatchDesign：比赛场地已设定\n";
    }
    virtual void NameSet() = 0;
    virtual void PlayerSet() = 0;
    virtual void RuleSet(std::string Rule) = 0;
    virtual void ShowInfo() = 0;

};
#endif