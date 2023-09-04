#include <iostream>
#include <atomic>
#include <mutex>
using namespace std;

/*
	����ģʽ����Ķ���ֻ��һ��

	����ʽ����ģʽ��
	1.Ϊ��ֹ������������ƻ�����ģʽ���ʣ���˹��캯����Ϊ˽�С�
	2.Ϊ��ֹͨ�������͸�ֵ�����ɶ��������˿�������͸�ֵ��Ϊ˽�С�
	3.��ʹ��ʱ�Ż����ɶ���������⽫��̬����ָ���ʼ��Ϊ�գ��ڻ�ȡ����ʱ�Ż���д�����

	����ʽ����ģʽȱ�ݣ��̲߳���ȫ��

	���ȱ�ݵķ�����
	1.˫�ؼ����+ԭ�ӱ���
	2.�ֲ�������Ҫ�������֧��C++11��


	���������
	1.��ȡ����ʱ���ȼ�����Ȼ���ж϶����Ƿ���ڣ������򷵻أ������ڴ�����
	2.ȱ�㣺���۵�ǰ�Ƿ��ж��󣬶���������Ч�ʵ͡�

	˫�ؼ������
	1.��ȡ����ʱ���ȼ���Ƿ��ж��������ֱ�ӷ��ء����û�����ȼ������жϡ�
	2.ȱ�㣺����ָ�����ţ����ָ�� sing = new Singleton() ��ִ��˳����ܺ�ԭ���Ĳ�ͬ��
		����˳��1.���ٿռ� 2.�ڿռ��д������� 3.singָ��ռ��ַ
		����˳��1.���ٿռ� 2.singָ��ռ��ַ 3.�ڿռ��д�������
	���ָ�����ţ���ô����һ���߳̽����ٽ�����������ʱ����һ���߳��ڵ�һ��if�ж�ʱ��
	sing���ǿգ�����ʱ�ڴ��л�û�д����������ʹ�þͻ�����⡣

	˫�ؼ����+ԭ�ӱ�����
	1.C++11������ԭ�ӱ��� atomic��ʹ��ԭ�ӱ����������ȱ�㡣
	2.����ָ̬��洢��ԭ�ӱ����У����ǰ����ԭ�ӱ�����ȡ�������������������ԭ�ӱ�����
	3.ֻҪû�б�������ԭ�ӱ�������ô�����̻߳�ȡʱ�����ɻ�ȡ�����ǿա�

	�ֲ�������Ҫ�������֧��C++11
	1.C++11�涨�����ָ���߼�����һ��δ����ʼ�����������������в���ִ��Ӧ���ȴ��ñ�����ɳ�ʼ����
	2.δ��ʼ����int a;int a=0;������δ��ʼ����
	3.ʹ�þ�̬�ֲ�����ʱ������߳���Ҫ�ȴ���̬�ֲ�������ʼ����ϡ�
	��ʼ����Ϻ󣬾Ͳ����ٳ�ʼ����ֱ�ӾͿ����ã�Ҳû���̰߳�ȫ�����⡣
	

*/

#if 0
// ˫�ؼ����+ԭ�ӱ���
class Singleton {
private:
	static atomic<Singleton*> sing;
	// ��̬������ֻ��ʹ�þ�̬������ͬʱ�������Ӧ��ʹ��ͬһ����
	static mutex sing_mutex;
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
		Singleton* _singptr = sing.load();// ��ȡԭ�ӱ����е�ָ��
		if (_singptr == nullptr) {
			sing_mutex.lock();
			_singptr = sing.load();
			if (_singptr == nullptr) {
				_singptr = new Singleton();// ��������
				sing.store(_singptr);// ��䵽ԭ�ӱ���
			}
			sing_mutex.unlock();
		}
		return _singptr;
	}

	void show() {
		cout << "��������" << endl;
	}
};
// �����ʼ��������������ʽ���������дһ��ͺã�
atomic<Singleton*> Singleton::sing;

// �����ʼ����
mutex Singleton::sing_mutex;

#endif


#if 1
// �ֲ�����
class Singleton {
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
		static Singleton sing;
		return &sing;
	}

	void show() {
		cout << "��������" << endl;
	}
};
#endif


#if 0
int main() {
	Singleton* sing = Singleton::GetSingleton();
	sing->show();
}
#endif
