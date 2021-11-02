#pragma once
#include"classObserver.h"

void observerTest() {
	std::cout << "***************  以下为Observer(观察者)设计模式  **************************************" << std::endl << std::endl;
	//创建MatchObject对象
	PlaceSubject* placesubject = new PlaceSubject("鸟巢");
	//创建观察者对象，进行附着观察
	MatchObserver* matchobserver1 = new MatchObserver(placesubject, new Match("跳高"));
	MatchObserver* matchobserver2 = new MatchObserver(placesubject, new Match("跳远"));
	MatchObserver* matchobserver3 = new MatchObserver(placesubject, new Match("男子100米跑"));
	placesubject->HowManyObserver();
	std::cout << std::endl;
	//MatchObject更新，发出消息给观察者
	placesubject->SetPlace("五棵松篮球馆");
	std::cout << std::endl;
	std::cout << "Now detach the MatchObserver named " << matchobserver1->GetMatchObserverName() << std::endl;
	placesubject->detach(matchobserver1);
	std::cout << std::endl;
	placesubject->HowManyObserver();
	std::cout << std::endl;
	placesubject->SetPlace("水立方");
	std::cout << std::endl;
	std::cout << "Now detach the MatchObserver named " << matchobserver2->GetMatchObserverName() << std::endl;
	placesubject->detach(matchobserver2);
	std::cout << "Now detach the MatchObserver named " << matchobserver3->GetMatchObserverName() << std::endl;
	placesubject->detach(matchobserver3);
	std::cout << std::endl;
	placesubject->HowManyObserver();
	std::cout << std::endl << "***************  Observer(观察者)设计模式结束  **************************************" << std::endl << std::endl;
}


MatchObserver* AttachMatch(PlaceSubject* placesubject, std::vector<Match*>matchvector, std::string place) {
	std::cout << "\n------请输入您要添加的比赛名称:----------\n";
	std::string match;
	std::cin >> match;
	int i = 0;
	for (; i < matchvector.size(); i++)
		if (matchvector[i]->GetName() == match)
		{
			break;
		}
	MatchObserver* matchobserver = new MatchObserver(placesubject, matchvector[i]);
	return matchobserver;
}
void DetachMatch(PlaceSubject* placesubject, std::vector<Match*>matchvector, std::list<MatchObserver*> observers) {
	std::cout << "\n------请输入您要删除的比赛名称:----------\n";
	std::string match;
	std::cin >> match;
	for (auto temp = observers.begin(); temp != observers.end(); temp++)
	{
		if ((*temp)->GetMatchObserverName() == match)
		{
			std::cout << "Now detach the MatchObserver named " << (*temp)->GetMatchObserverName() << std::endl;
			placesubject->detach(*temp);
			observers.remove(*temp);
			break;
		}
	}
}
void ChangePlace(PlaceSubject* placesubject, std::vector<Match*>matchvector) {
	std::cout << "\n------请输入您要修改成的地点:----------\n";
	std::string place;
	std::cin >> place;
	placesubject->SetPlace(place);
}

void observer(std::vector<Match*>matchvector) {
	std::cout << "***************  以下为Observer(观察者)设计模式  **************************************" << std::endl << std::endl;
	std::list<MatchObserver*> observers;
	std::cout << "请输入需要管理的比赛场地\n";
	std::string place;
	std::cin >> place;
	//创建MatchObject对象
	PlaceSubject* placesubject = new PlaceSubject(place);
	//创建观察者对象，进行附着观察
	while (1) {
		std::cout << "\n------请输入您想要进行的操作:----------\n";
		std::cout << "1.添加在这个场地进行的比赛\n";
		std::cout << "2.删除在这个场地进行的比赛\n";
		std::cout << "3.修改比赛场地\n";
		std::cout << "0.返回\n";
		int type;
		std::cout << "input:";
		std::cin >> type;
		switch (type)
		{
		case 1:
			//添加在这个场地进行的比赛
			observers.push_back(AttachMatch(placesubject, matchvector, place));
			break;
		case 2:
			//删除在这个场地进行的比赛
			DetachMatch(placesubject, matchvector, observers);
			break;
		case 3:
			//修改比赛场地
			ChangePlace(placesubject, matchvector);
			break;
		case 0:
			//管理体育项目场地
			return;
		}
	}
	std::cout << std::endl << "***************  memento(备忘率)设计模式结束  **************************************" << std::endl << std::endl;
}


