#pragma once
#include<iostream>
#include<string>
#include"Decorator.h"

//װ����1����ǰ����
class Front : public Decorator {

public:

	Front(Diving* Diving) : Decorator(Diving) {
		std:: cout << "Front:: Create a motion ��ǰ\n";
	}

	//��װ�����ڵ��ø���operation�Ļ�����ʵ���Լ��Ĳ���
	string Operation() const override {
		return "��ǰ" + Decorator::Operation(); //���ض�������
	}
};
//װ����2���������
class Back : public Decorator {
public:
	Back(Diving* Diving) : Decorator(Diving) {
		std:: cout << "Back:: Create a motion ���\n";
	}

	//��װ�����ڵ��ø���operation�Ļ�����ʵ���Լ��Ĳ���
	string Operation() const override {
		return "���" + Decorator::Operation(); //���ض�������
	}
};


//װ����3:����
class Reverse : public Decorator {
public:
	Reverse(Diving* Diving) : Decorator(Diving) {
		std:: cout << "Reverse:: Create a motion ����\n";
	}

	//��װ�����ڵ��ø���operation�Ļ�����ʵ���Լ��Ĳ���
	string Operation() const override {
		return "����" + Decorator::Operation(); //���ض�������
	}
};
//װ����4�����ڰ�����
class doubleAxel : public Decorator {
public:
	doubleAxel(Diving* Diving) : Decorator(Diving) {
		std:: cout << "doubleAxel:: Create a motion �������ܰ�\n";
	}

	//��װ�����ڵ��ø���operation�Ļ�����ʵ���Լ��Ĳ���
	string Operation() const override {
		return "�������ܰ�" + Decorator::Operation(); //���ض�������
	}
};
//װ����5��ת�������
class Tumble : public Decorator {
public:
	Tumble(Diving* Diving) : Decorator(Diving) {
		std:: cout << "Front:: Create a motion ת��1�ܰ�\n";
	}

	//��װ�����ڵ��ø���operation�Ļ�����ʵ���Լ��Ĳ���
	string Operation() const override {
		return "ת��1�ܰ�" + Decorator::Operation(); //���ض�������
	}
};

void Operation(Diving* Diving) {
	std:: cout << "ѡ�ֶ���:\n" << Diving->Operation(); //���ض�������
}
int decoratorTest() {
	std:: cout << "****************����ΪDecorator��װ�Σ����ģʽ****************:\n";
	Diving* simple1 = new Straight;//ֱ��
	Diving* simple2 = new Pike;//����
	Diving* simple3 = new Tuck;//��ϥ
	Diving* simple4 = new TAT;//���ڼ�ת��
	Diving* decorator1 = new Tumble(simple1);//ת��1�ܰ�
	Diving* decorator2 = new doubleAxel(simple2);//�������ܰ�
	Diving* decorator3 = new doubleAxel(decorator1);
	Diving* decorator4 = new Reverse(decorator2);//���������ܰ�����
	Diving* decorator5 = new Front(decorator3);//��ǰ�������ܰ�ת��1�ܰ�ֱ��
	Diving* decorator6 = new Back(decorator2);//��������ܰ�����

	std:: cout << "��һλѡ�ֶ���:\n";
	std:: cout <<"Reverse::Operation():" <<decorator4->Operation();
	std:: cout << "\n";
	std:: cout << "�ڶ�λѡ�ֶ���:\n";
	std:: cout << "Front::Operation():" << decorator5->Operation();
	std:: cout << "\n";
	std:: cout << "����λѡ�ֶ���:\n";
	std:: cout << "Back::Operation():" << decorator6->Operation();
	std:: cout << "\n";
	std:: cout << "****************Decorator��װ�Σ����ģʽ����****************:\n";
	delete simple1;
	delete simple2;
	delete simple3;
	delete simple4;
	delete  decorator1;
	delete decorator2;
	delete decorator3;
	delete decorator4;
	delete decorator5;
	delete decorator6;

	return 0;
}
