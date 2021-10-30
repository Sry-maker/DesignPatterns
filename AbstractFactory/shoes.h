//
//  shoes.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#ifndef shoes_h
#define shoes_h


// 抽象产品Shoes
class AbstractShoes {
public:
    virtual ~AbstractShoes() {};
    virtual void wearShoes() = 0;
};


// 具体产品：篮球鞋
class BasketballShoes : public AbstractShoes {
public:
    void wearShoes() override {
        
    }
};


// 具体产品：足球鞋
class SoccerShoes : public AbstractShoes {
public:
    void wearShoes() {
        
    }
};


#endif /* shoes_h */
