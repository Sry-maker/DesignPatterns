#include<iostream>
#include<string>
#include"Decorator.h"
using namespace std;

//װ����1
class AntiSlipPaint  : public Decorator {
    
public:

    AntiSlipPaint (Windsurfing* Windsurfing) : Decorator(Windsurfing) {
    }
 
    //��װ�����ڵ��ø���operation�Ļ�����ʵ���Լ��Ĳ���
    string Operation() const override {
        return "��װ������\n" + Decorator::Operation() ; //������Ʒ����
    }
};
//װ����2
class Centerboard : public Decorator {
public:
    Centerboard(Windsurfing* Windsurfing) : Decorator(Windsurfing) {
    }

    //��װ�����ڵ��ø���operation�Ļ�����ʵ���Լ��Ĳ���
    string Operation() const override {
        return "��װ�����\n" + Decorator::Operation(); //������Ʒ����
    }
};


//װ����3
class Collinder  : public Decorator {
public:
    Collinder (Windsurfing* Windsurfing) : Decorator(Windsurfing) {
    }

    //��װ�����ڵ��ø���operation�Ļ�����ʵ���Լ��Ĳ���
    string Operation() const override {
        return "��װ������\n" + Decorator::Operation(); //������Ʒ����
    }
};

void Operation(Windsurfing* Windsurfing) {
    cout << "ѡ���豸:\n" << Windsurfing->Operation(); //������Ʒ����
}

int decoratorTest() {
    
    Windsurfing* simple = new ConcreteWindsurfing;
    cout << "��һλѡ���豸��鱨��:\n";
    Operation(simple);
    cout << "\n\n";
    
    Windsurfing* decorator1 = new AntiSlipPaint (simple);
    Windsurfing* decorator2 = new Collinder (decorator1);
    Windsurfing* decorator3 = new Centerboard(decorator2);
    cout << "�ڶ�λѡ���豸��鱨��:\n";
    Operation(decorator3);
    cout << "\n";

    delete simple;
    delete decorator1;
    delete decorator2;

    return 0;
}
