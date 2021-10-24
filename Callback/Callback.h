#pragma once

#ifndef __CALLBACK_H__
#define __CALLBACK_H__

#include<iostream>
using namespace::std;

//����һ���Ľӿ�
class CallBack {
public:
	virtual void setNOCResult(const char* result)  const = 0;
};

//������а��˻���ί��,��д�ʽ������ʰ�ί�Ṥ������
class NOC {
public:
	NOC(CallBack* mCallBack2) :mCallBack(mCallBack2) {
	cout<<"NOC::NOC():Create a National Olympic Committees"<<endl;
	}
	~NOC() {}

	//��д�ʽ������ʰ�ί�Ṥ������
	void caculateNOC() {
		cout << "NOC::caculateNOC():Generates a work report" << endl;
		mCallBack->setNOCResult("������˻Ṥ������");
	}
private:
	CallBack* mCallBack;
};


//���ʰ�ί�ᣬʵ�ֽӿ�callback
class IOC :public CallBack {
public:
	IOC() {
		cout << "IOC::IOC():Create a International Olympic Committees" << endl;
		mNOC = new NOC(this);
	}
	~IOC() {
		delete mNOC;
	}
	//�鿴��������
	void readReport() {
		cout << "IOC::readReport():Call NOC to build" << endl;
		mNOC->caculateNOC();
	}
	//ʵ�ֺ�Ļص����������ջص���ֵ,����������
	void setNOCResult(const char* result) const {
		cout << "IOC::setNOCResult():" << result << endl;
	}
private:
	NOC* mNOC;
};

#endif
