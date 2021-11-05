#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include"Composite.h"


Composite* COC =NULL;
int compositeAddDepartment() {
    std::cout << "****************以下为Composite（组合）设计模式****************:\n";
    COC = new Department("中国奥委会");
    Composite* Staff_2 = new Staff("中国奥委会主席");
    Composite* Staff_3 = new Staff("中国奥委会副主席");
    Composite* Department6 = new Department("新闻委员会");
    Composite* Department7 = new Department("秘书部");
    Composite* Department8 = new Department("法律事务部");
    COC->Add(Staff_2);
    COC->Add(Staff_3);
    COC->Add(Department6);
    COC->Add(Department7);
    COC->Add(Department8);
    std::cout << "\n\n北京奥组委部门结构:\n";
    std::cout << "composite::Operation(): " << COC->Operation();
    std::cout << "\n\n";
    std::cout << "请输入添加部门名称:\n";
    char name[20]="";
    std::cin >> name;
    Composite* Department9 = new Department(name);
    COC->Add(Department9);
    std::cout << "composite::Operation(): " << COC->Operation();
    std::cout << "\n";
    std::cout << "\n****************Composite（组合）设计模式结束****************:\n";
    return 0;
}

int compositeAddClient() {
    std::cout << "****************以下为Composite（组合）设计模式****************:\n";
    if (COC == NULL) {
        COC = new Department("中国奥委会");
    }
    std::cout << "\n\n北京奥组委部门结构:\n";
    std::cout << "composite::Operation(): " << COC->Operation();
    std::cout << "\n\n";
    std::cout << "请输入添加员工名称:\n";
    char name[20] = "";
    std::cin >> name;
    Composite* staff_4 = new Staff(name);
    COC->Add(staff_4);
    std::cout << "composite::Operation(): " << COC->Operation();
    std::cout << "\n";
    std::cout << "\n****************Composite（组合）设计模式结束****************:\n";
    return 0;
}
int compositeTest() {
    cout << "****************以下为Composite（组合）设计模式****************:\n";
    Composite* Department1 = new Department("国际奥委会");
    Composite* Department2 = new Department("国际奥委会全体委员会");
    Composite* Department3 = new Department("执行委员会");
    Composite* Staff_1 = new Staff("国际奥委会主席");
    Composite* Department4 = new Department("中国奥委会");
    Composite* Staff_2 = new Staff("中国奥委会主席");
    Composite* Staff_3 = new Staff("中国奥委会副主席");
    Composite* Department5 = new Department("日本奥委会");
    Composite* Department6 = new Department("新闻委员会");
    Composite* Department7 = new Department("秘书部");
    Composite* Department8 = new Department("法律事务部");
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
    cout << "composite::Operation(): " << Department1->Operation();
    cout << "\n\n";
    cout << "调整部门结构时不需要考虑是部门还是职工:\n";
    Department1->Remove(Staff_1);
    cout << "composite::Operation(): " << Department1->Operation();
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
    compositeAddDepartment();
    compositeAddClient();
    return 0;
}

