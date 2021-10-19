﻿#pragma once
#define DELETE_OBJECT(p) {if(NULL != (p)){delete (p); (p) = NULL;}}
#include<iostream>

using namespace std;

/*
为表现优异的运动员颁发赞助商提供的手机作为奖品。
赞助商品牌有Samsung与Apple，每个品牌各提供了两种型号的旗舰手机;
手机的操作系统有iOS与Android，由于出厂时间不同，不同手机预装操作系统的版本有区别。
 */

 //抽象的操作系统类：
class OS
{
public:
    virtual std::string GetOS() = 0;
};

//iOS类的实现
class iOS : public OS
{
public:
    virtual std::string GetOS()
    {
        return "iOS操作系统";
    }
};

//Android类的实现
class Android : public OS
{
public:
    virtual std::string GetOS()
    {
        return "Android操作系统";
    }
};

//iOS某个版本的实现
class iOSSubSystem1 : public iOS
{
public:
    virtual std::string GetOS()
    {
        return "iOS 13操作系统";
    }
};

//iOS某个版本的实现
class iOSSubSystem2 : public iOS
{
public:
    virtual std::string GetOS()
    {
        return "iOS 14操作系统";
    }
};

//Android系统某个类的实现
class AndroidSubSystem1 : public Android
{
public:
    virtual std::string GetOS()
    {
        return "Android 11操作系统";
    }
};

//Android系统某个类的实现
class AndroidSubSystem2 : public Android
{
public:
    virtual std::string GetOS()
    {
        return "Android 12操作系统";
    }
};

//抽象的手机类
class Phone
{
public:
    virtual void SetOS() = 0;
};

//Apple手机类，依赖抽象的操作系统
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
        cout << "手机的预装系统为: " << m_pOS->GetOS().c_str() <<"。"<< endl;
    }
private:
    OS* m_pOS;
};

//Samsung手机类，以来抽象的操作系统
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
        cout << "手机的预装系统为: " << m_pOS->GetOS().c_str() << "。" << endl;
    }
private:
    OS* m_pOS;
};


void bridgeTest() {
    
    cout << "BridgeTest:" << endl<<endl;

    cout<<"下面为近期比赛表现优异的四位选手颁发奖品："<<endl << endl;

    OS* piOS1 = new iOSSubSystem1(); //创建一个操作系统
    Phone* iPhone13Pro = new iPhone(piOS1);//应用到该手机上
    cout << "第一位选手的奖品为iPhone13Pro，"<<endl;
    iPhone13Pro->SetOS();
    cout << endl;

    OS* piOS2 = new iOSSubSystem2();
    Phone* iPhone13ProMax = new iPhone(piOS2);
    cout << "第二位选手的奖品为iPhone13ProMax，" << endl;
    iPhone13ProMax->SetOS();
    cout << endl;

    OS* pAndroid1 = new AndroidSubSystem1();
    Phone* SamsungS21 = new Samsung(pAndroid1);
    cout << "第三位选手的奖品为SamsungS21，" << endl;
    SamsungS21->SetOS();
    cout << endl;

    OS* pAndroid2 = new AndroidSubSystem2();
    Phone* SamsungS21Ultra = new Samsung(pAndroid2);
    cout << "第四位选手的奖品为SamsungS21Ultra，" << endl;
    SamsungS21Ultra->SetOS();
    cout << endl;

    cout<<"再次祝贺这四位选手！"<<endl;

    DELETE_OBJECT(iPhone13Pro);
    DELETE_OBJECT(iPhone13ProMax);
    DELETE_OBJECT(SamsungS21);
    DELETE_OBJECT(SamsungS21Ultra);
}