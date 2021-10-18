//
//  medalTableModel.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/18.
//

#ifndef medalTableModel_h
#define medalTableModel_h

#include <vector>
#include <string>

using namespace std;

class MedalTableModel {
    
    friend class MedalTableController;
    
private:
    vector<string> national_names;
    vector<int> gold_medal_num;
    vector<int> silver_medal_num;
    vector<int> bronze_medal_num;
    
    int getTableSize() {
        return static_cast<int>(national_names.size());
    }
    
    string getNationalNames(int index) {
        if (index < 0 || index > this->national_names.size() - 1) {
            return string("null");
        }
        else {
            return this->national_names[index];
        }
    }
    
    int getGoldMedalNum(int index) {
        if (index < 0 || index > this->gold_medal_num.size() - 1) {
            return -1;
        }
        else {
            return this->gold_medal_num[index];
        }
    }
    
    int getSilverMedalNum(int index) {
        if (index < 0 || index > this->silver_medal_num.size() - 1) {
            return -1;
        }
        else {
            return this->silver_medal_num[index];
        }
    }
    
    int getBronzeMedalNum(int index) {
        if (index < 0 || index > this->bronze_medal_num.size() - 1) {
            return -1;
        }
        else {
            return this->bronze_medal_num[index];
        }
    }
    
    bool setGoldMedalNum(int index, int num) {
        if (index < 0 || index > this->gold_medal_num.size() - 1) {
            return false;
        }
        else {
            this->gold_medal_num[index] = num;
            return true;
        }
    }
    
    bool setSilverMedalNum(int index, int num) {
        if (index < 0 || index > this->silver_medal_num.size() - 1) {
            return false;
        }
        else {
            this->silver_medal_num[index] = num;
            return true;
        }
    }
    
    bool setBronzeMedalNum(int index, int num) {
        if (index < 0 || index > this->bronze_medal_num.size() - 1) {
            return false;
        }
        else {
            this->bronze_medal_num[index] = num;
            return true;
        }
    }
    
public:
    MedalTableModel(vector<string> national_names,
                    vector<int> gold_medal_num,
                    vector<int> silver_medal_num,
                    vector<int> bronze_medal_num):
    national_names(national_names),
    gold_medal_num(gold_medal_num),
    silver_medal_num(silver_medal_num),
    bronze_medal_num(bronze_medal_num)
    {}
    
    MedalTableModel() {}
};

#endif /* medalTableModel_h */
