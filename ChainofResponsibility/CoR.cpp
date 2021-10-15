#include<iostream>
#include<string>
#include<vector>
#include"CoR.h"

using namespace std;

//��ݺ���-����-��Ʊ


/**
 * All Concrete Handlers either handle a request or pass it to the next handler
 * in the chain.
 */
class IdentityAuthenticationHandler : public AbstractHandler {
public:
    void Handle(audience request) override {
        if (request.ID == "1"&&request.name=="1") {
            cout << "��ݺ���ͨ��" << endl;
            AbstractHandler::Handle(request);
        }
        else {
            cout << "��ݺ��鲻ͨ��" << endl;
        }
        
    }
};
class SecurityCheckHandler : public AbstractHandler {
public:
    void Handle(audience request) override {
        if (request.dangerous_articles == false) {
            cout << "����ͨ��" << endl;
            AbstractHandler::Handle(request);
        }
        else {
            cout << "���첻ͨ��" << endl;
        }
        
    }
};
class TicketCheckHandler : public AbstractHandler {
public:
    void Handle(audience request) override {
        if (request.ticketID == "1") {
            cout << "��Ʊͨ��" << endl;
            AbstractHandler::Handle(request);
        }
        else {
            cout << "��Ʊ��ͨ��" << endl;
        }
        
    }
};
/**
 * The client code is usually suited to work with a single handler. In most
 * cases, it is not even aware that the handler is part of a chain.
 */
void ClientCode(Handler& handler) {
    std::vector<audience> audiences = { {"1", "1", "1", 0 } ,{"2","1","1",0} ,{"1","1","2",0} ,{"1","1","1",1} };
    int count = 0;
    for (const audience& i : audiences) {
        //cout << "Client: Who wants a " << f << "?\n";
        //audience i = { "1","1","2",0 };
        count += 1;
        cout << endl << endl << "��" << count << "λ���������볡" << endl << endl;
        handler.Handle(i);
        //if (!result.empty()) {
            //cout << "  " << result;
        //}
        /*else {
            cout << "  " << f << " was left untouched.\n";
        }*/
    }
}
/**
 * The other part of the client code constructs the actual chain.
 */
int main() {
    IdentityAuthenticationHandler* IdentityAuthentication = new IdentityAuthenticationHandler;
    SecurityCheckHandler* SecurityCheck = new SecurityCheckHandler;
    TicketCheckHandler* TicketCheck = new TicketCheckHandler;
    IdentityAuthentication->SetNext(SecurityCheck)->SetNext(TicketCheck);

    /**
     * The client should be able to send a request to any handler, not just the
     * first one in the chain.
     */
    cout << "������ģ�����ƥ���˶�������볡������ʹ����CoR--������ģʽ" << endl << endl;
    cout << "���ڿ�ʼ�볡"<<endl<<endl;
    ClientCode(*IdentityAuthentication);
    //cout << "\n";
    //cout << "Subchain: Squirrel > Dog\n\n";
    //ClientCode(*squirrel);

    delete IdentityAuthentication;
    delete SecurityCheck;
    delete TicketCheck;

    return 0;
}
