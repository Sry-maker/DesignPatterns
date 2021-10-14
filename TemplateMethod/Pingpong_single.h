#pragma once
#ifndef _Pingpong_single_H
#define _Pingpong_single_H

#include "Match_design.h"

class Pingpong_single : public MatchDesign {
private:
    std::string player1;
    std::string player2;
    std::string rule;
protected:
    void NameSet() override {
        Name = "乒乓球单打";
        std::cout << "Pingpong_single：乒乓球单打:\n";
    }
    void PlayerSet() override {
        std::cout << "Pingpong_single：请输入第一位运动员ID:";
        std::cin >> player1;
        std::cout << "Pingpong_single：请输入第二位运动员ID:";
        std::cin >> player2;
        std::cout << "Pingpong_single：运动员已设定\n";
    }
    void RuleSet() override {
        std::cout << "Pingpong_single：请输入比赛规则:";
        std::cin >> rule;
        std::cout << "Pingpong_single：比赛规则已设定\n";
    }
    void ShowInfo() override {
        std::cout << "Pingpong_single: name:"<< Name<< "\n";
        std::cout << "Pingpong_single: time:"<< Time<< "\n";
        std::cout << "Pingpong_single: area:"<< Area<< "\n";
        std::cout << "Pingpong_single: player1:"<< player1<< "\n";
        std::cout << "Pingpong_single: player2:"<< player2<< "\n";
        std::cout << "Pingpong_single: rule:"<< rule<< "\n";
    }
};
#endif