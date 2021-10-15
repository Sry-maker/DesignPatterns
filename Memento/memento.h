#define _CRT_SECRTY_NO_WARNINGS
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;

void mementoTest();
//����¼
/*����¼��ԭ����״̬���յ�ֵ���� ��value object���� 
ͨ�������ǽ�����¼��Ϊ���ɱ�ģ�
��ͨ�����캯��һ���Դ������ݡ�*/

class Memento {
private:
    string operation;
public:
    //Memento�Ĵ��麯�����õ�����¼��¼�Ĳ�������
    virtual  string GetOperation() = 0;
};

//ԭ����
/*ԭ�����������������״̬�Ŀ��գ� 
Ҳ��������Ҫʱͨ�����ջָ�����״̬*/
class EventOriginator {
private:
     string event_;
    //������EventOriginator���У��� EventOriginator�ṩ��ӿڣ����������ṩխ�ӿ�
    class ConcreteMemento : public Memento {
    private:
        string event_;
        string operation_;
    public:
        //ConcreteMemento�Ĺ��캯��������һ������¼
        ConcreteMemento(string,string);
        //�õ���������Ŀ����
        string GetEvent();
        //�õ�����¼��¼�Ĳ�������
        string GetOperation();
    };

public:
    //EventOriginator��Ĺ��캯������ʼ��EventOriginator
    EventOriginator(string);
    //�ı䱨������Ŀ����
    void ChangeEvent(string);
    //չʾ��������Ŀ����
    string ShowEvent();
    //����ǰ��Ŀ���Ƽ�¼�ڱ���¼��
    Memento* Save();
    //�˻ص�֮ǰ����Ŀ����
    void Restore(Memento*);
};

//������
/*������ͨ�����汸��¼ջ����¼ԭ��������ʷ״̬�� 
��ԭ������Ҫ������ʷ״̬ʱ�� �����˽���ջ�л�ȡ
����ı���¼�� �����䴫�ݸ�ԭ�����Ļָ� ��restore�� ������*/

class Caretaker {
private:
     vector<Memento*> mementos_;
    EventOriginator* originator_;
public:
    //���ɶ���ԭ�����ĸ�����
    Caretaker(EventOriginator*);
    //����ԭ�����ĵ�ǰ״̬����¼�ڱ���¼��
    void Backup();
    //�˻ص�ԭ����֮ǰ��״̬
    void Undo();
    //չʾ����¼�����еĲ�����¼
    void ShowHistory()const;
};

