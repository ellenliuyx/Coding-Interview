//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题59（二）：队列的最大值
// 题目：请定义一个队列并实现函数max得到队列的最大值，要求函数max、push_back
// 和pop_front的时间复杂度都是O(1)

#include <deque>
#include <iostream>
#include <exception>
using namespace std;

//****************************************************************************//
//-------------------------包含最大值函数的队列模板类-------------------------//
//****************************************************************************//
template <typename T> class QueueWithMax
{
public:
	//------构造函数，将currentIndex初始化为0------//
	QueueWithMax() :currentIndex(0) {}

	//------push_back函数------//
	void push_back(T value)
	{
		InternalData inData = { value, currentIndex };		//构造InternalData的inData

		data.push_back(inData);			//对于数据队列，直接push_back即可

		//对于最大值队列
		while (!maxValue.empty() && value >= maxValue.back().number)	//若非空且当前元素值大于队尾元素
			maxValue.pop_back();		//弹出队尾元素
		maxValue.push_back(inData);		//将当前元素入队

		currentIndex++;			//当前元素下标+1
	}

	//------pop_front函数------//
	void pop_front()
	{
		if (maxValue.empty())		//若队列为空，抛出异常
			throw new exception("The queue is empty!");

		if (maxValue.front().index == data.front().index)	//若最大值队列队头元素下标 与 数据队列队头元素下标相同，则也需要弹出
			maxValue.pop_front();

		data.pop_front();			//数据队列则直接弹出
	}

	//------max函数------//
	T max()
	{
		if (maxValue.empty())		//若队列为空，抛出异常
			throw new exception("The queue is empty!");

		return maxValue.front().number;		//否则，返回最大值队列的队头元素值
	}

private:
	struct InternalData		//数据队列和最大值队列中的数据类型包含数据值和数据元素下标两部分
	{
		T number;
		int index;
	};

	deque<InternalData> data;		//数据队列
	deque<InternalData> maxValue;	//最大值队列

	int currentIndex;		//当前元素下标
};

int main()
{
	QueueWithMax<int> myQueue;

	myQueue.push_back(2);			//{2}
	cout << myQueue.max() << '\t';
	myQueue.push_back(3);			//{2,3}
	cout << myQueue.max() << '\t';
	myQueue.push_back(4);			//{2,3,4}
	cout << myQueue.max() << '\t';
	myQueue.push_back(2);			//{2,3,4,2}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{3,4,2}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{4,2}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{2}
	cout << myQueue.max() << '\t';
	myQueue.push_back(6);			//{2,6}
	cout << myQueue.max() << '\t';
	myQueue.push_back(2);			//{2,6,2}
	cout << myQueue.max() << '\t';
	myQueue.push_back(5);			//{2,6,2,5}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{6,2,5}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{2,5}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{5}
	cout << myQueue.max() << '\t';
	myQueue.push_back(1);			//{5,1}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{1}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{}
	cout << myQueue.max() << '\t';
}