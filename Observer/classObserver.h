#pragma once
#include<iostream>
#include<string>
#include<list>
#include<vector>
#include"../Match.h"

class Observer;
class Subject;
class MatchObserver;
class PlaceSubject;

//Observer观察者抽象类
class Observer {
public:
	virtual ~Observer() {}
	//Observer的update虚函数，监听事件发生后进行数据修改
	virtual void update()=0;
};

//Subject发布者抽象类(必须放在MatchObserver之前)
class Subject {
public:
	//Subject的构造函数。赋值changed_为false
	Subject() { changed_ = false; }
	//添加观察者对象
	void attach(Observer* observer) {
		observers_.push_back(observer);
		observer->update();
	}
	//删除观察者对象
	void detach(Observer* observer) {
		observers_.remove(observer);
		delete observer;
	}
	//通知观察者更新消息
	void Notify() {
		if (changed_)
			for (auto x : observers_)
				x->update();
		changed_ = false;
	}
	//有数据改变了，更改changed_
	void DataChange() {
		changed_ = true;
	}
	//输出有多少个观察者附着在发布者上
	void HowManyObserver() {
		std::cout << "There are " << observers_.size() << " observers in the std::list.\n";
	}
private:
	//定义一个集合，用来存储多个观察者对象
	std::list<Observer*> observers_;
	//存储数值是否发生了变化
	bool changed_;
};
//发布者抽象子实现类
class PlaceSubject :public Subject {
private:
	//比赛地点
	std::string place_;
public:
	//PlaceSubject的构造函数，创建地点
	PlaceSubject(std::string place) {
		place_ = place;
		std::cout << "created a PlaceSubject , the place is " << place_ << std::endl << std::endl;;
	}
	//设置Match
	void SetPlace(std::string place) {
		std::cout << "Now change the data of PlaceSubject to " << place << std::endl;
		this->place_ = place;
		DataChange();
		Notify();
	}
	//得到Match
	std::string GetPlace() {
		return place_;
	}
};

//具体Observer观察者实现类
class MatchObserver :public Observer {
private:
	Match* match_;
	PlaceSubject* placesubject_;
public:
	//MatchObserver的构造函数，进行赋值和绑定PlaceSubject
	MatchObserver(PlaceSubject* placesubject, Match* match) {
		std::cout << "created a MatchObserver,the match is" << match->GetName()<< std::endl;
		match_ = match;
		std::cout << "the MatchObserver named " << match_->GetName() << " is attached" << std::endl;
		placesubject_ = placesubject;
		placesubject_->attach(this);
		std::cout << std::endl;
	}
	//MatchObserver的析造函数，输出相应提示语句
	~MatchObserver() {
		std::cout << "goodbye,I was the match :" << match_->GetName() << std::endl;
		match_->SetPlace("");
	}
	//监听到通知后进行数据修改
	void update() {
		this->match_->SetPlace(placesubject_->GetPlace());
		std::cout << "the place of " << match_->GetName() << " now is " << match_->GetPlace() << std::endl;
	}
	//得到该MatchObserver存储的matchname
	std::string GetMatchObserverName() {
		return   match_->GetName();
	}
};
