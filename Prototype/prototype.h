#pragma once
#include <iostream>
#include <unordered_map>
#include <string>


//�����˶��淶 ����ƹ���򡢱���     ���š����������Ĺ淶�����ߡ����
enum Type {
	Football = 0,//����
	Pingpong,    //ƹ����
	Icehockey    //����

};


class Prototype {//ԭ��
protected:
	std::string prototypename; //�˶���Ŀ
	double length;        //���س���
	double width;         //���ؿ��


public:
	Prototype() {}//���캯��
	Prototype(std::string prototype_name) {
		this->prototypename = prototype_name;
	}
	virtual ~Prototype() {}//��������
	virtual Prototype* Clone() const = 0;//����ԭ�͹�������
	virtual void assign(double length, double width) {//��ֵ
		this->length = length;
		this->width = width;
	}
	virtual void standard() const = 0;//�淶��ӡ
};


class FootballPrototype : public Prototype {//���򳡵�
private:
	std::string goalstandard;//�������Ź淶

public:
	FootballPrototype(std::string prototype_name, std::string goal_standard)//���캯��
		: Prototype(prototype_name), goalstandard(goal_standard) {
	}

	Prototype* Clone() const override {//��������
		return new  FootballPrototype(*this);
	}
	void standard() const override {//�淶��ӡ
		std::cout << "FootballPrototype::standard : " << std::endl << prototypename << ":" << std::endl;
		std::cout << "���س���:" << length << std::endl << "���ؿ��:" << width << std::endl << "�������Ź淶:" << goalstandard << std::endl << std::endl;
	}
};


class PingpongPrototype : public Prototype {//ƹ�ҳ���
private:
	std::string netstandard;//�����淶
	std::string racketstandard;//���Ĺ淶

public:
	PingpongPrototype(std::string prototype_name, std::string net_standard, std::string racket_standard)//���캯��
		: Prototype(prototype_name), netstandard(net_standard), racketstandard(racket_standard) {
	}

	Prototype* Clone() const override {//��������
		return new  PingpongPrototype(*this);
	}
	void standard() const override {//�淶��ӡ
		std::cout << "PingpongPrototype::standard : " << std::endl << prototypename << ":" << std::endl;
		std::cout << "���س���:" << length << std::endl << "���ؿ��:" << width << std::endl << "ƹ���������淶:" << netstandard << std::endl << "ƹ�������Ĺ淶:" << racketstandard << std::endl << std::endl;
	}
};

class icehockeyPrototype : public Prototype {//���򳡵�
private:
	std::string goalstandard;//���Ź淶
	std::string clubstandard;//��˹淶

public:
	icehockeyPrototype(std::string prototype_name, std::string goal_standard, std::string club_standard)//���캯��
		: Prototype(prototype_name), goalstandard(goal_standard), clubstandard(club_standard) {
	}

	Prototype* Clone() const override {//��������
		return new  icehockeyPrototype(*this);
	}
	void standard() const override {//�淶��ӡ
		std::cout << "icehockeyPrototype::standard : " << std::endl << prototypename << ":" << std::endl;
		std::cout << "���س���:" << length << std::endl << "���ؿ��:" << width << std::endl << "���������淶:" << goalstandard << std::endl << "������˹淶:" << clubstandard << std::endl << std::endl;
	}
};


class PrototypeFactory {//ԭ��
private:
	std::unordered_map<Type, Prototype*, std::hash<int>> prototypes_;

public:
	PrototypeFactory() {//���캯������������ԭ��
		prototypes_[Type::Football] = new FootballPrototype("����淶", "������Ӧ����ÿ�������ߵ����룬���������7.32�ס�������������Ⱦ��� ......");
		prototypes_[Type::Pingpong] = new PingpongPrototype("ƹ����淶 ", "����װ�ð����������������������������ǹ̶�����̨�ϵļ�ǯ����......", "���ĵĴ�С����״���������ޣ����װ�Ӧƽ������Ӳ......");
		prototypes_[Type::Icehockey] = new PingpongPrototype("������淶 ", "������Ŀ�У����ŵĿ����180���ף�����1��8��......", "��ľ�ʲ����Ƴɣ��Ӹ������˱��˲��ܳ���147����......");
	}


	~PrototypeFactory() {//��������
		delete prototypes_[Type::Football];
		delete prototypes_[Type::Pingpong];
		delete prototypes_[Type::Icehockey];
	}

	Prototype* CreatePrototype(Type type) {//����ĳ������ԭ��
		return prototypes_[type]->Clone();
	}

};

void Client(PrototypeFactory& prototype_factory) {//���Ժ���

	//��������
	Prototype* prototype = prototype_factory.CreatePrototype(Type::Football);
	prototype->assign(105, 70);
	prototype->standard();
	delete prototype;

	std::cout << std::endl;
	//����ƹ����
	prototype = prototype_factory.CreatePrototype(Type::Pingpong);
	prototype->assign(2.7, 1.5);
	prototype->standard();
	delete prototype;

	std::cout << std::endl;
	//���Ա���
	prototype = prototype_factory.CreatePrototype(Type::Icehockey);
	prototype->assign(61, 30);
	prototype->standard();
	delete prototype;
}

void prototypeTest()
{
	std::cout << "*****************Prototype(ԭ��)���ģʽ**********" << std::endl << std::endl;
	PrototypeFactory* prototype_factory = new PrototypeFactory();
	Client(*prototype_factory);
	delete prototype_factory;
	std::cout << "**************************************************" << std::endl << std::endl;
}
