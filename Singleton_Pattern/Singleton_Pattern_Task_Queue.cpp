#include <iostream>
#include <atomic>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;

/*
	用饿汉式单例模式实现一个任务队列。
	生产者给任务队列放任务，消费者从任务队列取任务。

	注意：仅仅使用了互斥锁，因此不合适，后面需要修改为 互斥锁+条件变量 或 信号量

*/

class TaskQueue {
private:
	queue<int> tasks;
	static TaskQueue* task_queue;
	mutex task_mutex;
private:
	// 生成默认构造
	TaskQueue() = default;
	// 禁止生成默认拷贝构造
	TaskQueue(const TaskQueue& _sing) = delete;
	// 禁止生成默认赋值运算符重载
	TaskQueue& operator=(const TaskQueue& _sing) = delete;

public:
	// 静态函数返回单例对象指针
	static TaskQueue* GetTaskQueue() {
		return task_queue;
	}

	// 任务队列判空
	bool Empty() {
		// 利用RAII的机制管理锁，出作用域自动销毁，保证解锁
		lock_guard<mutex> locker(task_mutex);
		return tasks.empty();
	}

	// 任务队列添加任务
	void Push(int node) {
		lock_guard<mutex> locker(task_mutex);
		tasks.push(node);
	}

	// 任务队列取任务
	int Front() {
		lock_guard<mutex> locker(task_mutex);
		if (tasks.empty()) {
			return -1;
		}
		//int data = tasks.front();
		//return data;
		return tasks.front();
	}

	// 任务队列删除任务
	bool Pop() {
		lock_guard<mutex> locker(task_mutex);
		if (tasks.empty()) {
			return false;
		}
		tasks.pop();
		return true;
	}

};
TaskQueue* TaskQueue::task_queue = new TaskQueue;



#if 0
int main() {
	TaskQueue* taskqueue = TaskQueue::GetTaskQueue();


	// 生产者线程处理函数
	auto thread1_func = [&]()->void
		{
			for (int i = 0; i < 10; i++)
			{
				taskqueue->Push(i);
				// 打印当前线程ID
				cout << "push data: " << i << " TID: " << this_thread::get_id() << endl;
				// 生产者500毫秒生产一个
				this_thread::sleep_for(chrono::milliseconds(500));
			}
		};

	// 消费者线程处理函数
	auto thread2_func = [&]()->void
		{
			// 线程刚开始需要休眠，否则一旦先调度消费者，那么由于没有元素，循环跳过，直接退出了
			this_thread::sleep_for(chrono::milliseconds(200));
			while (!taskqueue->Empty())
			{
				int data = taskqueue->Front();
				cout << "get data: " << data << " TID: " << this_thread::get_id() << endl;
				taskqueue->Pop();
				// 消费者1000毫秒消费一个
				this_thread::sleep_for(chrono::milliseconds(1000));
			}
		};

	// 创建线程
	thread producer(thread1_func);
	thread consumer(thread2_func);

	// 等待线程
	producer.join();
	consumer.join();
}
#endif

