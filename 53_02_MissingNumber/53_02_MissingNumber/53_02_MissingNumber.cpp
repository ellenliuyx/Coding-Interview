//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。

#include <iostream>
#include <assert.h>
using namespace std;

//********************************************************************//
//--------------------------求缺失的数字函数--------------------------//
//********************************************************************//
int GetMissingNumber(int* array, int start, int end)
{
	assert(array != nullptr);		//非法输入

	if (start > end)				//当区间头大于区间尾时，没有找到缺失数字返回-1
		return -1;

	int middle = (start + end) / 2;

	//若当前元素值与下标不等且上一个元素值与下标相等，则返回当前元素下标即为缺失元素
	if (array[middle] == middle + 1 && array[middle - 1] == middle - 1)
		return middle;
	else
	{
		//若当前元素值与下标不等且上一个元素值也与下标不等，则继续在前半段找缺失元素
		if (array[middle] == middle + 1 && array[middle - 1] == middle)
			return GetMissingNumber(array, start, middle - 1);

		//若当前元素值与下标相等，则继续在后半段找缺失元素
		if (array[middle] == middle)
			return GetMissingNumber(array, middle + 1, end);
	}
}

//********************************************************************//
//-----------------测试函数1：缺失数字出现在数组中间------------------//
//********************************************************************//
void Test1()
{
	const int length = 8;
	int array[length] = { 0,1,2,4,5,6,7,8 };
	int MissingNumber = GetMissingNumber(array, 0, length - 1);
	if (MissingNumber >= 0)
		cout << "数组中缺失的数字是：" << MissingNumber << endl;
	else
		cout << "数组中没有缺失的数字" << endl;
}

//********************************************************************//
//-----------------测试函数2：缺失数字出现在数组开头------------------//
//********************************************************************//
void Test2()
{
	const int length = 8;
	int array[length] = { 1,2,3,4,5,6,7,8 };
	int MissingNumber = GetMissingNumber(array, 0, length - 1);
	if (MissingNumber >= 0)
		cout << "数组中缺失的数字是：" << MissingNumber << endl;
	else
		cout << "数组中没有缺失的数字" << endl;
}

//********************************************************************//
//-----------------测试函数3：缺失数字出现在数组末尾------------------//
//********************************************************************//
void Test3()
{
	const int length = 8;
	int array[length] = { 0,1,2,3,4,5,6,8 };
	int MissingNumber = GetMissingNumber(array, 0, length - 1);
	if (MissingNumber >= 0)
		cout << "数组中缺失的数字是：" << MissingNumber << endl;
	else
		cout << "数组中没有缺失的数字" << endl;
}

//********************************************************************//
//-----------------测试函数4：单元素数组且无缺失数字------------------//
//********************************************************************//
void Test4()
{
	const int length = 1;
	int array[length] = { 0 };
	int MissingNumber = GetMissingNumber(array, 0, length - 1);
	if (MissingNumber >= 0)
		cout << "数组中缺失的数字是：" << MissingNumber << endl;
	else
		cout << "数组中没有缺失的数字" << endl;
}

//********************************************************************//
//-------------------------测试函数5：空数组--------------------------//
//********************************************************************//
void Test5()
{
	const int length = 0;
	int *array = nullptr;
	int MissingNumber = GetMissingNumber(array, 0, length - 1);
	if (MissingNumber >= 0)
		cout << "数组中缺失的数字是：" << MissingNumber << endl;
	else
		cout << "数组中没有缺失的数字" << endl;
}

//********************************************************************//
//------------------------------主函数--------------------------------//
//********************************************************************//
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;
}