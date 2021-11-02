#pragma once
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

class Strategy
{
public:
    virtual ~Strategy() {}
    virtual std::string DoAlgorithm(const std::vector<std::string>& data) const = 0;
};

class Context_Strategy
{
   
private:
    Strategy* strategy_;
    
public:
    Context_Strategy(Strategy* strategy = nullptr) : strategy_(strategy)
    {
    }
    ~Context_Strategy()
    {
        delete this->strategy_;
    }
    
    void set_strategy(Strategy* strategy)
    {
        delete this->strategy_;
        this->strategy_ = strategy;
    }
    
    void DoSomeBusinessLogic() const
    {
        
        std::cout << "Context::DoSomeBusinessLogic : ";
        std::cout << "本算法下的比赛顺序\n";
        std::string result = this->strategy_->DoAlgorithm(std::vector<std::string>{"乒乓球", "跳水", "羽毛球"});
        std::cout << result << "\n";
       
    }
};


class ConcreteStrategyA : public Strategy
{
public:
    std::string DoAlgorithm(const std::vector<std::string>& data) const override
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string& letter) {
            result += letter;
            result += " ";
            });

        return result;
    }
};
class ConcreteStrategyB : public Strategy
{
    std::string DoAlgorithm(const std::vector<std::string>& data) const override
    {
        std::string result;
        std::for_each(std::begin(data), std::end(data), [&result](const std::string& letter) {
            result = letter + " " + result ;
            
            });

        return result;
    }
};


void AthleteCode_strategy()
{
    Context_Strategy* context = new Context_Strategy(new ConcreteStrategyA);
    std::cout << "ConcreteStrategyB::DoAlgorithm : 算法2策略下\n";
    context->DoSomeBusinessLogic();
    std::cout << "ConcreteStrategyA::DoAlgorithm : 算法1策略下\n";
    context->set_strategy(new ConcreteStrategyB);
    context->DoSomeBusinessLogic();
    delete context;
}
Context_Strategy* context2 = new Context_Strategy(new ConcreteStrategyA);
void strategy_2()
{
    std::cout << "ConcreteStrategyB::DoAlgorithm : 算法2策略下\n";
    context2->DoSomeBusinessLogic();
}
void strategy_1()
{
    std::cout << "ConcreteStrategyA::DoAlgorithm : 算法1策略下\n";
    context2->set_strategy(new ConcreteStrategyB);
    context2->DoSomeBusinessLogic();
    delete context2;
}

void strategyTest(){
    std::cout << "***************  以下为strategy(策略)设计模式  ******************************" << std::endl;
    AthleteCode_strategy();
    std::cout << std::endl;
}