//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
// 个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
// 个函数求任意位对应的数字。

#include <iostream>
#include <assert.h>
using namespace std;

//*************************************************************************************//
//--------------------------------求nDigits位的数字总数--------------------------------//
//*************************************************************************************//
int NextNumberOfDigit(int nDigits)
{
	if (nDigits == 0)
		return 0;
	else if (nDigits == 1)
		return 10;
	else
		return 9 * pow(10, nDigits - 1) * nDigits;
}

//*************************************************************************************//
//--------------求digits位数字number中从左往右的第n位数字（从0开始计数）---------------//
//-------------------------例如：3位数370从左往右第1位数字是7--------------------------//
//*************************************************************************************//
int GetNthDigitInNumber(int number, int digits, int n)
{
	int count = digits - n;			//从右往左数的数字位数
	for (int i = 1; i < count; i++)
	{
		number = number / 10;
	}
	return number % 10;
}

//*************************************************************************************//
//-------------------------------求数字序列中的第n位数字-------------------------------//
//*************************************************************************************//
int TheNthDigit(int n)
{
	int nDigits = 0;	//数字位数
	int index, numberCount, numberLocate, NthDigit;
	while (1)
	{
		nDigits++;
		if (n < NextNumberOfDigit(nDigits))		//当第n位数字位于nDigits位的数字区域内时
		{
			numberCount = n / (nDigits);	//第n位数字在第几个nDigits位数字内
			index = n % (nDigits);			//第n位数字在该nDigits位数字的第几位上
			
			if (nDigits == 1)				//若位数为1，该nDigits位数字就是numberCount
				numberLocate = numberCount;
			else							//若位数大于1，该nDigits位数字是numberCount加上10^(nDigits-1)
				numberLocate = pow(10, nDigits - 1) + numberCount;

			NthDigit = GetNthDigitInNumber(numberLocate, nDigits, index);	//求该nDigits位数字的第index位上的数字

			return NthDigit;
		}
		else									//当第n位数字不在nDigits位的数字区域内时
			n -= NextNumberOfDigit(nDigits);	
	}
}

//*************************************************************************************//
//---------------------------------------主函数----------------------------------------//
//*************************************************************************************//
int main()
{
	int n1 = 5;
	cout << "第" << n1 << "位的数字是：" << TheNthDigit(n1) << endl;

	int n2 = 13;
	cout << "第" << n2 << "位的数字是：" << TheNthDigit(n2) << endl;

	int n3 = 19;
	cout << "第" << n3 << "位的数字是：" << TheNthDigit(n3) << endl;

	int n4 = 1001;
	cout << "第" << n4 << "位的数字是：" << TheNthDigit(n4) << endl;

	return 0;
}