#include <iostream>
#include <vector>
using namespace std;

//球拍制造
//球拍制造说明

class  Racket {
public:
    vector<std::string> pro;
    void process()const {
        for (size_t i = 0; i < pro.size(); i++) {
            cout<<endl << "第" << (i + 1) << "步: ";
            if (pro[i] == pro.back()) {
                cout<< pro[i];
            }
            else {
                cout << pro[i] <<endl;
            }
        }
        cout << endl << endl << endl<<endl;
    }
};


class Manual {
public:
    vector<std::string> con;
    void content()const {
        for (size_t i = 0; i < con.size(); i++) {
            cout << endl << "手册内容" << endl;
            if (con[i] == con.back()) {
                cout << con[i];
            }
            else {
                cout << con[i] << endl;
            }
        }
        cout << endl << endl << endl << endl;
    }
};

class Builder {
public:
    virtual ~Builder() {}
    virtual void frame() const = 0;//球拍框架
    virtual void face() const = 0;//球拍面
    virtual void handle() const = 0;//球拍柄
    virtual void bond() const = 0;//粘合
    
};

class tabletennisBatsBuilder : public Builder {
private:

    Racket* racket;
public:

    tabletennisBatsBuilder() {
        this->Reset();
    }

    ~tabletennisBatsBuilder() {
        delete racket;
    }

    void Reset() {
        this->racket = new Racket();
    }

    void frame() const override {
        this->racket->pro.push_back("制作乒乓球框架");
    }
    void face() const override {
        this->racket->pro.push_back("制作乒乓球拍面");
    }
    void handle() const override {
        this->racket->pro.push_back("制作乒乓球拍柄");
    }
    void bond() const override {
        this->racket->pro.push_back("粘合乒乓球球拍");
    
    }

    Racket* GetProduct() {
        Racket* result = this->racket;
        this->Reset();
        return result;
    }
};

class badmintonBuilder : public Builder {
private:

    Racket* racket;
public:

    badmintonBuilder() {
        this->Reset();
    }

    ~badmintonBuilder() {
        delete racket;
    }

    void Reset() {
        this->racket = new Racket();
    }

    void frame() const override {
        this->racket->pro.push_back("制作羽毛球框架");
    }
    void face() const override {
        this->racket->pro.push_back("制作羽毛球拍面");
    }
    void handle() const override {
        this->racket->pro.push_back("制作羽毛球拍柄");
    }
    void bond() const override {
        this->racket->pro.push_back("粘合羽毛球球拍");

    }

    Racket* GetProduct() {
        Racket* result = this->racket;
        this->Reset();
        return result;
    }
};
class tabletennisBatsmanualBuilder : public Builder {
private:

    Manual* manual;
public:

    tabletennisBatsmanualBuilder() {
        this->Reset();
    }

    ~tabletennisBatsmanualBuilder() {
        delete manual;
    }

    void Reset() {
        this->manual = new Manual();
    }

    void frame() const override {
        this->manual->con.push_back("制作乒乓球框架说明......");
    }
    void face() const override {
        this->manual->con.push_back("制作乒乓球拍面说明......");
    }
    void handle() const override {
        this->manual->con.push_back("制作乒乓球拍柄说明......");
    }
    void bond() const override {
        this->manual->con.push_back("粘合乒乓球球拍说明......");

    }

    Manual* GetProduct() {
        Manual* result = this->manual;
        this->Reset();
        return result;
    }
};

class badmintonmanualBuilder : public Builder {
private:

    Manual* manual;
public:

    badmintonmanualBuilder() {
        this->Reset();
    }

    ~badmintonmanualBuilder() {
        delete manual;
    }

    void Reset() {
        this->manual = new Manual();
    }

    void frame() const override {
        this->manual->con.push_back("制作羽毛球框架说明......");
    }
    void face() const override {
        this->manual->con.push_back("制作羽毛球拍面说明......");
    }
    void handle() const override {
        this->manual->con.push_back("制作羽毛球拍柄说明......");
    }
    void bond() const override {
        this->manual->con.push_back("粘合羽毛球球拍说明......");

    }

    Manual* GetProduct() {
        Manual* result = this->manual;
        this->Reset();
        return result;
    }
};



class Director {

private:
    Builder* builder;
public:

    void set_builder(Builder* builder) {
        this->builder = builder;
    }

    void BuildRacket() {

        this->builder->frame();
        this->builder->face();
        this->builder->handle();
        this->builder->bond();
    }

    
};


void ClientCode(Director& director)
{
    tabletennisBatsBuilder* pingpong = new tabletennisBatsBuilder();
    director.set_builder(pingpong);
    cout << "乒乓球拍制作过程:\n";
    director.BuildRacket();

    Racket* p = pingpong->GetProduct();
    p->process();
    delete p;
    delete pingpong;


    badmintonBuilder* badminton = new  badmintonBuilder();
    director.set_builder(badminton);
    cout << "羽毛球拍制作过程:\n";
    director.BuildRacket();

    Racket* b = badminton->GetProduct();
    b->process();
    delete b;
    delete  badminton;


    tabletennisBatsmanualBuilder* pingpongm = new tabletennisBatsmanualBuilder();
    director.set_builder(pingpongm);
    cout << "乒乓球拍制作过程说明:\n";
    director.BuildRacket();

    Manual* pm = pingpongm->GetProduct();
    pm->content();
    delete pm;
    delete pingpongm;

    badmintonmanualBuilder* badmintonm = new  badmintonmanualBuilder();
    director.set_builder(badmintonm);
    cout << "羽毛球拍制作过程说明:\n";
    director.BuildRacket();

    Manual* bm = badmintonm->GetProduct();
    bm->content();
    delete bm;
    delete  badmintonm;
}

int main() {
    Director* director = new Director();
    ClientCode(*director);
    delete director;
    return 0;
}
