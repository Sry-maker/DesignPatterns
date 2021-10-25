#include"interpreter.h"

void interpreterTest() {
	cout << "***************  以下为Interpreter(解释器)设计模式  **************************************" << endl << endl;
	//创建环境对象
	Context* context = new Context();
	cout << endl;
	//创建多个变量对象
	Variable* init = new Variable("当前的钱");
	Variable* a = new Variable("网球拍");
	Variable* b = new Variable("羽毛球拍");
	Variable* c = new Variable("篮球");
	Variable* d = new Variable("足球");
	cout << endl;
	//将变量存储到环境对象中
	context->assign(init, 1000);
	context->assign(a, 500);
	context->assign(b, 300);
	context->assign(c, 150);
	context->assign(d, 120);
	cout << endl;
	//获取抽象语法树  :  当前的钱出售了网球拍,出售了羽毛球拍,购买了篮球,购买了足球,
	AbstractExpression* expression = new Buy(new Buy(new Sell(new Sell(init, a), b), c), d);
	cout << "AbstractExpression::toString : 获取抽象语法树: " << expression->toString() << endl;
	cout << endl;
	//解释（计算）
	cout << "对抽象语法树进行解释（计算）" << endl;
	int result = expression->interpret(context);
	cout << expression->toString() << " 之后剩" << result<<endl;
	cout << endl << "*************** Interpreter(解释器)设计模式结束  **************************************" << endl << endl;
}

int AbstractExpression::interpret(Context* context) { return 0; }
string AbstractExpression::toString() { return ""; }

Variable::Variable(string name) :name_(name) {
	cout << "Variable::Variable : 创建 " << name_ << " 的变量对象"<<endl;
}
int Variable::interpret(Context* context) {
	//直接返回变量的值
	return context->getValue(this);
}
string Variable::toString() {
	return name_;
}

Sell::Sell(AbstractExpression* left, AbstractExpression* right) :left_(left), right_(right) {}
int Sell::interpret(Context* context) {
	return left_->interpret(context) + right_->interpret(context);
}
string Sell::toString() {
	return  left_->toString() + "出售了" + right_->toString() +",";
}

Buy::Buy(AbstractExpression* left, AbstractExpression* right) :left_(left), right_(right) {}
int Buy::interpret(Context* context) {
	return left_->interpret(context) - right_->interpret(context);
}
string Buy::toString() {
	return  left_->toString() + "购买了" + right_->toString()+",";
}

Context::Context() {
	cout << "Context::Context : 创建环境对象类Context对象"<<endl;
}
void Context::assign(Variable* var, int value) {
	map_[var->toString()] = value;
	cout << "Context::assign : 将变量 " << var->toString() << " 存储到环境对象中，" << "存储值为 " << value << endl;
}
int Context::getValue(Variable* var) {
	auto temp = map_.find(var->toString());
	if (temp != map_.end())
		return temp->second;
	else
	{
		cout << "Do not Find" << endl;
		exit(-1);
		return -1;
	}
	return 1;
}
