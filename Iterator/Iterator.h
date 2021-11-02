#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include"personnel.h"
#include"athlete.h"
#include"../Match.h"
using namespace std;
template <typename T, typename U>
class Iterator {
 public:
  typedef typename std::vector<T>::iterator iter_type;
  Iterator(U *p_data, bool reverse = false) : m_p_data_(p_data) {
    m_it_ = m_p_data_->m_data_.begin();
  }

  void First() {
    m_it_ = m_p_data_->m_data_.begin();
  }

  void Next() {
    m_it_++;
  }

  bool IsDone() {
    return (m_it_ == m_p_data_->m_data_.end());
  }

  iter_type Current() {
    return m_it_;
  }

 private:
  U *m_p_data_;
  iter_type m_it_;
};



template <class T>
class Container {
    friend class Iterator<T, Container>;

public:
    void Add(T a) {
        m_data_.push_back(a);
    }

    Iterator<T, Container>* CreateIterator() {
        return new Iterator<T, Container>(this);
    }

private:
    std::vector<T> m_data_;
};




//class Athlete {
//private:
//    string id_;
//    string name_;
//    string contury_;
//    string match_;
//public:
//    Athlete(string id, string name, string contury) :id_(id), name_(name), contury_(contury) { match_ = ""; }
//    string GetId() {
//        return id_;
//    }
//    string GetName() {
//        return name_;
//    }
//    string GetContury() {
//        return contury_;
//    }
//    string GetMatch() {
//        return match_;
//    }
//    void SetId(string id) {
//        id_ = id;
//    }
//    void SetName(string name) {
//        name_ = name;
//    }
//    void SetContury(string contury) {
//        contury_ = contury;
//    }
//    void SetMatch(string match) {
//        match_ = match;
//    }
//    string athlete() {
//        return id_ +" "+ name_ +" "+ contury_;
//    }
//};



void iteratorTest() {
    vector<Match*> match;
    //Match _match1("羽毛球"), _match2("跳水"), _match3("乒乓球");
    Match* _match1 = new Match("羽毛球");
    Match* _match2 = new Match("跳水");
    Match* _match3 = new Match("乒乓球");

    match.push_back(_match1);
    match.push_back(_match2);
    match.push_back(_match3);
    Container<Match> sport_name;
    for (int i = 0; i < match.size(); i++)
    {
        sport_name.Add(*match[i]);
    }
    cout << endl;
    vector<athlete*> sport;
   // athlete a("01", "运动员1", "China"), b("02", "运动员2", "USA"), c("03", "运动员3", "UK");
    athlete* temp = new athlete("01", "运动员1", "China");
    athlete* temp1 = new athlete("02", "运动员2", "China");
    athlete* temp2 = new athlete("03", "运动员3", "China");
    
    sport.push_back(temp);
    sport.push_back(temp1);
    sport.push_back(temp2);
    Container<athlete> cont2;
    for (int i = 0; i < sport.size(); i++)
    {
        cont2.Add(*sport[i]);
    }


   /* Container<Match> cont;
    Match e1("篮球"), e2("足球");
    cont.Add(e1);
    cont.Add(e2);
    Iterator<Match, Container<Match>>* it1 = cont.CreateIterator();
    for (it1->First(); !it1->IsDone(); it1->Next()) {
        std::cout << it1->Current()->_match() << std::endl;
    }*/
    cout << endl << endl;
   // Container<athlete> cont2;
   // athlete a("01","运动员1","China"), b("02","运动员2","USA"), c("03","运动员3","UK");
   /* cont2.Add(a);
    cont2.Add(b);
    cont2.Add(c);*/

    std::cout << "****************  以下为Iterator（迭代器）设计模式  ******************" << std::endl;
    cout << "Container::Add : created a container named Athlete" << endl;
    cout << "Iterator : created a iterator to visit container" << endl;
    Iterator<Match, Container<Match>>* it1 = sport_name.CreateIterator();
    for (it1->First(); !it1->IsDone(); it1->Next()) {
        std::cout << it1->Current()->GetName() << std::endl;
    }

    Iterator<athlete, Container<athlete>>* it2 = cont2.CreateIterator();
    for (it2->First(); !it2->IsDone(); it2->Next()) {
        std::cout << it2->Current()->_athlete() << std::endl;
    }
    //delete it;
    delete it2;
    std::cout << "****************  Iterator（迭代器）设计模式结束  ******************" << std::endl;
    //delete it3;
}




