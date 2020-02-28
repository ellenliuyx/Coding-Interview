//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

#include <iostream>
using namespace std;

//******************************************************************************//
//----------------------------递归实现斐波那契数列------------------------------//
//******************************************************************************//
long long Fibonacci_Rucursive(const int& n)
{
	if (n == 0)	return 0;
	else if (n == 1) return 1;
	else
	{
		return Fibonacci_Rucursive(n - 1) + Fibonacci_Rucursive(n - 2);
	}
}

//******************************************************************************//
//----------------------------循环实现斐波那契数列------------------------------//
//******************************************************************************//
long long Fibonacci_Iterative(const int& n)
{
	long long FibN = 0, FibN_1 = 1, FibN_2 = 0;
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else 
	{
		for (int i = 2; i <= n; i++)
		{
			FibN = FibN_1 + FibN_2;
			FibN_2 = FibN_1;
			FibN_1 = FibN;
		}
	}

	return FibN;
}

//******************************************************************************//
//-----------------------------------主函数-------------------------------------//
//******************************************************************************//
int main()
{
	int index;
	long long FibN_Recursive, FibN_Iterative;
	while (1)
	{
		cout << "请输入Fibonacci的索引：" << endl;
		cin >> index;
		if (index == -1)							//键入-1时，程序退出while(1)循环
			break;
		FibN_Recursive = Fibonacci_Rucursive(index);
		FibN_Iterative = Fibonacci_Iterative(index);
		cout << "递归实现的Fibonacci的第 " << index << " 项为：" << FibN_Recursive << endl;
		cout << "循环实现的Fibonacci的第 " << index << " 项为：" << FibN_Iterative << endl;
	}
	return 0;
}