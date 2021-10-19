#pragma once
#ifndef _Airgun_H
#define _Airgun_H

#include "matchDesign.h"

class Airgun : public MatchDesign {
private:
    std::string player;
    std::string rule;
protected:
    void NameSet() override {
        Name = "气枪";
        std::cout << "Airgun：气枪:\n";
    }
    void PlayerSet() override {
        std::cout << "Airgun：请输入运动员ID:";
        std::cin >> player;
        std::cout << "Airgun：运动员已设定\n";
    }
    void RuleSet() override {
        std::cout << "Airgun：请输入比赛规则:";
        std::cin >> rule;
        std::cout << "Airgun：比赛规则已设定\n";
    }
    void ShowInfo() override {
        std::cout << "Airgun: name:"<< Name<< "\n";
        std::cout << "Airgun: time:"<< Time<< "\n";
        std::cout << "Airgun: area:"<< Area<< "\n";
        std::cout << "Airgun: player:"<< player<< "\n";
        std::cout << "Airgun: rule:"<< rule<< "\n";
    }
};
#endif