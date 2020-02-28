//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
// 则输出"student. a am I"。

#include <iostream>
#include <assert.h>
using namespace std;

//**************************************************************************//
//---------------------反转从p_Begin到p_End的每一个字符---------------------//
//**************************************************************************//
void Reverse(char* p_Begin, char* p_End)
{
	while (p_Begin <= p_End)
	{
		swap(*p_Begin, *p_End);
		p_Begin++;
		p_End--;
	}
}

//**************************************************************************//
//--------------左旋转字符串，将字符串的前n个字符移植字符串末尾-------------//
//**************************************************************************//
void LeftRotate(string& str, int n)
{
	assert(str.length() != 0 && n <= str.length());

	//找到字符串的头和尾，并翻转字符串中的所有字符
	char* p_Begin = &(str[0]);
	char* p_End = &(str[0]);
	while (*(p_End + 1) != '\0')
	{
		p_End++;
	}
	Reverse(p_Begin, p_End);

	//找到字符串的最后n的字符并翻转
	p_Begin = p_End - n + 1;
	Reverse(p_Begin, p_End);

	//字符串的剩余字符翻转
	p_End = p_Begin - 1;
	p_Begin = &(str[0]);
	Reverse(p_Begin, p_End);
}

//**************************************************************************//
//----------------------------------主函数----------------------------------//
//**************************************************************************//
int main()
{
	string str;

	//-----测试用例1：n < 字符串长度-----//
	str = "abcdefg";
	cout << str << endl;
	LeftRotate(str, 2);
	cout << str << endl << endl;

	//-----测试用例2：n = 0-----//
	str = "abcdefg";
	cout << str << endl;
	LeftRotate(str, 0);
	cout << str << endl << endl;

	//-----测试用例3：n = 字符串长度-----//
	str = "abcdefg";
	cout << str << endl;
	LeftRotate(str, 7);
	cout << str << endl << endl;

	//-----测试用例4：n > 字符串长度-----//
	str = "abcdefg";
	cout << str << endl;
	LeftRotate(str, 8);
	cout << str << endl << endl;

	//-----测试用例5：字符串为空-----//
	str = "";
	cout << str << endl;
	LeftRotate(str, 2);
	cout << str << endl << endl;
}