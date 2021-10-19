#pragma once
#include <iostream>
#include < unordered_map >

using namespace std;
struct SharedState
{
	std::string nationality_;
	std::string type_;
	//...
	SharedState(const std::string& nationality, const std::string& type)
		: nationality_(nationality), type_(type)
	{
	}

	friend std::ostream& operator<<(std::ostream& os, const SharedState& ss)
	{
		return os << "[ " << ss.nationality_ << " , " << ss.type_ << " ]";
	}
};

struct UniqueState
{
	std::string name_;
	std::string number_;
	//...
	UniqueState(const std::string& name, const std::string& number)
		: name_(name), number_(number)
	{
	}

	friend std::ostream& operator<<(std::ostream& os, const UniqueState& us)
	{
		return os << "[ " << us.name_ << " , " << us.number_ << " ]";
	}
};


class Flyweight
{
private:
	SharedState* shared_state_;

public:
	Flyweight(const SharedState* shared_state) : shared_state_(new SharedState(*shared_state))
	{
	}
	Flyweight(const Flyweight& other) : shared_state_(new SharedState(*other.shared_state_))
	{
	}
	~Flyweight()
	{
		delete shared_state_;
	}
	SharedState* shared_state() const
	{
		return shared_state_;
	}
	void Operation(const UniqueState& unique_state) const
	{
		std::cout << "Flyweight: 展示共享数据 (" << *shared_state_ << ") 私有数据 (" << unique_state << ")\n";
	}
};

class FlyweightFactory
{

private:
	std::unordered_map<std::string, Flyweight> flyweights_;

	std::string GetKey(const SharedState& ss) const
	{
		return ss.nationality_ + "_" + ss.type_;
	}

public:
	FlyweightFactory(std::initializer_list<SharedState> share_states)
	{
		for (const SharedState& ss : share_states)
		{
			this->flyweights_.insert(std::make_pair<std::string, Flyweight>(this->GetKey(ss), Flyweight(&ss)));
		}
	}

	/**
	 * Returns an existing Flyweight with a given state or creates a new one.
	 */
	Flyweight GetFlyweight(const SharedState& shared_state)
	{
		std::string key = this->GetKey(shared_state);
		if (this->flyweights_.find(key) == this->flyweights_.end())
		{
			std::cout << "FlyweightFactory: 找不到 flyweight建一个新的.\n";
			this->flyweights_.insert(std::make_pair(key, Flyweight(&shared_state)));
		}
		else
		{
			std::cout << "FlyweightFactory: 重复利用已经有的 flyweight.\n";
		}
		return this->flyweights_.at(key);
	}
	void ListFlyweights() const
	{
		size_t count = this->flyweights_.size();
		std::cout << "\nFlyweightFactory: 共有 " << count << " 个flyweight：\n";
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
	std::cout << "\n添加一个运动员到数据库.\n";
	const Flyweight& flyweight = ff.GetFlyweight({ nationality, type });
	flyweight.Operation({ name, number });
}
int flyweightTest() {

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
		"美国");
	factory->ListFlyweights();
	delete factory;


	return 0;
}

