//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

#include <iostream>
using namespace std;

//思想：把一个整数减去1后再和原来的整数做位运算，得到的结果相当与把整数的二进制表示中最右边的一个1变成0

//****************************************************************************************//
//--------------------------------------求1的个数-----------------------------------------//
//****************************************************************************************//
int NumberOf1(int n)
{
	int count = 0;
	while (n)
	{
		n = (n - 1) & n;
		count++;
	}
	return count;
}

//****************************************************************************************//
//----------------------------------------主函数------------------------------------------//
//****************************************************************************************//
int main()
{
	int number, count;
	while(1)
	{
		cout << "请输入一个整数：" << endl;
		cin >> number;

		count = NumberOf1(number);

		cout << "该数的二进制表示中的1的个数：" << count << endl;
	}
	return 0;
}