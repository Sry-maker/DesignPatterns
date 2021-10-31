#include "builder.h"
#include "interpreter.h"
#include "AbstractFactory/abstractFactory.h"



void Buysouvenirtest()
{
	int chose;
	int chose1 = 0;
	int chose2 = 0;
	int chose3 = 0;
	int chose4 = 0;
	std::cout << "纪念品列表：" << std::endl;
	std::cout << "1.乒乓球拍纪念品" << std::endl; 
	std::cout << "2.羽毛球拍纪念品" << std::endl;
	std::cout << "3.篮球系列纪念品" << std::endl;
	std::cout << "4.足球系列纪念品" << std::endl;
	std::cout << "0.退出纪念品预定" << std::endl;
	std::cout << "请选择需要预定的纪念品" << std::endl;
	for (;;) {
		std::cin >> chose;
		std::cout << std::endl;
		if (chose == 0) {
			break;
		}
		switch (chose)
		{
		case 1:
			chose1++;
			buTest(chose);
			break;
		case 2:
			chose2++;
			buTest(chose);
			break;
		case 3:
			chose3++;
			abstractFactoryTest1();
			
			break;
		case 4:
			chose4++;
			
			abstractFactoryTest2();
			break;
		default:
			break;
		}
	}
	interpreter(chose1, chose2, chose3, chose4);
}

int main() {
	Buysouvenirtest();
	return 0;
}
