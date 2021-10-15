#include<iostream>
#include<string>
#include<vector>
#include"CoR.h"

using namespace std;

//身份核验-安检-验票


/**
 * All Concrete Handlers either handle a request or pass it to the next handler
 * in the chain.
 */
class IdentityAuthenticationHandler : public AbstractHandler {
public:
    void Handle(audience request) override {
        if (request.ID == "1"&&request.name=="1") {
            cout << "身份核验通过" << endl;
            AbstractHandler::Handle(request);
        }
        else {
            cout << "身份核验不通过" << endl;
        }
        
    }
};
class SecurityCheckHandler : public AbstractHandler {
public:
    void Handle(audience request) override {
        if (request.dangerous_articles == false) {
            cout << "安检通过" << endl;
            AbstractHandler::Handle(request);
        }
        else {
            cout << "安检不通过" << endl;
        }
        
    }
};
class TicketCheckHandler : public AbstractHandler {
public:
    void Handle(audience request) override {
        if (request.ticketID == "1") {
            cout << "验票通过" << endl;
            AbstractHandler::Handle(request);
        }
        else {
            cout << "验票不通过" << endl;
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
        cout << endl << endl << "第" << count << "位观众正在入场" << endl << endl;
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
    cout << "本程序模拟奥林匹克运动会观众入场场景，使用了CoR--责任链模式" << endl << endl;
    cout << "观众开始入场"<<endl<<endl;
    ClientCode(*IdentityAuthentication);
    //cout << "\n";
    //cout << "Subchain: Squirrel > Dog\n\n";
    //ClientCode(*squirrel);

    delete IdentityAuthentication;
    delete SecurityCheck;
    delete TicketCheck;

    return 0;
}
