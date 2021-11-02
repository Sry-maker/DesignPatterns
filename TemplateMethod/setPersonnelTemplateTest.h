#pragma once
#ifndef _setPersonnelTemplateTest_H
#define _setPersonnelTemplateTest_H
#include "worker.h"
#include "customer.h"
#include "athlete.h"
worker* Worker1;
customer* Customer1;
athlete* Athlete1;
void setPersonnel(int tp, personnel* person) {
	std::cout << "**************  以下为Template(模板)设计模式  ***************\n\n";
	if (tp == 1)
	{
		(*(athlete*)person).IDSet("0001");
		(*(athlete*)person).nameSet("马小龙");
		(*(athlete*)person).genderSet("男");
		(*(athlete*)person).countrySet("中国");
		(*(athlete*)person).ShowInfo();
	}
	if (tp == 2)
	{
		(*(worker*)person).IDSet("1001");
		(*(worker*)person).nameSet("陈小洁");
		(*(worker*)person).genderSet("女");
		(*(worker*)person).typeSet("赛事管理员");
		(*(worker*)person).ShowInfo();
	}
	if (tp == 3)
	{
		(*(customer*)person).IDSet("2001");
		(*(customer*)person).nameSet("王小咩");
		(*(customer*)person).genderSet("男");
		(*(customer*)person).typeSet("男单乒乓VIP票");
		(*(customer*)person).ShowInfo();
	}
	std::cout << "***************  Template(模板)设计模式结束  ***************\n\n";
}
#endif
