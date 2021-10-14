//
//  ball.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/9.
//

#ifndef ball_h
#define ball_h


// 抽象的产品Ball
class AbstractBall {
public:
    virtual ~AbstractBall(){};
    virtual void useBall() = 0;
};


// 具体产品：篮球
class Basketball : public AbstractBall {
public:
    void useBall() override {
        
    }
};


//具体产品：足球
class Soccerball : public AbstractBall {
public:
    void useBall() override {
        
    }
};


#endif /* ball_h */
