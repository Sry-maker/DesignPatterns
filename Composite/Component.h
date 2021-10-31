#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;


//�����࣬���ܴ���ְ�������ܴ������ί������
class Component {
protected:
    string Name;
public:
    virtual ~Component() {}
    //��Ӳ����Ĵ���
    virtual void Add(Component* component) {}
    //�Ƴ������Ĵ���
    virtual void Remove(Component* component) {}
    //�ж��Ƿ��ǰ���ί����
    virtual bool IsDepartment() const {
        return false;
    }
    //��������Ľṹ
    virtual string Operation() const = 0;
};

class Staff : public Component {
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

class Department : public Component {

protected:
    list<Component*> children_;
public:
    Department(string name) {
        Name = name;
        std:: cout << "Department::Department():create a department: " << name<<"\n";
    }
    //��Ӳ����Ĵ���
    void Add(Component* component) override {
        this->children_.push_back(component);
    }
    //�Ƴ������Ĵ���
    void Remove(Component* component) override {
        children_.remove(component);
    }
    //�ж��Ƿ��ǰ���ί����
    bool IsDepartment() const override {
        return true;
    }
    //����ð���ί���ŵĽṹ��
    string Operation() const override {
        string result;
        for (const Component* c : children_) {
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
