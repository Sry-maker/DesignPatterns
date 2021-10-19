#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include"Component.h"
using namespace std;


void ClientCode(Component* component) {
    cout << "RESULT: " << component->Operation();
}

void ClientCode2(Component* component1, Component* component2) {
    if (component1->IsDepartment()) {
        component1->Add(component2);
    }
    cout << "RESULT: " << component1->Operation();
}

int componentTest() {
    Component* simple = new staff;
    cout << "一个职工\n";
    ClientCode(simple);
    cout << "\n\n";
    Component* tree = new Department;
    Component* Department1 = new Department;
    Component* staff_1 = new staff;
    Component* staff_2 = new staff;
    Component* staff_3 = new staff;
    Department1->Add(staff_1);
    Department1->Add(staff_2);
    Component* Department2 = new Department;
    Department2->Add(staff_3);
    tree->Add(Department1);
    tree->Add(Department2);
    cout << "奥组委各部门:\n";
    ClientCode(tree);
    cout << "\n\n";
    cout << "调整部门结构时不需要考虑是部门还是职工:\n";
    ClientCode2(tree, simple);
    cout << "\n";
    delete simple;
    delete tree;
    delete Department1;
    delete Department2;
    delete staff_1;
    delete staff_2;
    delete staff_3;
    return 0;
}
