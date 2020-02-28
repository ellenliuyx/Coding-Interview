//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
// 字符串的长度。假设字符串中只包含从'a'到'z'的字符。

#include <iostream>
using namespace std;

//************************************************************************************//
//----------------------------求最长不含重复字符的子字符串----------------------------//
//************************************************************************************//
int LongestSubstringWithoutDup(const string& str)
{
	int* position = new int[26];				//该数组用于存放每一个字符上一次在字符串中出现的位置
	for (int i = 0; i < 26; i++)	//初始时数组初始化为-1，表示所有字符均未出现过
		position[i] = -1;

	if (str.length() == 0)		//若字符串为空，则返回0
		return 0;

	int curLength = 0;			//用于存储f(i-1)
	int maxLength = 0;			//用于存储f(i)
	
	for (int i = 0; i < str.length(); i++)		//从头遍历字符串的每一个字符元素
	{
		int index = str[i] - 'a';				//计算第i个字符对应position数组中的位置
		if (position[index] == -1)				//若第i个字符未出现过
		{
			if (i == 0)							//若是第一个字符，则f(i)=1
				maxLength = 1;
			else								//若不是第一个字符，则f(i)=f(i-1)+1
				maxLength = curLength + 1;
		}
		else									//若第i个字符已经出现过
		{
			int distance = i - position[index];	//第i个字符和它上次出现在字符串中的位置间的距离
			if (distance <= curLength)			//若上次出现的位置在f(i-1)包含的子字符串内，则f(i)=d
			{
				maxLength = distance;
			}
			else								//若上次出现的位置在f(i-1)包含的子字符串之前，则f(i)=f(i-1)+1
			{
				maxLength = curLength + 1;
			}
		}
		position[index] = i;					//更新position数组中第i个字符出现的位置
		curLength = maxLength;					//f(i-1) = f(i)，循环继续
	}
	delete[] position;

	return maxLength;
}

//************************************************************************************//
//---------------------------------------主函数---------------------------------------//
//************************************************************************************//
int main()
{
	//------------测试用例1：4------------//
	string str1 = "arabcacfr";
	int subStrLen1 = LongestSubstringWithoutDup(str1);
	cout << "字符串 " << str1 << " 的最小无重复子字符串的长度为：" << subStrLen1 << endl;

	//------------测试用例2：1------------//
	string str2 = "aaaa";
	int subStrLen2 = LongestSubstringWithoutDup(str2);
	cout << "字符串 " << str2 << " 的最小无重复子字符串的长度为：" << subStrLen2 << endl;

	//------------测试用例3：7------------//
	string str3 = "abcdefg";
	int subStrLen3 = LongestSubstringWithoutDup(str3);
	cout << "字符串 " << str3 << " 的最小无重复子字符串的长度为：" << subStrLen3 << endl;

	//------------测试用例4：4------------//
	string str4 = "abcdcba";
	int subStrLen4 = LongestSubstringWithoutDup(str4);
	cout << "字符串 " << str4 << " 的最小无重复子字符串的长度为：" << subStrLen4 << endl;

	//------------测试用例5：6------------//
	string str5 = "abcdaef";
	int subStrLen5 = LongestSubstringWithoutDup(str5);
	cout << "字符串 " << str5 << " 的最小无重复子字符串的长度为：" << subStrLen5 << endl;

	//------------测试用例6：1------------//
	string str6 = "a";
	int subStrLen6 = LongestSubstringWithoutDup(str6);
	cout << "字符串 " << str6 << " 的最小无重复子字符串的长度为：" << subStrLen6 << endl;

	//------------测试用例7：0------------//
	string str7 = "";
	int subStrLen7 = LongestSubstringWithoutDup(str7);
	cout << "字符串 " << str7 << " 的最小无重复子字符串的长度为：" << subStrLen7 << endl;

	return 0;
}