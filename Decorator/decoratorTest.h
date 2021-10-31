#pragma once
#include<iostream>
#include<string>
#include"Decorator.h"

//装饰器1，向前起跳
class Front : public Decorator {

public:

	Front(Diving* Diving) : Decorator(Diving) {
		std:: cout << "Front:: Create a motion 向前\n";
	}

	//该装饰器在调用父类operation的基础上实现自己的操作
	string Operation() const override {
		return "向前" + Decorator::Operation(); //返回动作描述
	}
};
//装饰器2，向后起跳
class Back : public Decorator {
public:
	Back(Diving* Diving) : Decorator(Diving) {
		std:: cout << "Back:: Create a motion 向后\n";
	}

	//该装饰器在调用父类operation的基础上实现自己的操作
	string Operation() const override {
		return "向后" + Decorator::Operation(); //返回动作描述
	}
};


//装饰器3:反身
class Reverse : public Decorator {
public:
	Reverse(Diving* Diving) : Decorator(Diving) {
		std:: cout << "Reverse:: Create a motion 反身\n";
	}

	//该装饰器在调用父类operation的基础上实现自己的操作
	string Operation() const override {
		return "反身" + Decorator::Operation(); //返回动作描述
	}
};
//装饰器4，翻腾半周数
class doubleAxel : public Decorator {
public:
	doubleAxel(Diving* Diving) : Decorator(Diving) {
		std:: cout << "doubleAxel:: Create a motion 翻腾三周半\n";
	}

	//该装饰器在调用父类operation的基础上实现自己的操作
	string Operation() const override {
		return "翻腾三周半" + Decorator::Operation(); //返回动作描述
	}
};
//装饰器5，转体半周数
class Tumble : public Decorator {
public:
	Tumble(Diving* Diving) : Decorator(Diving) {
		std:: cout << "Front:: Create a motion 转体1周半\n";
	}

	//该装饰器在调用父类operation的基础上实现自己的操作
	string Operation() const override {
		return "转体1周半" + Decorator::Operation(); //返回动作描述
	}
};

void Operation(Diving* Diving) {
	std:: cout << "选手动作:\n" << Diving->Operation(); //返回动作描述
}
int decoratorTest() {
	std:: cout << "****************以下为Decorator（装饰）设计模式****************:\n";
	Diving* simple1 = new Straight;//直体
	Diving* simple2 = new Pike;//屈体
	Diving* simple3 = new Tuck;//抱膝
	Diving* simple4 = new TAT;//翻腾兼转体
	Diving* decorator1 = new Tumble(simple1);//转体1周半
	Diving* decorator2 = new doubleAxel(simple2);//翻腾三周半
	Diving* decorator3 = new doubleAxel(decorator1);
	Diving* decorator4 = new Reverse(decorator2);//反身翻腾三周半屈体
	Diving* decorator5 = new Front(decorator3);//向前翻腾三周半转体1周半直体
	Diving* decorator6 = new Back(decorator2);//向后翻腾三周半屈体

	std:: cout << "第一位选手动作:\n";
	std:: cout <<"Reverse::Operation():" <<decorator4->Operation();
	std:: cout << "\n";
	std:: cout << "第二位选手动作:\n";
	std:: cout << "Front::Operation():" << decorator5->Operation();
	std:: cout << "\n";
	std:: cout << "第三位选手动作:\n";
	std:: cout << "Back::Operation():" << decorator6->Operation();
	std:: cout << "\n";
	std:: cout << "****************Decorator（装饰）设计模式结束****************:\n";
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
