#pragma once
#ifndef _athlete_H
#define _athlete_H

#include "personnel.h"
//�˶�Ա����
#include<string>
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
    //�����趨
    void countrySet(std::string country) {
        Country = country;
        std::cout << "athlete::countrySet : �������趨,Ϊ:" << Country << "\n";
    }
    std::string getCountry() {
        return Country;
    }
    //�μӱ����趨
    void matchSet(std::string match) {
        Match = match;
        std::cout << "athlete::countrySet : �������趨,Ϊ:" << Match << "\n";
    }
    std::string getMatch() {
        return Match;
    }
    //��Ϣ��ѯ
    void ShowInfo() override {
        std::cout << "athlete::ShowInfo : ����:" << Name << "\n";
        std::cout << "athlete::ShowInfo : ID:" << ID << "\n";
        std::cout << "athlete::ShowInfo : �Ա�:" << Gender << "\n";
        std::cout << "athlete::ShowInfo : ����:" << Country << "\n";
        std::cout << "athlete::ShowInfo : ������Ŀ:" << Match << "\n";
    }
    std::string _athlete() {
        return ID + " " + Name + " " + Country+" "+Match;
    }
           
};
#endif