#include <iostream>
#include <mutex>
#include <string>
using namespace std;


class Singleton
{

private:
    static Singleton* pinstance;
    static mutex mut;

protected:
    string Olympicname;
    string recordholder;
    string record;
    Singleton(const string name,const string holder,const string rec) : Olympicname(name), recordholder(holder), record(rec)
    {
    }
    ~Singleton() {}
  

public:

    Singleton(Singleton& other) = delete;
    void operator=(const Singleton&) = delete;

    static Singleton* GetInstance(const string& name, const string& holder, const string& rec);


    void recorddeclaration()
    {
        cout << "奥林匹克运动会项目: " << Olympicname << endl << "纪录保持者: " << recordholder << endl << "记录: " << record << endl;
    }


    string Olympicnamevalue() const {
        return Olympicname;
    }
    string recordholdervalue() const {
        return recordholder;
    }
    string recordvalue() const {
        return record;
    }
};


Singleton* Singleton::pinstance{ nullptr };
mutex Singleton::mut;


Singleton* Singleton::GetInstance(const string& name, const string& holder, const string& rec)
{
    lock_guard<std::mutex> lock(mut);
    if (pinstance == nullptr)
    {
        pinstance = new Singleton(name,  holder, rec);
    }
    return pinstance;
}



int main()
{

    cout << "记录创建" << endl;
    Singleton* singleton = Singleton::GetInstance("男子100米","博尔特","9秒58");
    singleton->recorddeclaration();

    cout << endl << endl << endl;
    cout << "记录查询" << endl;
    Singleton* singl = Singleton::GetInstance("","","");
    singl->recorddeclaration();
    return 0;
}