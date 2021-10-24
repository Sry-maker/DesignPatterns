#pragma once
#include <iostream>
using namespace std;
/***************************************************************************
  ��  ���ƣ�Fencing
  ��    �ܣ�������ɻ�������
  ˵    ����
***************************************************************************/
class Fencing {
public:
	std::string enterAthlete() const {
		return "Fencing::enterAthlete:¼���������ѡ����Ϣ!\n";
	}
	std::string generateCompetition() const {
		return "Fencing::generateCompetition:���ɻ�������!\n";
	}
	// ...
	std::string settlement() const {
		return "Fencing::settlement:������ɣ���¼����!\n";
	}
};
/***************************************************************************
  ��  ���ƣ�Swimming
  ��    �ܣ����������Ӿ����
  ˵    ����
***************************************************************************/
class Swimming {
public:
	std::string enterAthlete() const {
		return "Swimming::enterAthlete:¼����Ӿѡ����Ϣ!\n";
	}
	std::string generateCompetition() const {
		return "Swimming::generateCompetition:������Ӿ����!\n";
	}
	// ...
	std::string settlement() const {
		return "Swimming::settlement:������ɣ���¼����!\n";
	}
};

/***************************************************************************
  ��  ���ƣ�Facade
  ��    �ܣ�����Facade��ɱ�����Ŀ�ĳ�ʼ������
  ˵    ����Init ��������Ŀ���г�ʼ����ֻ�о�����Ӿ�ͻ�������
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
		std::string result = "Facade::Init: ��ʼ��������Ŀ:\n";
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
	std::cout << "*************** facadeģʽչʾ:*************************************\n";
	Fencing* fencing = new Fencing;
	Swimming* swimming = new Swimming;
	Facade* facade = new Facade(fencing, swimming);
	Init(facade);

	delete facade;

	return 0;
}