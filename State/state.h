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
    
    void TransitionTo(State* state) {     // 改变比赛状态
        std::cout << "Context_state::TransitionTo : ";
        std::cout << "比赛状态已改为" << typeid(*state).name() << ".\n";
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

class ConcreteStateC_state : public State { //C状态表示比赛已完成/已取消
public:
    void Handle1() override {
        std::cout << "ConcreteStateC_state::Handle1 : ";
        std::cout << "比赛状态 已完成\n";
    }
    void Handle2() override {
        std::cout << "ConcreteStateC_state::Handle2 : ";
        std::cout << "比赛状态 已取消\n";
    }
    void Handle3() override {
        std::cout << "ConcreteStateC_state::Handle3 : ";
        std::cout << "比赛状态 已完成/已取消\n";
    }
};
class ConcreteStateB_state : public State { //B状态表示比赛正在进行
public:
    void Handle1() override;
    void Handle2() override {
        std::cout << "ConcreteStateB_state::Handle2 : ";
        std::cout << "比赛即将结束\n";
        std::cout << "比赛状态即将改为 已完成\n";
        this->Context_state_->TransitionTo(new ConcreteStateC_state);
    }
    void Handle3() override {
        std::cout << "ConcreteStateB_state::Handle3 : ";
        std::cout << "比赛继续进行\n";
    }
};
class ConcreteStateA_state : public State {  //A状态表示比赛未进行
public:
    void Handle1() override {
        std::cout << "ConcreteStateA_state::Handle1 : ";
        std::cout << "比赛即将开始\n";
        std::cout << "比赛状态即将改为 进行中\n";

        this->Context_state_->TransitionTo(new ConcreteStateB_state);
    }

    void Handle2() override {
        std::cout << "ConcreteStateA_state::Handle2 : "; 
        std::cout << "比赛取消\n";
        this->Context_state_->TransitionTo(new ConcreteStateC_state);
    }
    void Handle3() override {
        std::cout << "ConcreteStateA_state::Handle3 : ";
        std::cout << "比赛继续等待\n";
    }
};

void ConcreteStateB_state::Handle1() {
    {
        std::cout << "ConcreteStateB_state::Handle1 : ";
        std::cout << "比赛暂停\n";
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
    std::cout << "***************  以下为state(状态)设计模式  *********************************" << endl;
    AthleteCode();
    std::cout << std::endl;
}
 