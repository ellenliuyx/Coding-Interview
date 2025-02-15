//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include <iostream>
using namespace std;

//*************************************************************************************//
//------------------------------字符串表示数字模拟加1函数------------------------------//
//输入：number（字符串表示数字）
//返回值：是否在最高位产生进位（溢出标志）
//*************************************************************************************//
bool Increment(char* number)
{
	bool overFlow = false;		//溢出标志位
	bool carryBit = true;		//将进位标志初始化为1，等价于一开始的加1操作

	for (int i = strlen(number) - 1; i >= 0; i--)		//从字符串的最后一位（除去'\0'）开始循环，直到字符串的第0位
	{
		if (!carryBit)									//若不再有进位产生，则无需继续向高位进位，停止循环
			break;

		if (number[i] + carryBit - '0' >= 10)			//若当前位为'9'，则加1后为10
		{
			number[i] = '0';							//将此为置为'0'
			carryBit = true;							//进位标志置为1
		}
		else											//若当前位小于'9'								
		{
			number[i]++;								//当前为+1
			carryBit = false;							//进位标志置为0
		}

		if (!i && carryBit)								//如果循环到达最高位（i=0），且仍需进位
			overFlow = true;							//溢出标志置为1
	}
	return overFlow;
}

//*************************************************************************************//
//------------------------字符串表示数字打印函数（去掉开头的0）------------------------//
//输入：number（字符串表示数字）
//*************************************************************************************//
void PrintNumber(char* number)
{
	bool needPrint = false;			//打印标志位，当找到第一个不为0的有效数字时置1

	for (int i = 0; i < strlen(number); i++)	//字符串数字从高位0开始循环，直到'\0'的前一位
	{
		if (number[i] != '0')					//若当前位不为'0'
		{
			needPrint = true;					//找到第一个不为0的有效数字,打印标志位置1
			cout << number[i];					//打印该位数字
		}

		if (number[i] == '0' && needPrint)		//若当前位为'0'且打印标志位已经被置1
		{
			cout << number[i];					//此时，该位的'0'亦为有效数字，需要打印
		}
	}
	cout << endl;			//在数字末尾换行
}


//*************************************************************************************//
//---------------------------加1法实现从1到最大n位整数的打印---------------------------//
//输入：number（字符串表示数字）
//*************************************************************************************//
void PrintNumbersIncremental(char* number)
{
	while (!Increment(number))					//若加1没有溢出，则打印该数字
	{
		PrintNumber(number);
		//printf("%s\n", number);
	}
}


//*************************************************************************************//
//---------------------------递归法实现从1到最大n位整数的打印--------------------------//
//输入：number（字符串表示数字），nLength（数组长度），index（当前位数指针）
//*************************************************************************************//
void PrintNumbersRecursive(char* number, int nLength, int index)
{
	if (index == nLength)				//当位数指针移动到字符串的最后一位时，打印字符串
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; i++)		//相当于用递归实现nLength重循环
	{
		number[index] = '0' + i;
		PrintNumbersRecursive(number, nLength, index + 1);
	}
}

//*************************************************************************************//
//---------------------------------------主函数----------------------------------------//
//*************************************************************************************//
int main()
{
	int nLength;
	while (1)
	{
		cout << "请输入位数n：" << endl;
		cin >> nLength;

		if (nLength <= 0)
			break;

		char* number = new char[nLength + 1];		//根据输入位数开辟char数组空间
		memset(number, '0', nLength);				//初始化为'0'
		number[nLength] = '\0';						//加入结束标志'\0'

		cout << "打印从1到最大的n位数（加1法）：" << endl;
		PrintNumbersIncremental(number);
		cout << endl;

		cout << "打印从1到最大的n位数（递归法）：" << endl;
		PrintNumbersRecursive(number, nLength, 0);
		cout << endl;

		delete[] number;
	}

	return 0;
}