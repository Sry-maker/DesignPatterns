#pragma once
#ifndef _Pingpong_single_H
#define _Pingpong_single_H

#include "matchDesign.h"

class Pingpong_single : public MatchDesign {
    Pingpong_single(){
        std::cout << "Pingpong_single::Pingpong_single : created a subclass, name is Pingpong_single\n"; 
    }
private:
    std::string player1;
    std::string player2;
    std::string rule;
protected:
    void NameSet() override {
        Name = "乒乓球单打";
        std::cout << "Pingpong_single::NameSet : 比赛名称已设定,为:"<<Name<<"\n";
    }
    void PlayerSet()override {
        player1="1002";
        std::cout << "Pingpong_single::PlayerSet : 第一位运动员ID已设定,为"<<player1<<"\n";
        player2="1003";
        std::cout << "Pingpong_single::PlayerSet : 第二位运动员ID已设定,为"<<player2<<"\n";
    }
    void RuleSet(std::string Rule) override{
        rule=Rule;
        std::cout << "Pingpong_single::RuleSet : 比赛规则已设定\n";
    }
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