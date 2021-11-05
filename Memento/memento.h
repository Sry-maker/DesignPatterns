#pragma once
#include"classMemento.h"
#include"../NullObject/NullObject.h"
#include"../Match.h"
void Enroll(MatchOriginator* matchoriginator, Caretaker* caretaker, athlete* athlete,vector<Match*>matchvector) {
    if (athlete->getMatch() != "")
    {
        std::cout << "您已报名了项目,无法再进行报名." << std::endl;
        return;
    }
    std::string temp_match;
    while (1)
    {
        std::cout << "\n请输入您要报名的项目：" << std::endl;
        std::cin >> temp_match;
        bool flag = false;
        for (int i = 0; i < matchvector.size(); i++)
            if (matchvector[i]->GetName() == temp_match)
            {
                flag = true;
                break;
            }
        if(flag==false)
        {
            nullObjectTest(temp_match);
            continue;
        }
        break;
    }
    matchoriginator->ChangeMatch(temp_match);
    caretaker->Backup();
}
void ChangeMatch(MatchOriginator* matchoriginator, Caretaker* caretaker, athlete* athlete, vector<Match*>matchvector) {
    if (athlete->getMatch() == "")
    {
        std::cout << "请先报名项目" << std::endl;
        return;
    }
    std::string temp_match;
    while (1)
    {
        std::cout << "\n请输入您要报名的项目：" << std::endl;
        std::cin >> temp_match;
        bool flag = false;
        for (int i = 0; i < matchvector.size(); i++)
            if (matchvector[i]->GetName() == temp_match)
            {
                flag = true;
                break;
            }
        if (flag == false)
        {
            nullObjectTest(temp_match);
            continue;
        }
        break;
    }
    matchoriginator->ChangeMatch(temp_match);
    caretaker->Backup();
}
void Undo(MatchOriginator* matchoriginator, Caretaker* caretaker, athlete* athlete) {
    caretaker->ShowHistory();
    caretaker->Undo();
}

void memento(athlete* athlete,vector<Match*>matchvector) {
    std::cout << "***************  以下为memento(备忘率)设计模式  **************************************" << std::endl << std::endl;
    MatchOriginator* matchoriginator = new MatchOriginator(athlete);
    Caretaker* caretaker = new Caretaker(matchoriginator);
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
            Enroll(matchoriginator, caretaker, athlete, matchvector);
            break;
        case 2:
            ChangeMatch(matchoriginator, caretaker, athlete, matchvector);
            break;
        case 3:
            Undo(matchoriginator, caretaker, athlete);
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
    MatchOriginator* matchoriginator = new MatchOriginator(new athlete("001", "张三", "中国"));
    Caretaker* caretaker = new Caretaker(matchoriginator);
    caretaker->Backup();
    matchoriginator->ChangeMatch("跳远");
    caretaker->Backup();
    matchoriginator->ChangeMatch("男子100米跑");
    caretaker->Backup();
    matchoriginator->ChangeMatch("男子200米跑");
    std::cout << "\n";
    caretaker->ShowHistory();
    std::cout << "\nNow, let's rollback!\n\n";
    caretaker->Undo();
    std::cout << "\n\nOnce more!\n\n";
    caretaker->Undo();
    std::cout << "\n\n";
    caretaker->ShowHistory();

    delete matchoriginator;
    delete caretaker;
    std::cout << std::endl << "***************  memento(备忘率)设计模式结束  **************************************" << std::endl << std::endl;
}
