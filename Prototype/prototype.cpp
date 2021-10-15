#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//�����˶��淶 ����ƹ���򡢱���     ���š����������Ĺ淶�����ߡ����
enum Type {
    Football = 0,
    Pingpong,
    Icehockey

};


class Prototype {
protected:
    string prototypename;
    double length;
    double width;
     

public:
    Prototype() {}
    Prototype(string prototype_name) {
        this->prototypename = prototype_name;
    }
    virtual ~Prototype() {}
    virtual Prototype* Clone() const = 0;
    virtual void Method(double length,double width) {
        this->length = length;
        this->width = width;
    }
    virtual void standard() const = 0;
};


class FootballPrototype : public Prototype {
private:
    string goalstandard;

public:
    FootballPrototype(string prototype_name, string goal_standard)
        : Prototype(prototype_name), goalstandard(goal_standard) {
    }

    Prototype* Clone() const override {
        return new  FootballPrototype(*this);
    }
    void standard() const override {
        cout << prototypename << ":" << endl;
        cout << "���س���:" << length << endl << "���ؿ��:" << width << endl << "�������Ź淶:" << goalstandard << endl << endl;
    }
};


class PingpongPrototype : public Prototype {
private:
    string netstandard;
    string racketstandard;

public:
    PingpongPrototype(string prototype_name, string net_standard, string racket_standard)
        : Prototype(prototype_name), netstandard(net_standard), racketstandard(racket_standard) {
    }

    Prototype* Clone() const override {
        return new  PingpongPrototype(*this);
    }
    void standard() const override {
        cout << prototypename << ":" << endl;
        cout << "���س���:" << length << endl << "���ؿ��:" << width << endl << "ƹ���������淶:" << netstandard<<endl<<"ƹ�������Ĺ淶:"<<racketstandard << endl << endl;
    }
};

class icehockeyPrototype : public Prototype {
private:
    string goalstandard;
    string clubstandard;

public:
    icehockeyPrototype(string prototype_name, string goal_standard,string club_standard)
        : Prototype(prototype_name), goalstandard(goal_standard), clubstandard(club_standard){
    }

    Prototype* Clone() const override {
        return new  icehockeyPrototype(*this);
    }
    void standard() const override {
        cout << prototypename << ":" << endl;
        cout << "���س���:" << length << endl << "���ؿ��:"<<width << endl << "���������淶:" << goalstandard << endl << "������˹淶:" << clubstandard << endl << endl;
    }
};


class PrototypeFactory {
private:
    std::unordered_map<Type, Prototype*, std::hash<int>> prototypes_;

public:
    PrototypeFactory() {
        prototypes_[Type::Football] = new FootballPrototype("����淶", "������Ӧ����ÿ�������ߵ����룬���������7.32�ס�������������Ⱦ��� ......");
        prototypes_[Type::Pingpong] = new PingpongPrototype("ƹ����淶 ", "����װ�ð����������������������������ǹ̶�����̨�ϵļ�ǯ����......","���ĵĴ�С����״���������ޣ����װ�Ӧƽ������Ӳ......");
        prototypes_[Type::Icehockey] = new PingpongPrototype("������淶 ", "������Ŀ�У����ŵĿ����180���ף�����1��8��......", "��ľ�ʲ����Ƴɣ��Ӹ������˱��˲��ܳ���147����......");
    }


    ~PrototypeFactory() {
        delete prototypes_[Type::Football];
        delete prototypes_[Type::Pingpong]; 
        delete prototypes_[Type::Icehockey];
    }

    Prototype* CreatePrototype(Type type) {
        return prototypes_[type]->Clone();
    }

};

void Client(PrototypeFactory& prototype_factory) {
    

    Prototype* prototype = prototype_factory.CreatePrototype(Type::Football);
    prototype->Method(105,70);
    prototype->standard();
    delete prototype;

    cout << endl;

    prototype = prototype_factory.CreatePrototype(Type::Pingpong);
    prototype->Method(2.7,1.5);
    prototype->standard();
    delete prototype;
    
    cout << endl;

    prototype = prototype_factory.CreatePrototype(Type::Icehockey);
    prototype->Method(61, 30);
    prototype->standard();
    delete prototype;
}

int main() {
    PrototypeFactory* prototype_factory = new PrototypeFactory();
    Client(*prototype_factory);
    delete prototype_factory;

    return 0;
}