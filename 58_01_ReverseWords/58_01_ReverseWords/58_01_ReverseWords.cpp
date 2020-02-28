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
//--------------------------反转句子中的每一个单词--------------------------//
//**************************************************************************//
void ReverseWords(string& sentence)
{
	assert(!sentence.empty());

	//-----调换整个句子中的每一个字符-----//
	char* p_Begin = &(sentence[0]); 
	char* p_End = &(sentence[0]);
	while (*(p_End + 1) != '\0')
	{
		p_End++;
	}
	Reverse(p_Begin, p_End);

	//-----调换每个单词中的每一个字符-----//
	p_Begin = &(sentence[0]);
	p_End = &(sentence[0]);
	while (*p_End != '\0')
	{
		if (*p_End == ' ')
		{
			Reverse(p_Begin, p_End - 1);
			p_Begin = p_End + 1;
			p_End = p_Begin;
		}
		p_End++;
	}
	Reverse(p_Begin, p_End - 1);
}

//**************************************************************************//
//----------------------------------主函数----------------------------------//
//**************************************************************************//
int main()
{
	//-----测试用例1：一个句子中含有多个单词和多个空格-----//
	string sentence1 = "I am a student.";
	cout << sentence1 << endl;
	ReverseWords(sentence1);
	cout << sentence1 << endl;

	//-----测试用例2：一个句子中含有一个单词且没有空格-----//
	string sentence2 = "student.";
	cout << sentence2 << endl;
	ReverseWords(sentence2);
	cout << sentence2 << endl;

	//-----测试用例3：一个句子中含有多个空格且没有单词-----//
	string sentence3 = "      ";
	cout << sentence3 << endl;
	ReverseWords(sentence3);
	cout << sentence3 << endl;

	//-----测试用例4：一个句子是空字符串-----//
	string sentence4 = "";
	cout << sentence4 << endl;
	ReverseWords(sentence4);
	cout << sentence4 << endl;
}