#pragma once
#ifndef _customer_H
#define _customer_H

#include "personnel.h"
//观众类型
class customer : public personnel {
public:
    customer() {
        std::cout << "customer::customer : created a subclass, name is customer\n";
    }
private:
    //票种
    std::string Type;
public:
    //票种设定
    void typeSet(std::string type) {
        Type = type;
        std::cout << "customer::typeSet : 票种已设定,为:" << Type << "\n";
    }
    std::string getType() {
        return Type;
    }
    //信息查询
    void ShowInfo() override {
        std::cout << "customer::ShowInfo : 姓名:" << Name << "\n";
        std::cout << "customer::ShowInfo : ID:" << ID << "\n";
        std::cout << "customer::ShowInfo : 性别:" << Gender << "\n";
        std::cout << "customer::ShowInfo : 票种:" << Type << "\n";
    }
};
#endif