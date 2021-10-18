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

class MedalTableController {
private:
    MedalTableModel model;
    MedalTableView view;
    
public:
    MedalTableController(MedalTableModel model, MedalTableView view) {
        this->model = model;
        this->view = view;
    }
    
    string getNationalNames(int index) {
        return model.getNationalNames(index);
    }
    
    int getGoldMedalNum(int index) {
        return model.getGoldMedalNum(index);
    }
    
    int getSilverMedalNum(int index) {
        return model.getSilverMedalNum(index);
    }
    
    int getBronzeMedalNum(int index) {
        return model.getBronzeMedalNum(index);
    }
    
    bool setGoldMedalNum(int index, int num) {
        return model.setGoldMedalNum(index, num);
    }
    
    bool setSilverMedalNum(int index, int num) {
        return model.setSilverMedalNum(index, num);
    }
    
    bool setBronzeMedalNum(int index, int num) {
        return model.setBronzeMedalNum(index, num);
    }
    
    void updateView(){
        view.printTitle();
        for(int i = 0; i < model.getTableSize(); i++) {
            view.printMedalTableRol(getNationalNames(i), getGoldMedalNum(i),
                                    getSilverMedalNum(i), getBronzeMedalNum(i));
        }
    }
    
};


#endif /* medalTableController_h */
