//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

#include <iostream>
#include <math.h>
using namespace std;

bool duplicate_noedit(int arrayinput[], int len, int* duplication)
{
	//判断输入数组是否为空
	if (arrayinput == nullptr)
	{
		cout << "输入数组为空" << endl;
		return false;
	}

	//判断输入数组是否合法: 是否所有数字都在1到n的范围内
	for (int i = 0; i < len; i++)
	{
		if (arrayinput[i]<1 || arrayinput[i]>(len - 1))
		{
			cout << "输入数组的值非法" << endl;
			return false;
		}
	}

	//找出重复的数字
	int begin = 1, end = len - 1;				//二分法区间起始点和终止点
	int middle = floor((end + begin) / 2);		//区间中点（向下取整）
	int count_i = middle - begin + 1;			//区间内若不重复的最多元素个数（若区间为1-n，则count_i应为n）
	int count_r = 0;							//计数器，用来统计区间内实际有的元素个数
	while (end > begin)							//当end<=begin时，停止二分循环
	{
		//在整个数组内统计值在[begin,middle]区间内的元素个数count_r
		for (int i = 0; i < len; i++)
		{
			if (arrayinput[i] >= begin && arrayinput[i] <= middle)
			{
				count_r++;
			}
		}
		//若count_r > count_i,则[begin,middle]区间内含有重复元素，否则[middle,end]区间内含有重复元素
		if (count_r > count_i)
		{
			end = middle;
		}
		else 
		{
			begin = middle + 1;
		}
		//二分缩小所关注区间长度
		middle = floor((end + begin) / 2);
		count_i = middle - begin + 1;
		count_r = 0;
	}
	//begin=end跳出循环时，重复的元素即为begin
	*duplication = begin;
	cout << "重复的元素为:" << begin << endl;
	return true;
}

int main()
{
	bool result = 0;
	int number, duplication;
	cout << "请输入数组的元素个数:" << endl;
	cin >> number;
	int* arraytest = (int*)malloc(sizeof(int) * number);	//根据元素个数动态分配数组
	while (!result)
	{
		cout << "请输入" << number << "个数:" << endl;
		for (int i = 0; i < number; i++)
		{
			cin >> arraytest[i];
		}
		result = duplicate_noedit(arraytest, number, &duplication);
	}
	free(arraytest);
	return 0;
}