#pragma once
#ifndef _Template_test_H
#define _Template_test_H
#include "Airgun.h"
#include "Pingpong_single.h"
void Template() {
	std::cout << "Template²âÊÔ:\n";
	MatchDesign* M1 = new Pingpong_single;
	M1->TemplateMethod();
	MatchDesign* M2 = new Airgun;
	M2->TemplateMethod();
	delete M1;
	delete M2;
}
#endif
