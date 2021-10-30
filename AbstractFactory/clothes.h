//
//  clothes.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#ifndef clothes_h
#define clothes_h


// 抽象产品Clothes
class AbstractClothes {
public:
    virtual ~AbstractClothes() {};
    virtual void wearClothes() = 0;
};


// 具体产品：篮球衣
class BasketballClothes : public AbstractClothes {
public:
    void wearClothes() override {
        
    }
};


// 具体产品：足球衣
class SoccerClothes : public AbstractClothes {
public:
    void wearClothes() override {
        
    }
};
#endif /* clothes_h */
