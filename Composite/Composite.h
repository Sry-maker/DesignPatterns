#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;


//�����࣬���ܴ���ְ�������ܴ������ί������
class Composite {
protected:
    string Name;
public:
    virtual ~Composite() {}
    //��Ӳ����Ĵ���
    virtual void Add(Composite* composite) {}
    //�Ƴ������Ĵ���
    virtual void Remove(Composite* composite) {}
    //�ж��Ƿ��ǰ���ί����
    virtual bool IsDepartment() const {
        return false;
    }
    //��������Ľṹ
    virtual string Operation() const = 0;
};

class Staff : public Composite {
public:
    Staff(string name) {
        Name = name;
        std:: cout << "Staff::Staff():create a staff: " << name<<"\n";
    }
    //���ְ�����
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
    //��Ӳ����Ĵ���
    void Add(Composite* composite) override {
        this->children_.push_back(composite);
    }
    //�Ƴ������Ĵ���
    void Remove(Composite* composite) override {
        children_.remove(composite);
    }
    //�ж��Ƿ��ǰ���ί����
    bool IsDepartment() const override {
        return true;
    }
    //����ð���ί���ŵĽṹ��
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
