#include"Observer.h"

void observerTest() {
	cout << "***************  以下为Observer(观察者)设计模式  **************************************" << endl << endl;
	//创建EventObject对象
	PlaceSubject* placesubject = new PlaceSubject("鸟巢");
	//创建观察者对象，进行附着观察
	EventObserver* eventobserver1 = new EventObserver(placesubject, "跳高");
	EventObserver* eventobserver2 = new EventObserver(placesubject, "跳远");
	EventObserver* eventobserver3 = new EventObserver(placesubject, "男子100米跑");
	placesubject->HowManyObserver();
	cout << endl;
	//EventObject更新，发出消息给观察者
	placesubject->SetPlace("五棵松篮球馆");
	cout << endl;
	cout << "Now detach the EventObserver named " << eventobserver1->GetEventObserverName() << endl;
	placesubject->detach(eventobserver1);
	cout << endl;
	placesubject->HowManyObserver();
	cout << endl;
	placesubject->SetPlace("水立方");
	cout << endl;
	cout << "Now detach the EventObserver named " << eventobserver2->GetEventObserverName() << endl;
	placesubject->detach(eventobserver2);
	cout << "Now detach the EventObserver named " << eventobserver3->GetEventObserverName() << endl;
	placesubject->detach(eventobserver3);
	cout << endl;
	placesubject->HowManyObserver();
	cout << endl << "***************  memento(备忘率)设计模式结束  **************************************" << endl << endl;
}

Observer::~Observer(){}

EventObserver::EventObserver(PlaceSubject* placesubject, string eventname) {
	cout << "created a EventObserver,the eventname is" << eventname << endl;
	eventname_ = eventname;
	placesubject_ = placesubject;
	cout << "the EventObserver named " << eventname << " is attached" << endl;
	placesubject_->attach(this);
	cout << endl;
}
EventObserver::~EventObserver() {
	cout << "goodbye,I was the event :" << eventname_ << endl;
}
void EventObserver::update() {
	this->place_ = placesubject_->GetPlace();
	cout << "the place of " << eventname_ << " now is " << place_ << endl;
}
string EventObserver::GetEventObserverName() {
	return  eventname_;
}

Subject::Subject() { changed_ = false;}
void Subject::attach(Observer* observer) {
	observers_.push_back(observer);
	observer->update();
}
void Subject::detach(Observer* observer) {
	observers_.remove(observer);
	delete observer;
}
void  Subject::Notify() {
	if (changed_)
		for (auto x : observers_)
			x->update();
	changed_ = false;
}
void  Subject::DataChange() {
	changed_ = true;
}
void Subject::HowManyObserver(){
	std::cout << "There are " << observers_.size() << " observers in the list.\n";
}

PlaceSubject::PlaceSubject(string place) {
	place_ = place;
	cout << "created a PlaceSubject , the place is " << place_ << endl << endl;;
}
void PlaceSubject::SetPlace(string place) {
	cout << "Now change the data of PlaceSubject to " << place << endl;
	this->place_ = place;
	DataChange();
	Notify();
}
string PlaceSubject::GetPlace() {
	return place_;
}