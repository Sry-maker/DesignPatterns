#pragma once
#include"classMemento.h"

void Enroll(EventOriginator* eventoriginator, Caretaker* caretaker, athlete* athlete) {
    if (athlete->getMatch() != "")
    {
        std::cout << "您已报名了项目,无法再进行报名." << std::endl;
        return;
    }
    std::cout << "\n请输入您要报名的项目：" << std::endl;
    std::string temp_event;
    std::cin >> temp_event;
    eventoriginator->ChangeEvent(temp_event);
    caretaker->Backup();
}
void ChangeEvent(EventOriginator* eventoriginator, Caretaker* caretaker, athlete* athlete) {
    if (athlete->getMatch() == "")
    {
        std::cout << "请先报名项目" << std::endl;
        return;
    }
    std::cout << "\n请输入要修改成的项目：" << std::endl;
    std::string temp_event;
    std::cin >> temp_event;
    eventoriginator->ChangeEvent(temp_event);
    caretaker->Backup();
}
void Undo(EventOriginator* eventoriginator, Caretaker* caretaker, athlete* athlete) {
    caretaker->ShowHistory();
    caretaker->Undo();
}

void memento(athlete* athlete) {
    std::cout << "***************  以下为memento(备忘率)设计模式  **************************************" << std::endl << std::endl;
    EventOriginator* eventoriginator = new EventOriginator(athlete);
    Caretaker* caretaker = new Caretaker(eventoriginator);
    while (1) {
        std::cout << "********************请选择您要进行的操作*****************************" << std::endl << std::endl;
        std::cout << "1.报名运动项目\n";
        std::cout << "2.修改运动项目\n";
        std::cout << "3.反悔操作（回到上一个运动项目）\n";
        std::cout << "0.返回\n";
        int type;
        std::cout << "input:";
        std::cin >> type;
        switch (type)
        {
        case 1:
            Enroll(eventoriginator, caretaker, athlete);
            break;
        case 2:
            ChangeEvent(eventoriginator, caretaker, athlete);
            break;
        case 3:
            Undo(eventoriginator, caretaker, athlete);
            break;
        default:
            break;
        }
        if (type == 0)
            break;
    }
    std::cout << std::endl << "***************  memento(备忘率)设计模式结束  **************************************" << std::endl << std::endl;
    return;
}


void mementoTest() {
    std::cout << "***************  以下为memento(备忘率)设计模式  **************************************" << std::endl << std::endl;
    EventOriginator* eventoriginator = new EventOriginator(new athlete("001", "张三", "中国"));
    Caretaker* caretaker = new Caretaker(eventoriginator);
    caretaker->Backup();
    eventoriginator->ChangeEvent("跳远");
    caretaker->Backup();
    eventoriginator->ChangeEvent("男子100米跑");
    caretaker->Backup();
    eventoriginator->ChangeEvent("男子200米跑");
    std::cout << "\n";
    caretaker->ShowHistory();
    std::cout << "\nNow, let's rollback!\n\n";
    caretaker->Undo();
    std::cout << "\n\nOnce more!\n\n";
    caretaker->Undo();
    std::cout << "\n\n";
    caretaker->ShowHistory();

    delete eventoriginator;
    delete caretaker;
    std::cout << std::endl << "***************  memento(备忘率)设计模式结束  **************************************" << std::endl << std::endl;
}
