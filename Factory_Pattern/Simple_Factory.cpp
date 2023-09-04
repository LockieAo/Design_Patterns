#include <iostream>
#include <string>
using namespace std;

/*
	�������յ�ר����������Ʒ�ƵĿյ����磺���������������ġ�
	���������˵��Ӧ�����һ��ר������࣬�������������������ݴ��ݵ�Ʒ�������Ӧ�Ŀյ�������
	ȱ�㣺Υ������ԭ�򡣵�ר���겻��ĳ��Ʒ�ƻ�������ĳ��Ʒ�ƣ�����Ҫ�޸����еĺ�����

	�򵥹���ģʽ��
	1.��Ƴ���յ��࣬����Ʒ�ƵĿյ������������ࡣ
	2.�յ�����ͨ�����ݵ�Ʒ�������첻ͬ�Ŀյ���


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
	virtual void introduce() override{
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

// �յ�Ʒ��ö������
enum Brand {
	Haier,
	Gree,
	Midea
};

// �յ�����
class AirConditionFactory {
public:
	// ����Ʒ������յ�
	AirCondition* createAirCondition(Brand brand) {
		AirCondition* airCondition = nullptr;// ָ��ʵ�ֶ�̬
		
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