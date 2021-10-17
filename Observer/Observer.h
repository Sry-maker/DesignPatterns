#pragma once
#include<iostream>
#include<cstring>
#include<list>
using namespace std;
class Observer;
class Subject;
class EventObserver;
class PlaceSubject;

void observerTest();

//Observer观察者抽象类
class Observer {
public:
	virtual ~Observer();
	//Observer的update虚函数，监听事件发生后进行数据修改
	virtual void update()=0;
};
//Subject发布者抽象类
class Subject {
public:
	//Subject的构造函数。赋值changed_为false
	Subject();
	//添加观察者对象
	void attach(Observer* observer);
	//删除观察者对象
	void detach(Observer* observer);
	//通知观察者更新消息
	void Notify();
	//有数据改变了，更改changed_
	void DataChange();
	//输出有多少个观察者附着在发布者上
	void HowManyObserver();
private:
	//定义一个集合，用来存储多个观察者对象
	list<Observer*> observers_;
	//存储数值是否发生了变化
	bool changed_;
};

//具体Observer观察者实现类
class EventObserver :public Observer {
private:
	string place_;
	string eventname_;
	PlaceSubject* placesubject_;
public:
	//EventObserver的构造函数，进行赋值和绑定PlaceSubject
	EventObserver(PlaceSubject*, string);
	//EventObserver的析造函数，输出相应提示语句
	~EventObserver();
	//监听到通知后进行数据修改
	void update();
	//得到该EventObserver存储的eventname
	string GetEventObserverName();
};

//发布者抽象子实现类
class PlaceSubject :public Subject {
private:
	//比赛地点
	string place_;
public:
	//PlaceSubject的构造函数，创建地点
	PlaceSubject(string);
	//设置Event
	void SetPlace(string);
	//得到Event
	string GetPlace();
};