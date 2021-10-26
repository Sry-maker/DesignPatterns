#pragma once
#include<iostream>
#include<algorithm>

using namespace std;

//Target定义一种行为的接口，这里指选手正常的语言：
class Target {
public:
	virtual ~Target() = default;

	virtual string Request() const {
		return "选手A:  Target::Request:I'm very glad that I won this game.";
	}
};

//Adaptee包含了另一种行为的接口，但接口不能被前一种行为的主题识别，需要一个Adapter
//这里指选手出故障的语言系统：
class Adaptee {
public:
	string SpecificRequest() const {
		return ".emag siht ni trap ekat ot duorp yrev m'I, detaefed hguohT";
	}
};

//Adapter使两种不同的接口之间能够互相交流，这里即为将出故障的语言转换为正常：
class Adapter : public Target {
private:
	Adaptee* adaptee_;

public:
	Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}
	string Request() const override {
		string to_reverse = this->adaptee_->SpecificRequest();
		reverse(to_reverse.begin(), to_reverse.end());
		return "选手B:(转换后)Adapter::Request:" + to_reverse;
	}
};


void AdapterClientCode(const Target* target) {
	std::cout << target->Request();
}

void adapterTest() {
	std::cout << "**********以下为Adapter(适配器)设计模式**********\n\n";

	std::cout << "记者：欢迎来到乒乓球比赛的赛后采访。" << "\n";
	std::cout << "现在是获胜方的采访时间:\n";
	Target* target = new Target;
	AdapterClientCode(target);
	std::cout << "\n\n";
	Adaptee* adaptee = new Adaptee;

	std::cout << "记者：好的，谢谢。现在是败方选手采访时间:\n";

	std::cout << "选手B: Adaptee::SpecificRequest:" << adaptee->SpecificRequest();
	std::cout << "\n\n";

	std::cout << "记者: 借助适配器模式，这位选手想要表达的是:\n";
	Adapter* adapter = new Adapter(adaptee);
	AdapterClientCode(adapter);

	std::cout << "\n\n";
	std::cout << "**********Adapter(适配器)设计模式结束**********\n\n";

	delete target;
	delete adaptee;
	delete adapter;
}