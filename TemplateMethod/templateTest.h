#pragma once
#ifndef _Template_test_H
#define _Template_test_H
#include "airgun.h"
#include "pingpongSingle.h"
void templateTest() {
	std::cout << "***************  以下为Template(模板)设计模式  ***************\n\n";
	MatchDesign* M1 = new Pingpong_single;
	M1->TimeSet("2021/10/19");
	M1->AreaSet("乒乓馆");
	M1->NameSet();
	M1->PlayerSet();
	M1->RuleSet("乒乓球规则");
	M1->ShowInfo();
	cout<<"\n";
	MatchDesign* M2 = new Airgun;
	M2->TimeSet("2021/10/20");
	M2->AreaSet("气枪馆");
	M2->NameSet();
	M2->PlayerSet();
	M2->RuleSet("气枪规则");
	M2->ShowInfo();
	cout<<"\n";
	delete M1;
	delete M2;
	std::cout << "***************  Template(模板)设计模式结束  ***************\n\n";
}
#endif
