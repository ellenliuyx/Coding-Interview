//==================================================================
// ����ָOffer������
//==================================================================

// ������58��һ������ת����˳��
// ��Ŀ������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣
// Ϊ������������ź���ͨ��ĸһ���������������ַ���"I am a student. "��
// �����"student. a am I"��

#include <iostream>
#include <assert.h>
using namespace std;

//**************************************************************************//
//---------------------��ת��p_Begin��p_End��ÿһ���ַ�---------------------//
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
//--------------------------��ת�����е�ÿһ������--------------------------//
//**************************************************************************//
void ReverseWords(string& sentence)
{
	assert(!sentence.empty());

	//-----�������������е�ÿһ���ַ�-----//
	char* p_Begin = &(sentence[0]); 
	char* p_End = &(sentence[0]);
	while (*(p_End + 1) != '\0')
	{
		p_End++;
	}
	Reverse(p_Begin, p_End);

	//-----����ÿ�������е�ÿһ���ַ�-----//
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
//----------------------------------������----------------------------------//
//**************************************************************************//
int main()
{
	//-----��������1��һ�������к��ж�����ʺͶ���ո�-----//
	string sentence1 = "I am a student.";
	cout << sentence1 << endl;
	ReverseWords(sentence1);
	cout << sentence1 << endl;

	//-----��������2��һ�������к���һ��������û�пո�-----//
	string sentence2 = "student.";
	cout << sentence2 << endl;
	ReverseWords(sentence2);
	cout << sentence2 << endl;

	//-----��������3��һ�������к��ж���ո���û�е���-----//
	string sentence3 = "      ";
	cout << sentence3 << endl;
	ReverseWords(sentence3);
	cout << sentence3 << endl;

	//-----��������4��һ�������ǿ��ַ���-----//
	string sentence4 = "";
	cout << sentence4 << endl;
	ReverseWords(sentence4);
	cout << sentence4 << endl;
}