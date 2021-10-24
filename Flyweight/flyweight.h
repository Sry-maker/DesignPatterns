#pragma once
#include <iostream>
#include < unordered_map >

using namespace std;


/***************************************************************************
  类  名称：athleteSharedState
  功    能：存储运动员的共享数据
  说    明：运动员数据中国际和运动类型应该共享以减少存储空间
***************************************************************************/
struct athleteSharedState
{
	std::string nationality_;
	std::string type_;
	//...
	athleteSharedState(const std::string& nationality, const std::string& type)
		: nationality_(nationality), type_(type)
	{
	}

	friend std::ostream& operator<<(std::ostream& os, const athleteSharedState& ss)
	{
		return os << "[ " << ss.nationality_ << " , " << ss.type_ << " ]";
	}
};
/***************************************************************************
  类  名称：athleteUniqueState
  功    能：存储运动员的特有数据
  说    明：这是每个运动员数据中无法共享的数据，只能单独存储
***************************************************************************/
struct athleteUniqueState
{
	std::string name_;
	std::string number_;
	//...
	athleteUniqueState(const std::string& name, const std::string& number)
		: name_(name), number_(number)
	{
	}

	friend std::ostream& operator<<(std::ostream& os, const athleteUniqueState& us)
	{
		return os << "[ " << us.name_ << " , " << us.number_ << " ]";
	}
};

/***************************************************************************
  类  名称：Flyweight
  功    能：存储各个不同的运动员的共享数据
  说    明：这是所有运动员共享数据的集合，如果某个新添加运动员的共享数据在Flyweight里已存在，则直接利用
            display 展示一个运动员的数据
***************************************************************************/
class Flyweight
{
private:
	athleteSharedState* shared_state_;

public:
	Flyweight(const athleteSharedState* shared_state) : shared_state_(new athleteSharedState(*shared_state))
	{
	}
	Flyweight(const Flyweight& other) : shared_state_(new athleteSharedState(*other.shared_state_))
	{
	}
	~Flyweight()
	{
		delete shared_state_;
	}
	athleteSharedState* shared_state() const
	{
		return shared_state_;
	}
	void display(const athleteUniqueState& unique_state) const
	{
		std::cout << "Flyweight::display: 展示共享数据 (" << *shared_state_ << ") 私有数据 (" << unique_state << ")\n";
	}
};
/***************************************************************************
  类  名称：FlyweightFactory
  功    能：通过FlyweightFactory来利用Flyweight
  说    明：GetFlyweight 如果某个新添加运动员的共享数据在Flyweight里已存在，则直接利用。否则新建一个新的Flyweight
            ListFlyweights 展示所有已有的Flyweight
  ***************************************************************************/
class FlyweightFactory
{

private:
	std::unordered_map<std::string, Flyweight> flyweights_;

	std::string GetKey(const athleteSharedState& ss) const
	{
		return ss.nationality_ + "_" + ss.type_;
	}

public:
	FlyweightFactory(std::initializer_list<athleteSharedState> share_states)
	{
		for (const athleteSharedState& ss : share_states)
		{
			this->flyweights_.insert(std::make_pair<std::string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
		}
	}

	
	Flyweight GetFlyweight(const athleteSharedState& shared_state)
	{
		std::string key = this->GetKey(shared_state);
		if (this->flyweights_.find(key) == this->flyweights_.end())
		{
			std::cout << "FlyweightFactory::GetFlyweight: 找不到 flyweight建一个新的.\n";
			this->flyweights_.insert(std::make_pair(key, Flyweight(&shared_state)));
		}
		else
		{
			std::cout << "FlyweightFactory::GetFlyweight: 重复利用已经有的 flyweight.\n";
		}
		return this->flyweights_.at(key);
	}
	void ListFlyweights() const
	{
		size_t count = this->flyweights_.size();
		std::cout << "\nFlyweightFactory::ListFlyweights: 共有 " << count << " 个flyweight：\n";
		for (std::pair<std::string, Flyweight> pair : this->flyweights_)
		{
			std::cout << pair.first << "\n";
		}
	}
};

// ...
void AddAthleteToPoliceDatabase(
	FlyweightFactory& ff, const std::string& name, const std::string& number,
	const std::string& nationality, const std::string& type)
{
	
	std::cout << "添加一个运动员到数据库.\n";
	const Flyweight& flyweight = ff.GetFlyweight({ nationality, type });
	flyweight.display({ name, number });
}
int flyweightTest() {
	std::cout << "*************** flyweight模式展示:*************************************";
	FlyweightFactory* factory = new FlyweightFactory({ {"游泳", "中国"}, {"击剑", "中国"}, {"游泳", "美国"}, {"击剑", "美国"} });
	factory->ListFlyweights();

	AddAthleteToPoliceDatabase(*factory,
		"张三",
		"30256",
		"游泳",
		"中国");

	AddAthleteToPoliceDatabase(*factory,
		"詹姆斯",
		"33654",
		"击剑",
		"法国");
	factory->ListFlyweights();
	delete factory;


	return 0;
}

