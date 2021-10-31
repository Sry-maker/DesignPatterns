#pragma once
#ifndef _Pingpong_single_H
#define _Pingpong_single_H

#include "matchDesign.h"
//单打乒乓球子类
class Pingpong_single : public MatchDesign {
public:
    Pingpong_single(){
        std::cout << "Pingpong_single::Pingpong_single : created a subclass, name is Pingpong_single\n"; 
    }
private:
    //运动员信息
    std::string player1;
    std::string player2;
    //比赛规则信息
    std::string rule;
protected:
    //比赛名称设定
    void NameSet() override {
        Name = "乒乓球单打";
        std::cout << "Pingpong_single::NameSet : 比赛名称已设定,为:"<<Name<<"\n";
    }
    //参赛者信息设定
    void PlayerSet()override {
        player1="1002";
        std::cout << "Pingpong_single::PlayerSet : 第一位运动员ID已设定,为"<<player1<<"\n";
        player2="1003";
        std::cout << "Pingpong_single::PlayerSet : 第二位运动员ID已设定,为"<<player2<<"\n";
    }
    //规则信息设定
    void RuleSet(std::string Rule) override{
        rule=Rule;
        std::cout << "Pingpong_single::RuleSet : 比赛规则已设定\n";
    }
    //比赛信息查询
    void ShowInfo() override {
        std::cout << "Pingpong_single::ShowInfo : name:"<< Name<< "\n";
        std::cout << "Pingpong_single::ShowInfo : time:"<< Time<< "\n";
        std::cout << "Pingpong_single::ShowInfo : area:"<< Area<< "\n";
        std::cout << "Pingpong_single::ShowInfo : player1:"<< player1<< "\n";
        std::cout << "Pingpong_single::ShowInfo : player2:"<< player2<< "\n";
        std::cout << "Pingpong_single::ShowInfo : rule:"<< rule<< "\n";
    }
};
#endif