#pragma once
#include <iostream>
/***************************************************************************
  类  名称：Handle
  功    能：处理请求的基类
  说    明：
***************************************************************************/
class Handle {
public:
	virtual void Request() const = 0;
};
/***************************************************************************
  类  名称：RealHandle
  功    能：继承了处理请求的基类，真正处理请求的类
  说    明：
***************************************************************************/
class RealHandle : public Handle {
public:
	void Request() const override {
		std::cout << "RealHandle::Request: 处理运动员请求.\n";
	}
};
/***************************************************************************
  类  名称：Proxy
  功    能：利用proxy来处理来自运动员的请求
  说    明：CheckAccess在发出真实请求之前检查访问权限
            LogAccess记录请求时间
***************************************************************************/
class Proxy : public Handle {
	
private:
	RealHandle* real_handle_;

	bool CheckAccess() const {
	
		std::cout << "Proxy::CheckAccess: 在发出真实请求之前检查访问权限\n";
		return true;
	}
	void LogAccess() const {
		std::cout << "Proxy::LogAccess: 记录请求时间\n";
	}

	
public:
	Proxy(RealHandle* real_handle) : real_handle_(new RealHandle(*real_handle)) {
	}

	~Proxy() {
		delete real_handle_;
	}
	
	void Request() const override {
		if (this->CheckAccess()) {
			this->real_handle_->Request();
			this->LogAccess();
		}
	}
};

void Client(const Handle& handle) {
	// ...
	handle.Request();
	// ...
}

int proxyTest() {
	std::cout << "*************** proxy模式展示:*************************************\n";
	std::cout << "直接处理客户端请求:\n";
	RealHandle* real_handle = new RealHandle;
	Client(*real_handle);
	std::cout << "\n";
	std::cout << "通过proxy处理请求:\n";
	Proxy* proxy = new Proxy(real_handle);
	Client(*proxy);

	delete real_handle;
	delete proxy;

	return 0;
}