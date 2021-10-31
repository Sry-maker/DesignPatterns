#pragma once
#ifndef _athlete_H
#define _athlete_H

#include "personnel.h"
//运动员类型
class athlete : public personnel {
private:
    std::string Country;
    std::string Match;
public:
    athlete() {
        std::cout << "athlete::athlete : created a subclass, name is athlete\n";
    }
    athlete(std::string id, std::string name, std::string country) {
        ID = id;
        Name = name;
        Country = country;
        std::cout << "athlete::athlete : created a subclass, name is athlete\n";
    }
public:
    //国籍设定
    void countrySet(std::string country) {
        Country = country;
        std::cout << "athlete::countrySet : 国籍已设定,为:" << Country << "\n";
    }
    std::string getCountry() {
        return Country;
    }
    //参加比赛设定
    void matchSet(std::string match) {
        Match = match;
        std::cout << "athlete::countrySet : 国籍已设定,为:" << Match << "\n";
    }
    std::string getMatch() {
        return Match;
    }
    //信息查询
    void ShowInfo() override {
        std::cout << "athlete::ShowInfo : 姓名:" << Name << "\n";
        std::cout << "athlete::ShowInfo : ID:" << ID << "\n";
        std::cout << "athlete::ShowInfo : 性别:" << Gender << "\n";
        std::cout << "athlete::ShowInfo : 国籍:" << Country << "\n";
        std::cout << "athlete::ShowInfo : 参赛项目:" << Match << "\n";
    }
    std::string _athlete() {
        return ID + " " + Name + " " + Country+" "+Match;
    }
};
#endif