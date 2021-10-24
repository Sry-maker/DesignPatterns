#pragma once
#ifndef _MatchDesign_H
#define _MatchDesign_H
#include <iostream>
#include <string>
//比赛设计模板父类
class MatchDesign {
    MatchDesign(){
       std::cout << "MatchDesign::MatchDesign : created a template, name is MatchDesign\n"; 
    }
public:
    std::string Time;//比赛开始时间
    std::string Name;//比赛名称
    std::string Area;//比赛地点
    //比赛时间设定
    void TimeSet(std::string time) {     
        Time=time;
        std::cout << "MatchDesign::TimeSet : 比赛时间已设定,为:"<<Time<<"\n";
    }
    //比赛地点设定
    void AreaSet(std::string area) {
        Area=area;
        std::cout << "MatchDesign::AreaSet : 比赛场地已设定,为:"<<Area<<"\n";
    }
    //比赛名称设定
    virtual void NameSet() = 0;
    //参赛者信息设定
    virtual void PlayerSet() = 0;
    //规则信息设定
    virtual void RuleSet(std::string Rule) = 0;
    //比赛信息查询
    virtual void ShowInfo() = 0;

};
#endif