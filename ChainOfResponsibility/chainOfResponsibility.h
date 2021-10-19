#include<iostream>
#include<string>
#include<vector>
#include"CoR.h"


//身份核验-安检-验票


/**
 * All Concrete Handlers either handle a request or pass it to the next handler
 * in the chain.
 */
class IdentityAuthenticationHandler : public AbstractHandler {
public:
    //进行身份核验处理
    void Handle(audience request) override {
        if (request.ID == "1"&&request.name=="1") {
            std::cout << "身份核验通过" << std::endl;
            AbstractHandler::Handle(request);
        }
        else {
            std::cout << "身份核验不通过" << std::endl;
        }
        
    }
};
class SecurityCheckHandler : public AbstractHandler {
public:
    //进行安检处理
    void Handle(audience request) override {
        if (request.dangerous_articles == false) {
            std::cout << "安检通过" << std::endl;
            AbstractHandler::Handle(request);
        }
        else {
            std::cout << "安检不通过" << std::endl;
        }
        
    }
};
class TicketCheckHandler : public AbstractHandler {
public:
    //进行验票处理
    void Handle(audience request) override {
        if (request.ticketID == "1") {
            std::cout << "验票通过" << std::endl;
            AbstractHandler::Handle(request);
        }
        else {
            std::cout << "验票不通过" << std::endl;
        }
        
    }
};
/**
 * The client code is usually suited to work with a single handler. In most
 * cases, it is not even aware that the handler is part of a chain.
 */
//用户代码，向chain中提供request
void ClientCode(Handler& handler) {
    std::vector<audience> audiences = { {"1", "1", "1", 0 } ,{"2","1","1",0} ,{"1","1","2",0} ,{"1","1","1",1} };
    int count = 0;
    for (const audience& i : audiences) {
        count += 1;
        std::cout << std::endl << std::endl << "第" << count << "位观众正在入场" << std::endl << std::endl;
        handler.Handle(i);
        
    }
}
/**
 * The other part of the client code constructs the actual chain.
 */
//设计模式测试代码
void chainOfResponsibilityTest() {
    IdentityAuthenticationHandler* IdentityAuthentication = new IdentityAuthenticationHandler;
    SecurityCheckHandler* SecurityCheck = new SecurityCheckHandler;
    TicketCheckHandler* TicketCheck = new TicketCheckHandler;
    IdentityAuthentication->SetNext(SecurityCheck)->SetNext(TicketCheck);

    /**
     * The client should be able to send a request to any handler, not just the
     * first one in the chain.
     */
    std::cout << "本程序模拟奥林匹克运动会观众身份核验-安检-验票入场场景，使用了CoR--责任链模式" << std::endl << std::endl;
    std::cout << "观众开始入场" << std::endl << std::endl;
    ClientCode(*IdentityAuthentication);
    

    delete IdentityAuthentication;
    delete SecurityCheck;
    delete TicketCheck;

    std::cout << std::endl << "***************  CoR(责任链)设计模式结束  **************************************" << std::endl << std::endl;

}
