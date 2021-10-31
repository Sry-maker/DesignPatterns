#pragma once
#ifndef _Airgun_H
#define _Airgun_H

#include "matchDesign.h"
//气枪子类
class Airgun : public MatchDesign {
public:
    Airgun(){
        std::cout << "Airgun::Airgun : created a subclass, name is Airgun\n"; 
    }
private:
    //运动员信息
    std::string player;
    //比赛规则信息
    std::string rule;
protected:
    //比赛名称设定
    void NameSet() override {
        Name = "气枪";
        std::cout << "Airgun::NameSet : 比赛名称已设定,为:"<<Name<<"\n";
    }
    //参赛者信息设定
    void PlayerSet() override{
        player="1001";
        std::cout << "Airgun::PlayerSet : 第一位运动员ID已设定,为"<<player<<"\n";
    }
    //规则信息设定
    void RuleSet(std::string Rule) override{
        rule=Rule;
        std::cout << "Airgun::RuleSet : 比赛规则已设定\n";
    }
    //比赛信息查询
    void ShowInfo() override {
        std::cout << "Airgun::ShowInfo : name:"<< Name<< "\n";
        std::cout << "Airgun::ShowInfo : time:"<< Time<< "\n";
        std::cout << "Airgun::ShowInfo : area:"<< Area<< "\n";
        std::cout << "Airgun::ShowInfo : player:"<< player<< "\n";
        std::cout << "Airgun::ShowInfo : rule:"<< rule<< "\n";
    }
};
#endif