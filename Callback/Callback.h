#pragma once
#ifndef __CALLBACK_H__
#define __CALLBACK_H__
#include<iostream>
#include"..\Singleton\Singleton.h"

//定义一个的接口
class CallBack {
public:
	virtual void setNOCResult(void (*result)())  const = 0;
};

//主办城市奥运会组委会,编写呈交给国际奥委会工作报告
class NOC {
public:
	NOC(CallBack* mCallBack2) :mCallBack(mCallBack2) {
		std::cout << "NOC::NOC():Create a National Olympic Committees\n";
	}
	~NOC() {}

	//编写呈交给国际奥委会工作报告
	void caculateNOC() {
		std::cout << "NOC::caculateNOC():Generates a work report\n";
		singletoncreat();
		mCallBack->setNOCResult(singletonquery);
	}
private:
	CallBack* mCallBack;
};


//国际奥委会，实现接口callback
class IOC :public CallBack {
public:
	IOC() {
		std::cout << "IOC::IOC():Create a International Olympic Committees";
		mNOC = new NOC(this);
	}
	~IOC() {
		delete mNOC;
	}
	//查看工作报告
	void readReport() {
		std::cout << "IOC::readReport():Call NOC to build\n";
		mNOC->caculateNOC();
	}
	//实现后的回调函数，接收回调的值,即工作报告
	void setNOCResult(void(*result)()) const {
		std::cout << "IOC::setNOCResult():\n";
		(*result)();
	}
private:
	NOC* mNOC;
};

#endif
