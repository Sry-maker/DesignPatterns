#include<iostream>
#include<string>
using namespace std;

class Athlete {
private:
    string id_;
    string name_;
    string contury_;
    string event_;
public:
    Athlete(string id,string name,string contury) :id_(id),name_(name),contury_(contury){event_="";}
    string GetId() {
        return id_;
    }
    string GetName() {
        return name_;
    }
    string GetContury() {
        return contury_;
    }
    string GetEvent() {
        return event_;
    }
    void SetId(string id) {
        id_ = id;
    }
    void SetName(string name) {
        name_ = name;
    }
    void SetContury(string contury) {
        contury_ = contury;
    }
    void SetEvent(string event) {
        event_ = event;
    }
};
