//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题31：栈的压入、弹出序列
// 题目：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是
// 否为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1、2、3、4、
// 5是某栈的压栈序列，序列4、5、3、2、1是该压栈序列对应的一个弹出序列，但
// 4、3、5、1、2就不可能是该压栈序列的弹出序列。

#include <stack>
#include <iostream>
#include <assert.h>		//防御式编程
using namespace std;

//***********************************************************************************************//
//-------------------------------------判断是否为一个弹出序列------------------------------------//
//***********************************************************************************************//
bool IsPopOrder(int* p_Push, int* p_Pop, int nLength)
{
	assert(p_Push != nullptr && p_Pop != nullptr && nLength != 0);		//防御式编程：非法输入判断

	stack<int> myStack;
	int indexPush = 0, indexPop = 0;	//p_Push和p_Pop序列的当前位置指针

	while (indexPop < nLength)			//直到p_Pop序列搜索完成时跳出循环
	{
		while (myStack.empty() || myStack.top() != p_Pop[indexPop])		//若栈为空或者栈顶元素与当前p_Pop序列元素不等
		{
			if (indexPush >= nLength)		//若此时p_Push已经遍历完，则返回false
				return false;

			myStack.push(p_Push[indexPush]);		//否则，按顺序将一个p_Push序列元素入栈
			cout << "push: " << p_Push[indexPush] <<endl;
			indexPush++;
		}
		cout << "pop: " << p_Pop[indexPop] << endl;
		myStack.pop();							//若栈顶元素与当前p_Pop序列元素相等，则弹出栈顶元素
		indexPop++;
	}
	return true;
}

//***********************************************************************************************//
//--------------------------------------------主函数---------------------------------------------//
//***********************************************************************************************//
int main()
{
	const int nLength = 5;

	int p_Push[nLength] = { 1,2,3,4,5 };
	int p_PopRight[nLength] = { 4,5,3,2,1 };	//弹出序列1：p_PopRight是p_Push的一个弹出序列
	int p_PopWrong[nLength] = { 4,3,5,1,2 };	//弹出序列2：p_PopWrong不是p_Push的一个弹出序列

	//--------弹出序列1---------//
	if (IsPopOrder(p_Push, p_PopRight, nLength))
		cout<<"是一个弹出序列"<<endl;
	else
		cout << "不是一个弹出序列" << endl;

	//--------弹出序列2---------//
	if (IsPopOrder(p_Push, p_PopWrong, nLength))
		cout << "是一个弹出序列" << endl;
	else
		cout << "不是一个弹出序列" << endl;
	
	return 0;
}