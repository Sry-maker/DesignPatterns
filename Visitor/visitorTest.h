#pragma once
#ifndef _Visitor_test_H
#define _Visitor_test_H
#include "grantAuthorizationVisitor.h"
#include "permitVerifyVisitor.h"
#include "permit.h"

void visitorTest() {
    std::cout << "***************  以下为Visitor(访问者)设计模式  ***************\n\n";
	Grant_authorization_Visitor* M1 = new Grant_authorization_Visitor;
	Permit_verify_Visitor* M2 = new Permit_verify_Visitor;
	cout<<"\n";
	Permit* O1 = new Customer_ticket;
	Permit* O2 = new Athlete_pass;
	Permit* O3 = new Referee_evidence;
	cout<<"\n";
	O1->Accept(M1);
	O2->Accept(M1);
	O3->Accept(M1);
	cout<<"\n";
	O1->Accept(M2);
	O2->Accept(M2);
	O3->Accept(M2);
	cout<<"\n";
	delete M1;
	delete M2;
	delete O1;
	delete O2;
	delete O3;
    std::cout << "***************  Visitor(访问者)设计模式结束  ***************\n\n";
};
#endif