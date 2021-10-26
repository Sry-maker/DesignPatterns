#include "../TemplateMethod/setPersonnelTemplateTest.h"
#include "../Visitor/grantVisitorTest.h"
#include "../Proxy/proxy.h"
#include <iostream>
#include <stdlib.h>

void menuRole();
void menuAthlete();
void menuWorker();
void menuCostomer();

void menuMain(){
    while (1)
    {
        std::cout << "\n\n---------------欢迎进入奥林匹克运动会！---------------\n";
        std::cout << "1.选择用户类型\n";
        std::cout << "2.进行比赛\n";
        std::cout << "3.退出系统\n";
        int type;
        std::cout << "input:";
        std::cin>>type;
        switch (type)
        {
        case 1:
           menuRole();
            break;
        case 2:
        //进行比赛
            break;
        case 3:
            return;
            break;
        default:
            break;
        }
    } 
    return;
}
void menuRole(){
    std::cout << "\n---------------请选择用户类型---------------\n";
    std::cout << "1.运动员\n";
    std::cout << "2.管理员\n";
    std::cout << "3.观众\n";
    int type;
    std::cout << "input:";
    std::cin>>type;
    switch (type)
    {
    case 1:
        setPersonnel(1);//TemplateMethod
        grantVisitorTest(1);//VisitorMethod
        menuAthlete();
        break;
    case 2:
        setPersonnel(2);//TemplateMethod
        grantVisitorTest(2);//VisitorMethod
        menuWorker();
        break;
    case 3:
        setPersonnel(3);//TemplateMethod
        grantVisitorTest(3);//VisitorMethod
        menuCostomer();
        break;
    default:
        break;
    }
    return;
}
void menuAthlete(){
    std::cout << "\n---------------请您要进行的操作---------------\n";
    std::cout << "1.报名\n";
    std::cout << "2.比赛信息查询\n";
    std::cout << "3.纪念品预定\n";
    int type;
    std::cout << "input:";
    std::cin>>type;
    switch (type)
    {
    case 1:
        //报名
        break;
    case 2:
        //比赛信息查询
        break;
    case 3:
        //纪念品预定
        break;
    default:
        break;
    }
    return;
}
void menuWorker(){
    std::cout << "\n---------------请您要进行的操作---------------\n";
    std::cout << "1.提交运动员数据\n";
    std::cout << "2.添加部门\n";
    std::cout << "3.添加职工\n";
    std::cout << "4.更改体育项目场地\n";
    std::cout << "5.查看比赛信息\n";
    std::cout << "6.安排比赛次序\n";
    int type;
    std::cout << "input:";
    std::cin>>type;
    switch (type)
    {
    case 1:
        //提交运动员数据
        break;
    case 2:
        //添加部门
        break;
    case 3:
        //添加职工
        break;
    case 4:
        //更改体育项目场地
        break;
    case 5:
        //查看比赛信息
        break;
    case 6:
        //安排比赛次序
        break;
    default:
        break;
    }
    return;
}
void menuCostomer(){
    std::cout << "\n---------------请您要进行的操作---------------\n";
    std::cout << "1.入场\n";
    std::cout << "2.纪念品预定\n";
    int type;
    std::cout << "input:";
    std::cin>>type;
    switch (type)
    {
    case 1:
        //入场
        break;
    case 2:
        //纪念品预定
        break;
    default:
        break;
    }
    return;
}
int main(int argc, const char * argv[]) {
    menuMain();
    return 0;
}
