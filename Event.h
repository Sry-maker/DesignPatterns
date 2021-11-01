#include<iostream>
#include<string>
using namespace std;
class Event {
private:
	string name_;
	string place_;
public:
	Event(string name):name_(name){}
	string GetName() { return name_; }
	void SetName(string name) { name_ = name; }
	string GetPlace() { return place_; }
	void SetPlace(string place) { place_ = place; }
};