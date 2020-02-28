//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题43：从1到n整数中1出现的次数
// 题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。例如
// 输入12，从1到12这些整数中包含1 的数字有1，10，11和12，1一共出现了5次。

#include <iostream>
#include <math.h>
#include <assert.h>
using namespace std;

//*********************************************************************//
//-----------------------求一个整数n中包含1的个数-----------------------//
//*********************************************************************//
int NumberOf1(unsigned int n)
{
	int number = 0;
	while (n != 0)
	{
		if (n % 10 == 1)
		{
			number++;
		}
		n = n / 10;
	}
	return number;
}

//*********************************************************************//
//----------求1到n中包含1的个数（时间复杂度为O(NlogN)的方法）----------//
//*********************************************************************//
int NumberOf1_O_NlogN(unsigned int n)
{
	assert(n > 0);

	int number = 0;
	for (int i = 1; i <= n; i++)
	{
		number += NumberOf1(i);		//计算从1到n的每个整数中包含的1的个数，并累加
	}
	return number;
}

//*********************************************************************//
//-----------求1到n中包含1的个数（时间复杂度为O(logN)的方法）----------//
//*********************************************************************//
int NumberOf1_O_logN(unsigned int n)
{
	assert(n > 0);

	unsigned int temp = n;	//用于计算数据位数、高位数字和低位数字
	int numberDigits = 0;	//n的数据位数
	int numberOf1 = 0;		//从1到n中包含的1的个数

	while (temp)			//每次循环当前数位加1
	{
		if (temp % 10 > 1)	//如果x > 1的话，则第i位数上包含的1的数目为：(高位数字+1）* 10^(i-1)  
							//(其中高位数字是从i+1位一直到最高位数构成的数字)
		{
			numberOf1 += (temp / 10 + 1) * pow(10, numberDigits);
		}
		if (temp % 10 < 1)	//如果x < 1的话，则第i位数上包含的1的数目为：(高位数字）* 10^(i-1)
		{
			numberOf1 += (temp / 10) * pow(10, numberDigits);
		}
		if (temp % 10 == 1)	//如果x == 1的话，则第i位数上包含1的数目为：(高位数字) * 10^(i-1)+(低位数字+1)   
							//(其中低位数字时从第i-1位数一直到第1位数构成的数字)
		{
			numberOf1 += (temp / 10) * pow(10, numberDigits) + (n - temp * pow(10, numberDigits) + 1);
		}
		numberDigits++;
		temp /= 10;
	}

	return numberOf1;
}

//*********************************************************************//
//-------------------------------主函数--------------------------------//
//*********************************************************************//
int main()
{
	unsigned int number1 = 1;
	cout << "时间复杂度为O(n)的算法——从1到" << number1 << "的所有整数中，1出现的次数为：" << NumberOf1_O_NlogN(number1) << endl;
	cout << "时间复杂度为O(logn)的算法——从1到" << number1 << "的所有整数中，1出现的次数为：" << NumberOf1_O_logN(number1) << endl << endl;

	unsigned int number2 = 55;
	cout << "时间复杂度为O(n)的算法——从1到" << number2 << "的所有整数中，1出现的次数为：" << NumberOf1_O_NlogN(number2) << endl;
	cout << "时间复杂度为O(logn)的算法——从1到" << number2 << "的所有整数中，1出现的次数为：" << NumberOf1_O_logN(number2) << endl << endl;

	unsigned int number3 = 99;
	cout << "时间复杂度为O(n)的算法——从1到" << number3 << "的所有整数中，1出现的次数为：" << NumberOf1_O_NlogN(number3) << endl;
	cout << "时间复杂度为O(logn)的算法——从1到" << number3 << "的所有整数中，1出现的次数为：" << NumberOf1_O_logN(number3) << endl << endl;

	unsigned int number4 = 10000;
	cout << "时间复杂度为O(n)的算法——从1到" << number4 << "的所有整数中，1出现的次数为：" << NumberOf1_O_NlogN(number4) << endl;
	cout << "时间复杂度为O(logn)的算法——从1到" << number4 << "的所有整数中，1出现的次数为：" << NumberOf1_O_logN(number4) << endl << endl;

	unsigned int number5 = 21345;
	cout << "时间复杂度为O(n)的算法——从1到" << number5 << "的所有整数中，1出现的次数为：" << NumberOf1_O_NlogN(number5) << endl;
	cout << "时间复杂度为O(logn)的算法——从1到" << number5 << "的所有整数中，1出现的次数为：" << NumberOf1_O_logN(number5) << endl << endl;

	return 0;
}