#pragma once
#include<iostream>
#include<string>

//抽象构件角色：给出一个抽象接口，以规范准备接收附加责任的对象。
class Diving {
public:
    virtual ~Diving() {}
    virtual string Operation() const = 0; //返回动作描述
};

//具体构件角色：定义一个将要接收附加责任的类
class Straight : public Diving {
public:
    Straight() {
        std:: cout << "Straight::Operation() : Creat a basic action 直体\n";
    }
    //返回动作类型
    string Operation() const override {
        return "直体";
    }
};

//具体构件角色：定义一个将要接收附加责任的类
class Pike : public Diving {
public:
    Pike() {
        std:: cout << "Pike::Operation(): Creat a basic action 屈体\n";
    }
    //返回动作类型
    string Operation() const override {
        return "屈体";
    }
};

//具体构件角色：定义一个将要接收附加责任的类
class Tuck : public Diving {
public:
    Tuck() {
        std:: cout << "Tuck::Operation(): Creat a basic action 抱膝\n";
    }
    //返回动作类型
    string Operation() const override {
        return "抱膝";
    }
};

//具体构件角色：定义一个将要接收附加责任的类
class TAT : public Diving {
public:
    TAT() {
        std:: cout << "TAT::Operation(): Creat a basic action: 翻腾兼转体\n";
    }
    //返回动作类型
    string Operation() const override {
        return "翻腾兼转体";
    }
};


//装饰角色：持有一个构件对象的实例，并定义一个与抽象构件接口一致的接口
class Decorator : public Diving {

protected:
    Diving* Diving_;

public:
    Decorator(Diving* Diving) : Diving_(Diving) {
    }

    string Operation() const override {
        return this->Diving_->Operation(); //返回子类中的动作描述
    }
};

