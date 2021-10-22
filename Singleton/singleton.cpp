#include <iostream>
#include <mutex>
#include <string>
using namespace std;

//����ģʽ
class Singleton
{

private:
	static Singleton* pinstance;
	static mutex mut;     //�̰߳�ȫ

protected:
	string Olympicname;   //����ƥ���˶�����Ŀ
	string recordholder;  //��¼������
	string record;        //��¼
	Singleton(const string name, const string holder, const string rec) : Olympicname(name), recordholder(holder), record(rec)//���캯��
	{
	}
	~Singleton() {}//��������


public:

	Singleton(Singleton& other) = delete;  //����ģʽ�����Խ��еĲ���
	void operator=(const Singleton&) = delete;

	static Singleton* GetInstance(const string& name, const string& holder, const string& rec);//��ȡʵ��


	void recorddeclaration()   //��¼��ӡ
	{
		cout << "Singleton::recorddeclaration : " << endl << "����ƥ���˶�����Ŀ: " << Olympicname << endl << "��¼������: " << recordholder << endl << "��¼: " << record << endl;
	}


	string Olympicnamevalue() const {//���ذ���ƥ���˶�����Ŀ
		return Olympicname;
	}
	string recordholdervalue() const {//���ؼ�¼������
		return recordholder;
	}
	string recordvalue() const {//���ؼ�¼
		return record;
	}
};


Singleton* Singleton::pinstance{ nullptr };
mutex Singleton::mut;


Singleton* Singleton::GetInstance(const string& name, const string& holder, const string& rec)//��ȡʵ��
{
	lock_guard<std::mutex> lock(mut);
	if (pinstance == nullptr)//���Ϊnullptr�򴴽�������ֱ�ӷ����Ѿ������õ�
	{
		pinstance = new Singleton(name, holder, rec);
	}
	return pinstance;
}

void singletonTest() {//���Ժ���


	cout << "*****************Singleton(����)���ģʽ**********" << endl << endl;

	cout << "��¼����" << endl;
	Singleton* singleton = Singleton::GetInstance("����100��", "������", "9��58");
	singleton->recorddeclaration();

	cout << endl << endl << endl;
	cout << "��¼��ѯ" << endl;
	Singleton* singl = Singleton::GetInstance("", "", "");
	singl->recorddeclaration();

	cout << "**************************************************" << endl << endl;
}

int main()
{

	singletonTest();
	return 0;
}