#pragma once
#ifndef _grantVisitorTest_H
#define _grantVisitorTest_H
#include "grantAuthorizationVisitor.h"


void grantVisitorTest(int tp) {
    std::cout << "***************  以下为Visitor(访问者)设计模式  ***************\n\n";
	Grant_authorization_Visitor* grantAuthorizationVisitor = new Grant_authorization_Visitor;
	Permit* permit=NULL;
	switch (tp)
	{
	case 1:
		permit = new Athlete_pass;
		break;
	case 2:
		permit = new Referee_evidence;
		break;
	case 3:
		permit = new Customer_ticket;
		break;
	default:
		break;
	}
    permit->Accept(grantAuthorizationVisitor);
    delete grantAuthorizationVisitor;
    delete permit;
    std::cout << "\n***************  Visitor(访问者)设计模式结束  ***************\n\n";
};
#endif