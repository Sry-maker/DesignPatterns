#pragma once
#include<iostream>
#include<string>
using namespace std;

//抽象构件角色：给出一个抽象接口，以规范准备接收附加责任的对象。
class Windsurfing {
public:
    virtual ~Windsurfing() {}
    virtual string Operation() const = 0; //返回物品描述
};

//具体构件角色：定义一个将要接收附加责任的类
class ConcreteWindsurfing : public Windsurfing {
public:
    //返回物品类型
    string Operation() const override {
        return "帆板\n";
    }
};

//装饰角色：持有一个构件对象的实例，并定义一个与抽象构件接口一致的接口
class Decorator : public Windsurfing {

protected:
    Windsurfing* Windsurfing_;

public:
    Decorator(Windsurfing* Windsurfing) : Windsurfing_(Windsurfing) {
    }

    string Operation() const override {
        return this->Windsurfing_->Operation(); //返回子类中的物品描述
    }
};

