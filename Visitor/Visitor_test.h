#pragma once
#ifndef _Visitor_test_H
#define _Visitor_test_H
#include "Grant_authorization_Visitor.h"
#include "Permit_verify_Visitor.h"
#include "Permit.h"

void Visitor() {

	Grant_authorization_Visitor* M1 = new Grant_authorization_Visitor;
	Permit_verify_Visitor* M2 = new Permit_verify_Visitor;
	Permit* O1 = new Customer_ticket;
	Permit* O2 = new Athlete_pass;
	Permit* O3 = new Referee_evidence;
	O1->Accept(M1);
	O2->Accept(M1);
	O3->Accept(M1);
	O1->Accept(M2);
	O2->Accept(M2);
	O3->Accept(M2);
	delete M1;
	delete M2;
	delete O1;
	delete O2;
	delete O3;

};
#endif