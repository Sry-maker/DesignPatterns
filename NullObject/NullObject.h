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
	string getName() { return "Not Available in coustomer database"; };
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

string CustomerFactory::name[3] = { "Rob","Joe","Julie" };

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

void nullObjectTest()
{
	std::cout << "****************  以下为NullObject（空对象）设计模式  ******************" << std::endl;
	cout << "CustomerFactory::getCustomer : created a AbstractCustomerFactory" << endl;
	AbstractCustomer* c1 = CustomerFactory::getCustomer("Rob");
	AbstractCustomer* c2 = CustomerFactory::getCustomer("Mickel");
	AbstractCustomer* c3 = CustomerFactory::getCustomer("Joe");
	AbstractCustomer* c4 = CustomerFactory::getCustomer("Julie");
	cout << "AbstractCustomer::getName : get object" << endl;
	cout << "Rob: " << c1->getName() << endl;
	cout << "Mickel: " << c2->getName() <<" "<<"This is a null object"<<endl;
	cout << "Joe: " << c3->getName() << endl;
	cout << "Juile: " << c4->getName() << endl;

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
