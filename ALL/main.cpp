//#include "../TemplateMethod/setPersonnelTemplateTest.h"
//#include "../Visitor/grantVisitorTest.h"
//#include "../Proxy/proxy.h"
//#include "../Memento/memento.h"
#include"Observer/Observer.h"
#include "MVC/MVC.h"
#include "FactoryMethod/factoryMethod.h"
#include <iostream>
#include <stdlib.h>

void menuRole();

void menuAthlete();

void menuWorker();

void menuCostomer();

void StartGame();

void MenuEnd();

void menuMain() {
    while (1) {
        std::cout << "\n\n---------------欢迎进入奥林匹克运动会！---------------\n";
        std::cout << "1.选择用户类型\n";
        std::cout << "2.进行比赛\n";
        std::cout << "0.退出系统\n";
        int type;
        std::cout << "input:";
        std::cin >> type;
        switch (type) {
            case 1:
                menuRole();
                break;
            case 2:
                //进行比赛
                StartGame();
                break;
            case 0:
                return;
                break;
            default:
                break;
        }
        if (type == 2 || type == 0)
            break;
    }
    return;
}

void menuRole() {
    std::cout << "\n---------------请选择用户类型---------------\n";
    std::cout << "1.运动员\n";
    std::cout << "2.管理员\n";
    std::cout << "3.观众\n";
    std::cout << "0.返回\n";
    int type;
    std::cout << "input:";
    std::cin >> type;
    switch (type) {
        case 1:
            //setPersonnel(1);//TemplateMethod
            //grantVisitorTest(1);//VisitorMethod
            menuAthlete();
            break;
        case 2:
            //setPersonnel(2);//TemplateMethod
            //grantVisitorTest(2);//VisitorMethod
            menuWorker();
            break;
        case 3:
            //setPersonnel(3);//TemplateMethod
            //grantVisitorTest(3);//VisitorMethod
            menuCostomer();
            break;
        default:
            break;
    }
    return;
}

void menuAthlete() {
    while (1) {
        std::cout << "\n---------------请您要进行的操作---------------\n";
        std::cout << "1.报名\n";
        std::cout << "2.比赛信息查询\n";
        std::cout << "3.纪念品预定\n";
        std::cout << "4.发起请求\n";
        std::cout << "0.返回\n";
        int type;
        std::cout << "input:";
        std::cin >> type;
        switch (type) {
            case 1:
                //报名
                break;
            case 2:
                //比赛信息查询
                break;
            case 3:
                //纪念品预定
                break;
            case 4:
                //发起请求
                break;
            case 0:
                break;
        }
        if (type == 0)
            break;
    }
    return;
}

void menuWorker() {
    while (1) {
        std::cout << "\n---------------请您要进行的操作---------------\n";
        std::cout << "1.提交运动员数据\n";
        std::cout << "2.添加部门\n";
        std::cout << "3.添加职工\n";
        std::cout << "4.更改体育项目场地\n";
        std::cout << "5.查看比赛信息\n";
        std::cout << "6.安排比赛次序\n";
        std::cout << "0.返回\n";
        int type;
        std::cout << "input:";
        std::cin >> type;
        switch (type) {
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
                //observerTest();
                break;
            case 5:
                //查看比赛信息
                break;
            case 6:
                //安排比赛次序
                break;
            case 0:
                break;
        }
        if (type == 0)
            break;
    }
    return;
}

void menuCostomer() {
    while (1) {
        std::cout << "\n---------------请您要进行的操作---------------\n";
        std::cout << "1.入场\n";
        std::cout << "2.纪念品预定\n";
        std::cout << "0.返回\n";
        int type;
        std::cout << "input:";
        std::cin >> type;
        switch (type) {
            case 1:
                //入场
                break;
            case 2:
                //纪念品预定
                break;
            case 0:
                break;
        }
        if (type == 0)
            break;
    }
    return;
}

void StartGame() {
    std::cout << "\n\n---------------奥林匹克运动会正式开始！---------------\n\n";
    std::cout << "\n--------本次奥林匹克运动会的比赛项目有-----------\n";
    //通过迭代器啥的输出比赛项目
    std::cout << "\n-------参加本次奥林匹克运动会的运动员有-----------\n";
    //通过迭代器啥的输出比赛选手
    std::cout << "\n-------接下来请观众进行审核并入场进入观众席-----------\n";
    //观众审核流程输出
    std::cout << "\n--------比赛正式开始--------------\n";
    std::cout << "\n--------首先进行乒乓球比赛--------------\n";
    //XXX比赛输出
    factoryMethodTest1();
    std::cout << "\n--------接下来进行跳水比赛--------------\n";
    //XXX比赛输出
    factoryMethodTest2();
    std::cout << "\n--------接下来进行羽毛球比赛--------------\n";
    //XXX比赛输出
    factoryMethodTest3();
    std::cout << "\n--------最后进行XXX比赛--------------\n";
    //XXX比赛输出
    std::cout << "\n--------所有比赛项目顺利结束--------------\n";
    MenuEnd();
}

void MenuEnd() {
    while (1) {
        std::cout << "\n\n-----------奥林匹克结束菜单-------------\n\n";
        std::cout << "1.打印奖牌榜\n";
        std::cout << "2.打印报告\n";
        std::cout << "0.退出系统\n";
        int type;
        std::cout << "input:";
        std::cin >> type;
        switch (type) {
            case 1:
                //打印奖牌榜
                // PrintMedalTally();
                MVCTest();
                break;
            case 2:
                //打印报告
                // PrintReport();
                break;
            case 0:
                return;
                break;
            default:
                break;
        }
        if (type == 0)
            break;
    }
    return;
}

int main(int argc, const char *argv[]) {
    menuMain();
    // Subject temp1;
    //temp1.Notify();
    return 0;
}