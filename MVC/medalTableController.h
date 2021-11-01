//
//  medalTableController.h
//  DesignPatterns
//
//  Created by 吴昊天 on 2021/10/18.
//

#ifndef medalTableController_h
#define medalTableController_h

#include "medalTableView.h"
#include "medalTableModel.h"

// 奖牌榜的控制器（Controller）
class MedalTableController {
private:
    MedalTableModel* model;
    MedalTableView* view;
    
public:
    MedalTableController(MedalTableModel *model, MedalTableView *view) {
        std::cout << "MedalTableController::MedalTableController : 使用Model和View创建控制器（Controller）" << std::endl;
        this->model = model;
        this->view = view;
    }
  
// 获取/设置 各种数据的接口（供外界调用）
// 这些接口都是调用Model的接口来实现的，避免了外界直接和Model通信，而是通过Controller进行的
    
    // 获取国家名称接口
    string getNationalNames(int index) {
        return model->getNationalNames(index);
    }
    
    // 获取金牌数接口
    int getGoldMedalNum(int index) {
        return model->getGoldMedalNum(index);
    }
    
    // 获取银牌数接口
    int getSilverMedalNum(int index) {
        return model->getSilverMedalNum(index);
    }
    
    // 获取铜牌数接口
    int getBronzeMedalNum(int index) {
        return model->getBronzeMedalNum(index);
    }
    
    // 设置金牌数接口
    bool setGoldMedalNum(int index, int num) {
        return model->setGoldMedalNum(index, num);
    }
    
    // 设置银牌数接口
    bool setSilverMedalNum(int index, int num) {
        return model->setSilverMedalNum(index, num);
    }
    
    // 设置铜牌数接口
    bool setBronzeMedalNum(int index, int num) {
        return model->setBronzeMedalNum(index, num);
    }
    
    // 更新视图（将Model显示出来）
    void updateView(){
        std::cout << "MedalTableController::updateView : 通过模型更新视图" << std::endl;
        view->printTitle();
        for(int i = 0; i < model->getTableSize(); i++) {
            view->printMedalTableRol(getNationalNames(i), getGoldMedalNum(i),
                                    getSilverMedalNum(i), getBronzeMedalNum(i));
        }
    }
    
};


#endif /* medalTableController_h */
