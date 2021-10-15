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
        cout << "����ƥ���˶�����Ŀ: " << Olympicname << endl << "��¼������: " << recordholder << endl << "��¼: " << record << endl;
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

    cout << "��¼����" << endl;
    Singleton* singleton = Singleton::GetInstance("����100��","������","9��58");
    singleton->recorddeclaration();

    cout << endl << endl << endl;
    cout << "��¼��ѯ" << endl;
    Singleton* singl = Singleton::GetInstance("","","");
    singl->recorddeclaration();
    return 0;
}