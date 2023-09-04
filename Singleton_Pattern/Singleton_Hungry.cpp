#include <iostream>
using namespace std;

/*
	单例模式：类的对象只有一个

	饿汉式单例模式：
	1.为防止创建多个对象，破坏单例模式性质，因此构造函数设为私有。
	2.为防止通过拷贝和赋值来生成多个对象，因此拷贝构造和赋值设为私有。
	3.类的对象中存储静态指针，在类外初始化静态指针，使得程序启动时，对象创建。

*/

class Singleton {
private:
	static Singleton* sing;
private:
	// 生成默认构造
	Singleton() = default;
	// 禁止生成默认拷贝构造
	Singleton(const Singleton& _sing) = delete;
	// 禁止生成默认赋值运算符重载
	Singleton& operator=(const Singleton& _sing) = delete;
public:
	// 静态函数返回单例对象指针
	static Singleton* GetSingleton() {
		return sing;
	}

	void show() {
		cout << "饿汉单例" << endl;
	}
};
// 类外初始化
Singleton* Singleton::sing = new Singleton();

#if 0
int main() {
	Singleton* sing = Singleton::GetSingleton();
	sing->show();
}
#endif

