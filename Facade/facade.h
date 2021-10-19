#pragma once
#include <iostream>
using namespace std;
class Fencing {
public:
	std::string Operation1() const {
		return "¼���������ѡ����Ϣ!\n";
	}
	std::string Operation2() const {
		return "���ɻ�������!\n";
	}
	// ...
	std::string OperationN() const {
		return "������ɣ���¼����!\n";
	}
};

class Swimming {
public:
	std::string Operation1() const {
		return "¼����Ӿѡ����Ϣ!\n";
	}
	std::string Operation2() const {
		return "������Ӿ����!\n";
	}
	// ...
	std::string OperationN() const {
		return "������ɣ���¼����!\n";
	}
};


class Facade {
protected:
	Fencing* fencing_;
	Swimming* swimming_;
	
public:	
	Facade(
		Fencing* fencing = nullptr,
		Swimming* swimming= nullptr) {
		
		this->fencing_ = fencing ? fencing_ = fencing : new Fencing;
		this->swimming_ = swimming ? swimming_ = swimming : new Swimming;
	}
	~Facade() {
		delete fencing_;
		delete swimming_;
	}
	
	std::string Init() {
		std::string result = "Facade ��ʼ��������Ŀ:\n";
		result += this->fencing_->Operation1();
		result += this->swimming_->Operation1();
		result += this->fencing_->Operation2();
		result += this->swimming_->Operation2();
		return result;
	}
};


void Init(Facade* facade) {
	// ...
	std::cout << facade->Init();
	// ...
}
int facadeTest() {
	Fencing* fencing = new Fencing;
	Swimming* swimming = new Swimming;
	Facade* facade = new Facade(fencing, swimming);
	Init(facade);

	delete facade;

	return 0;
}