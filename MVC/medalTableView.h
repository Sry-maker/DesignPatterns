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

class MedalTableView {
    friend class MedalTableController;
    
private:
    void printMedalTableRol(
                string national_name,
                int gold_medal_num,
                int silver_medal_num,
                int bronze_medal_num) {
        cout.setf(std::ios::left);
        cout << setw(WIDTH) << national_name << setw(WIDTH) << gold_medal_num
        << setw(WIDTH) << silver_medal_num << setw(WIDTH) << bronze_medal_num << endl;
    }
    
    void printTitle() {
        cout.setf(std::ios::left);
        cout << setw(WIDTH) << "国家" << setw(WIDTH) << "金牌数"
        << setw(WIDTH) << "    银牌数" << setw(WIDTH) << "     铜牌数" << endl;
    }
};


#endif /* medalTableView_h */
