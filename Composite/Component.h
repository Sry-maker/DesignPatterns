#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
using namespace std;


//�����࣬���ܴ���ְ�������ܴ������ί������
class Component {

protected:
    Component* parent_;

public:
    virtual ~Component() {}
    // ��ȷ�����������ĸ�����
    void SetParent(Component* parent) {
        this->parent_ = parent;
    }
    // �˽ⲿ���������ĸ�����
    Component* GetParent() const {
        return this->parent_;
    }
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

class staff : public Component {
public:
    //���ְ�����
    string Operation() const override {
        return "staff";
    }
};

class Department : public Component {

protected:
    list<Component*> children_;

public:
    //��Ӳ����Ĵ���
    void Add(Component* component) override {
        this->children_.push_back(component);
        component->SetParent(this);
    }
    //�Ƴ������Ĵ���
    void Remove(Component* component) override {
        children_.remove(component);
        component->SetParent(nullptr);
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
        return "Department(" + result + ")";
    }
};
