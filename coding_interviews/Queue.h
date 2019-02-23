// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

// 只要在头文件的最开始加入这条指令就能够保证头文件被编译一次，这条指令实际上在VC6中就已经有了，
// 但是考虑到兼容性并没有太多的使用它。 

#pragma once
#include <stack>
#include <exception>

using namespace std;

template <typename T> class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	// 在队列末尾添加一个元素
	void appendTail(const T& node);

	// 删除队列的第一个元素
	T deleteHead();

private:
	stack<T> stack1;
	stack<T> stack2;
};

template <typename T> CQueue<T>::CQueue(void)
{
}

template <typename T> CQueue<T>::~CQueue(void)
{
}

template <typename T> void CQueue<T>::appendTail(const T& element)
{
	stack.push(element);
}

template <typename T> T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while(stack1.size()>0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
		throw new exception("queue is empty");
	
	T head = stack2.top();
	stack2.pop();

	return head;
}