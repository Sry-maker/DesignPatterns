#pragma once
#include<iostream>
#include<string>
class Colleague;
class Mediator {
public:
    virtual void Notify(Colleague* sender, string event) const = 0;
};

/**
 * The Base Component provides the basic functionality of storing a mediator's
 * instance inside component objects.
 */
class Colleague {
protected:
    Mediator* mediator_;

public:
    Colleague(Mediator* mediator = nullptr) : mediator_(mediator) {
    }
    void set_mediator(Mediator* mediator) {
        this->mediator_ = mediator;
    }
};


class ConcreteAthlete : public Colleague {
public:
    void DoA() {
        std::cout << "";
        this->mediator_->Notify(this, "请你尽快准备参赛");
    }
   /* void DoB() {
        std::cout << "Component 1 does B.\n";
        this->mediator_->Notify(this, "B");
    }*/
};

class ConcreteCommittee : public Colleague {
public:
   /* void DoC() {
        std::cout << "Component 2 does what hhk.\n";
        this->mediator_->Notify(this, "C");
    }
    void DoD() {
        std::cout << "Component 2 does D.\n";
        this->mediator_->Notify(this, "D");
    }*/
};

/**
 * Concrete Mediators implement cooperative behavior by coordinating several
 * components.
 */
class ConcreteMediator : public Mediator {
private:
    ConcreteAthlete* ConcreteAthlete_;
    ConcreteCommittee* ConcreteCoach_;

public:
    ConcreteMediator(ConcreteAthlete* c1, ConcreteCommittee* c2) : ConcreteAthlete_(c1), ConcreteCoach_(c2) {
        this->ConcreteAthlete_->set_mediator(this);
        this->ConcreteCoach_->set_mediator(this);
    }
    void Notify(Colleague* sender, std::string event) const override {
        /*if (event == "hhk") {
            std::cout << "Mediator reacts on hhk and triggers following operations:\n";
            this->ConcreteCoach_->DoC();
        }*/
        if (sender == ConcreteAthlete_) {
            
            std::cout << "运动员已收到消息";
           // this->ConcreteCoach_->DoC();
        }
       /* if (event == "D") {
            std::cout << "Mediator reacts on D and triggers following operations:\n";
            this->ConcreteAthlete_->DoB();
            this->ConcreteCoach_->DoC();
        }*/
    }
};


void mediatorTest() {
    ConcreteAthlete* c1 = new ConcreteAthlete;
    ConcreteCommittee* c2 = new ConcreteCommittee;
    ConcreteMediator* mediator = new ConcreteMediator(c1, c2);
    std::cout << "****************  以下为Mediator（中介者）设计模式  ******************" << std::endl;
    cout << "ConcreteAthlete : created a concreteAthlete" << endl;
    cout << "ConcreteCommittee : created a concreteCommittee" << endl;
    cout << "ConcreteMediator : created a mediator between concreteAthlete and concreteCommittee" << endl;


    std::cout << "组委会通知选手参赛" << endl;
    c1->DoA();
    /*std::cout << "\n";
    std::cout << "Client triggers operation D.\n";
    c2->DoD();*/
   // Colleague* cc = new Colleague;

    delete c1;
    delete c2;
    delete mediator;
    std::cout << "****************  Mediator（中介者）设计模式结束  ******************" << std::endl;
    


}

