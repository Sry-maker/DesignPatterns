#pragma once
#ifndef _MatchDesign_H
#define _MatchDesign_H
#include <iostream>
#include <string>
class MatchDesign {
    MatchDesign(){
       std::cout << "MatchDesign::MatchDesign : created a template, name is MatchDesign\n"; 
    }
public:
    std::string Time;
    std::string Name;
    std::string Area;
    void TimeSet(std::string time) {     
        Time=time;
        std::cout << "MatchDesign::TimeSet : 比赛时间已设定,为:"<<Time<<"\n";
    }
    void AreaSet(std::string area) {
        Area=area;
        std::cout << "MatchDesign::AreaSet : 比赛场地已设定,为:"<<Area<<"\n";
    }
    virtual void NameSet() = 0;
    virtual void PlayerSet() = 0;
    virtual void RuleSet(std::string Rule) = 0;
    virtual void ShowInfo() = 0;

};
#endif