#ifndef interpreter_h
#define interpreter_h
#include<iostream>
#include<map>
#include<cstring>

// interpreter测试函数

class AbstractExpression;
class Variable;
class Sell;
class Buy;
class Context;
//抽象表达式类
class AbstractExpression {
public:
	//抽象表达式类的解释函数，无意义，因为C++不允许抽象父类作为参数，此处不能为纯虚函数
	virtual int interpret(Context*);
	//抽象表达式类的转字符串函数，无意义，因为C++不允许抽象父类作为参数，此处不能为纯虚函数
	virtual std::string toString();
};
//封装变量的类
class Variable :public AbstractExpression {
private:
	//声明清楚变量名的成员变量
	std::string name_;
public:
	//创建变量这一表达式对象
	Variable(std::string);
	//变量对象的解释函数
	int interpret(Context*);
	//变量对象的转字符串函数
	std::string toString();
};
//加法表达式类
class Sell :public AbstractExpression {
private:
	//+号左边的表达式
	AbstractExpression* left_;
	//+号右边的表达式
	AbstractExpression* right_;
public:
	//创建加法这一表达式对象
	Sell(AbstractExpression*, AbstractExpression*);
	//加法的解释函数
	int interpret(Context*);
	//加法的转字符串函数
	std::string toString();
};
//减法表达式类
class Buy :public AbstractExpression {
private:
	//-号左边的表达式
	AbstractExpression* left_;
	//-号右边的表达式
	AbstractExpression* right_;
public:
	//创建减法这一表达式对象
	Buy(AbstractExpression*, AbstractExpression*);
	//减法的解释函数
	int interpret(Context*);
	//减法的转字符串函数
	std::string toString();
};
//环境角色类
class Context {
private:
	//定义一个map集合，用来存储变量及对应的值
	std::map< std::string, int>map_;
public:
	//Context构造函数
	Context();
	//添加变量的功能
	void assign(Variable*, int);
	//得到哈希表map_中存储对应变量的值
	int getValue(Variable*);
};

int AbstractExpression::interpret(Context* context) { return 0; }
std::string AbstractExpression::toString() { return ""; }

Variable::Variable(std::string name) :name_(name) {
	std::cout << "Variable::Variable : 创建 " << name_ << " 的变量对象" << std::endl;
}
int Variable::interpret(Context* context) {
	//直接返回变量的值
	return context->getValue(this);
}
std::string Variable::toString() {
	return name_;
}

Sell::Sell(AbstractExpression* left, AbstractExpression* right) :left_(left), right_(right) {}
int Sell::interpret(Context* context) {
	return left_->interpret(context) + right_->interpret(context);
}
std::string Sell::toString() {
	return  left_->toString() + "出售了" + right_->toString() + ",";
}

Buy::Buy(AbstractExpression* left, AbstractExpression* right) :left_(left), right_(right) {}
int Buy::interpret(Context* context) {
	return left_->interpret(context) - right_->interpret(context);
}
std::string Buy::toString() {
	return  left_->toString() + "购买了" + right_->toString() + ",";
}

Context::Context() {
	std::cout << "Context::Context : 创建环境对象类Context对象" << std::endl;
}
void Context::assign(Variable* var, int value) {
	map_[var->toString()] = value;
	std::cout << "Context::assign : 将变量 " << var->toString() << " 存储到环境对象中，" << "存储值为 " << value << std::endl;
}
int Context::getValue(Variable* var) {
	auto temp = map_.find(var->toString());
	if (temp != map_.end())
		return temp->second;
	else
	{
		std::cout << "Do not Find" << std::endl;
		exit(-1);
		return -1;
	}
	return 1;
}



void interpreterTest() {
	std::cout << "***************  以下为Interpreter(解释器)设计模式  **************************************" << std::endl << std::endl;
	//创建环境对象
	Context* context = new Context();
	std::cout << std::endl;
	//创建多个变量对象
	Variable* init = new Variable("当前的钱");
	Variable* a = new Variable("网球拍");
	Variable* b = new Variable("羽毛球拍");
	Variable* c = new Variable("篮球");
	Variable* d = new Variable("足球");
	std::cout << std::endl;
	//将变量存储到环境对象中
	context->assign(init, 1000);
	context->assign(a, 500);
	context->assign(b, 300);
	context->assign(c, 150);
	context->assign(d, 120);
	std::cout << std::endl;
	//获取抽象语法树  :  当前的钱出售了网球拍,出售了羽毛球拍,购买了篮球,购买了足球,
	AbstractExpression* expression = new Buy(new Buy(new Sell(new Sell(init, a), b), c), d);
	std::cout << "AbstractExpression::toString : 获取抽象语法树: " << expression->toString() << std::endl;
	std::cout << std::endl;
	//解释（计算）
	std::cout << "对抽象语法树进行解释（计算）" << std::endl;
	int result = expression->interpret(context);
	std::cout << expression->toString() << " 之后剩" << result << std::endl;
	std::cout << std::endl << "*************** Interpreter(解释器)设计模式结束  **************************************" << std::endl << std::endl;
}
void interpreter(int num1, int num2, int num3, int num4) {
	std::cout << "***************  以下为Interpreter(解释器)设计模式  **************************************" << std::endl << std::endl;
	//创建环境对象
	Context* context = new Context();
	std::cout << std::endl;
	//创建多个变量对象
	Variable* init = new Variable("当前的钱");
	Variable* a = new Variable("乒乓球拍");
	Variable* b = new Variable("羽毛球拍");
	Variable* c = new Variable("篮球系列");
	Variable* d = new Variable("足球系列");
	std::cout << std::endl;
	//将变量存储到环境对象中
	context->assign(init, 1000);
	context->assign(a, 50);
	context->assign(b, 30);
	context->assign(c, 15);
	context->assign(d, 12);
	std::cout << std::endl;
	//获取抽象语法树  :  当前的钱出售了网球拍,出售了羽毛球拍,购买了篮球,购买了足球,
	AbstractExpression* last = init;
	for (int i = 0; i < num1; i++)
		last = new Buy(last, a);
	for (int i = 0; i < num2; i++)
		last = new Buy(last, b);
	for (int i = 0; i < num3; i++)
		last = new Buy(last, c);
	for (int i = 0; i < num4; i++)
		last = new Buy(last, d);
	std::cout << "AbstractExpression::toString : 获取抽象语法树: " << last->toString() << std::endl;
	std::cout << std::endl;
	//解释（计算）
	std::cout << "对抽象语法树进行解释（计算）" << std::endl;
	int result = last->interpret(context);
	std::cout << last->toString() << " 之后剩" << result << std::endl;
	std::cout << std::endl << "*************** Interpreter(解释器)设计模式结束  **************************************" << std::endl << std::endl;
}



#endif 
