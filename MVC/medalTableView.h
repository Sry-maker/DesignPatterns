//
//  medalTableView.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/18.
//

#ifndef medalTableView_h
#define medalTableView_h

#include <string>
#include <iomanip>


const int WIDTH = 10;

using namespace std;

// 奖牌榜的视图（View）
class MedalTableView {
    
    // 将控制器设置为友元类
    friend class MedalTableController;
    
private:
    
    // 打印奖牌榜（控制器调用 显示模型）
    void printMedalTableRol(
                string national_name,
                int gold_medal_num,
                int silver_medal_num,
                int bronze_medal_num) {
        cout.setf(std::ios::left);
        cout << setw(WIDTH) << national_name << setw(WIDTH) << gold_medal_num
        << setw(WIDTH) << silver_medal_num << setw(WIDTH) << bronze_medal_num << endl;
    }
    
    // 打印奖牌榜标头
    void printTitle() {
        cout.setf(std::ios::left);
        cout << setw(WIDTH) << "国家" << setw(WIDTH) << "金牌数"
        << setw(WIDTH) << "    银牌数" << setw(WIDTH) << "     铜牌数" << endl;
    }
};


#endif /* medalTableView_h */
