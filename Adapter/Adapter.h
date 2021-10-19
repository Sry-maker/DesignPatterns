#pragma once
#include<iostream>
#include<algorithm>

using namespace std;

//Target����һ����Ϊ�Ľӿڣ�����ָ����������������ϵͳ��
class Target {
public:
    virtual ~Target() = default;

    virtual string Request() const {
        return "������A: I'm very glad that I won this game.";
    }
};

//Adaptee��������һ����Ϊ�Ľӿڣ����ӿڲ��ܱ�ǰһ����Ϊ������ʶ����Ҫһ��Adapter
//����ָ�����˳����ϵ�����ϵͳ��
class Adaptee {
public:
    string SpecificRequest() const {
        return ".emag siht ni trap ekat ot duorp yrev m'I, detaefed hguohT";
    }
};

//Adapterʹ���ֲ�ͬ�Ľӿ�֮���ܹ����ཻ�������ＴΪ�����õ�����ת��Ϊ������
class Adapter : public Target {
private:
    Adaptee* adaptee_;

public:
    Adapter(Adaptee* adaptee) : adaptee_(adaptee) {}
    string Request() const override {
        string to_reverse = this->adaptee_->SpecificRequest();
        reverse(to_reverse.begin(), to_reverse.end());
        return "������B:(ת����)" + to_reverse;
    }
};


void AdapterClientCode(const Target* target) {
    std::cout << target->Request();
}

void adapterTest() {
	std::cout << "AdapterTest:\n\n";
	
	std::cout <<"���ߣ���ӭ����������ȭ������������ɷá�"<< "\n";
	std::cout << "�����ǻ�ʤ���Ĳɷ�ʱ��:\n";
	Target* target = new Target;
	AdapterClientCode(target);
	std::cout << "\n\n";
	Adaptee* adaptee = new Adaptee;
	
	std::cout << "���ߣ������ǰܷ�������ѡ�ֲɷ�ʱ�䣬���������⵽KO��ͷ��������ϵͳ����һ����ϣ���ʾ�ľ�������β���õģ��Һ��ѿ���:\n";
	
	std::cout << "������B: " << adaptee->SpecificRequest();
	std::cout << "\n\n";
	
	std::cout << "����: ��������������ģʽ�İ��������ܹ������λѡ����������:\n";
	Adapter* adapter = new Adapter(adaptee);
	AdapterClientCode(adapter);

	delete target;
	delete adaptee;
	delete adapter;
}