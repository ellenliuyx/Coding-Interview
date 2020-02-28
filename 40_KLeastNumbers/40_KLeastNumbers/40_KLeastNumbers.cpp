//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

#include <iostream>
#include <assert.h>
#include <set>
#include <vector>
using namespace std;

//********************************************************************************//
//----------------------------------单趟快速排序----------------------------------//
//输入：int* numbers（输入数组）, int start（区间起始）, int end（区间结束）
//********************************************************************************//
int QuickSort(int* numbers, int start, int end)
{
	int refer = numbers[0];
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
			high--;
		else
			low++;
	}

	return low;
}

//********************************************************************************//
//----------------------------基于快速排序找最小的k个数---------------------------//
//输入：int* input（输入数组）, int n（输入数组长度）, int* output（储存最小k个数的数组）, int k
//********************************************************************************//
void GetKLeastNumbers_QuickSort(int* input, int n, int* output, int k)
{
	assert(input != nullptr && n > 0 && k > 0 && k <= n);

	int start = 0, end = n - 1;
	int index = QuickSort(input, start, end);

	while (index != k - 1)			//若排序后的枢轴位置不在k-1，则继续递归调用快速排序
	{
		if (index > k - 1)
			index = QuickSort(input, start, index - 1);
		else
			index = QuickSort(input, index + 1, end);
	}

	for (int i = 0; i < k; i++)
		output[i] = input[i];
}

//********************************************************************************//
//---------------------------基于关联容器找最小的k个数----------------------------//
//输入：vector<int> input（输入动态数组）, int n（动态数组长度）,
//      multiset<int, greater<int>>& output（存储最小k个数的关联容器）, int k
//********************************************************************************//
void GetKLeastNumbers_Multiset(vector<int> input, int n, multiset<int, greater<int>>& output, int k)
{
	output.clear();		//先将关联容器清空

	assert(n > 0 && k > 0 && k < n);

	for (vector<int>::iterator itr = input.begin(); itr != input.end(); itr++)		//每次进入一个动态数据
	{
		if (output.size() < k)			//若关联容器内元素个数小于k，则直接将输入的数据插入关联容器
		{
			output.insert(*itr);
		}
		else							//若关联容器内元素个数等于k
		{
			if (*itr < *(output.begin()))	//若输入数据比关联容器中的最大值小
			{
				output.erase(output.begin());	//将原最大值删掉
				output.insert(*itr);			//将输入数据插入关联容器
			}
		}
	}
}

//********************************************************************************//
//------------------------------------打印数组------------------------------------//
//********************************************************************************//
void PrintArray(int* numbers, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << numbers[i] << "\t";
	}
	cout << endl;
}

//********************************************************************************//
//----------------------------------打印关联容器----------------------------------//
//********************************************************************************//
void PrintMultiset(multiset<int, greater<int>> numbers, int length)
{
	for (multiset<int, greater<int>>::iterator itr = numbers.begin(); itr != numbers.end(); itr++)
	{
		cout << *itr << "\t";
	}
	cout << endl;
}

//********************************************************************************//
//-------------------------------------主函数-------------------------------------//
//********************************************************************************//
int main()
{
	//------------数组形式存储输入数据-------------//
	const int length = 10;
	int input[length] = { 10,5,3,9,6,7,1,8,2,4 };
	cout << "输入数组为：" << endl;
	PrintArray(input, length);

	//------------数组形式存储最小的k个元素-------------//
	int k = 4;
	int* output = (int*)malloc(sizeof(int)*k);
	GetKLeastNumbers_QuickSort(input, length, output, k);
	cout << "基于快速排序法找到的 "<< k << " 个最小的数为：" << endl;
	PrintArray(output, k);

	delete[] output;

	//------------动态数组形式存储输入数据-------------//
	vector<int> DataInput;
	for (int i = 0; i < length; i++)
	{
		DataInput.push_back(input[i]);
	}

	//------------关联容器形式存储最小的k个元素-------------//
	multiset<int, greater<int>> LeastNumbers;
	GetKLeastNumbers_Multiset(DataInput, length, LeastNumbers, k);
	cout << "基于multiset找到的 " << k << " 个最小的数为：" << endl;
	PrintMultiset(LeastNumbers, k);

	return 0;
}