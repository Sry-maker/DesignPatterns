#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include"Composite.h"


Composite* COC = new Department("�й���ί��");
int compositeAddDepartment() {
    std::cout << "****************����ΪComposite����ϣ����ģʽ****************:\n";
    Composite* Staff_2 = new Staff("�й���ί����ϯ");
    Composite* Staff_3 = new Staff("�й���ί�ḱ��ϯ");
    Composite* Department6 = new Department("����ίԱ��");
    Composite* Department7 = new Department("���鲿");
    Composite* Department8 = new Department("��������");
    COC->Add(Staff_2);
    COC->Add(Staff_3);
    COC->Add(Department6);
    COC->Add(Department7);
    COC->Add(Department8);
    std::cout << "\n\n��������ί���Žṹ:\n";
    std::cout << "composite::Operation(): " << COC->Operation();
    std::cout << "\n\n";
    std::cout << "��������Ӳ�������:\n";
    char name[20];
    std::cin >> name;
    Composite* Department9 = new Department(name);
    COC->Add(Department9);
    std::cout << "composite::Operation(): " << COC->Operation();
    std::cout << "\n";
    std::cout << "\n****************Composite����ϣ����ģʽ����****************:\n";
    return 0;
}

int compositeAddClient() {
    std::cout << "****************����ΪComposite����ϣ����ģʽ****************:\n";
    std::cout << "\n\n��������ί���Žṹ:\n";
    std::cout << "composite::Operation(): " << COC->Operation();
    std::cout << "\n\n";
    std::cout << "���������Ա������:\n";
    char name[20];
    std::cin >> name;
    Composite* staff_4 = new Staff(name);
    COC->Add(staff_4);
    std::cout << "composite::Operation(): " << COC->Operation();
    std::cout << "\n";
    std::cout << "\n****************Composite����ϣ����ģʽ����****************:\n";
    return 0;
}
int compositeTest() {
    cout << "****************����ΪComposite����ϣ����ģʽ****************:\n";
    Composite* Department1 = new Department("���ʰ�ί��");
    Composite* Department2 = new Department("���ʰ�ί��ȫ��ίԱ��");
    Composite* Department3 = new Department("ִ��ίԱ��");
    Composite* Staff_1 = new Staff("���ʰ�ί����ϯ");
    Composite* Department4 = new Department("�й���ί��");
    Composite* Staff_2 = new Staff("�й���ί����ϯ");
    Composite* Staff_3 = new Staff("�й���ί�ḱ��ϯ");
    Composite* Department5 = new Department("�ձ���ί��");
    Composite* Department6 = new Department("����ίԱ��");
    Composite* Department7 = new Department("���鲿");
    Composite* Department8 = new Department("��������");
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
    cout << "\n\n����ί���Žṹ:\n";
    cout << "composite::Operation(): " << Department1->Operation();
    cout << "\n\n";
    cout << "�������Žṹʱ����Ҫ�����ǲ��Ż���ְ��:\n";
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
    cout << "\n****************Composite����ϣ����ģʽ����****************:\n";
    compositeAddDepartment();
    compositeAddClient();
    return 0;
}
