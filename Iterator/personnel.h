#pragma once
#ifndef _personnel_H
#define _personnel_H
#include <iostream>
#include <string>
//��Աģ�常��
class personnel {
public:
    personnel() {
        std::cout << "personnel::personnel : created a template, name is personnel\n";
    }
public:
    std::string ID;
    std::string Name;
    std::string Gender;
    //��ԱID�趨
    void IDSet(std::string id) {
        ID = id;
        std::cout << "personnel::IDSet : ��ԱID���趨,Ϊ:" << ID << "\n";
    }
    //��Ա�����趨
    void nameSet(std::string name) {
        Name = name;
        std::cout << "personnel::nameSet : ��Ա�������趨,Ϊ:" << Name << "\n";
    }
    //��Ա�Ա��趨
    void genderSet(std::string gender) {
        Gender = gender;
        std::cout << "personnel::genderSet : ��Ա�Ա����趨,Ϊ:" << gender << "\n";
    }
    //��ԱID��ѯ
    std::string getId() {
        return ID;
    }
    //��Ա���Ʋ�ѯ
    std::string getName() {
        return Name;
    }
    //��Ա�Ա��ѯ
    std::string genderSet() {
        return Gender;
    }
    //��Ա��Ϣ��ѯ
    virtual void ShowInfo() = 0;

};
#endif