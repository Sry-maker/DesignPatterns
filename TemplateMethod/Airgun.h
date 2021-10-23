#pragma once
#ifndef _Airgun_H
#define _Airgun_H

#include "matchDesign.h"

class Airgun : public MatchDesign {
    Airgun(){
        std::cout << "Airgun::Airgun : created a subclass, name is Airgun\n"; 
    }
private:
    std::string player;
    std::string rule;
protected:
    void NameSet() override {
        Name = "气枪";
        std::cout << "Airgun::NameSet : 比赛名称已设定,为:"<<Name<<"\n";
    }
    void PlayerSet() override{
        player="1001";
        std::cout << "Airgun::PlayerSet : 第一位运动员ID已设定,为"<<player<<"\n";
    }
    void RuleSet(std::string Rule) override{
        rule=Rule;
        std::cout << "Airgun::RuleSet : 比赛规则已设定\n";
    }
    void ShowInfo() override {
        std::cout << "Airgun::ShowInfo : name:"<< Name<< "\n";
        std::cout << "Airgun::ShowInfo : time:"<< Time<< "\n";
        std::cout << "Airgun::ShowInfo : area:"<< Area<< "\n";
        std::cout << "Airgun::ShowInfo : player:"<< player<< "\n";
        std::cout << "Airgun::ShowInfo : rule:"<< rule<< "\n";
    }
};
#endif