#pragma once
#ifndef _worker_H
#define _worker_H

#include "personnel.h"
//工作人员类型
class worker : public personnel {
    worker(){
        std::cout << "worker::worker : created a subclass, name is worker\n"; 
    }
private:
    //职务
    std::string Type;
public:
    //职务设定
    void typeSet(std::string type) {
        Type = type;
        std::cout << "worker::typeSett : 职务已设定,为:"<<Type<<"\n";
    }
    std::string getType() {
        return Type;
    }
    //信息查询
    void ShowInfo() override {
        std::cout << "worker::ShowInfo : 姓名:"<< Name<< "\n";
        std::cout << "worker::ShowInfo : ID:"<< ID<< "\n";
        std::cout << "worker::ShowInfo : 性别:"<< Gender<< "\n";
        std::cout << "worker::ShowInfo : 职务:"<< Type<< "\n";
    }
};
#endif