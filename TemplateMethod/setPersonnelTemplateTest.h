#pragma once
#ifndef _Template_test_H
#define _Template_test_H
#include "worker.h"
#include "customer.h"
#include "athlete.h"
worker Worker1;
customer Customer1;
athlete Athlete1;
void setPersonnel(int tp) {
	std::cout << "***************  以下为Template(模板)设计模式  ***************\n\n";
	if(tp == 1)
	{
		Athlete1.IDSet("0001");
		Athlete1.nameSet("马小龙");
		Athlete1.genderSet("男");
		Athlete1.countrySet("中国");
		Athlete1.ShowInfo();
	}
	if(tp == 2)
	{
		Worker1.IDSet("1001");
		Worker1.nameSet("陈小洁");
		Worker1.genderSet("女");
		Worker1.typeSet("赛事管理员");
		Worker1.ShowInfo();
	}
	if(tp == 3)
	{
		Customer1.IDSet("2001");
		Customer1.nameSet("王小咩");
		Customer1.genderSet("男");
		Customer1.typeSet("男单乒乓VIP票");
		Customer1.ShowInfo();
	}
	std::cout << "***************  Template(模板)设计模式结束  ***************\n\n";
}
#endif
