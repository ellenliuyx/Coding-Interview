//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

#include <iostream>
using namespace std;

bool duplicate(int arrayinput[], int len, int* duplication)
{
	//判断输入数组是否为空
	if (arrayinput == nullptr)
	{
		cout << "输入数组为空" << endl;
		return false;
	}
	
	//判断输入数组是否合法: 是否所有数字都在0到n-1的范围内
	for (int i = 0; i < len; i++)
	{
		if (arrayinput[i]<0 || arrayinput[i]>(len - 1))
		{
			cout << "输入数组的值非法" << endl;
			return false;
		}
	}

	//找出重复的数字
	for (int i = 0; i < len; i++)
	{
		while(arrayinput[i] != i)
		{
			if(arrayinput[i] != arrayinput[arrayinput[i]])
				swap(arrayinput[i], arrayinput[arrayinput[i]]);
			else
			{
				*duplication = arrayinput[i];		//指针形式作为输出变量
				cout << "找到重复数字：" << *duplication << endl;
				return true;
			}		
		}
	}

	return false;
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
		result = duplicate(arraytest, number, &duplication);	
	}
	free(arraytest);
	return 0;
}