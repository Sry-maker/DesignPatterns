#include "../TemplateMethod/setPersonnelTemplateTest.h"
#include "../Visitor/grantVisitorTest.h"
#include "../Builder/builder.h"
#include "../Interpreter/interpreter.h"
#include "../Memento/memento.cpp"
#include "../Proxy/proxy.h"
#include "../Facade/facade.h"
#include "../Flyweight/flyweight.h"
#include"../Observer/Observer.h"
#include "../MVC/MVC.h"
#include "../FactoryMethod/factoryMethod.h"
#include "../AbstractFactory/abstractFactory.h"
#include "../Prototype/prototype.h"
#include "../Callback/callBackTest.h"
#include "../Composite/componentTest.h"
#include "../ChainOfResponsibility/chainOfResponsibility.h"
#include "../Command/command.h"
#include "../State/state.h"
#include "../Strategy/strategy.h"
#include "../ExtensionObject/extensionObject.h"
#include <iostream>
#include <stdlib.h>

FlyweightFactory* factory = new FlyweightFactory({});//存储已有的flyweight


void menuRole();

void menuAthlete();

void menuWorker();

void menuCostomer();

void StartGame();

void MenuEnd();

void Buysouvenirtest();

void ShowEvent(Athlete* athlete);

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

void menuAthlete() {
    Athlete* athlete = new Athlete("001", "张三", "中国");
    while (1) {
        std::cout << "\n---------------请您要进行的操作---------------\n";
        std::cout << "1.报名\n";
        std::cout << "2.比赛信息查询\n";
        std::cout << "3.纪念品预定\n";
        //std::cout << "4.发起请求\n";
        std::cout << "0.返回\n";
        int type;
        std::cout << "input:";
        std::cin >> type;
        if (type != 0) {
            RealHandle* real_handle = new RealHandle;
            std::cout << "\n";
            std::cout << "通过proxy处理请求:\n";
            Proxy* proxy = new Proxy(real_handle);
            Client(*proxy);
            delete real_handle;
            delete proxy;
        }
        switch (type) {
        case 1:
        {//报名
            memento(athlete);
			
                factory->ListFlyweights();
                AddAthleteToPoliceDatabase(*factory,
                    athlete->GetName(),
                     athlete->GetId(),
                    athlete->GetEvent(),
                     athlete->GetContury());
                factory->ListFlyweights();
              
        }
        break;
        case 2:
        {
            //比赛信息查询
            ShowEvent(athlete);
        }
        break;
        case 3:
            //纪念品预定
            Buysouvenirtest();
            break;
            // case 4:
                 //发起请求
               //  break;
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
        std::cout << "1.添加部门\n";
        std::cout << "2.添加职工\n";
        std::cout << "3.更改体育项目场地\n";
        std::cout << "4.查看比赛信息\n";
        std::cout << "5.安排比赛次序\n";
        std::cout << "0.返回\n";
        int type;
        std::cout << "input:";
        std::cin >> type;
        switch (type) {
        case 1:
            componentAddDepartment();//添加部门
            break;
        case 2:
            componentAddClient();//添加职工
            break;
        case 3:
            //更改体育项目场地
            //observerTest();
            break;
        case 4:
            //查看比赛信息
            prototypeTest();
            break;
        case 5:
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
            extensionObjectTest();
            commandTest();
            chainOfResponsibilityTest();
            break;
        case 2:
            //纪念品预定
            Buysouvenirtest();
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
    std::cout << "请输入比赛顺序算法策略：\n";
    std::cout << "1.顺序\n";
    std::cout << "2.倒序\n";
    int strategy_order;
    std::cout << "input:";
    std::cin >> strategy_order;
    std::cout << "\n--------本次奥林匹克运动会的比赛项目有-----------\n";
    //通过迭代器啥的输出比赛项目
    std::cout << "\n-------参加本次奥林匹克运动会的运动员有-----------\n";
    //通过迭代器啥的输出比赛选手
    //初始化比赛
    Fencing* fencing = new Fencing;
    Swimming* swimming = new Swimming;
    Facade* facade = new Facade(fencing, swimming);
    Init(facade);
    delete facade;
    switch (strategy_order) {
        case 1:
            strategy_1();
            std::cout << "\n-------接下来请观众进行审核并入场进入观众席-----------\n";
            //观众审核流程输出
            std::cout << "\n--------比赛正式开始--------------\n";
            event_start_state();
            std::cout << "\n--------首先进行羽毛球比赛--------------\n";
            //XXX比赛输出
            factoryMethodTest3();
            std::cout << "\n--------接下来进行跳水比赛--------------\n";
            //XXX比赛输出
            factoryMethodTest2();
            std::cout << "\n--------接下来进行乒乓球球比赛--------------\n";
            //XXX比赛输出
            factoryMethodTest1();
            std::cout << "\n--------所有比赛项目顺利结束--------------\n";
            break;
        case 2:
            strategy_2();
            std::cout << "\n-------接下来请观众进行审核并入场进入观众席-----------\n";
            //观众审核流程输出
            std::cout << "\n--------比赛正式开始--------------\n";
            event_start_state();
            std::cout << "\n--------首先进行乒乓球比赛--------------\n";
            //XXX比赛输出
            factoryMethodTest1();
            std::cout << "\n--------接下来进行跳水比赛--------------\n";
            //XXX比赛输出
            factoryMethodTest2();
            std::cout << "\n--------接下来进行羽毛球比赛--------------\n";
            //XXX比赛输出
            factoryMethodTest3();
            
            std::cout << "\n--------所有比赛项目顺利结束--------------\n";
            break;
    }
    
    event_end_state();
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
//                callbackTest();
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

void Buysouvenirtest()
{
    int chose;
    int chose1 = 0;
    int chose2 = 0;
    int chose3 = 0;
    int chose4 = 0;
    std::cout << "纪念品列表：" << std::endl;
    std::cout << "1.乒乓球拍纪念品" << std::endl;
    std::cout << "2.羽毛球拍纪念品" << std::endl;
    std::cout << "3.篮球系列纪念品" << std::endl;
    std::cout << "4.足球系列纪念品" << std::endl;
    std::cout << "0.退出纪念品预定" << std::endl;
    std::cout << "请选择需要预定的纪念品" << std::endl;
    for (;;) {
        std::cin >> chose;
        std::cout << std::endl;
        if (chose == 0) {
            break;
        }
        switch (chose)
        {
        case 1:
            chose1++;
            buTest(chose);
            break;
        case 2:
            chose2++;
            buTest(chose);
            break;
        case 3:
            chose3++;
            abstractFactoryTest1();

            break;
        case 4:
            chose4++;

            abstractFactoryTest2();
            break;
        default:
            break;
        }
    }
    interpreter(chose1, chose2, chose3, chose4);
}
void ShowEvent(Athlete* athlete) {
    std::cout << "\n选手 " << athlete->GetName() << "的运动项目是" << athlete->GetEvent();
}
int main(int argc, const char* argv[]) {
    menuMain();
    // Subject temp1;
    //temp1.Notify();
	delete factory;
    return 0;
}
