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
	NOC(CallBack* mCallBack2) :mCallBack(mCallBack2) {}
	~NOC() {}

	//��д�ʽ������ʰ�ί�Ṥ������
	void caculateNOC() {
		mCallBack->setNOCResult("������˻Ṥ������");
	}



private:
	CallBack* mCallBack;
};


//���ʰ�ί�ᣬʵ�ֽӿ�callback
class IOC :public CallBack {
public:
	IOC() {
		mFinace = new NOC(this);
	}
	~IOC() {
		delete mFinace;
	}
	//�鿴��������
	void readReport() {
		cout << "IOC readReport" << endl;
		mFinace->caculateNOC();
	}
	//ʵ�ֺ�Ļص����������ջص���ֵ,����������
	void setNOCResult(const char* result) const {
		cout << "result:" << result << endl;
	}
private:
	NOC* mFinace;
};

#endif
