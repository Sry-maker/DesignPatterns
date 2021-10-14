//
//  factory.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#ifndef factory_h
#define factory_h

#include "ball.h"
#include "shoes.h"
#include "clothes.h"
#include <iostream>


// 抽象工厂类
class AbstractFactory {
public:
    virtual AbstractBall* makeBall() = 0;
    virtual AbstractShoes* makeShoes() = 0;
    virtual AbstractClothes* makeClothes() = 0;
    
    virtual ~AbstractFactory(){};
};


// 具体篮球相关产品工厂：继承自普通工厂
class BasketballSuppliesFactory : public AbstractFactory {
public:
    AbstractBall* makeBall() override {
        std::cout << "生产一个篮球" << std::endl;
        return new Basketball();
    }
    AbstractShoes* makeShoes() override {
        std::cout << "生产一双篮球鞋" << std::endl;
        return new BasketballShoes();
    }
    AbstractClothes* makeClothes() override {
        std::cout << "生产一件篮球衣" << std::endl;
        return new BasketballClothes();
    }
    BasketballSuppliesFactory() {
        std::cout << "篮球相关产品工厂" << std::endl;
    }
};


// 具体足球相关产品工厂：继承自普通工厂
class SoccerballSuppliesFactory : public AbstractFactory {
public:
    AbstractBall* makeBall() override {
        std::cout << "生产一个足球" << std::endl;
        return new Soccerball();
    }
    AbstractShoes* makeShoes() override {
        std::cout << "生产一双足球鞋" << std::endl;
        return new SoccerShoes();
    }
    AbstractClothes* makeClothes() override {
        std::cout << "生产一件足球衣" << std::endl;
        return new SoccerClothes();
    }
    SoccerballSuppliesFactory() {
        std::cout << "足球相关产品工厂" << std::endl;
    }
};



#endif /* factory_h */
