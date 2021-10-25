#include<iostream>
#include<map>
#include<cstring>
using namespace std;

// interpreter测试函数
void interpreterTest();

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
	virtual string toString();
};
//封装变量的类
class Variable :public AbstractExpression {
private:
	//声明清楚变量名的成员变量
	string name_;
public:
	//创建变量这一表达式对象
	Variable(string);
	//变量对象的解释函数
	int interpret(Context* );
	//变量对象的转字符串函数
	string toString();
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
	Sell(AbstractExpression*,AbstractExpression* );
	//加法的解释函数
	int interpret(Context*);
	//加法的转字符串函数
	string toString();
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
	string toString();
};
//环境角色类
class Context {
private:
	//定义一个map集合，用来存储变量及对应的值
	map<string, int>map_;
public:
	//Context构造函数
	Context();
	//添加变量的功能
	void assign(Variable*, int);
	//得到哈希表map_中存储对应变量的值
	int getValue(Variable*);
};
