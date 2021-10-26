#pragma once
#include <iostream>
#include <vector>


//球拍制造
//球拍制造说明

class  Racket {     //球拍
public:
	std::vector<std::string> pro;
	void process()const {
		for (size_t i = 0; i < pro.size(); i++) {
			std::cout << std::endl << "Racket : 第" << (i + 1) << "步: ";
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


class Manual {     //球拍制作说明
public:
	std::vector<std::string> con;
	void content()const {
		for (size_t i = 0; i < con.size(); i++) {
			std::cout << std::endl << "Manual : 手册内容" << std::endl;
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

class Builder {    //生成器
public:
	virtual ~Builder() {}//析构函数
	virtual void frame() const = 0;//球拍框架
	virtual void face() const = 0;//球拍面
	virtual void handle() const = 0;//球拍柄
	virtual void bond() const = 0;//粘合

};

class tabletennisBatsBuilder : public Builder {  //乒乓球拍生成器
private:

	Racket* racket;
public:

	tabletennisBatsBuilder() {//构造函数
		this->Reset();
	}

	~tabletennisBatsBuilder() {//析构函数
		delete racket;
	}

	void Reset() {//动态申请Racket
		this->racket = new Racket();
	}

	void frame() const override {//制作乒乓球框架
		this->racket->pro.push_back("制作乒乓球框架");
	}
	void face() const override {//制作乒乓球拍面
		this->racket->pro.push_back("制作乒乓球拍面");
	}
	void handle() const override {//制作乒乓球拍柄
		this->racket->pro.push_back("制作乒乓球拍柄");
	}
	void bond() const override {//粘合乒乓球球拍
		this->racket->pro.push_back("粘合乒乓球球拍");

	}

	void Get() {//取得乒乓球拍制作过程

		racket->process();

	}
};

class badmintonBuilder : public Builder {//羽毛球拍生成器
private:

	Racket* racket;
public:

	badmintonBuilder() {//构造函数
		this->Reset();
	}

	~badmintonBuilder() {//析构函数
		delete racket;
	}

	void Reset() {//动态申请
		this->racket = new Racket();
	}

	void frame() const override {//制作羽毛球框架
		this->racket->pro.push_back("制作羽毛球框架");
	}
	void face() const override {//制作羽毛球拍面
		this->racket->pro.push_back("制作羽毛球拍面");
	}
	void handle() const override {//制作羽毛球拍柄
		this->racket->pro.push_back("制作羽毛球拍柄");
	}
	void bond() const override {//粘合羽毛球球拍
		this->racket->pro.push_back("粘合羽毛球球拍");

	}

	void Get() {//取得羽毛球拍制作过程

		racket->process();

	}
};
class tabletennisBatsmanualBuilder : public Builder {//乒乓球拍手册生成器
private:

	Manual* manual;
public:

	tabletennisBatsmanualBuilder() {//构造函数
		this->Reset();
	}

	~tabletennisBatsmanualBuilder() {//析构函数
		delete manual;
	}

	void Reset() {//动态申请
		this->manual = new Manual();
	}

	void frame() const override {//制作乒乓球框架说明
		this->manual->con.push_back("制作乒乓球框架说明......");
	}
	void face() const override {//制作乒乓球拍面说明
		this->manual->con.push_back("制作乒乓球拍面说明......");
	}
	void handle() const override {//制作乒乓球拍柄说明
		this->manual->con.push_back("制作乒乓球拍柄说明......");
	}
	void bond() const override {//粘合乒乓球球拍说明
		this->manual->con.push_back("粘合乒乓球球拍说明......");

	}


	void Get() {//取得乒乓球拍说明

		manual->content();

	}
};

class badmintonmanualBuilder : public Builder {//羽毛球拍说明
private:

	Manual* manual;
public:

	badmintonmanualBuilder() {//构造函数
		this->Reset();
	}

	~badmintonmanualBuilder() {//析构函数
		delete manual;
	}

	void Reset() {//动态申请
		this->manual = new Manual();
	}

	void frame() const override {//制作羽毛球框架说明
		this->manual->con.push_back("制作羽毛球框架说明......");
	}
	void face() const override {//制作羽毛球拍面说明
		this->manual->con.push_back("制作羽毛球拍面说明......");
	}
	void handle() const override {//制作羽毛球拍柄说明
		this->manual->con.push_back("制作羽毛球拍柄说明......");
	}
	void bond() const override {//粘合羽毛球球拍说明
		this->manual->con.push_back("粘合羽毛球球拍说明......");

	}

	void Get() {//取得羽毛球拍说明

		manual->content();

	}
};



class Director {//主管负责按照特定顺序执行生成步骤

private:
	Builder* builder;
public:

	void set_builder(Builder* builder) {//取得生成器
		this->builder = builder;
	}

	void BuildRacket() {//顺序生成步骤

		this->builder->frame();
		this->builder->face();
		this->builder->handle();
		this->builder->bond();
	}


};


void ClientCode(Director& director)//测试函数
{
	//测试乒乓球拍制作过程
	tabletennisBatsBuilder* pingpong = new tabletennisBatsBuilder();
	director.set_builder(pingpong);
	std::cout << "乒乓球拍制作过程:\n";
	director.BuildRacket();

	pingpong->Get();

	delete pingpong;

	//测试羽毛球拍制作过程
	badmintonBuilder* badminton = new  badmintonBuilder();
	director.set_builder(badminton);
	std::cout << "羽毛球拍制作过程:\n";
	director.BuildRacket();

	badminton->Get();

	delete  badminton;

	//测试乒乓球拍制作过程说明
	tabletennisBatsmanualBuilder* pingpongm = new tabletennisBatsmanualBuilder();
	director.set_builder(pingpongm);
	std::cout << "乒乓球拍制作过程说明:\n";
	director.BuildRacket();

	pingpongm->Get();
	delete pingpongm;


	//测试羽毛球拍制作过程说明
	badmintonmanualBuilder* badmintonm = new  badmintonmanualBuilder();
	director.set_builder(badmintonm);
	std::cout << "羽毛球拍制作过程说明:\n";
	director.BuildRacket();
	badmintonm->Get();
	delete  badmintonm;
}

void builderTest() {//测试接口
	std::cout << "*****************Builder(生成器)设计模式**********" << std::endl;
	Director* director = new Director();
	ClientCode(*director);
	delete director;
	std::cout << "**************************************************" << std::endl;
}
