//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出'b'。

#include <iostream>
using namespace std;

//*************************************************************************//
//-------------------------求第一个只出现一次的字符------------------------//
//*************************************************************************//
char FirstNotRepeatingChar(const string& str)
{
	const int MaxLength = 256;				//字符的位数为8，因此最多有256个
	char* frequency = new char[MaxLength];	//统计每一个字符出现的次数
	for (int i = 0; i < MaxLength; i++)		//初始化为0
		frequency[i] = 0;
	
	for (int i = 0; i < str.length(); i++)	//第一次扫描字符串，统计每一个字符出现的次数，下表为字符的ASCII码
	{
		frequency[(int)(str[i])]++;
	}

	for (int i = 0; i < str.length(); i++)	//第二次扫描字符串，返回第一个出现频次为1的字符
	{
		if (frequency[(int)(str[i])] == 1)
			return str[i];
	}
	return '\0';							//若未找到，则返回'\0'
}

//*************************************************************************//
//----------------------------------主函数---------------------------------//
//*************************************************************************//
int main()
{
	//---------测试用例1：常规测试，有的字符出现多次，有的字符出现一次---------//
	const string str1 = "abaccdeff";
	char result1 = FirstNotRepeatingChar(str1);
	cout << str1 << "中第一个只出现一次的字符是：" << result1 << endl;

	//---------测试用例2：常规测试，所有的字符出现一次---------//
	const string str2 = "abcdefghi";
	char result2 = FirstNotRepeatingChar(str2);
	cout << str2 << "中第一个只出现一次的字符是：" << result2 << endl;

	//---------测试用例3：常规测试，所有的字符出现多次---------//
	const string str3 = "aabbccddee";
	char result3 = FirstNotRepeatingChar(str3);
	cout << str3 << "中第一个只出现一次的字符是：" << result3 << endl;

	//---------测试用例4：空字符串---------//
	const string str4 = "";
	char result4 = FirstNotRepeatingChar(str4);
	cout << str4 << "中第一个只出现一次的字符是：" << result4 << endl;

	return 0;
}