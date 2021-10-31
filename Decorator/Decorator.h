#pragma once
#include<iostream>
#include<string>

//���󹹼���ɫ������һ������ӿڣ��Թ淶׼�����ո������εĶ���
class Diving {
public:
    virtual ~Diving() {}
    virtual string Operation() const = 0; //���ض�������
};

//���幹����ɫ������һ����Ҫ���ո������ε���
class Straight : public Diving {
public:
    Straight() {
        std:: cout << "Straight::Operation() : Creat a basic action ֱ��\n";
    }
    //���ض�������
    string Operation() const override {
        return "ֱ��";
    }
};

//���幹����ɫ������һ����Ҫ���ո������ε���
class Pike : public Diving {
public:
    Pike() {
        std:: cout << "Pike::Operation(): Creat a basic action ����\n";
    }
    //���ض�������
    string Operation() const override {
        return "����";
    }
};

//���幹����ɫ������һ����Ҫ���ո������ε���
class Tuck : public Diving {
public:
    Tuck() {
        std:: cout << "Tuck::Operation(): Creat a basic action ��ϥ\n";
    }
    //���ض�������
    string Operation() const override {
        return "��ϥ";
    }
};

//���幹����ɫ������һ����Ҫ���ո������ε���
class TAT : public Diving {
public:
    TAT() {
        std:: cout << "TAT::Operation(): Creat a basic action: ���ڼ�ת��\n";
    }
    //���ض�������
    string Operation() const override {
        return "���ڼ�ת��";
    }
};


//װ�ν�ɫ������һ�����������ʵ����������һ������󹹼��ӿ�һ�µĽӿ�
class Decorator : public Diving {

protected:
    Diving* Diving_;

public:
    Decorator(Diving* Diving) : Diving_(Diving) {
    }

    string Operation() const override {
        return this->Diving_->Operation(); //���������еĶ�������
    }
};

