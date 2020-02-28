//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题11-2：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

#include <iostream>
using namespace std;

//************************************************************************//
//-------------------------------打印数组元素-----------------------------//
//************************************************************************//
void PrintArray(int array[], int length)
{
	if (array == nullptr)			//非法输入
	{
		cout << "Invalid input!" << endl;
		throw new exception("Invalid input!");
	}
	for (int i = 0; i < length; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}

//************************************************************************//
//---------------------------------顺序查找-------------------------------//
//************************************************************************//
int MinInOrder(int array[], int start, int end)
{
	int min = array[start];
	for (int i = start; i <= end; i++)
	{
		if (array[i] < min)
			min = array[i];
	}

	return min;
}

//************************************************************************//
//---------------------------------折半查找-------------------------------//
//************************************************************************//
int Min(int array[], int length)
{
	if (array == nullptr)			//非法输入
	{
		cout << "Invalid input!" << endl;
		throw new exception("Invalid input!");
	}

	int start = 0, end = length - 1;
	int middle = (start + end) / 2;

	while (start < end - 1)										//直到start指针与end指针相邻时结束循环
	{
		cout << start << ' ' << middle << ' ' << end << endl;	//循环输出区间记录

		//若start,middle,end处元素相等，则只能用顺序查找法
		if (array[start] == array[middle] && array[middle] == array[end])
		{
			return MinInOrder(array, start, end);
		}

		//若start处元素小于middle处元素，或者middle处元素大于end处元素
		//则说明middle处元素位于第一个递增数组，继续搜索[middle, end]区间
		if (array[start] < array[middle] || array[middle] > array[end])
		{
			start = middle;
			middle = (start + end) / 2;
		}

		//若start处元素大于middle处元素，或者middle处元素小于end处元素
		//则说明middle处元素位于第二个递增数组，继续搜索[start, middle]区间
		if (array[start] > array[middle] || array[middle] < array[end])
		{
			end = middle;
			middle = (start + end) / 2;
		}
	}
	cout << start << ' ' << middle << ' ' << end << endl;		//输出最后一条区间记录

	return array[end];
}

//************************************************************************//
//----------------------------------主函数--------------------------------//
//************************************************************************//
int main()
{
	//--------------------测试1：空数组---------------------//
	/*int length = 0;
	int* array = NULL;*/

	//-----------------测试2：常规旋转数组------------------//
	int length = 9;
	int array[9] = { 6,7,8,9,1,2,3,4,5 };

	//----------------测试3：非常规旋转数组-----------------//
	/*int length = 9;
	int array[9] = { 1,1,0,1,1,1,1,1,1 };*/

	//---------------测试4：全部元素相等数组----------------//
	/*int length = 9;
	int array[9] = { 1,1,1,1,1,1,1,1,1 };*/
	
	cout << "测试数组为： ";
	PrintArray(array, length);

	int minValue;
	minValue = Min(array, length);

	cout << "最小的元素为： "<< minValue << endl;

	return 0;
}