﻿#pragma once
#include<iostream>
#include<queue>
#include"Cmd.h"


void commandTest()
{
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
}