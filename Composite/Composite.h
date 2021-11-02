#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;


//抽象类，既能代表职工，又能代表奥组委各部门
class Composite {
protected:
    string Name;
public:
    virtual ~Composite() {}
    //添加部件的从属
    virtual void Add(Composite* composite) {}
    //移除部件的从属
    virtual void Remove(Composite* composite) {}
    //判断是否是奥组委部门
    virtual bool IsDepartment() const {
        return false;
    }
    //输出部件的结构
    virtual string Operation() const = 0;
};

class Staff : public Composite {
public:
    Staff(string name) {
        Name = name;
        std:: cout << "Staff::Staff():create a staff: " << name<<"\n";
    }
    //输出职工身份
    string Operation() const override {
        return "Staff:"+Name;
    }
};

class Department : public Composite {

protected:
    list<Composite*> children_;
public:
    Department(string name) {
        Name = name;
        std:: cout << "Department::Department():create a department: " << name<<"\n";
    }
    //添加部件的从属
    void Add(Composite* composite) override {
        this->children_.push_back(composite);
    }
    //移除部件的从属
    void Remove(Composite* composite) override {
        children_.remove(composite);
    }
    //判断是否是奥组委部门
    bool IsDepartment() const override {
        return true;
    }
    //输出该奥组委部门的结构树
    string Operation() const override {
        string result;
        for (const Composite* c : children_) {
            if (c == children_.back()) {
                result += c->Operation();
            }
            else {
                result += c->Operation() + "+";
            }
        }
        return "Department"+Name+"(" + result + ")";
    }
};
