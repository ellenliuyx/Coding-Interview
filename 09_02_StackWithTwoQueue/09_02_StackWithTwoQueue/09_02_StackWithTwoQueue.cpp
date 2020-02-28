//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题9（拓展）：用两个队列实现栈
// 题目：用两个队列实现一个栈。栈的声明如下，请实现它的两个函数PushStack
// 和PopStack，分别完成从栈顶入栈和出栈的功能。

#include <iostream>
#include <queue>
#include <exception>
using namespace std;

//*******************************************************************************//
//--------------------------------栈模板类的声明---------------------------------//
//*******************************************************************************//
template <typename T> class CStack
{
public:
	CStack(void);		//构造函数声明
	~CStack(void);		//析构函数声明

	void PushStack(const T& node);		//入栈函数
	T PopStack();						//出栈函数

private:
	queue<T> queue1;
	queue<T> queue2;
};

template <typename T> CStack<T>::CStack(void) {}	//构造函数定义
template <typename T> CStack<T>::~CStack(void) {}	//析构函数定义

//*******************************************************************************//
//------------------------------------入栈函数-----------------------------------//
//-------------------------哪个队列非空，就将元素入哪个队列----------------------//
//*******************************************************************************//
template <typename T> void CStack<T>::PushStack(const T& node) 
{
	if (queue1.empty())
		queue2.push(node);
	else
		queue1.push(node);
}

//*******************************************************************************//
//------------------------------------出栈函数-----------------------------------//
//-------哪个队列非空（含n个元素），就将该队列的前n-1个元素移入另一个队列，------//
//------------------------------将最后剩下的元素出栈-----------------------------//
//*******************************************************************************//
template <typename T> T CStack<T>::PopStack()
{
	T temp, top;
	if (queue1.empty())									//若队列1为空
	{
		if (queue2.empty())								//若队列2也为空
		{
			cout << "stack is empty" << endl;
			throw new exception("stack is empty");		//抛出异常：栈为空
		}
		while (queue2.size() > 1)						//将队列2的前n-1个元素移入队列1
		{
			temp = queue2.front();
			queue2.pop();
			queue1.push(temp);
		}
		top = queue2.front();							//将队列2的最后一个元素出栈
		queue2.pop();
	}
	else if (queue2.empty())							//若队列2为空
	{
		while (queue1.size() > 1)						//将队列1的前n-1个元素移入队列2
		{
			temp = queue1.front();
			queue1.pop();
			queue2.push(temp);
		}
		top = queue1.front();							//将队列1的最后一个元素出栈
		queue1.pop();
	}
	return top;
}

//*******************************************************************************//
//-------------------------------------主函数------------------------------------//
//*******************************************************************************//
int main()
{
	CStack<int> MyStack;			//非静态成员函数需要定义对象才能使用

	//将0，1，2入栈
	for (int i = 0; i < 3; i++)
	{
		MyStack.PushStack(i);
		cout << "push:" << i << endl;
	}

	//将0，1出栈
	int head;
	for (int j = 0; j < 2; j++)
	{
		head = MyStack.PopStack();
		cout << "pop:" << head << endl;
	}

	//将3入栈
	MyStack.PushStack(3);
	cout << "push:" << 3 << endl;

	//将2，3出栈后，在申请出栈则抛出异常
	for (int j = 0; j < 3; j++)
	{
		head = MyStack.PopStack();
		cout << "pop:" << head << endl;
	}
}