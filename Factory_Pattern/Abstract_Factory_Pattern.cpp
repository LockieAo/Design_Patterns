#include <iostream>
#include <string>
using namespace std;

/*
	情景：海尔、格力、美的，不止造空调、还有电视机、.....
	简单工厂模式和工厂模式只适用于单个产品，不适合创建产品族。

	抽象工厂模式：
	1.对每种产品都定义抽象类，各个品牌的该产品都是该类的子类
	2.定义抽象工厂，各个产品的工厂都是该类的子类，具体工厂类中可以创建该品牌产品族的产品

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

// 抽象电视类
class TV {
public:
	virtual void introduce() = 0;
	virtual ~TV() {}
};

// 海尔电视类
class HaierTV : public TV {
public:
	virtual void introduce() override {
		cout << "海尔电视" << endl;
	}
};

// 格力电视类
class GreeTV : public TV {
public:
	virtual void introduce() override {
		cout << "格力电视" << endl;
	}
};

// 美的电视类
class MideaTV : public TV {
public:
	virtual void introduce() override {
		cout << "美的电视" << endl;
	}
};



// 抽象工厂类
class Factory {
public:
	virtual AirCondition* createAirCondition() = 0;
	virtual TV* createTV() = 0;
	virtual ~Factory() {}
};

// 海尔工厂类
class HaierFactory : public Factory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new HaierAirCondition();
		cout << "海尔空调制造完毕" << endl;
		return airCondition;
	}

	virtual TV* createTV() override {
		TV* tv = new HaierTV();
		cout << "海尔电视制造完毕" << endl;
		return tv;
	}
};

// 格力工厂类
class GreeFactory : public Factory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new GreeAirCondition();
		cout << "格力空调制造完毕" << endl;
		return airCondition;
	}

	virtual TV* createTV() override {
		TV* tv = new GreeTV();
		cout << "格力电视制造完毕" << endl;
		return tv;
	}
};

// 美的工厂类
class MideaFactory : public Factory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new MideaAirCondition();
		cout << "美的空调制造完毕" << endl;
		return airCondition;
	}

	virtual TV* createTV() override {
		TV* tv = new MideaTV();
		cout << "美的电视制造完毕" << endl;
		return tv;
	}
};

#if 0
int main() {
	MideaFactory* factory = new MideaFactory();
	AirCondition* airCondition = factory->createAirCondition();
	TV* tv = factory->createTV();
	
	airCondition->introduce();
	tv->introduce();

	delete airCondition;
	delete tv;
}
#endif