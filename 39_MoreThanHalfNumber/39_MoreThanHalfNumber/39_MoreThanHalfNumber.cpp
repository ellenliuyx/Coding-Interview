//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。

#include <iostream>
#include <assert.h>
using namespace std;

//**********************************************************************************//
//-----------------判断最终找到的数字是否满足出现次数超过一半的要求-----------------//
//输入：int* numbers（输入数组）, int length（数组长度）, int number（已检测出的数字）
//**********************************************************************************//
bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] == number)			//统计number在numbers中出现的次数
			times++;
	}

	if (times * 2 < length)					//将次数与数组长度的一半比较
		return false;
	else
		return true;
}

//**********************************************************************************//
//----------------------------------单趟快速排序------------------------------------//
//输入：int* numbers（输入数组）, int start（区间起始）, int end（区间终止）
//**********************************************************************************//
int QuickSort(int* numbers, int start, int end)
{
	int refer = numbers[start];
	int low = start, high = end;
	bool flag = 0;
	while (low < high)
	{
		if (numbers[low] > numbers[high])
		{
			swap(numbers[low], numbers[high]);
			flag = !flag;
		}
		if (flag == 0)
		{
			high--;
		}
		else
		{
			low++;
		}
	}
	return low;
}

//**********************************************************************************//
//----------------------基于快速排序找到出现次数超过一半的数字----------------------//
//输入：int* numbers（输入数组）, int length（数组长度）
//**********************************************************************************//
int MoreThanHalfNumber_QuickSort(int* numbers, int length)
{
	assert(numbers != nullptr && length != 0);

	int start = 0, end = length - 1, middle = length >> 1;		//middle为中位数的位置

	int index = QuickSort(numbers, start, end);					//单趟快速排序找到一个索引

	while (index != middle)										//直到索引位置为middle，停止循环
	{
		if (index < middle)										//若索引位置小于middle，在后半部分继续递归
		{
			index = QuickSort(numbers, index + 1, end);
		}
		else													//若索引位置大于middle，在前半部分继续递归
		{
			index = QuickSort(numbers, start, index - 1);
		}
	}

	if (CheckMoreThanHalf(numbers, length, numbers[middle]))	//判断找到的数字是否满足出现频率大于数组长度的一半的条件
		return numbers[middle];
	else
		return 0;
}

//**********************************************************************************//
//----------------------基于次数统计找到出现次数超过一半的数字----------------------//
//输入：int* numbers（输入数组）, int length（数组长度）
//**********************************************************************************//
int MoreThanHalfNumber_TimesCount(int* numbers, int length)
{
	assert(numbers != nullptr && length != 0);

	int count = 1;				//次数
	int number = numbers[0];	//当前保存的数字

	for (int i = 1; i < length; i++)	//遍历整个数组
	{
		if (numbers[i] == number)		//若下一个数字和当前保存数字相同，次数加1
			count++;
		else							//若下一个数字和当前保存数字不同，次数减1
			count--;

		if (count == 0)					//当次数减为0时，修改当前保存的数字，次数重新置1
		{
			number = numbers[i];
			count = 1;
		}
	}

	if (CheckMoreThanHalf(numbers, length, number))		//判断找到的数字是否满足出现频率大于数组长度的一半的条件
		return number;
	else
		return 0;
}

//**********************************************************************************//
//-------------------------------------测试函数-------------------------------------//
//输入：int(*func)(int*,int)（找出现次数超过一半的数字的函数指针）
//      int* numbers（输入数组）, int length（数组长度）
//**********************************************************************************//
void Test(int(*func)(int*,int),int* numbers, int length)
{
	int result = func(numbers, length);
	if (result)
		cout << "数组中出现次数超过一半的数字是：" << result << endl;
	else
		cout << "数组中没有出现次数超过一半的数字" << endl;
	cout << endl;
}

//**********************************************************************************//
//--------------------------------------主函数--------------------------------------//
//**********************************************************************************//
int main()
{
	//---------测试用例1：有出现次数超过一半的数字的数组-----------//
	const int length1 = 9;
	int numbers1[length1] = { 1,2,3,2,2,2,5,4,2 };
	Test(MoreThanHalfNumber_QuickSort, numbers1, length1);
	Test(MoreThanHalfNumber_TimesCount,numbers1, length1);
	cout << endl;

	//---------测试用例2：没有出现次数超过一半的数字的数组-----------//
	const int length2 = 9;
	int numbers2[length2] = { 1,2,3,3,2,1,5,4,2 };
	Test(MoreThanHalfNumber_QuickSort, numbers2, length2);
	Test(MoreThanHalfNumber_TimesCount, numbers2, length2);
	cout << endl;

	//---------测试用例3：空数组-------------//
	const int length3 = 0;
	int * numbers3 = nullptr;
	Test(MoreThanHalfNumber_QuickSort, numbers3, length3);
	Test(MoreThanHalfNumber_TimesCount, numbers3, length3);
	cout << endl;

	return 0;
}