#pragma once
#include <iostream>
#include <mutex>
#include <string>


//单例模式
class Singleton
{

private:
	static Singleton* pinstance;
	static std::mutex mut;     //线程安全

protected:
	std::string Olympicname;   //奥林匹克运动会项目
	std::string recordholder;  //记录保持者
	std::string record;        //记录
	Singleton(const std::string name, const std::string holder, const std::string rec) : Olympicname(name), recordholder(holder), record(rec)//构造函数
	{
	}
	~Singleton() {}//析构函数


public:

	Singleton(Singleton& other) = delete;  //单例模式不可以进行的操作
	void operator=(const Singleton&) = delete;

	static Singleton* GetInstance(const std::string& name, const std::string& holder, const std::string& rec);//获取实例


	void recorddeclaration()   //记录打印
	{
		std::cout << "Singleton::recorddeclaration : " << std::endl << "奥林匹克运动会项目: " << Olympicname << std::endl << "纪录保持者: " << recordholder << std::endl << "记录: " << record <<std:: endl;
	}


	std::string Olympicnamevalue() const {//返回奥林匹克运动会项目
		return Olympicname;
	}
	std::string recordholdervalue() const {//返回纪录保持者
		return recordholder;
	}
	std::string recordvalue() const {//返回记录
		return record;
	}
};


Singleton* Singleton::pinstance{ nullptr };
std::mutex Singleton::mut;


Singleton* Singleton::GetInstance(const std::string& name, const std::string& holder, const std::string& rec)//获取实例
{
	std::lock_guard<std::mutex> lock(mut);
	if (pinstance == nullptr)//如果为nullptr则创建，否则直接返回已经创建好的
	{
		pinstance = new Singleton(name, holder, rec);
	}
	return pinstance;
}

void singletonTest() {//测试函数


	std::cout << "*****************Singleton(单例)设计模式**********" << std::endl << std::endl;

	std::cout << "记录创建" << std::endl;
	Singleton* singleton = Singleton::GetInstance("男子100米", "博尔特", "9秒58");
	singleton->recorddeclaration();

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "记录查询" << std::endl;
	Singleton* singl = Singleton::GetInstance("", "", "");
	singl->recorddeclaration();

	std::cout << "**************************************************" << std::endl << std::endl;
}

