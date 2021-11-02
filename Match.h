#pragma once
#include<iostream>
#include<string>
using namespace std;
class Match {
private:
	string name_;
	string place_;
public:
	Match(string name):name_(name){}
	string GetName() { return name_; }
	void SetName(string name) { name_ = name; }
	string GetPlace() { return place_; }
	void SetPlace(string place) { place_ = place; }
};