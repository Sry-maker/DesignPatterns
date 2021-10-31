#pragma once
#ifndef __CALLBACK_H__
#define __CALLBACK_H__
#include<iostream>
#include"..\Singleton\Singleton.h"

//����һ���Ľӿ�
class CallBack {
public:
	virtual void setNOCResult(void (*result)())  const = 0;
};

//������а��˻���ί��,��д�ʽ������ʰ�ί�Ṥ������
class NOC {
public:
	NOC(CallBack* mCallBack2) :mCallBack(mCallBack2) {
		std::cout << "NOC::NOC():Create a National Olympic Committees\n";
	}
	~NOC() {}

	//��д�ʽ������ʰ�ί�Ṥ������
	void caculateNOC() {
		std::cout << "NOC::caculateNOC():Generates a work report\n";
		singletoncreat();
		mCallBack->setNOCResult(singletonquery);
	}
private:
	CallBack* mCallBack;
};


//���ʰ�ί�ᣬʵ�ֽӿ�callback
class IOC :public CallBack {
public:
	IOC() {
		std::cout << "IOC::IOC():Create a International Olympic Committees";
		mNOC = new NOC(this);
	}
	~IOC() {
		delete mNOC;
	}
	//�鿴��������
	void readReport() {
		std::cout << "IOC::readReport():Call NOC to build\n";
		mNOC->caculateNOC();
	}
	//ʵ�ֺ�Ļص����������ջص���ֵ,����������
	void setNOCResult(void(*result)()) const {
		std::cout << "IOC::setNOCResult():\n";
		(*result)();
	}
private:
	NOC* mNOC;
};

#endif
