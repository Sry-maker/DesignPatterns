#pragma once
#ifndef _Template_test_H
#define _Template_test_H
#include "airgun.h"
#include "pingpongSingle.h"
void templateTest() {
	std::cout << "Template测试:\n";
	MatchDesign* M1 = new Pingpong_single;
	M1->TemplateMethod();
	MatchDesign* M2 = new Airgun;
	M2->TemplateMethod();
	delete M1;
	delete M2;
}
#endif
