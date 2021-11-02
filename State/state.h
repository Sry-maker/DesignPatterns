#pragma once
#include <iostream>
#include <typeinfo>


class Context_state;
class ConcreteStateA_state;
class ConcreteStateB_state;
class ConcreteStateC_state;

class State {
    
protected:
    Context_state* Context_state_;

public:
    virtual ~State() {
    }

    void set_Context_state(Context_state* Context_state1) {
        this->Context_state_ = Context_state1;
    }

    virtual void Handle1() = 0;
    virtual void Handle2() = 0;
    virtual void Handle3() = 0;
};


class Context_state {
    
private:
    State* state_;

public:
    Context_state(State* state) : state_(nullptr) {
        this->TransitionTo(state);
    }
    ~Context_state() {
        delete state_;
    }
    
    void TransitionTo(State* state) {     // �ı����״̬
        std::cout << "Context_state::TransitionTo : ";
        std::cout << "����״̬�Ѹ�Ϊ" << typeid(*state).name() << ".\n";
        if (this->state_ != nullptr)
            delete this->state_;
        this->state_ = state;
        this->state_->set_Context_state(this);
    }
   
    void Request1() {
        this->state_->Handle1();
    }
    void Request2() {
        this->state_->Handle2();
    }
    void Request3() {
        this->state_->Handle3();
    }
};

class ConcreteStateC_state : public State { //C״̬��ʾ���������/��ȡ��
public:
    void Handle1() override {
        std::cout << "ConcreteStateC_state::Handle1 : ";
        std::cout << "����״̬ �����\n";
    }
    void Handle2() override {
        std::cout << "ConcreteStateC_state::Handle2 : ";
        std::cout << "����״̬ ��ȡ��\n";
    }
    void Handle3() override {
        std::cout << "ConcreteStateC_state::Handle3 : ";
        std::cout << "����״̬ �����/��ȡ��\n";
    }
};
class ConcreteStateB_state : public State { //B״̬��ʾ�������ڽ���
public:
    void Handle1() override;
    void Handle2() override {
        std::cout << "ConcreteStateB_state::Handle2 : ";
        std::cout << "������������\n";
        std::cout << "����״̬������Ϊ �����\n";
        this->Context_state_->TransitionTo(new ConcreteStateC_state);
    }
    void Handle3() override {
        std::cout << "ConcreteStateB_state::Handle3 : ";
        std::cout << "������������\n";
    }
};
class ConcreteStateA_state : public State {  //A״̬��ʾ����δ����
public:
    void Handle1() override {
        std::cout << "ConcreteStateA_state::Handle1 : ";
        std::cout << "����������ʼ\n";
        std::cout << "����״̬������Ϊ ������\n";

        this->Context_state_->TransitionTo(new ConcreteStateB_state);
    }

    void Handle2() override {
        std::cout << "ConcreteStateA_state::Handle2 : "; 
        std::cout << "����ȡ��\n";
        this->Context_state_->TransitionTo(new ConcreteStateC_state);
    }
    void Handle3() override {
        std::cout << "ConcreteStateA_state::Handle3 : ";
        std::cout << "���������ȴ�\n";
    }
};

void ConcreteStateB_state::Handle1() {
    {
        std::cout << "ConcreteStateB_state::Handle1 : ";
        std::cout << "������ͣ\n";
        this->Context_state_->TransitionTo(new ConcreteStateA_state);
    }
}

void AthleteCode() {
    Context_state* Context_state1 = new Context_state(new ConcreteStateA_state);
    Context_state1->Request1();
    Context_state1->Request2();
    Context_state1->Request3();
    delete Context_state1;
}
Context_state* Context_state2 = new Context_state(new ConcreteStateA_state);
void event_start_state()
{
    Context_state2->Request1();
}
void event_end_state()
{
    Context_state2->Request2();
    delete Context_state2;
}

void stateTest(){
    std::cout << "***************  ����Ϊstate(״̬)���ģʽ  *********************************" << endl;
    AthleteCode();
    std::cout << std::endl;
}
 