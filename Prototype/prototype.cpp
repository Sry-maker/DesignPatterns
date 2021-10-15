#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

//场地运动规范 足球、乒乓球、冰球     球门、球网、球拍规范、护具、球杆
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
        cout << "场地长度:" << length << endl << "场地宽度:" << width << endl << "足球球门规范:" << goalstandard << endl << endl;
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
        cout << "场地长度:" << length << endl << "场地宽度:" << width << endl << "乒乓球球网规范:" << netstandard<<endl<<"乒乓球球拍规范:"<<racketstandard << endl << endl;
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
        cout << "场地长度:" << length << endl << "场地宽度:"<<width << endl << "冰球球网规范:" << goalstandard << endl << "冰球球杆规范:" << clubstandard << endl << endl;
    }
};


class PrototypeFactory {
private:
    std::unordered_map<Type, Prototype*, std::hash<int>> prototypes_;

public:
    PrototypeFactory() {
        prototypes_[Type::Football] = new FootballPrototype("足球规范", "足球门应设在每条球门线的中央，由两根相距7.32米、与西面角旗点相等距离 ......");
        prototypes_[Type::Pingpong] = new PingpongPrototype("乒乓球规范 ", "球网装置包括球网、悬网绳、网柱及将它们固定在球台上的夹钳部分......","球拍的大小，形状和重量不限，但底板应平整、坚硬......");
        prototypes_[Type::Icehockey] = new PingpongPrototype("冰球球规范 ", "冰球项目中，球门的宽度是180厘米，就是1米8宽......", "用木质材料制成，从根部至杆柄端不能长于147厘米......");
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