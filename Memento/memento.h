#define _CRT_SECRTY_NO_WARNINGS
#include<cstring>
#include<vector>
#include<iostream>

#include"../Athlete.h"

using namespace std;



void mementoTest();
//备忘录
/*备忘录是原发器状态快照的值对象 （value object）。 
通常做法是将备忘录设为不可变的，
并通过构造函数一次性传递数据。*/

class Memento {
private:
    string operation;
public:
    //Memento的纯虚函数，得到备忘录记录的操作名称
    virtual  string GetOperation() = 0;
};

//原发器
/*原发器类可以生成自身状态的快照， 
也可以在需要时通过快照恢复自身状态*/
class EventOriginator {
private:
    Athlete* athlete_;
    //定义在EventOriginator类中，对 EventOriginator提供宽接口，对其他类提供窄接口
    class ConcreteMemento : public Memento {
    private:
        string event_;
        string operation_;
    public:
        //ConcreteMemento的构造函数，生成一个备忘录
        ConcreteMemento(string,string);
        //得到报名的项目名称
        string GetEvent();
        //得到备忘录记录的操作名称
        string GetOperation();
    };

public:
    //EventOriginator类的构造函数，初始化EventOriginator
    EventOriginator(Athlete*);
    //改变报名的项目名称
    void ChangeEvent(string);
    //展示报名的项目名称
    string ShowEvent();
    //将当前项目名称记录在备忘录中
    Memento* Save();
    //退回到之前的项目名称
    void Restore(Memento*);
};

//负责人
/*负责人通过保存备忘录栈来记录原发器的历史状态。 
当原发器需要回溯历史状态时， 负责人将从栈中获取
最顶部的备忘录， 并将其传递给原发器的恢复 （restore） 方法。*/

class Caretaker {
private:
     vector<Memento*> mementos_;
    EventOriginator* originator_;
public:
    //生成对于原发器的负责人
    Caretaker(EventOriginator*);
    //保存原发器的当前状态，记录在备忘录中
    void Backup();
    //退回到原发器之前的状态
    void Undo();
    //展示备忘录中所有的操作记录
    void ShowHistory()const;
};

