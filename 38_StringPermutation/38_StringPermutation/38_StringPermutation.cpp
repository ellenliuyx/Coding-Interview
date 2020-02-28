//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题38：字符串的排列
// 题目：输入一个字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
// 则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。

#include <iostream>
#include <assert.h>
using namespace std;

//************************************************************************//
//------------------------求输入字符串的排列的函数------------------------//
//输入：char* str（输入字符串头指针）, char* p_Begin（字符串当前字符指针）
//************************************************************************//
void permutation(char* str, char* p_Begin)
{
	assert(str != nullptr);		//防御式编程

	if (*p_Begin == '\0')		//若p_Begin到达字符串末尾，则输出字符串
	{
		cout << str << endl;
		return;
	}

	for (char* pointer = p_Begin; *pointer != '\0'; pointer++)		//交换p_Begin和p_Begin的后面每一位字符
	{
		swap(*p_Begin, *pointer);									//交换p_Begin和pointer
		permutation(str, p_Begin + 1);								//p_Begin后移一位，递归调用permutation函数
		swap(*p_Begin, *pointer);									//换回来之后再交换下一位
	}
}

//************************************************************************//
//---------------------------------主函数---------------------------------//
//************************************************************************//
int main()
{
	//-------测试用例1：单字符字符串--------//
	char str1[] = "a";
	permutation(str1, str1);
	cout << endl;

	//-------测试用例2：普通字符串--------//
	char str[] = "abcd";
	permutation(str, str);
	cout << endl;

	//-------测试用例3：空字符串--------//
	char* str_null = nullptr;
	permutation(str_null, str_null);
	cout << endl;

	return 0;
}