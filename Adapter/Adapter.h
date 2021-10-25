#pragma once
#include<iostream>
#include<algorithm>

using namespace std;

//Target定义一种行为的接口，这里指机器人正常的语言系统：
class Target {
public:
	virtual ~Target() = default;

	virtual string Request() const {
		return "机器人A:  Target::Request:I'm very glad that I won this game.";
	}
};

//Adaptee包含了另一种行为的接口，但接口不能被前一种行为的主题识别，需要一个Adapter
//这里指机器人出故障的语言系统：
class Adaptee {
public:
	string SpecificRequest() const {
		return ".emag siht ni trap ekat ot duorp yrev m'I, detaefed hguohT";
	}
};

//Adapter使两种不同的接口之间能够互相交流，这里即为将倒置的语言转换为正常：
class Adapter : public Target {
private:
	Adaptee* adaptee_;

public:
	Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}
	string Request() const override {
		string to_reverse = this->adaptee_->SpecificRequest();
		reverse(to_reverse.begin(), to_reverse.end());
		return "机器人B:(转换后)Adapter::Request:" + to_reverse;
	}
};


void AdapterClientCode(const Target* target) {
	std::cout << target->Request();
}

void adapterTest() {
	std::cout << "**********以下为Adapter(适配器)设计模式**********\n\n";

	std::cout << "记者：欢迎来到机器人拳击大赛的赛后采访。" << "\n";
	std::cout << "现在是获胜方的采访时间:\n";
	Target* target = new Target;
	AdapterClientCode(target);
	std::cout << "\n\n";
	Adaptee* adaptee = new Adaptee;

	std::cout << "记者：好的，谢谢。现在是败方机器人选手采访时间，但它由于遭到KO，头部的语言系统出了一点故障，显示的句子是首尾倒置的，我很难看懂:\n";

	std::cout << "机器人B: Adaptee::SpecificRequest:" << adaptee->SpecificRequest();
	std::cout << "\n\n";

	std::cout << "记者: 但现在有适配器模式的帮助，我能够理解这位选手所表达的了:\n";
	Adapter* adapter = new Adapter(adaptee);
	AdapterClientCode(adapter);

	std::cout << "\n\n";
	std::cout << "**********Adapter(适配器)设计模式结束**********\n\n";

	delete target;
	delete adaptee;
	delete adapter;
}