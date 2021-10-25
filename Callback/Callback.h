#pragma once

#ifndef __CALLBACK_H__
#define __CALLBACK_H__

#include<iostream>
using namespace::std;

//定义一个的接口
class CallBack {
public:
	virtual void setNOCResult(const char* result)  const = 0;
};

//主办城市奥运会组委会,编写呈交给国际奥委会工作报告
class NOC {
public:
	NOC(CallBack* mCallBack2) :mCallBack(mCallBack2) {
	cout<<"NOC::NOC():Create a National Olympic Committees"<<endl;
	}
	~NOC() {}

	//编写呈交给国际奥委会工作报告
	void caculateNOC() {
		cout << "NOC::caculateNOC():Generates a work report" << endl;
		mCallBack->setNOCResult("本届奥运会工作报告");
	}
private:
	CallBack* mCallBack;
};


//国际奥委会，实现接口callback
class IOC :public CallBack {
public:
	IOC() {
		cout << "IOC::IOC():Create a International Olympic Committees" << endl;
		mNOC = new NOC(this);
	}
	~IOC() {
		delete mNOC;
	}
	//查看工作报告
	void readReport() {
		cout << "IOC::readReport():Call NOC to build" << endl;
		mNOC->caculateNOC();
	}
	//实现后的回调函数，接收回调的值,即工作报告
	void setNOCResult(const char* result) const {
		cout << "IOC::setNOCResult():" << result << endl;
	}
private:
	NOC* mNOC;
};

#endif
