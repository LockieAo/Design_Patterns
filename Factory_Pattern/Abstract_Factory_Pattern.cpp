#include <iostream>
#include <string>
using namespace std;

/*
	�龰�����������������ģ���ֹ��յ������е��ӻ���.....
	�򵥹���ģʽ�͹���ģʽֻ�����ڵ�����Ʒ�����ʺϴ�����Ʒ�塣

	���󹤳�ģʽ��
	1.��ÿ�ֲ�Ʒ����������࣬����Ʒ�Ƶĸò�Ʒ���Ǹ��������
	2.������󹤳���������Ʒ�Ĺ������Ǹ�������࣬���幤�����п��Դ�����Ʒ�Ʋ�Ʒ��Ĳ�Ʒ

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

// ���������
class TV {
public:
	virtual void introduce() = 0;
	virtual ~TV() {}
};

// ����������
class HaierTV : public TV {
public:
	virtual void introduce() override {
		cout << "��������" << endl;
	}
};

// ����������
class GreeTV : public TV {
public:
	virtual void introduce() override {
		cout << "��������" << endl;
	}
};

// ���ĵ�����
class MideaTV : public TV {
public:
	virtual void introduce() override {
		cout << "���ĵ���" << endl;
	}
};



// ���󹤳���
class Factory {
public:
	virtual AirCondition* createAirCondition() = 0;
	virtual TV* createTV() = 0;
	virtual ~Factory() {}
};

// ����������
class HaierFactory : public Factory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new HaierAirCondition();
		cout << "�����յ��������" << endl;
		return airCondition;
	}

	virtual TV* createTV() override {
		TV* tv = new HaierTV();
		cout << "���������������" << endl;
		return tv;
	}
};

// ����������
class GreeFactory : public Factory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new GreeAirCondition();
		cout << "�����յ��������" << endl;
		return airCondition;
	}

	virtual TV* createTV() override {
		TV* tv = new GreeTV();
		cout << "���������������" << endl;
		return tv;
	}
};

// ���Ĺ�����
class MideaFactory : public Factory {
public:
	virtual AirCondition* createAirCondition() override {
		AirCondition* airCondition = new MideaAirCondition();
		cout << "���Ŀյ��������" << endl;
		return airCondition;
	}

	virtual TV* createTV() override {
		TV* tv = new MideaTV();
		cout << "���ĵ����������" << endl;
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