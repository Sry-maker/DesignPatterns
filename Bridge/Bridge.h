#pragma once
#define DELETE_OBJECT(p) {if(NULL != (p)){delete (p); (p) = NULL;}}
#include<iostream>

using namespace std;

/*
Ϊ����������˶�Ա�䷢�������ṩ���ֻ���Ϊ��Ʒ��
������Ʒ����Samsung��Apple��ÿ��Ʒ�Ƹ��ṩ�������ͺŵ��콢�ֻ�;
�ֻ��Ĳ���ϵͳ��iOS��Android�����ڳ���ʱ�䲻ͬ����ͬ�ֻ�Ԥװ����ϵͳ�İ汾������
 */

 //����Ĳ���ϵͳ�ࣺ
class OS
{
public:
    virtual std::string GetOS() = 0;
};

//iOS���ʵ��
class iOS : public OS
{
public:
    virtual std::string GetOS()
    {
        return "iOS����ϵͳ";
    }
};

//Android���ʵ��
class Android : public OS
{
public:
    virtual std::string GetOS()
    {
        return "Android����ϵͳ";
    }
};

//iOSĳ���汾��ʵ��
class iOSSubSystem1 : public iOS
{
public:
    virtual std::string GetOS()
    {
        return "iOS 13����ϵͳ";
    }
};

//iOSĳ���汾��ʵ��
class iOSSubSystem2 : public iOS
{
public:
    virtual std::string GetOS()
    {
        return "iOS 14����ϵͳ";
    }
};

//Androidϵͳĳ�����ʵ��
class AndroidSubSystem1 : public Android
{
public:
    virtual std::string GetOS()
    {
        return "Android 11����ϵͳ";
    }
};

//Androidϵͳĳ�����ʵ��
class AndroidSubSystem2 : public Android
{
public:
    virtual std::string GetOS()
    {
        return "Android 12����ϵͳ";
    }
};

//������ֻ���
class Phone
{
public:
    virtual void SetOS() = 0;
};

//Apple�ֻ��࣬��������Ĳ���ϵͳ
class iPhone : public Phone
{
public:
    iPhone(OS* os)
    {
        m_pOS = os;
    }
    ~iPhone()
    {
        DELETE_OBJECT(m_pOS);
    }
    virtual void SetOS()
    {
        cout << "�ֻ���ԤװϵͳΪ: " << m_pOS->GetOS().c_str() <<"��"<< endl;
    }
private:
    OS* m_pOS;
};

//Samsung�ֻ��࣬��������Ĳ���ϵͳ
class Samsung : public Phone
{
public:
    Samsung(OS* os)
    {
        m_pOS = os;
    }
    ~Samsung()
    {
        DELETE_OBJECT(m_pOS);
    }

    virtual void SetOS()
    {
        cout << "�ֻ���ԤװϵͳΪ: " << m_pOS->GetOS().c_str() << "��" << endl;
    }
private:
    OS* m_pOS;
};


void bridgeTest() {
    
    cout << "BridgeTest:" << endl<<endl;

    cout<<"����Ϊ���ڱ��������������λѡ�ְ䷢��Ʒ��"<<endl << endl;

    OS* piOS1 = new iOSSubSystem1(); //����һ������ϵͳ
    Phone* iPhone13Pro = new iPhone(piOS1);//Ӧ�õ����ֻ���
    cout << "��һλѡ�ֵĽ�ƷΪiPhone13Pro��"<<endl;
    iPhone13Pro->SetOS();
    cout << endl;

    OS* piOS2 = new iOSSubSystem2();
    Phone* iPhone13ProMax = new iPhone(piOS2);
    cout << "�ڶ�λѡ�ֵĽ�ƷΪiPhone13ProMax��" << endl;
    iPhone13ProMax->SetOS();
    cout << endl;

    OS* pAndroid1 = new AndroidSubSystem1();
    Phone* SamsungS21 = new Samsung(pAndroid1);
    cout << "����λѡ�ֵĽ�ƷΪSamsungS21��" << endl;
    SamsungS21->SetOS();
    cout << endl;

    OS* pAndroid2 = new AndroidSubSystem2();
    Phone* SamsungS21Ultra = new Samsung(pAndroid2);
    cout << "����λѡ�ֵĽ�ƷΪSamsungS21Ultra��" << endl;
    SamsungS21Ultra->SetOS();
    cout << endl;

    cout<<"�ٴ�ף������λѡ�֣�"<<endl;

    DELETE_OBJECT(iPhone13Pro);
    DELETE_OBJECT(iPhone13ProMax);
    DELETE_OBJECT(SamsungS21);
    DELETE_OBJECT(SamsungS21Ultra);
}
