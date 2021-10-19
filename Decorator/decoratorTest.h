#include<iostream>
#include<string>
#include"Decorator.h"
using namespace std;

//装饰器1
class AntiSlipPaint  : public Decorator {
    
public:

    AntiSlipPaint (Windsurfing* Windsurfing) : Decorator(Windsurfing) {
    }
 
    //该装饰器在调用父类operation的基础上实现自己的操作
    string Operation() const override {
        return "加装防滑漆\n" + Decorator::Operation() ; //返回物品描述
    }
};
//装饰器2
class Centerboard : public Decorator {
public:
    Centerboard(Windsurfing* Windsurfing) : Decorator(Windsurfing) {
    }

    //该装饰器在调用父类operation的基础上实现自己的操作
    string Operation() const override {
        return "加装稳向板\n" + Decorator::Operation(); //返回物品描述
    }
};


//装饰器3
class Collinder  : public Decorator {
public:
    Collinder (Windsurfing* Windsurfing) : Decorator(Windsurfing) {
    }

    //该装饰器在调用父类operation的基础上实现自己的操作
    string Operation() const override {
        return "加装防滑绳\n" + Decorator::Operation(); //返回物品描述
    }
};

void Operation(Windsurfing* Windsurfing) {
    cout << "选手设备:\n" << Windsurfing->Operation(); //返回物品描述
}

int decoratorTest() {
    
    Windsurfing* simple = new ConcreteWindsurfing;
    cout << "第一位选手设备检查报告:\n";
    Operation(simple);
    cout << "\n\n";
    
    Windsurfing* decorator1 = new AntiSlipPaint (simple);
    Windsurfing* decorator2 = new Collinder (decorator1);
    Windsurfing* decorator3 = new Centerboard(decorator2);
    cout << "第二位选手设备检查报告:\n";
    Operation(decorator3);
    cout << "\n";

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}
