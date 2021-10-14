//
//  abstractFactory.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#ifndef abstractFactory_h
#define abstractFactory_h

#include "factory.h"


// 抽象工厂模式测试接口函数
void abstractFactory() {
    AbstractFactory* factory1 = new BasketballSuppliesFactory(); // 创建一个新的篮球运动相关工厂
    AbstractBall* ball1 = factory1->makeBall();                  // 生产相关的产品
    AbstractShoes* shoes1 = factory1->makeShoes();
    AbstractClothes* clothes1 = factory1->makeClothes();
    
    AbstractFactory* factory2 = new SoccerballSuppliesFactory(); // 创建一个新的足球运动相关工厂
    AbstractBall* ball2 = factory2->makeBall();                  // 生产相关的产品
    AbstractShoes* shoes2 = factory2->makeShoes();
    AbstractClothes* clothes2 = factory2->makeClothes();
    
    delete factory1;
    delete ball1;
    delete shoes1;
    delete clothes1;
    delete factory2;
    delete ball2;
    delete shoes2;
    delete clothes2;
}

#endif /* abstractFactory_h */
