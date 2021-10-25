#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include"Component.h"
using namespace std;



int componentTest()  {
    cout << "****************以下为Composite（组合）设计模式****************:\n";
    Component* Department1 = new Department("国际奥委会");
    Component* Department2 = new Department("国际奥委会全体委员会");
    Component* Department3 = new Department("执行委员会");
    Component* Staff_1 = new Staff("国际奥委会主席");
    Component* Department4 = new Department("中国奥委会");
    Component* Staff_2 = new Staff("中国奥委会主席");
    Component* Staff_3 = new Staff("中国奥委会副主席");
    Component* Department5 = new Department("日本奥委会");
    Component* Department6 = new Department("新闻委员会");
    Component* Department7 = new Department("秘书部");
    Component* Department8 = new Department("法律事务部");
    Department1->Add(Department2);
    Department1->Add(Department3);
    Department1->Add(Staff_1);
    Department2->Add(Department4);
    Department2->Add(Department5);
    Department4->Add(Staff_1);
    Department4->Add(Staff_2);
    Department4->Add(Department6);
    Department4->Add(Department7);
    Department4->Add(Department8);
    cout << "\n\n奥组委部门结构:\n";
    cout << "component::Operation(): " << Department1->Operation();
    cout << "\n\n";
    cout << "调整部门结构时不需要考虑是部门还是职工:\n";
    Department1->Remove(Staff_1);
    cout << "component::Operation(): " << Department1->Operation();
    cout << "\n";
    delete Department1;
    delete Department2;
    delete Department3;
    delete Department4;
    delete Department5;
    delete Department6;
    delete Department7;
    delete Department8;
    delete Staff_1;
    delete Staff_2;
    delete Staff_3;
    cout << "\n****************Composite（组合）设计模式结束****************:\n";
    return 0;
}
