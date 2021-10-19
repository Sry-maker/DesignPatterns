//
//  MVC.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/18.
//

#ifndef MVC_h
#define MVC_h

#include "medalTableView.h"
#include "medalTableModel.h"
#include "medalTableController.h"

// MVC设计模式的测试接口
void MVCTest() {
    
    // 奖牌榜数据
    vector<string> national_names {
        "美国",
        "中国",
        "日本",
        "英国"
    };
    vector<int> gold_medal_num {
        39,
        38,
        27,
        21
    };
    
    vector<int> silver_medal_num {
        41,
        32,
        14,
        21
    };
    
    vector<int> bronze_medal_num {
        33,
        18,
        17,
        22
    };
    
    // 建立模型和视图，并且和控制器关联起来
    MedalTableModel model = MedalTableModel(national_names, gold_medal_num,
                                            silver_medal_num, bronze_medal_num);
    MedalTableView view = MedalTableView();
    MedalTableController controller = MedalTableController(model, view);
    
    // 显示视图
    controller.updateView();
}


#endif /* MVC_h */
