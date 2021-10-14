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
        Name = "ƹ���򵥴�";
        std::cout << "Pingpong_single��ƹ���򵥴�:\n";
    }
    void PlayerSet() override {
        std::cout << "Pingpong_single���������һλ�˶�ԱID:";
        std::cin >> player1;
        std::cout << "Pingpong_single��������ڶ�λ�˶�ԱID:";
        std::cin >> player2;
        std::cout << "Pingpong_single���˶�Ա���趨\n";
    }
    void RuleSet() override {
        std::cout << "Pingpong_single���������������:";
        std::cin >> rule;
        std::cout << "Pingpong_single�������������趨\n";
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