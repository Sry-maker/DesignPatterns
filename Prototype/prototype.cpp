#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//�����˶��淶 ����ƹ���򡢱���     ���š����������Ĺ淶�����ߡ����
enum Type {
	Football = 0,//����
	Pingpong,    //ƹ����
	Icehockey    //����

};


class Prototype {//ԭ��
protected:
	string prototypename; //�˶���Ŀ
	double length;        //���س���
	double width;         //���ؿ��


public:
	Prototype() {}//���캯��
	Prototype(string prototype_name) {
		this->prototypename = prototype_name;
	}
	virtual ~Prototype() {}//��������
	virtual Prototype* Clone() const = 0;//����ԭ�͹�������
	virtual void assign(double length, double width) {//��ֵ
		this->length = length;
		this->width = width;
	}
	virtual void standard() const = 0;//�淶��ӡ
};


class FootballPrototype : public Prototype {//���򳡵�
private:
	string goalstandard;//�������Ź淶

public:
	FootballPrototype(string prototype_name, string goal_standard)//���캯��
		: Prototype(prototype_name), goalstandard(goal_standard) {
	}

	Prototype* Clone() const override {//��������
		return new  FootballPrototype(*this);
	}
	void standard() const override {//�淶��ӡ
		cout << "FootballPrototype::standard : " << endl << prototypename << ":" << endl;
		cout << "���س���:" << length << endl << "���ؿ��:" << width << endl << "�������Ź淶:" << goalstandard << endl << endl;
	}
};


class PingpongPrototype : public Prototype {//ƹ�ҳ���
private:
	string netstandard;//�����淶
	string racketstandard;//���Ĺ淶

public:
	PingpongPrototype(string prototype_name, string net_standard, string racket_standard)//���캯��
		: Prototype(prototype_name), netstandard(net_standard), racketstandard(racket_standard) {
	}

	Prototype* Clone() const override {//��������
		return new  PingpongPrototype(*this);
	}
	void standard() const override {//�淶��ӡ
		cout << "PingpongPrototype::standard : " << endl << prototypename << ":" << endl;
		cout << "���س���:" << length << endl << "���ؿ��:" << width << endl << "ƹ���������淶:" << netstandard << endl << "ƹ�������Ĺ淶:" << racketstandard << endl << endl;
	}
};

class icehockeyPrototype : public Prototype {//���򳡵�
private:
	string goalstandard;//���Ź淶
	string clubstandard;//��˹淶

public:
	icehockeyPrototype(string prototype_name, string goal_standard, string club_standard)//���캯��
		: Prototype(prototype_name), goalstandard(goal_standard), clubstandard(club_standard) {
	}

	Prototype* Clone() const override {//��������
		return new  icehockeyPrototype(*this);
	}
	void standard() const override {//�淶��ӡ
		cout << "icehockeyPrototype::standard : " << endl << prototypename << ":" << endl;
		cout << "���س���:" << length << endl << "���ؿ��:" << width << endl << "���������淶:" << goalstandard << endl << "������˹淶:" << clubstandard << endl << endl;
	}
};


class PrototypeFactory {//ԭ��
private:
	std::unordered_map<Type, Prototype*, std::hash<int>> prototypes_;

public:
	PrototypeFactory() {//���캯������������ԭ��
		prototypes_[Type::Football] = new FootballPrototype("����淶", "������Ӧ����ÿ�������ߵ����룬���������7.32�ס�������������Ⱦ��� ......");
		prototypes_[Type::Pingpong] = new PingpongPrototype("ƹ����淶 ", "����װ�ð����������������������������ǹ̶�����̨�ϵļ�ǯ����......", "���ĵĴ�С����״���������ޣ����װ�Ӧƽ������Ӳ......");
		prototypes_[Type::Icehockey] = new PingpongPrototype("������淶 ", "������Ŀ�У����ŵĿ����180���ף�����1��8��......", "��ľ�ʲ����Ƴɣ��Ӹ������˱��˲��ܳ���147����......");
	}


	~PrototypeFactory() {//��������
		delete prototypes_[Type::Football];
		delete prototypes_[Type::Pingpong];
		delete prototypes_[Type::Icehockey];
	}

	Prototype* CreatePrototype(Type type) {//����ĳ������ԭ��
		return prototypes_[type]->Clone();
	}

};

void Client(PrototypeFactory& prototype_factory) {//���Ժ���

	//��������
	Prototype* prototype = prototype_factory.CreatePrototype(Type::Football);
	prototype->assign(105, 70);
	prototype->standard();
	delete prototype;

	cout << endl;
	//����ƹ����
	prototype = prototype_factory.CreatePrototype(Type::Pingpong);
	prototype->assign(2.7, 1.5);
	prototype->standard();
	delete prototype;

	cout << endl;
	//���Ա���
	prototype = prototype_factory.CreatePrototype(Type::Icehockey);
	prototype->assign(61, 30);
	prototype->standard();
	delete prototype;
}

void prototypeTest()
{
	cout << "*****************Prototype(ԭ��)���ģʽ**********" << endl << endl;
	PrototypeFactory* prototype_factory = new PrototypeFactory();
	Client(*prototype_factory);
	delete prototype_factory;
	cout << "**************************************************" << endl << endl;
}
int main() {

	prototypeTest();
	return 0;
}