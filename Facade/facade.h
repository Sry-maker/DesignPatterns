#pragma once
#include <iostream>
using namespace std;
/***************************************************************************
  类  名称：Fencing
  功    能：用来完成击剑比赛
  说    明：
***************************************************************************/
class Fencing {
public:
	std::string enterAthlete() const {
		return "Fencing::enterAthlete:录入击剑比赛选手信息!\n";
	}
	std::string generateCompetition() const {
		return "Fencing::generateCompetition:生成击剑比赛!\n";
	}
	// ...
	std::string settlement() const {
		return "Fencing::settlement:比赛完成，记录名次!\n";
	}
};
/***************************************************************************
  类  名称：Swimming
  功    能：用来完成游泳比赛
  说    明：
***************************************************************************/
class Swimming {
public:
	std::string enterAthlete() const {
		return "Swimming::enterAthlete:录入游泳选手信息!\n";
	}
	std::string generateCompetition() const {
		return "Swimming::generateCompetition:生成游泳比赛!\n";
	}
	// ...
	std::string settlement() const {
		return "Swimming::settlement:比赛完成，记录名次!\n";
	}
};

/***************************************************************************
  类  名称：Facade
  功    能：利用Facade完成比赛项目的初始化工作
  说    明：Init 对所有项目进行初始化，只列举了游泳和击剑比赛
***************************************************************************/
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
		std::string result = "Facade::Init: 初始化比赛项目:\n";
		result += this->fencing_->enterAthlete();
		result += this->swimming_->enterAthlete();
		result += this->fencing_->generateCompetition();
		result += this->swimming_->generateCompetition();
		return result;
	}
};


void Init(Facade* facade) {
	// ...
	std::cout << facade->Init();
	// ...
}
int facadeTest() {
	std::cout << "*************** facade模式展示:*************************************\n";
	Fencing* fencing = new Fencing;
	Swimming* swimming = new Swimming;
	Facade* facade = new Facade(fencing, swimming);
	Init(facade);

	delete facade;

	return 0;
}