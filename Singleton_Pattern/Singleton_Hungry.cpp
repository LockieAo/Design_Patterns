#include <iostream>
using namespace std;

/*
	����ģʽ����Ķ���ֻ��һ��

	����ʽ����ģʽ��
	1.Ϊ��ֹ������������ƻ�����ģʽ���ʣ���˹��캯����Ϊ˽�С�
	2.Ϊ��ֹͨ�������͸�ֵ�����ɶ��������˿�������͸�ֵ��Ϊ˽�С�
	3.��Ķ����д洢��ָ̬�룬�������ʼ����ָ̬�룬ʹ�ó�������ʱ�����󴴽���

*/

class Singleton {
private:
	static Singleton* sing;
private:
	// ����Ĭ�Ϲ���
	Singleton() = default;
	// ��ֹ����Ĭ�Ͽ�������
	Singleton(const Singleton& _sing) = delete;
	// ��ֹ����Ĭ�ϸ�ֵ���������
	Singleton& operator=(const Singleton& _sing) = delete;
public:
	// ��̬�������ص�������ָ��
	static Singleton* GetSingleton() {
		return sing;
	}

	void show() {
		cout << "��������" << endl;
	}
};
// �����ʼ��
Singleton* Singleton::sing = new Singleton();

#if 0
int main() {
	Singleton* sing = Singleton::GetSingleton();
	sing->show();
}
#endif

