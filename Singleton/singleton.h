#pragma once
#include <iostream>
#include <mutex>
#include <string>


//����ģʽ
class Singleton
{

private:
	static Singleton* pinstance;
	static std::mutex mut;     //�̰߳�ȫ

protected:
	std::string Olympicname;   //����ƥ���˶�����Ŀ
	std::string recordholder;  //��¼������
	std::string record;        //��¼
	Singleton(const std::string name, const std::string holder, const std::string rec) : Olympicname(name), recordholder(holder), record(rec)//���캯��
	{
	}
	~Singleton() {}//��������


public:

	Singleton(Singleton& other) = delete;  //����ģʽ�����Խ��еĲ���
	void operator=(const Singleton&) = delete;

	static Singleton* GetInstance(const std::string& name, const std::string& holder, const std::string& rec);//��ȡʵ��


	void recorddeclaration()   //��¼��ӡ
	{
		std::cout << "Singleton::recorddeclaration : " << std::endl << "����ƥ���˶�����Ŀ: " << Olympicname << std::endl << "��¼������: " << recordholder << std::endl << "��¼: " << record << std::endl;
	}


	std::string Olympicnamevalue() const {//���ذ���ƥ���˶�����Ŀ
		return Olympicname;
	}
	std::string recordholdervalue() const {//���ؼ�¼������
		return recordholder;
	}
	std::string recordvalue() const {//���ؼ�¼
		return record;
	}
};


Singleton* Singleton::pinstance{ nullptr };
std::mutex Singleton::mut;


Singleton* Singleton::GetInstance(const std::string& name, const std::string& holder, const std::string& rec)//��ȡʵ��
{
	std::lock_guard<std::mutex> lock(mut);
	if (pinstance == nullptr)//���Ϊnullptr�򴴽�������ֱ�ӷ����Ѿ������õ�
	{
		pinstance = new Singleton(name, holder, rec);
	}
	return pinstance;
}

void singletonTest() {//���Ժ���


	std::cout << "*****************Singleton(����)���ģʽ**********" << std::endl << std::endl;

	std::cout << "��¼����" << std::endl;
	Singleton* singleton = Singleton::GetInstance("����100��", "������", "9��58");
	singleton->recorddeclaration();

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "��¼��ѯ" << std::endl;
	Singleton* singl = Singleton::GetInstance("", "", "");
	singl->recorddeclaration();

	std::cout << "**************************************************" << std::endl << std::endl;
}

