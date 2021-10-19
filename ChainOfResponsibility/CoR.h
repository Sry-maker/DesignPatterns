#pragma once
/**
* The audience class represents people who are the audience of the Olympic Games.
*/
class audience {
public:
    std::string ID;
    std::string name;
    std::string ticketID;
    bool dangerous_articles;//whether the person carries dangerous articles.

    audience(std::string ID, std::string name, std::string ticketID, bool dangerous_articles)
    {
        this->ID = ID;
        this->name = name;
        this->ticketID = ticketID;
        this->dangerous_articles = dangerous_articles;
    }
};



/**
 * The Handler interface declares a method for building the chain of handlers.
 * It also declares a method for executing a request.
 */
class Handler {
public:
    virtual Handler* SetNext(Handler* handler) = 0;
    virtual void Handle(audience request) = 0;
};
/**
 * The default chaining behavior can be implemented inside a base handler class.
 */
class AbstractHandler : public Handler {
private:
    Handler* next_handler_;

public:
    AbstractHandler() : next_handler_(nullptr) {
    }
    
    //设置chain,连接下一个handler
    Handler* SetNext(Handler* handler) override {
        this->next_handler_ = handler;
        // Returning a handler from here will let us link handlers in a convenient
        // way
        return handler;
    }
    
    //向下一个handler传递request
    void Handle(audience request) override {
        
        if (this->next_handler_) {
            this->next_handler_->Handle(request);
        }

        
    }
};
