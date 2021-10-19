//
//  main.cpp
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#include "FactoryMethod/factoryMethod.h"
#include "AbstractFactory/abstractFactory.h"
#include "TemplateMethod/Template_test.h"
#include "Visitor/Visitor_test.h"
#include "ChainOfResponsibility/chainOfResponsibility.h"
#include "Command/command.h"
#include "facade.h"
#include "flyweight.h"
#include "proxy.h"
#include <iostream>

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    factoryMethodTest();
    abstractFactoryTest();
    MVCTest();
    Template();
    Visitor();
    chainOfResponsibilityTest();
    commandTest();
    facadeTest();
    flyweightTest();
    proxyTest();
    return 0;
}
