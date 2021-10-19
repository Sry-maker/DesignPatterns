//
//  main.cpp
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#include "FactoryMethod/factoryMethod.h"
#include "AbstractFactory/abstractFactory.h"
#include "TemplateMethod/TemplateTest.h"
#include "Visitor/VisitorTest.h"
#include "ChainOfResponsibility/chainOfResponsibility.h"
#include "Command/command.h"
#include "facade.h"
#include "flyweight.h"
#include "proxy.h"
#include "./Callback/callBackTest.h"
#include "./Composite/compositeTest.h"
#include "./Decorator/decoratorTest.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    factoryMethodTest();
    abstractFactoryTest();
    MVCTest();
    templateTest();
    visitorTest();
    chainOfResponsibilityTest();
    commandTest();
    facadeTest();
    flyweightTest();
    proxyTest();
    callBackTest();
    compositeTest();
    decoratorTest();
    return 0;
}
