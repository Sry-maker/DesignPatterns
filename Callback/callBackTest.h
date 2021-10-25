
#include<iostream>
#include"Callback.h"
using namespace::std;

int callBackTest() {
	
	cout << "****************以下为Callback（回调）设计模式****************:\n";
	IOC IOC;
	IOC.readReport();
	cout << "****************Callback（回调）设计模式结束****************:\n";
	return 0;
}
