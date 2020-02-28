//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
// 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。

#include <iostream>
#include <assert.h>
using namespace std;

//*********************************************************************************//
//--------------------------求数组中第一个k在数组中的下标--------------------------//
//*********************************************************************************//
int GetFirstK(int* array, int k, int start, int end)
{
	assert(array != nullptr);		//非法输入：空指针

	if (start > end)				//当区间头大于区间尾时，说明未找到第一个k，则返回-1
		return -1;

	int middle = (start + end) / 2;
	if (array[middle] == k && array[middle - 1] != k)	//若当前元素为k且前一个元素不为k，则找到第一个k
		return middle;
	else							//否则
	{
		//若当前元素大于k，或者当前元素和前一个元素均等于k，在前半段继续寻找
		if (array[middle] > k || (array[middle] == k && array[middle - 1] == k))
			return GetFirstK(array, k, start, middle - 1);

		//若当前元素小于k，或者当前元素和前一个元素均等于k，在后半段继续寻找
		if (array[middle] < k)
			return GetFirstK(array, k, middle + 1, end);
	}
}

//*********************************************************************************//
//-------------------------求数组中最后一个k在数组中的下标-------------------------//
//*********************************************************************************//
int GetLastK(int* array, int k, int start, int end)
{
	assert(array != nullptr);

	if (start > end)
		return -1;

	int middle = (start + end) / 2;
	if (array[middle] == k && array[middle + 1] != k)
		return middle;
	else
	{
		if (array[middle] < k || (array[middle] == k && array[middle + 1] == k))
			return GetLastK(array, k, middle + 1, end);
		if (array[middle] > k)
			return GetLastK(array, k, start, middle - 1);
	}
}

//*********************************************************************************//
//--------------------------测试函数1：k在数组中出现过多次-------------------------//
//*********************************************************************************//
void Test1()
{
	const int length = 8;
	int array[length] = { 1,2,3,3,3,3,4,5 };
	int k = 3;
	int indexFirstK = GetFirstK(array, k, 0, length - 1);
	int indexLastK = GetLastK(array, k, 0, length - 1);
	if (indexFirstK >= 0 && indexLastK >= 0)		//当indexFirstK和indexLastK为-1时，数组中没有k
		cout << k << " 在数组中的个数为：" << indexLastK - indexFirstK + 1 << endl;
	else
		cout << "数组中没有 " << k << endl;
}

//*********************************************************************************//
//--------------------测试函数2：k在数组中只出现1次，且为最小值--------------------//
//*********************************************************************************//
void Test2()
{
	const int length = 8;
	int array[length] = { 1,2,3,3,3,3,4,5 };
	int k = 1;
	int indexFirstK = GetFirstK(array, k, 0, length - 1);
	int indexLastK = GetLastK(array, k, 0, length - 1);
	if (indexFirstK >= 0 && indexLastK >= 0)
		cout << k << " 在数组中的个数为：" << indexLastK - indexFirstK + 1 << endl;
	else
		cout << "数组中没有 " << k << endl;
}

//*********************************************************************************//
//--------------------测试函数3：k在数组中只出现1次，且为最大值--------------------//
//*********************************************************************************//
void Test3()
{
	const int length = 8;
	int array[length] = { 1,2,3,3,3,3,4,5 };
	int k = 5;
	int indexFirstK = GetFirstK(array, k, 0, length - 1);
	int indexLastK = GetLastK(array, k, 0, length - 1);
	if (indexFirstK >= 0 && indexLastK >= 0)
		cout << k << " 在数组中的个数为：" << indexLastK - indexFirstK + 1 << endl;
	else
		cout << "数组中没有 " << k << endl;
}

//*********************************************************************************//
//---------------------------测试函数4：k在数组中未出现过--------------------------//
//*********************************************************************************//
void Test4()
{
	const int length = 8;
	int array[length] = { 1,2,3,3,3,3,4,5 };
	int k = 0;
	int indexFirstK = GetFirstK(array, k, 0, length - 1);
	int indexLastK = GetLastK(array, k, 0, length - 1);
	if (indexFirstK >= 0 && indexLastK >= 0)
		cout << k << " 在数组中的个数为：" << indexLastK - indexFirstK + 1 << endl;
	else
		cout << "数组中没有 " << k << endl;
}

//*********************************************************************************//
//-----------------------------测试函数5：数组为空指针-----------------------------//
//*********************************************************************************//
void Test5()
{
	const int length = 0;
	int* array = nullptr;
	int k = 5;
	int indexFirstK = GetFirstK(array, k, 0, length - 1);
	int indexLastK = GetLastK(array, k, 0, length - 1);
	if (indexFirstK >= 0 && indexLastK >= 0)
		cout << k << " 在数组中的个数为：" << indexLastK - indexFirstK + 1 << endl;
	else
		cout << "数组中没有 " << k << endl;
}

//*********************************************************************************//
//-------------------------------------主函数--------------------------------------//
//*********************************************************************************//
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;
}