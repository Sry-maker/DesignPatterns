#pragma once
#include<iostream>
#include<queue>
#include"Cmd.h"

//设计模式测试代码
void commandTest()
{
	std::cout << "****************  以下为Command（命令）设计模式  ******************" << std::endl;
	Invoker* invoker=new Invoker;
	VipPassage vip_passage;
	NormalPassage normal_passage;
	SpecialPassage special_passage;
	Command* cmd1 = new EnterCommand<VipPassage>(&vip_passage,&VipPassage::EnterVipPassage);
	Command* cmd2 = new EnterCommand<NormalPassage>(&normal_passage, &NormalPassage::EnterNormalPassage);
	Command* cmd3 = new EnterCommand<SpecialPassage>(&special_passage, &SpecialPassage::EnterSpecialPassage);
	invoker->commands.push(cmd1);
	invoker->commands.push(cmd2);
	invoker->commands.push(cmd3);
	invoker->Enter();
	delete invoker;
	delete cmd1;
	delete cmd2;
	delete cmd3;
	std::cout << "****************  Command（命令）设计模式结束  ******************" << std::endl;
}
