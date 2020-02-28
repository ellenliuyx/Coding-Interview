//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题46：把数字翻译成字符串
// 题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
// 译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。例
// 如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
// "mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

//******************************************************************************************//
//--------------------------------把数字翻译成字符串的方法数--------------------------------//
//******************************************************************************************//
int GetTranslationCount(int number)
{
	const int MaxNumberLength = 10;

	assert(number >= 0);

	char* numberStr = new char[MaxNumberLength];
	sprintf(numberStr, "%d", number);				//将数字number转成字符串numberStr

	int length = strlen(numberStr);					//字符串numberStr的长度，即数字number的位数

	int* count = (int*)malloc(sizeof(int) * (length + 1));		//count数组用来存储从第i位数字开始的不同翻译的数目
	count[length] = 0;
	count[length - 1] = 1;

	for (int i = length - 2; i >= 0; i--)			//从后往前循环，用到了动态规划的思想，避免了递归产生的重复计算
	{
		int temp0 = numberStr[i + 1] - '0';			//第i位数字
		int temp1 = numberStr[i] - '0';				//第i+1位数字
		int temp = temp1 * 10 + temp0;				//第i位和第i+1位拼起来的数字
		bool g = 0;									//第i位和第i+1位拼起来的数字是否在10到25之间的标志位

		if (temp >= 10 && temp <= 25)				//若在10到25之间，则将g置1
		{
			g = 1;
			if (i == length - 2)					//！！这个判断必须要加，否则当g为1时，count[i + 2] = countcount[length] = 0
			{
				count[i] = count[i + 1] + 1;		//若没有此判断，10，125这样的最后两位在10到25之间的数字会少算一种方法
				continue;
			}
		}
		count[i] = count[i + 1] + g * count[i + 2];	//f(i) = f(i+1) + g(i,i+1) * f(i+2)
	}
	int result = count[0];
	delete[] count;

	return result;
}

//******************************************************************************************//
//------------------------------------------主函数------------------------------------------//
//******************************************************************************************//
int main()
{
	int number1 = 12258;
	int TranslateNumber1 = GetTranslationCount(number1);
	cout << "数字 " << number1 << " 的翻译方法有 " << TranslateNumber1 << " 种" << endl;

	int number2 = 426;
	int TranslateNumber2 = GetTranslationCount(number2);
	cout << "数字 " << number2 << " 的翻译方法有 " << TranslateNumber2 << " 种" << endl;

	int number3 = 126;
	int TranslateNumber3 = GetTranslationCount(number3);
	cout << "数字 " << number3 << " 的翻译方法有 " << TranslateNumber3 << " 种" << endl;

	int number4 = 125;
	int TranslateNumber4 = GetTranslationCount(number4);
	cout << "数字 " << number4 << " 的翻译方法有 " << TranslateNumber4 << " 种" << endl;

	int number5 = 101;
	int TranslateNumber5 = GetTranslationCount(number5);
	cout << "数字 " << number5 << " 的翻译方法有 " << TranslateNumber5 << " 种" << endl;

	int number6 = 100;
	int TranslateNumber6 = GetTranslationCount(number6);
	cout << "数字 " << number6 << " 的翻译方法有 " << TranslateNumber6 << " 种" << endl;

	int number7 = 10;
	int TranslateNumber7 = GetTranslationCount(number7);
	cout << "数字 " << number7 << " 的翻译方法有 " << TranslateNumber7 << " 种" << endl;

	int number8 = 0;
	int TranslateNumber8 = GetTranslationCount(number8);
	cout << "数字 " << number8 << " 的翻译方法有 " << TranslateNumber8 << " 种" << endl;

	int number9 = -11;
	int TranslateNumber9 = GetTranslationCount(number9);
	cout << "数字 " << number9 << " 的翻译方法有 " << TranslateNumber9 << " 种" << endl;
	return 0;
}