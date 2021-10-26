#pragma once
#include <iostream>
#include <unordered_map>
#include <string>


//场地运动规范 足球、乒乓球、冰球     球门、球网、球拍规范、护具、球杆
enum Type {
	Football = 0,//足球
	Pingpong,    //乒乓球
	Icehockey    //冰球

};


class Prototype {//原型
protected:
	std::string prototypename; //运动项目
	double length;        //场地长度
	double width;         //场地宽度


public:
	Prototype() {}//构造函数
	Prototype(std::string prototype_name) {
		this->prototypename = prototype_name;
	}
	virtual ~Prototype() {}//析构函数
	virtual Prototype* Clone() const = 0;//根据原型构造新型
	virtual void assign(double length, double width) {//赋值
		this->length = length;
		this->width = width;
	}
	virtual void standard() const = 0;//规范打印
};


class FootballPrototype : public Prototype {//足球场地
private:
	std::string goalstandard;//足球球门规范

public:
	FootballPrototype(std::string prototype_name, std::string goal_standard)//构造函数
		: Prototype(prototype_name), goalstandard(goal_standard) {
	}

	Prototype* Clone() const override {//构造新型
		return new  FootballPrototype(*this);
	}
	void standard() const override {//规范打印
		std::cout << "FootballPrototype::standard : " << std::endl << prototypename << ":" << std::endl;
		std::cout << "场地长度:" << length << std::endl << "场地宽度:" << width << std::endl << "足球球门规范:" << goalstandard << std::endl << std::endl;
	}
};


class PingpongPrototype : public Prototype {//乒乓场地
private:
	std::string netstandard;//球网规范
	std::string racketstandard;//球拍规范

public:
	PingpongPrototype(std::string prototype_name, std::string net_standard, std::string racket_standard)//构造函数
		: Prototype(prototype_name), netstandard(net_standard), racketstandard(racket_standard) {
	}

	Prototype* Clone() const override {//构造新型
		return new  PingpongPrototype(*this);
	}
	void standard() const override {//规范打印
		std::cout << "PingpongPrototype::standard : " << std::endl << prototypename << ":" << std::endl;
		std::cout << "场地长度:" << length << std::endl << "场地宽度:" << width << std::endl << "乒乓球球网规范:" << netstandard << std::endl << "乒乓球球拍规范:" << racketstandard << std::endl << std::endl;
	}
};

class icehockeyPrototype : public Prototype {//冰球场地
private:
	std::string goalstandard;//球门规范
	std::string clubstandard;//球杆规范

public:
	icehockeyPrototype(std::string prototype_name, std::string goal_standard, std::string club_standard)//构造函数
		: Prototype(prototype_name), goalstandard(goal_standard), clubstandard(club_standard) {
	}

	Prototype* Clone() const override {//构造新型
		return new  icehockeyPrototype(*this);
	}
	void standard() const override {//规范打印
		std::cout << "icehockeyPrototype::standard : " << std::endl << prototypename << ":" << std::endl;
		std::cout << "场地长度:" << length << std::endl << "场地宽度:" << width << std::endl << "冰球球网规范:" << goalstandard << std::endl << "冰球球杆规范:" << clubstandard << std::endl << std::endl;
	}
};


class PrototypeFactory {//原型
private:
	std::unordered_map<Type, Prototype*, std::hash<int>> prototypes_;

public:
	PrototypeFactory() {//构造函数，三个具体原型
		prototypes_[Type::Football] = new FootballPrototype("足球规范", "足球门应设在每条球门线的中央，由两根相距7.32米、与西面角旗点相等距离 ......");
		prototypes_[Type::Pingpong] = new PingpongPrototype("乒乓球规范 ", "球网装置包括球网、悬网绳、网柱及将它们固定在球台上的夹钳部分......", "球拍的大小，形状和重量不限，但底板应平整、坚硬......");
		prototypes_[Type::Icehockey] = new PingpongPrototype("冰球球规范 ", "冰球项目中，球门的宽度是180厘米，就是1米8宽......", "用木质材料制成，从根部至杆柄端不能长于147厘米......");
	}


	~PrototypeFactory() {//析构函数
		delete prototypes_[Type::Football];
		delete prototypes_[Type::Pingpong];
		delete prototypes_[Type::Icehockey];
	}

	Prototype* CreatePrototype(Type type) {//返回某个具体原型
		return prototypes_[type]->Clone();
	}

};

void Client(PrototypeFactory& prototype_factory) {//测试函数

	//测试足球
	Prototype* prototype = prototype_factory.CreatePrototype(Type::Football);
	prototype->assign(105, 70);
	prototype->standard();
	delete prototype;

	std::cout << std::endl;
	//测试乒乓球
	prototype = prototype_factory.CreatePrototype(Type::Pingpong);
	prototype->assign(2.7, 1.5);
	prototype->standard();
	delete prototype;

	std::cout << std::endl;
	//测试冰球
	prototype = prototype_factory.CreatePrototype(Type::Icehockey);
	prototype->assign(61, 30);
	prototype->standard();
	delete prototype;
}

void prototypeTest()
{
	std::cout << "*****************Prototype(原型)设计模式**********" << std::endl << std::endl;
	PrototypeFactory* prototype_factory = new PrototypeFactory();
	Client(*prototype_factory);
	delete prototype_factory;
	std::cout << "**************************************************" << std::endl << std::endl;
}
