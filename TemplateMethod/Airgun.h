#pragma once
#ifndef _Airgun_H
#define _Airgun_H

#include "Match_design.h"

class Airgun : public MatchDesign {
private:
    std::string player;
    std::string rule;
protected:
    void NameSet() override {
        Name = "��ǹ";
        std::cout << "Airgun����ǹ:\n";
    }
    void PlayerSet() override {
        std::cout << "Airgun���������˶�ԱID:";
        std::cin >> player;
        std::cout << "Airgun���˶�Ա���趨\n";
    }
    void RuleSet() override {
        std::cout << "Airgun���������������:";
        std::cin >> rule;
        std::cout << "Airgun�������������趨\n";
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