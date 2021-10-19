#pragma once
#include <iostream>
using namespace std;
class Fencing {
public:
	std::string Operation1() const {
		return "录入击剑比赛选手信息!\n";
	}
	std::string Operation2() const {
		return "生成击剑比赛!\n";
	}
	// ...
	std::string OperationN() const {
		return "比赛完成，记录名次!\n";
	}
};

class Swimming {
public:
	std::string Operation1() const {
		return "录入游泳选手信息!\n";
	}
	std::string Operation2() const {
		return "生成游泳比赛!\n";
	}
	// ...
	std::string OperationN() const {
		return "比赛完成，记录名次!\n";
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
		std::string result = "Facade 初始化比赛项目:\n";
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