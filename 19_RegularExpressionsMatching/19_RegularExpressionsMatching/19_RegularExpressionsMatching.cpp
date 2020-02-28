//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
// 表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
// 中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
// 和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

#include <iostream>
using namespace std;

//************************************************************************************************//
//----------------------------------正则表达式与字符串的匹配函数----------------------------------//
//输入：str（输入字符串），pattern（输入正则表达式）
//返回值：true（匹配成功），false（匹配失败）
//************************************************************************************************//
bool RegularExpressionsMatching(const char* str, const char* pattern)
{
	if (str == nullptr)				//非法输入
	{
		cout << "输入字符串为空" << endl;
		return false;
	}
	if (pattern == nullptr)
	{
		cout << "输入正则表达式为空" << endl;
		return false;
	}

	int current_s = 0, current_p = 0;	//字符串和模式的当前匹配位置指针

	while (str[current_s] != '\0' || pattern[current_p] != '\0')	//循环直到字符串和模式均遍历到末尾时结束
	{
		cout << "str[" << current_s << "] = " <<str[current_s] << "\t" 
			<< "pattern[" << current_p << "] = "<<pattern[current_p] << endl;	//打印输出当前匹配位置

		if (str[current_s] == pattern[current_p])	//若当前匹配位置字符相同，两个指针分别后移一位
		{
			current_s++;
			current_p++;
		}
		else										//若当前匹配位置字符不相同
		{
			if (pattern[current_p] == '.')			//若pattern字符为'.'，对应"aaa"和"a.a"
			{
				current_s++;						//也匹配，两个指针分别后移一位
				current_p++;
			}
			else if (pattern[current_p] == '*')		//若pattern字符为'*'，则'*'之前的一位字符相同，对应"aaaab"和"a*b"
			{
				while (str[current_s] == pattern[current_p - 1])	//循环遍历str，直到当前区域内重复的字符'a'结束
					current_s++;
				current_p++;
			}
			else if (pattern[current_p + 1] == '*')	//若pattern的下一个字符为'*'，且'*'之前的一位字符不相同，对应"aa"和"ab*a"
			{
				current_p += 2;						//此时，pattern跨过2个字符'b*'
			}
			else									//若以上情况均不符合，匹配失败
			{
				return false;
			}
		}
	}
	return true;	//str和pattern均到达'\0'，匹配成功。
					//若其中一个到达'\0'，另一个没有，则继续进入循环，发现两个字符不相等，返回失败
}

//************************************************************************************************//
//---------------------------------------------主函数---------------------------------------------//
//************************************************************************************************//
int main()
{
	const char* str = "aaabbcdde";
	cout << "字符串为：" << str << endl;

	const char* pattern = "a*b*.d*e";
	cout << "正则表达式为：" << pattern << endl;

	cout << "匹配过程如下：" << endl;

	if (RegularExpressionsMatching(str, pattern))
		cout << "匹配成功!" << endl;
	else
		cout << "匹配失败!" << endl;
}