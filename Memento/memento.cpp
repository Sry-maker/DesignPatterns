#include"memento.h"
void mementoTest(){
    cout << "***************  以下为memento(备忘率)设计模式  **************************************"<<endl<<endl;
    EventOriginator* eventoriginator = new EventOriginator(new Athlete("001","张三","中国"));
    Caretaker* caretaker = new Caretaker(eventoriginator);
    caretaker->Backup();
    eventoriginator->ChangeEvent("跳远");
    caretaker->Backup();
    eventoriginator->ChangeEvent("男子100米跑");
    caretaker->Backup();
    eventoriginator->ChangeEvent("男子200米跑");
    std::cout << "\n";
    caretaker->ShowHistory();
    std::cout << "\nNow, let's rollback!\n\n";
    caretaker->Undo();
    std::cout << "\n\nOnce more!\n\n";
    caretaker->Undo();
    std::cout << "\n\n";
    caretaker->ShowHistory();

    delete eventoriginator;
    delete caretaker;
    cout <<endl<< "***************  memento(备忘率)设计模式结束  **************************************" << endl << endl;
}


void Enroll(EventOriginator* eventoriginator, Caretaker* caretaker, Athlete* athlete) {
    if (athlete->GetEvent() != "")
    {
        std::cout << "您已报名了项目,无法再进行报名." << endl;
        return;
    }
    std::cout << "\n请输入您要报名的项目：" << endl;
    string temp_event;
    cin >> temp_event;
    eventoriginator = new EventOriginator(athlete);
    caretaker = new Caretaker(eventoriginator);
    caretaker->Backup();

    athlete->SetEvent(temp_event);
}
void ChangeEvent(EventOriginator* eventoriginator, Caretaker* caretaker, Athlete* athlete) {
    if (athlete->GetEvent() == "")
    {
        std::cout << "请先报名项目" << endl;
        return;
    }
    std::cout << "\n请输入要修改成的项目：" << endl;
    string temp_event;
    cin >> temp_event;
    eventoriginator->ChangeEvent(temp_event);
    caretaker->Backup();
}
void Undo(EventOriginator* eventoriginator, Caretaker* caretaker, Athlete* athlete) {
    caretaker->ShowHistory();
    caretaker->Undo();
}

void memento(Athlete* athlete){
    cout << "***************  以下为memento(备忘率)设计模式  **************************************"<<endl<<endl;
    EventOriginator* eventoriginator=NULL;
    Caretaker* caretaker=NULL;
    while(1){
        cout << "********************请选择您要进行的操作*****************************" << endl << endl;
        std::cout << "1.报名运动项目\n";
        std::cout << "2.修改运动项目\n";
        std::cout << "3.反悔操作（回到上一个运动项目）\n";
        std::cout << "0.返回\n";
        int type;
        std::cout << "input:";
        std::cin >> type;
        switch (type)
        {
        case 1:
            Enroll(eventoriginator,caretaker,athlete);
            break;
        case 2:
            ChangeEvent(eventoriginator, caretaker, athlete);
            break;
        case 3:
            Undo( eventoriginator,caretaker, athlete);
            break;
       default:
            break;
        }
        if(type==0)
	break;
    }
    return;
}

//EventOriginator::ConcreteMemento类的函数
EventOriginator::ConcreteMemento::ConcreteMemento(string event,string operation) : event_(event),operation_(operation) {}
string EventOriginator::ConcreteMemento::GetEvent() {
    return event_;
}
string EventOriginator::ConcreteMemento::GetOperation() {
    return operation_;
}
//EventOriginator类的函数
EventOriginator::EventOriginator(Athlete* athlete) {
    athlete_ = athlete;
    cout << "Originator:" <<athlete->GetName()<<"'s initial event is: " << athlete_->GetEvent() << "\n";
}
void EventOriginator::ChangeEvent(string newevent) {
    cout << "Originator: I'm changing the event.\n";
    athlete_->SetEvent(newevent);
    cout << "Originator: and my event has changed to: " << athlete_->GetEvent() << "\n";
}
string EventOriginator::ShowEvent() {
    return athlete_->GetEvent();
}
Memento* EventOriginator::Save() {
    return new ConcreteMemento(athlete_->GetEvent(),"改变项目");
}
void EventOriginator::Restore(Memento* memento) {
    //将Memento* 类型转变成ConcreteMemento* 类型，实现窄接口变宽接口
    ConcreteMemento* concretememento = (ConcreteMemento*) memento;
    athlete_->SetEvent(concretememento->GetEvent());
    cout << "Originator:" << athlete_->GetName() <<"'s event has changed to: " << athlete_->GetEvent() << "\n";
}
//Caretaker类的函数
Caretaker::Caretaker(EventOriginator* originator) : originator_(originator) {
    this->originator_ = originator;
}
void Caretaker::Backup() {
    cout << "\nCaretaker: Saving Originator's state...\n";
    this->mementos_.push_back(this->originator_->Save());
}
void Caretaker::Undo() {
    if (!this->mementos_.size()) {
        return;
    }
    Memento* memento = this->mementos_.back();
    this->mementos_.pop_back();
    try {
        this->originator_->Restore(memento);
        cout << "Caretaker: Restoring event to: " << originator_->ShowEvent();
    }
    catch (...) {
        this->Undo();
    }
}
void Caretaker::ShowHistory() const {
    cout << "Caretaker: Here's the list of mementos:\n";
    for (Memento* memento : this->mementos_) {
        cout << memento->GetOperation() << "\n";
    }
}