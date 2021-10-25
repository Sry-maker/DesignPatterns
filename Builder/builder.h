#pragma once
#include <iostream>
#include <vector>


//��������
//��������˵��

class  Racket {     //����
public:
	std::vector<std::string> pro;
	void process()const {
		for (size_t i = 0; i < pro.size(); i++) {
			std::cout << std::endl << "Racket : ��" << (i + 1) << "��: ";
			if (pro[i] == pro.back()) {
				std::cout << pro[i];
			}
			else {
				std::cout << pro[i] << std::endl;
			}
		}
		std::cout << std::endl << std::endl << std::endl << std::endl;
	}
};


class Manual {     //��������˵��
public:
	std::vector<std::string> con;
	void content()const {
		for (size_t i = 0; i < con.size(); i++) {
			std::cout << std::endl << "Manual : �ֲ�����" << std::endl;
			if (con[i] == con.back()) {
				std::cout << "Manual : " << con[i];
			}
			else {
				std::cout << "Manual : " << con[i] << std::endl;
			}
		}
		std::cout << std::endl << std::endl << std::endl << std::endl;
	}
};

class Builder {    //������
public:
	virtual ~Builder() {}//��������
	virtual void frame() const = 0;//���Ŀ��
	virtual void face() const = 0;//������
	virtual void handle() const = 0;//���ı�
	virtual void bond() const = 0;//ճ��

};

class tabletennisBatsBuilder : public Builder {  //ƹ������������
private:

	Racket* racket;
public:

	tabletennisBatsBuilder() {//���캯��
		this->Reset();
	}

	~tabletennisBatsBuilder() {//��������
		delete racket;
	}

	void Reset() {//��̬����Racket
		this->racket = new Racket();
	}

	void frame() const override {//����ƹ������
		this->racket->pro.push_back("����ƹ������");
	}
	void face() const override {//����ƹ��������
		this->racket->pro.push_back("����ƹ��������");
	}
	void handle() const override {//����ƹ�����ı�
		this->racket->pro.push_back("����ƹ�����ı�");
	}
	void bond() const override {//ճ��ƹ��������
		this->racket->pro.push_back("ճ��ƹ��������");

	}

	void Get() {//ȡ��ƹ��������������

		racket->process();

	}
};

class badmintonBuilder : public Builder {//��ë����������
private:

	Racket* racket;
public:

	badmintonBuilder() {//���캯��
		this->Reset();
	}

	~badmintonBuilder() {//��������
		delete racket;
	}

	void Reset() {//��̬����
		this->racket = new Racket();
	}

	void frame() const override {//������ë����
		this->racket->pro.push_back("������ë����");
	}
	void face() const override {//������ë������
		this->racket->pro.push_back("������ë������");
	}
	void handle() const override {//������ë���ı�
		this->racket->pro.push_back("������ë���ı�");
	}
	void bond() const override {//ճ����ë������
		this->racket->pro.push_back("ճ����ë������");

	}

	void Get() {//ȡ����ë������������

		racket->process();

	}
};
class tabletennisBatsmanualBuilder : public Builder {//ƹ�������ֲ�������
private:

	Manual* manual;
public:

	tabletennisBatsmanualBuilder() {//���캯��
		this->Reset();
	}

	~tabletennisBatsmanualBuilder() {//��������
		delete manual;
	}

	void Reset() {//��̬����
		this->manual = new Manual();
	}

	void frame() const override {//����ƹ������˵��
		this->manual->con.push_back("����ƹ������˵��......");
	}
	void face() const override {//����ƹ��������˵��
		this->manual->con.push_back("����ƹ��������˵��......");
	}
	void handle() const override {//����ƹ�����ı�˵��
		this->manual->con.push_back("����ƹ�����ı�˵��......");
	}
	void bond() const override {//ճ��ƹ��������˵��
		this->manual->con.push_back("ճ��ƹ��������˵��......");

	}


	void Get() {//ȡ��ƹ������˵��

		manual->content();

	}
};

class badmintonmanualBuilder : public Builder {//��ë����˵��
private:

	Manual* manual;
public:

	badmintonmanualBuilder() {//���캯��
		this->Reset();
	}

	~badmintonmanualBuilder() {//��������
		delete manual;
	}

	void Reset() {//��̬����
		this->manual = new Manual();
	}

	void frame() const override {//������ë����˵��
		this->manual->con.push_back("������ë����˵��......");
	}
	void face() const override {//������ë������˵��
		this->manual->con.push_back("������ë������˵��......");
	}
	void handle() const override {//������ë���ı�˵��
		this->manual->con.push_back("������ë���ı�˵��......");
	}
	void bond() const override {//ճ����ë������˵��
		this->manual->con.push_back("ճ����ë������˵��......");

	}

	void Get() {//ȡ����ë����˵��

		manual->content();

	}
};



class Director {//���ܸ������ض�˳��ִ�����ɲ���

private:
	Builder* builder;
public:

	void set_builder(Builder* builder) {//ȡ��������
		this->builder = builder;
	}

	void BuildRacket() {//˳�����ɲ���

		this->builder->frame();
		this->builder->face();
		this->builder->handle();
		this->builder->bond();
	}


};


void ClientCode(Director& director)//���Ժ���
{
	//����ƹ��������������
	tabletennisBatsBuilder* pingpong = new tabletennisBatsBuilder();
	director.set_builder(pingpong);
	std::cout << "ƹ��������������:\n";
	director.BuildRacket();

	pingpong->Get();

	delete pingpong;

	//������ë������������
	badmintonBuilder* badminton = new  badmintonBuilder();
	director.set_builder(badminton);
	std::cout << "��ë������������:\n";
	director.BuildRacket();

	badminton->Get();

	delete  badminton;

	//����ƹ��������������˵��
	tabletennisBatsmanualBuilder* pingpongm = new tabletennisBatsmanualBuilder();
	director.set_builder(pingpongm);
	std::cout << "ƹ��������������˵��:\n";
	director.BuildRacket();

	pingpongm->Get();
	delete pingpongm;


	//������ë������������˵��
	badmintonmanualBuilder* badmintonm = new  badmintonmanualBuilder();
	director.set_builder(badmintonm);
	std::cout << "��ë������������˵��:\n";
	director.BuildRacket();
	badmintonm->Get();
	delete  badmintonm;
}

void builderTest() {//���Խӿ�
	std::cout << "*****************Builder(������)���ģʽ**********" << std::endl;
	Director* director = new Director();
	ClientCode(*director);
	delete director;
	std::cout << "**************************************************" << std::endl;
}
