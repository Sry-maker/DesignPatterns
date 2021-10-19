#pragma once
#include <iostream>

class Subject {
public:
	virtual void Request() const = 0;
};

class RealSubject : public Subject {
public:
	void Request() const override {
		std::cout << "RealSubject: �����˶�Ա����.\n";
	}
};

class Proxy : public Subject {
	
private:
	RealSubject* real_subject_;

	bool CheckAccess() const {
	
		std::cout << "Proxy: �ڷ�����ʵ����֮ǰ������Ȩ��\n";
		return true;
	}
	void LogAccess() const {
		std::cout << "Proxy: ��¼����ʱ��\n";
	}

	
public:
	Proxy(RealSubject* real_subject) : real_subject_(new RealSubject(*real_subject)) {
	}

	~Proxy() {
		delete real_subject_;
	}
	
	void Request() const override {
		if (this->CheckAccess()) {
			this->real_subject_->Request();
			this->LogAccess();
		}
	}
};

void ClientCode(const Subject& subject) {
	// ...
	subject.Request();
	// ...
}

int proxyTest() {
	
	std::cout << "ֱ�Ӵ���ͻ�������:\n";
	RealSubject* real_subject = new RealSubject;
	ClientCode(*real_subject);
	std::cout << "\n";
	std::cout << "ͨ��proxy��������:\n";
	Proxy* proxy = new Proxy(real_subject);
	ClientCode(*proxy);

	delete real_subject;
	delete proxy;

	return 0;
}