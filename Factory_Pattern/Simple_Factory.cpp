#include <iostream>
#include <string>
using namespace std;

/*
	场景：空调专卖店卖各种品牌的空调，如：海尔、格力、美的。
	正常情况来说，应该设计一个专卖店的类，类中有售卖函数，根据传递的品牌制造对应的空调售卖。
	缺点：违反开闭原则。当专卖店不卖某种品牌或者增加某种品牌，就需要修改类中的函数。

	简单工厂模式：
	1.设计抽象空调类，各个品牌的空调都是它的子类。
	2.空调工厂通过传递的品牌来制造不同的空调。


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
	virtual void introduce() override{
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

// 空调品牌枚举类型
enum Brand {
	Haier,
	Gree,
	Midea
};

// 空调工厂
class AirConditionFactory {
public:
	// 根据品牌制造空调
	AirCondition* createAirCondition(Brand brand) {
		AirCondition* airCondition = nullptr;// 指针实现多态
		
		switch (brand)
		{
		case Brand::Gree:
			airCondition = new GreeAirCondition();
			break;
		case Brand::Haier:
			airCondition = new HaierAirCondition();
			break;
		case Brand::Midea:
			airCondition = new MideaAirCondition();
			break;
		default:
			break;
		}

		return airCondition;
	}
};

#if 0
int main() {
	AirConditionFactory factory;
	AirCondition* airCondition = factory.createAirCondition(Brand::Haier);
	airCondition->introduce();
	delete airCondition;
}
#endif