//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，

#include <iostream>
#include <assert.h>
#include <deque>
using namespace std;

//****************************************************************************//
//----------------------------求滑动窗口内的最大值----------------------------//
//****************************************************************************//
int* MaxInSildingWindow(int* array, int length, int WindowLength)
{
	assert(array != nullptr && length >= 0 && WindowLength > 0 && WindowLength <= length);

	int maxNumber = length - WindowLength + 1;		//最大值数组长度与滑动窗口个数相同
	int* maxValue = new int[maxNumber];

	deque<int> index;			//双端队列用于存储有可能是滑动窗口最大值的数字的下标

	for (int i = 0; i < length; i++)		//依次遍历数组中的每一个元素
	{
		while (!index.empty() && array[i] > array[index.back()])	//当数组非空，或者当前元素值大于队尾元素值时
		{
			index.pop_back();		//弹出队尾元素
		}
		index.push_back(i);			//将当前元素对应下标存入

		if (i - index.front() >= WindowLength)		//若队头元素下标与当前处理数字下标之差大于或等于滑动窗口大小时，队头元素已经从滑动窗口移出
			index.pop_front();

		if (i >= WindowLength - 1)					//当当前元素下标大于等于滑动窗口大小-1时，才开始存储滑动窗口最大值
			maxValue[i - WindowLength + 1] = array[index.front()];
	}

	return maxValue;
}

//****************************************************************************//
//----------------------------------打印矩阵----------------------------------//
//****************************************************************************//
void PrintArray(int* array, int length)
{
	for (int i = 0; i <= length; i++)
	{
		cout << array[i] << "\t";
	}
	cout << endl;
}

//****************************************************************************//
//---------------------测试用例1：数组无序，窗口大小正常----------------------//
//****************************************************************************//
void Test1()
{
	const int length = 8, WindowLength = 3;
	int array[length] = { 2,3,4,2,6,2,5,1 };
	int* maxValue = MaxInSildingWindow(array, length, WindowLength);
	PrintArray(maxValue, length - WindowLength);
}

//****************************************************************************//
//------------------测试用例2：数组无序，窗口大小与数组等长-------------------//
//****************************************************************************//
void Test2()
{
	const int length = 8, WindowLength = 8;
	int array[length] = { 2,3,4,2,6,2,5,1 };
	int* maxValue = MaxInSildingWindow(array, length, WindowLength);
	PrintArray(maxValue, length - WindowLength);
}

//****************************************************************************//
//----------------------测试用例3：数组无序，窗口大小为1----------------------//
//****************************************************************************//
void Test3()
{
	const int length = 8, WindowLength = 1;
	int array[length] = { 2,3,4,2,6,2,5,1 };
	int* maxValue = MaxInSildingWindow(array, length, WindowLength);
	PrintArray(maxValue, length - WindowLength);
}

//****************************************************************************//
//-------------------测试用例4：数组单调递增，窗口大小正常--------------------//
//****************************************************************************//
void Test4()
{
	const int length = 8, WindowLength = 3;
	int array[length] = { 1,2,3,4,5,6,7,8 };
	int* maxValue = MaxInSildingWindow(array, length, WindowLength);
	PrintArray(maxValue, length - WindowLength);
}

//****************************************************************************//
//-------------------测试用例5：数组单调递减，窗口大小正常--------------------//
//****************************************************************************//
void Test5()
{
	const int length = 8, WindowLength = 3;
	int array[length] = { 8,7,6,5,4,3,2,1 };
	int* maxValue = MaxInSildingWindow(array, length, WindowLength);
	PrintArray(maxValue, length - WindowLength);
}

//****************************************************************************//
//-----------------------------------主函数-----------------------------------//
//****************************************************************************//
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
}