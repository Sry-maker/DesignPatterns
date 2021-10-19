#pragma once
#include<iostream>
#include<string>
using namespace std;

//���󹹼���ɫ������һ������ӿڣ��Թ淶׼�����ո������εĶ���
class Windsurfing {
public:
    virtual ~Windsurfing() {}
    virtual string Operation() const = 0; //������Ʒ����
};

//���幹����ɫ������һ����Ҫ���ո������ε���
class ConcreteWindsurfing : public Windsurfing {
public:
    //������Ʒ����
    string Operation() const override {
        return "����\n";
    }
};

//װ�ν�ɫ������һ�����������ʵ����������һ������󹹼��ӿ�һ�µĽӿ�
class Decorator : public Windsurfing {

protected:
    Windsurfing* Windsurfing_;

public:
    Decorator(Windsurfing* Windsurfing) : Windsurfing_(Windsurfing) {
    }

    string Operation() const override {
        return this->Windsurfing_->Operation(); //���������е���Ʒ����
    }
};

