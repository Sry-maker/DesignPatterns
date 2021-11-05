#pragma once
#include<iostream>
#include<string>

using namespace std;

//创建一个抽象类AbstractCustomer。
class AbstractCustomer
{
public:
	AbstractCustomer() {};
	virtual ~AbstractCustomer() {};
	virtual bool isNull() = 0;
	virtual string getName() = 0;

protected:
	string name;
};

//创建扩展了抽象类AbstractCustomer的实体类RealCustomer。
class RealCustomer :AbstractCustomer
{
public:
	RealCustomer(string tname) { name = tname; };
	~RealCustomer() {};
	bool isNull() { return false; };
	string getName() { return name; };
};

//创建扩展了抽象类AbstractCustomer的空类NullCustomer。
class NullCustomer :AbstractCustomer
{
public:
	NullCustomer() {};
	~NullCustomer() {};
	bool isNull() { return true; };
	string getName() { return "本次比赛没有该项目，请重新输入项目名称"; };
};

//创建CustomerFactory类，用来获取实体类或空类的实例
class CustomerFactory
{
public:
	CustomerFactory() {};
	~CustomerFactory() {};
	static string name[3];
	static AbstractCustomer* getCustomer(string tname);
};

string CustomerFactory::name[3] = { "羽毛球","跳水","乒乓球" };

AbstractCustomer* CustomerFactory::getCustomer(string tname)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		if (name[i] == tname)
		{
			return (AbstractCustomer*)new RealCustomer(tname);
		}
	}
	return (AbstractCustomer*)new NullCustomer();
}

void nullObjectTest(string name)
{
	std::cout << "****************  以下为NullObject（空对象）设计模式  ******************" << std::endl;
	std::cout << "CustomerFactory::getCustomer : created a AbstractCustomerFactory" << endl;
	AbstractCustomer* c1 = CustomerFactory::getCustomer("羽毛球");
	AbstractCustomer* c2 = CustomerFactory::getCustomer(name);
	AbstractCustomer* c3 = CustomerFactory::getCustomer("跳水");
	AbstractCustomer* c4 = CustomerFactory::getCustomer("乒乓球");
	std::cout << "AbstractCustomer::getName : get object" << endl;
	std::cout << "羽毛球: " << c1->getName() << endl;
	std::cout <<name<<": "<< c2->getName() <<" "<<"This is a null object"<<endl;
	std::cout << "跳水: " << c3->getName() << endl;
	std::cout << "乒乓球: " << c4->getName() << endl;

	delete c1;
	c1 = NULL;

	delete c2;
	c2 = NULL;

	delete c3;
	c3 = NULL;

	delete c4;
	c4 = NULL;

	std::cout << "****************  NullObject（空对象）设计模式结束  ******************" << std::endl;

}
void nullObjectTest()
{
	std::cout << "****************  以下为NullObject（空对象）设计模式  ******************" << std::endl;
	std::cout << "CustomerFactory::getCustomer : created a AbstractCustomerFactory" << endl;
	AbstractCustomer* c1 = CustomerFactory::getCustomer("羽毛球");
	AbstractCustomer* c2 = CustomerFactory::getCustomer("篮球");
	AbstractCustomer* c3 = CustomerFactory::getCustomer("跳水");
	AbstractCustomer* c4 = CustomerFactory::getCustomer("乒乓球");
	std::cout << "AbstractCustomer::getName : get object" << endl;
	std::cout << "羽毛球: " << c1->getName() << endl;
	std::cout << "篮球" << ": " << c2->getName() << " " << "This is a null object" << endl;
	std::cout << "跳水: " << c3->getName() << endl;
	std::cout << "乒乓球: " << c4->getName() << endl;

	delete c1;
	c1 = NULL;

	delete c2;
	c2 = NULL;

	delete c3;
	c3 = NULL;

	delete c4;
	c4 = NULL;

	std::cout << "****************  NullObject（空对象）设计模式结束  ******************" << std::endl;

}
