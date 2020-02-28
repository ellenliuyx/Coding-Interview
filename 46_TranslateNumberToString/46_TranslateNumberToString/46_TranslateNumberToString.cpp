//==================================================================
// ����ָOffer������
//==================================================================

// ������46�������ַ�����ַ���
// ��Ŀ������һ�����֣����ǰ������¹����������Ϊ�ַ�����0�����"a"��1��
// ���"b"��������11�����"l"��������25�����"z"��һ�����ֿ����ж�����롣��
// ��12258��5�ֲ�ͬ�ķ��룬���Ƿֱ���"bccfi"��"bwfi"��"bczi"��"mcfi"��
// "mzi"������ʵ��һ��������������һ�������ж����ֲ�ͬ�ķ��뷽����

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <assert.h>
using namespace std;

//******************************************************************************************//
//--------------------------------�����ַ�����ַ����ķ�����--------------------------------//
//******************************************************************************************//
int GetTranslationCount(int number)
{
	const int MaxNumberLength = 10;

	assert(number >= 0);

	char* numberStr = new char[MaxNumberLength];
	sprintf(numberStr, "%d", number);				//������numberת���ַ���numberStr

	int length = strlen(numberStr);					//�ַ���numberStr�ĳ��ȣ�������number��λ��

	int* count = (int*)malloc(sizeof(int) * (length + 1));		//count���������洢�ӵ�iλ���ֿ�ʼ�Ĳ�ͬ�������Ŀ
	count[length] = 0;
	count[length - 1] = 1;

	for (int i = length - 2; i >= 0; i--)			//�Ӻ���ǰѭ�����õ��˶�̬�滮��˼�룬�����˵ݹ�������ظ�����
	{
		int temp0 = numberStr[i + 1] - '0';			//��iλ����
		int temp1 = numberStr[i] - '0';				//��i+1λ����
		int temp = temp1 * 10 + temp0;				//��iλ�͵�i+1λƴ����������
		bool g = 0;									//��iλ�͵�i+1λƴ�����������Ƿ���10��25֮��ı�־λ

		if (temp >= 10 && temp <= 25)				//����10��25֮�䣬��g��1
		{
			g = 1;
			if (i == length - 2)					//��������жϱ���Ҫ�ӣ�����gΪ1ʱ��count[i + 2] = countcount[length] = 0
			{
				count[i] = count[i + 1] + 1;		//��û�д��жϣ�10��125�����������λ��10��25֮������ֻ�����һ�ַ���
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
//------------------------------------------������------------------------------------------//
//******************************************************************************************//
int main()
{
	int number1 = 12258;
	int TranslateNumber1 = GetTranslationCount(number1);
	cout << "���� " << number1 << " �ķ��뷽���� " << TranslateNumber1 << " ��" << endl;

	int number2 = 426;
	int TranslateNumber2 = GetTranslationCount(number2);
	cout << "���� " << number2 << " �ķ��뷽���� " << TranslateNumber2 << " ��" << endl;

	int number3 = 126;
	int TranslateNumber3 = GetTranslationCount(number3);
	cout << "���� " << number3 << " �ķ��뷽���� " << TranslateNumber3 << " ��" << endl;

	int number4 = 125;
	int TranslateNumber4 = GetTranslationCount(number4);
	cout << "���� " << number4 << " �ķ��뷽���� " << TranslateNumber4 << " ��" << endl;

	int number5 = 101;
	int TranslateNumber5 = GetTranslationCount(number5);
	cout << "���� " << number5 << " �ķ��뷽���� " << TranslateNumber5 << " ��" << endl;

	int number6 = 100;
	int TranslateNumber6 = GetTranslationCount(number6);
	cout << "���� " << number6 << " �ķ��뷽���� " << TranslateNumber6 << " ��" << endl;

	int number7 = 10;
	int TranslateNumber7 = GetTranslationCount(number7);
	cout << "���� " << number7 << " �ķ��뷽���� " << TranslateNumber7 << " ��" << endl;

	int number8 = 0;
	int TranslateNumber8 = GetTranslationCount(number8);
	cout << "���� " << number8 << " �ķ��뷽���� " << TranslateNumber8 << " ��" << endl;

	int number9 = -11;
	int TranslateNumber9 = GetTranslationCount(number9);
	cout << "���� " << number9 << " �ķ��뷽���� " << TranslateNumber9 << " ��" << endl;
	return 0;
}