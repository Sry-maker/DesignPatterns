#pragma once
#include<iostream>
#include"Callback.h"

int callBackTest() {
	
	std:: cout << "****************以下为Callback（回调）设计模式****************:\n";
	IOC IOC;
	IOC.readReport();
	std:: cout << "****************Callback（回调）设计模式结束****************:\n";
	return 0;
}
