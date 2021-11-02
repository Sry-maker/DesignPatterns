#pragma once
#include<string>
#include<vector>
#include<iostream>
#include"../TemplateMethod/athlete.h"

class Memento;
class EventOriginator;
class Caretaker;
//备忘录
/*备忘录是原发器状态快照的值对象 （value object）。 
通常做法是将备忘录设为不可变的，
并通过构造函数一次性传递数据。*/

class Memento {
private:
    std::string operation;
public:
    //Memento的纯虚函数，得到备忘录记录的操作名称
    virtual  std::string GetOperation() = 0;
};

//原发器
/*原发器类可以生成自身状态的快照， 
也可以在需要时通过快照恢复自身状态*/
class EventOriginator {
private:
    athlete* athlete_;
    //定义在EventOriginator类中，对 EventOriginator提供宽接口，对其他类提供窄接口
    class ConcreteMemento : public Memento {
    private:
        std::string event_;
        std::string operation_;
    public:
        //ConcreteMemento的构造函数，生成一个备忘录
        ConcreteMemento(std::string event, std::string operation) : event_(event), operation_(operation) {}
        //得到报名的项目名称
        std::string GetEvent() {
            return event_;
        }
        //得到备忘录记录的操作名称
        std::string GetOperation() {
            return operation_;
        }
    };
public:
    //EventOriginator类的构造函数，初始化EventOriginator
    EventOriginator(athlete* athlete) {
        athlete_ = athlete;
        std::cout << "Originator:" << athlete->getName() << "'s initial event is: " << athlete_->getMatch() << "\n";
    }
    //改变报名的项目名称
    void ChangeEvent(std::string newevent) {
        std::cout << "Originator: I'm changing the event.\n";
        athlete_->matchSet(newevent);
        std::cout << "Originator: and my event has changed to: " << athlete_->getMatch() << "\n";
    }
    //展示报名的项目名称
    std::string ShowEvent() {
        return athlete_->getMatch();
    }
    //将当前项目名称记录在备忘录中
    Memento* Save() {
        return new ConcreteMemento(athlete_->getMatch(), "改变项目");
    }
    //退回到之前的项目名称
    void Restore(Memento* memento) {
        //将Memento* 类型转变成ConcreteMemento* 类型，实现窄接口变宽接口
        ConcreteMemento* concretememento = (ConcreteMemento*)memento;
        athlete_->matchSet(concretememento->GetEvent());
        std::cout << "Originator:" << athlete_->getName() << "'s event has changed to: " << athlete_->getMatch() << "\n";
    }
};

//负责人
/*负责人通过保存备忘录栈来记录原发器的历史状态。 
当原发器需要回溯历史状态时， 负责人将从栈中获取
最顶部的备忘录， 并将其传递给原发器的恢复 （restore） 方法。*/

class Caretaker {
private:
     std::vector<Memento*> mementos_;
    EventOriginator* originator_;
public:
    //生成对于原发器的负责人
    Caretaker(EventOriginator* originator) : originator_(originator) {
        this->originator_ = originator;
    }
    //保存原发器的当前状态，记录在备忘录中
    void Backup() {
        std::cout << "\nCaretaker: Saving Originator's state...\n";
        this->mementos_.push_back(this->originator_->Save());
    }
    //退回到原发器之前的状态
    void Undo() {
        if (!this->mementos_.size()) {
            return;
        }
        this->mementos_.pop_back();
        Memento* memento = this->mementos_.back();
        try {
            this->originator_->Restore(memento);
            std::cout << "Caretaker: Restoring event to: " << originator_->ShowEvent();
        }
        catch (...) {
            this->Undo();
        }
    }
    //展示备忘录中所有的操作记录
    void ShowHistory() const {
        std::cout << "Caretaker: Here's the list of mementos:\n";
        for (Memento* memento : this->mementos_) {
            std::cout << memento->GetOperation() << "\n";
        }
    }
};

