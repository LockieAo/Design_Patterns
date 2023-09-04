#include <iostream>
#include <string>
using namespace std;

/*
	�������յ�ר����������Ʒ�ƵĿյ����磺���������������ġ�
	�򵥹���ģʽȱ�㣺������Υ������ԭ�򣬵��յ�Ʒ�Ʊ����������ҲҪ�޸ġ�

	����ģʽ��
	1.��ƿյ������࣬����Ʒ�ƵĿյ����Ǹ�������ࡣ
	2.��ƹ��������࣬����Ʒ�ƵĿյ��������Ǹ�������ࡣ
	3.Ҫ����ĳ��Ʒ�ƵĿյ���ֻ��Ҫ�����ù�����Ķ����ø�����������յ����ɡ�
	4.���Ҫ���ӻ���ɾ���յ�Ʒ�ƣ�ֻ��Ҫ���ӻ���ɾ���յ���Ϳյ������༴�ɡ�

*/

// ����յ���
class AirCondition {
public:
	virtual void introduce() = 0;
	virtual ~AirCondition() {}
};

// �����յ���
class HaierAirCondition : public AirCondition {
public:
	virtual void introduce() override {
		cout << "�����յ�" << endl;
	}
};

// �����յ���
class GreeAirCondition : public AirCondition {
public:
	virtual void introduce() override {
		cout << "�����յ�" << endl;
	}
};

// ���Ŀյ���
class MideaAirCondition : public AirCondition {
public:
	virtual void introduce() override {
		cout << "���Ŀյ�" << endl;
	}
};

// ���󹤳���
class AirConditionFactory {
public:
	virtual AirCondition* createAirCondition() = 0;
	virtual ~AirConditionFactory(){}
};

// �����յ�������
class HaierAirConditionFactory : public AirConditionFactory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new HaierAirCondition();
		cout << "�����յ��������" << endl;
		return airCondition;
	}
};

// �����յ�������
class GreeAirConditionFactory : public AirConditionFactory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new GreeAirCondition();
		cout << "�����յ��������" << endl;
		return airCondition;
	}
};

// ���Ŀյ�������
class MideaAirConditionFactory : public AirConditionFactory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new MideaAirCondition();
		cout << "���Ŀյ��������" << endl;
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