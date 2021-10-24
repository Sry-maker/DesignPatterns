#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include"Component.h"
using namespace std;



int componentTest()  {
    cout << "****************����ΪComposite����ϣ����ģʽ****************:\n";
    Component* Department1 = new Department("���ʰ�ί��");
    Component* Department2 = new Department("���ʰ�ί��ȫ��ίԱ��");
    Component* Department3 = new Department("ִ��ίԱ��");
    Component* Staff_1 = new Staff("���ʰ�ί����ϯ");
    Component* Department4 = new Department("�й���ί��");
    Component* Staff_2 = new Staff("�й���ί����ϯ");
    Component* Staff_3 = new Staff("�й���ί�ḱ��ϯ");
    Component* Department5 = new Department("�ձ���ί��");
    Component* Department6 = new Department("����ίԱ��");
    Component* Department7 = new Department("���鲿");
    Component* Department8 = new Department("��������");
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
    cout << "component::Operation(): " << Department1->Operation();
    cout << "\n\n";
    cout << "�������Žṹʱ����Ҫ�����ǲ��Ż���ְ��:\n";
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
    cout << "\n****************Composite����ϣ����ģʽ����****************:\n";
    return 0;
}
