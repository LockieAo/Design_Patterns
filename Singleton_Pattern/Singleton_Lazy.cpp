#include <iostream>
#include <atomic>
#include <mutex>
using namespace std;

/*
	单例模式：类的对象只有一个

	懒汉式单例模式：
	1.为防止创建多个对象，破坏单例模式性质，因此构造函数设为私有。
	2.为防止通过拷贝和赋值来生成多个对象，因此拷贝构造和赋值设为私有。
	3.在使用时才会生成对象，因此类外将静态对象指针初始化为空，在获取对象时才会进行创建。

	懒汉式单例模式缺陷：线程不安全。

	解决缺陷的方法：
	1.双重检查锁+原子变量
	2.局部变量（要求编译器支持C++11）


	单检查锁：
	1.获取对象时，先加锁，然后判断对象是否存在，存在则返回，不存在创建。
	2.缺点：不论当前是否有对象，都会上锁，效率低。

	双重检查锁：
	1.获取对象时，先检查是否有对象，如果有直接返回。如果没有则先加锁再判断。
	2.缺点：由于指令重排，因此指令 sing = new Singleton() 的执行顺序可能和原本的不同。
		正常顺序：1.开辟空间 2.在空间中创建对象 3.sing指向空间地址
		重排顺序：1.开辟空间 2.sing指向空间地址 3.在空间中创建对象
	如果指令重排，那么假设一个线程进入临界区创建对象时，另一个线程在第一个if判断时，
	sing不是空，但此时内存中还没有创建对象，如果使用就会出问题。

	双重检查锁+原子变量：
	1.C++11中引入原子变量 atomic，使用原子变量解决上述缺点。
	2.将静态指针存储在原子变量中，检查前，从原子变量获取，创建对象后重新填充进原子变量。
	3.只要没有被填充进入原子变量，那么其他线程获取时，依旧获取到的是空。

	局部变量：要求编译器支持C++11
	1.C++11规定：如果指令逻辑进入一个未被初始化的声明变量，所有并发执行应当等待该变量完成初始化。
	2.未初始化：int a;int a=0;都算是未初始化。
	3.使用静态局部变量时，多个线程需要等待静态局部变量初始化完毕。
	初始化完毕后，就不会再初始化，直接就可以用，也没有线程安全的问题。
	

*/

#if 0
// 双重检查锁+原子变量
class Singleton {
private:
	static atomic<Singleton*> sing;
	// 静态函数中只能使用静态变量，同时多个对象应该使用同一把锁
	static mutex sing_mutex;
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
		Singleton* _singptr = sing.load();// 获取原子变量中的指针
		if (_singptr == nullptr) {
			sing_mutex.lock();
			_singptr = sing.load();
			if (_singptr == nullptr) {
				_singptr = new Singleton();// 创建对象
				sing.store(_singptr);// 填充到原子变量
			}
			sing_mutex.unlock();
		}
		return _singptr;
	}

	void show() {
		cout << "懒汉单例" << endl;
	}
};
// 类外初始化（由于是懒汉式，因此重新写一遍就好）
atomic<Singleton*> Singleton::sing;

// 类外初始化锁
mutex Singleton::sing_mutex;

#endif


#if 1
// 局部变量
class Singleton {
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
		static Singleton sing;
		return &sing;
	}

	void show() {
		cout << "懒汉单例" << endl;
	}
};
#endif


#if 0
int main() {
	Singleton* sing = Singleton::GetSingleton();
	sing->show();
}
#endif
