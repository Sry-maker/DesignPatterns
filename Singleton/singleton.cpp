#include <iostream>
#include <mutex>
#include <string>
using namespace std;

//单例模式
class Singleton
{

private:
	static Singleton* pinstance;
	static mutex mut;     //线程安全

protected:
	string Olympicname;   //奥林匹克运动会项目
	string recordholder;  //记录保持者
	string record;        //记录
	Singleton(const string name, const string holder, const string rec) : Olympicname(name), recordholder(holder), record(rec)//构造函数
	{
	}
	~Singleton() {}//析构函数


public:

	Singleton(Singleton& other) = delete;  //单例模式不可以进行的操作
	void operator=(const Singleton&) = delete;

	static Singleton* GetInstance(const string& name, const string& holder, const string& rec);//获取实例


	void recorddeclaration()   //记录打印
	{
		cout << "Singleton::recorddeclaration : " << endl << "奥林匹克运动会项目: " << Olympicname << endl << "纪录保持者: " << recordholder << endl << "记录: " << record << endl;
	}


	string Olympicnamevalue() const {//返回奥林匹克运动会项目
		return Olympicname;
	}
	string recordholdervalue() const {//返回纪录保持者
		return recordholder;
	}
	string recordvalue() const {//返回记录
		return record;
	}
};


Singleton* Singleton::pinstance{ nullptr };
mutex Singleton::mut;


Singleton* Singleton::GetInstance(const string& name, const string& holder, const string& rec)//获取实例
{
	lock_guard<std::mutex> lock(mut);
	if (pinstance == nullptr)//如果为nullptr则创建，否则直接返回已经创建好的
	{
		pinstance = new Singleton(name, holder, rec);
	}
	return pinstance;
}

void singletonTest() {//测试函数


	cout << "*****************Singleton(单例)设计模式**********" << endl << endl;

	cout << "记录创建" << endl;
	Singleton* singleton = Singleton::GetInstance("男子100米", "博尔特", "9秒58");
	singleton->recorddeclaration();

	cout << endl << endl << endl;
	cout << "记录查询" << endl;
	Singleton* singl = Singleton::GetInstance("", "", "");
	singl->recorddeclaration();

	cout << "**************************************************" << endl << endl;
}

int main()
{

	singletonTest();
	return 0;
}