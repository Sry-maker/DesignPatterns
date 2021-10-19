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
	NOC(CallBack* mCallBack2) :mCallBack(mCallBack2) {}
	~NOC() {}

	//编写呈交给国际奥委会工作报告
	void caculateNOC() {
		mCallBack->setNOCResult("本届奥运会工作报告");
	}



private:
	CallBack* mCallBack;
};


//国际奥委会，实现接口callback
class IOC :public CallBack {
public:
	IOC() {
		mFinace = new NOC(this);
	}
	~IOC() {
		delete mFinace;
	}
	//查看工作报告
	void readReport() {
		cout << "IOC readReport" << endl;
		mFinace->caculateNOC();
	}
	//实现后的回调函数，接收回调的值,即工作报告
	void setNOCResult(const char* result) const {
		cout << "result:" << result << endl;
	}
private:
	NOC* mFinace;
};

#endif
