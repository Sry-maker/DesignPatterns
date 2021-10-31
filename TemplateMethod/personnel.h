#pragma once
#ifndef _personnel_H
#define _personnel_H
#include <iostream>
#include <string>
//人员模板父类
class personnel {
public:
    personnel() {
        std::cout << "personnel::personnel : created a template, name is personnel\n";
    }
public:
    std::string ID;
    std::string Name;
    std::string Gender;
    //人员ID设定
    void IDSet(std::string id) {
        ID = id;
        std::cout << "personnel::IDSet : 人员ID已设定,为:" << ID << "\n";
    }
    //人员名称设定
    void nameSet(std::string name) {
        Name = name;
        std::cout << "personnel::nameSet : 人员名称已设定,为:" << Name << "\n";
    }
    //人员性别设定
    void genderSet(std::string gender) {
        Gender = gender;
        std::cout << "personnel::genderSet : 人员性别已设定,为:" << gender << "\n";
    }
    //人员ID查询
    std::string getId() {
        return ID;
    }
    //人员名称查询
    std::string getName() {
        return Name;
    }
    //人员性别查询
    std::string genderSet() {
        return Gender;
    }
    //人员信息查询
    virtual void ShowInfo() = 0;

};
#endif