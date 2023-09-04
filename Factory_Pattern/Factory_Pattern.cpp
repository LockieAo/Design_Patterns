#include <iostream>
#include <string>
using namespace std;

/*
	场景：空调专卖店卖各种品牌的空调，如：海尔、格力、美的。
	简单工厂模式缺点：工厂类违反开闭原则，当空调品牌变更，工厂类也要修改。

	工厂模式：
	1.设计空调抽象类，所有品牌的空调都是该类的子类。
	2.设计工厂抽象类，所有品牌的空调工厂都是该类的子类。
	3.要生产某种品牌的空调，只需要创建该工厂类的对象，让该类对象生产空调即可。
	4.如果要增加或者删除空调品牌，只需要增加或者删除空调类和空调工厂类即可。

*/

// 抽象空调类
class AirCondition {
public:
	virtual void introduce() = 0;
	virtual ~AirCondition() {}
};

// 海尔空调类
class HaierAirCondition : public AirCondition {
public:
	virtual void introduce() override {
		cout << "海尔空调" << endl;
	}
};

// 格力空调类
class GreeAirCondition : public AirCondition {
public:
	virtual void introduce() override {
		cout << "格力空调" << endl;
	}
};

// 美的空调类
class MideaAirCondition : public AirCondition {
public:
	virtual void introduce() override {
		cout << "美的空调" << endl;
	}
};

// 抽象工厂类
class AirConditionFactory {
public:
	virtual AirCondition* createAirCondition() = 0;
	virtual ~AirConditionFactory(){}
};

// 海尔空调工厂类
class HaierAirConditionFactory : public AirConditionFactory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new HaierAirCondition();
		cout << "海尔空调制造完毕" << endl;
		return airCondition;
	}
};

// 格力空调工厂类
class GreeAirConditionFactory : public AirConditionFactory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new GreeAirCondition();
		cout << "格力空调制造完毕" << endl;
		return airCondition;
	}
};

// 美的空调工厂类
class MideaAirConditionFactory : public AirConditionFactory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new MideaAirCondition();
		cout << "美的空调制造完毕" << endl;
		return airCondition;
	}
};

#if 0

int main() {
	AirConditionFactory* factory = new MideaAirConditionFactory;
	AirCondition* airCondition = factory->createAirCondition();
	airCondition->introduce();
	delete factory;
	delete airCondition;

}

#endif