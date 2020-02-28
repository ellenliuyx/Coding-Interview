//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

#include <iostream>
#include <stack>
#include <exception>
using namespace std;

//*******************************************************************************//
//-------------------------------队列模板类的声明--------------------------------//
//*******************************************************************************//
template <typename T> class CQueue		//template <类型参数表> classs 类名
{
public:
	CQueue(void);		//构造函数
	~CQueue(void);		//析构函数

	void appendTail(const T& node);		//入队
	T deleteHead();						//出队

private:
	stack<T> stack1;
	stack<T> stack2;
};

//*******************************************************************************//
//-------------------------------队列模板类函数定义------------------------------//
//-----template <类型参数表> 返回值类型 类名<类型参数表>::函数名(函数参数表)-----//
//*******************************************************************************//
template <typename T> CQueue<T>::CQueue(void){}		//构造函数

template <typename T> CQueue<T>::~CQueue(void){}	//析构函数

template <typename T> void CQueue<T>::appendTail(const T& node)		//入队函数
{
	stack1.push(node);
}

template <typename T> T CQueue<T>::deleteHead()						//出队函数
{
	if (stack2.empty())								//若stack2为空
	{
		T temp;
		if (stack1.empty())							//若stack1也为空，则队列为空，抛出异常
		{
			cout << "queue is empty" << endl;
			throw new exception("queue is empty");
		}
		while (!stack1.empty())						//若stack1不为空，则将stack1全部元素弹出，并入stack2
		{
			temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
	}
	T head = stack2.top();							//将stack2栈顶元素弹出
	stack2.pop();
	
	return head;
}

//*******************************************************************************//
//-------------------------------------主函数------------------------------------//
//*******************************************************************************//
int main()
{
	CQueue<int> MyQueue;			//非静态成员函数需要定义对象才能使用

	//将0，1，2入队
	for (int i = 0; i < 3; i++)
	{
		MyQueue.appendTail(i);
		cout << "push:" << i << endl;
	}

	//将0，1出队
	int head;
	for (int j = 0; j < 2; j++)
	{
		head = MyQueue.deleteHead();
		cout << "pop:" << head << endl;
	}
	
	//将3入队
	MyQueue.appendTail(3);
	cout << "push:" << 3 << endl;

	//将2，3出队后，在申请出队则抛出异常
	for (int j = 0; j < 3; j++)
	{
		head = MyQueue.deleteHead();
		cout << "pop:" << head << endl;
	}
}