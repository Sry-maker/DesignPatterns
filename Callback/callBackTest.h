#pragma once
#include<iostream>
#include"Callback.h"

int callBackTest() {
	
	std:: cout << "****************����ΪCallback���ص������ģʽ****************:\n";
	IOC IOC;
	IOC.readReport();
	std:: cout << "****************Callback���ص������ģʽ����****************:\n";
	return 0;
}
