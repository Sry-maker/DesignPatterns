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


// 奖牌榜的模型（Model）
class MedalTableModel {

    // 将控制器设置为友元类
    friend class MedalTableController;
    
private:
    
    // 奖牌榜的数据
    vector<string> national_names;
    vector<int> gold_medal_num;
    vector<int> silver_medal_num;
    vector<int> bronze_medal_num;
    
// 各种接口以供控制器调用

    // 获取奖牌榜大小接口
    int getTableSize() {
        return static_cast<int>(national_names.size());
    }
    
    // 获取国家名称接口
    string getNationalNames(int index) {
        if (index < 0 || index > this->national_names.size() - 1) {
            return string("null");
        }
        else {
            return this->national_names[index];
        }
    }
    
    // 获取金牌数接口
    int getGoldMedalNum(int index) {
        if (index < 0 || index > this->gold_medal_num.size() - 1) {
            return -1;
        }
        else {
            return this->gold_medal_num[index];
        }
    }
    
    // 获取银牌数接口
    int getSilverMedalNum(int index) {
        if (index < 0 || index > this->silver_medal_num.size() - 1) {
            return -1;
        }
        else {
            return this->silver_medal_num[index];
        }
    }
    
    // 获取铜牌数接口
    int getBronzeMedalNum(int index) {
        if (index < 0 || index > this->bronze_medal_num.size() - 1) {
            return -1;
        }
        else {
            return this->bronze_medal_num[index];
        }
    }
    
    // 设置金牌数接口
    bool setGoldMedalNum(int index, int num) {
        if (index < 0 || index > this->gold_medal_num.size() - 1) {
            return false;
        }
        else {
            this->gold_medal_num[index] = num;
            return true;
        }
    }
    
    // 设置银牌数接口
    bool setSilverMedalNum(int index, int num) {
        if (index < 0 || index > this->silver_medal_num.size() - 1) {
            return false;
        }
        else {
            this->silver_medal_num[index] = num;
            return true;
        }
    }
    
    // 设置铜牌数接口
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
    {
        std::cout << "MedalTableModel::MedalTableModel : 创建模型（Model）" << std::endl;
    }
    
    MedalTableModel() {}
};

#endif /* medalTableModel_h */
