#include <iostream>
#include <atomic>
#include <mutex>
#include <queue>
#include <thread>
using namespace std;

/*
	�ö���ʽ����ģʽʵ��һ��������С�
	�����߸�������з����������ߴ��������ȡ����

	ע�⣺����ʹ���˻���������˲����ʣ�������Ҫ�޸�Ϊ ������+�������� �� �ź���

*/

class TaskQueue {
private:
	queue<int> tasks;
	static TaskQueue* task_queue;
	mutex task_mutex;
private:
	// ����Ĭ�Ϲ���
	TaskQueue() = default;
	// ��ֹ����Ĭ�Ͽ�������
	TaskQueue(const TaskQueue& _sing) = delete;
	// ��ֹ����Ĭ�ϸ�ֵ���������
	TaskQueue& operator=(const TaskQueue& _sing) = delete;

public:
	// ��̬�������ص�������ָ��
	static TaskQueue* GetTaskQueue() {
		return task_queue;
	}

	// ��������п�
	bool Empty() {
		// ����RAII�Ļ��ƹ����������������Զ����٣���֤����
		lock_guard<mutex> locker(task_mutex);
		return tasks.empty();
	}

	// ��������������
	void Push(int node) {
		lock_guard<mutex> locker(task_mutex);
		tasks.push(node);
	}

	// �������ȡ����
	int Front() {
		lock_guard<mutex> locker(task_mutex);
		if (tasks.empty()) {
			return -1;
		}
		//int data = tasks.front();
		//return data;
		return tasks.front();
	}

	// �������ɾ������
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


	// �������̴߳�����
	auto thread1_func = [&]()->void
		{
			for (int i = 0; i < 10; i++)
			{
				taskqueue->Push(i);
				// ��ӡ��ǰ�߳�ID
				cout << "push data: " << i << " TID: " << this_thread::get_id() << endl;
				// ������500��������һ��
				this_thread::sleep_for(chrono::milliseconds(500));
			}
		};

	// �������̴߳�����
	auto thread2_func = [&]()->void
		{
			// �̸߳տ�ʼ��Ҫ���ߣ�����һ���ȵ��������ߣ���ô����û��Ԫ�أ�ѭ��������ֱ���˳���
			this_thread::sleep_for(chrono::milliseconds(200));
			while (!taskqueue->Empty())
			{
				int data = taskqueue->Front();
				cout << "get data: " << data << " TID: " << this_thread::get_id() << endl;
				taskqueue->Pop();
				// ������1000��������һ��
				this_thread::sleep_for(chrono::milliseconds(1000));
			}
		};

	// �����߳�
	thread producer(thread1_func);
	thread consumer(thread2_func);

	// �ȴ��߳�
	producer.join();
	consumer.join();
}
#endif

