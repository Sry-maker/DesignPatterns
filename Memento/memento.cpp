#include"memento.h"
void mementoTest(){
    cout << "***************  以下为memento(备忘率)设计模式  **************************************"<<endl<<endl;
    EventOriginator* eventoriginator = new EventOriginator("跳高");
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

//EventOriginator::ConcreteMemento类的函数
EventOriginator::ConcreteMemento::ConcreteMemento(string event,string operation) : event_(event),operation_(operation) {}
string EventOriginator::ConcreteMemento::GetEvent() {
    return event_;
}
string EventOriginator::ConcreteMemento::GetOperation() {
    return operation_;
}
//EventOriginator类的函数
EventOriginator::EventOriginator(string event) : event_(event) {
    cout << "Originator: My initial event is: " << this->event_ << "\n";
}
void EventOriginator::ChangeEvent(string newevent) {
    cout << "Originator: I'm changing the event.\n";
    this->event_ = newevent;
    cout << "Originator: and my event has changed to: " << this->event_ << "\n";
}
string EventOriginator::ShowEvent() {
    return this->event_;
}
Memento* EventOriginator::Save() {
    return new ConcreteMemento(this->event_,"改变项目");
}
void EventOriginator::Restore(Memento* memento) {
    //将Memento* 类型转变成ConcreteMemento* 类型，实现窄接口变宽接口
    ConcreteMemento* concretememento = (ConcreteMemento*) memento;
    this->event_ = concretememento->GetEvent();
    cout << "Originator: My state has changed to: " << this->event_ << "\n";
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