#pragma once
#ifndef _Template_test_H
#define _Template_test_H
#include "airgun.h"
#include "pingpongSingle.h"
void templateTest() {
	std::cout << "Template测试:\n";
	MatchDesign* M1 = new Pingpong_single;
	M1->TimeSet("2021/10/19");
	M1->AreaSet("乒乓馆");
	M1->NameSet();
	M1->PlayerSet();
	M1->RuleSet("乒乓球规则");
	M1->ShowInfo();
	MatchDesign* M2 = new Airgun;
	M2->TimeSet("2021/10/20");
	M2->AreaSet("气枪馆");
	M2->NameSet();
	M2->PlayerSet();
	M2->RuleSet("气枪规则");
	M2->ShowInfo();
	delete M1;
	delete M2;
}
#endif
