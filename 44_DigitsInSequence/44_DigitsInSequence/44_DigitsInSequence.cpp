//==================================================================
// ����ָOffer������
//==================================================================

// ������44������������ĳһλ������
// ��Ŀ��������0123456789101112131415���ĸ�ʽ���л���һ���ַ������С�����
// �������У���5λ����0��ʼ��������5����13λ��1����19λ��4���ȵȡ���дһ
// ������������λ��Ӧ�����֡�

#include <iostream>
#include <assert.h>
using namespace std;

//*************************************************************************************//
//--------------------------------��nDigitsλ����������--------------------------------//
//*************************************************************************************//
int NextNumberOfDigit(int nDigits)
{
	if (nDigits == 0)
		return 0;
	else if (nDigits == 1)
		return 10;
	else
		return 9 * pow(10, nDigits - 1) * nDigits;
}

//*************************************************************************************//
//--------------��digitsλ����number�д������ҵĵ�nλ���֣���0��ʼ������---------------//
//-------------------------���磺3λ��370�������ҵ�1λ������7--------------------------//
//*************************************************************************************//
int GetNthDigitInNumber(int number, int digits, int n)
{
	int count = digits - n;			//����������������λ��
	for (int i = 1; i < count; i++)
	{
		number = number / 10;
	}
	return number % 10;
}

//*************************************************************************************//
//-------------------------------�����������еĵ�nλ����-------------------------------//
//*************************************************************************************//
int TheNthDigit(int n)
{
	int nDigits = 0;	//����λ��
	int index, numberCount, numberLocate, NthDigit;
	while (1)
	{
		nDigits++;
		if (n < NextNumberOfDigit(nDigits))		//����nλ����λ��nDigitsλ������������ʱ
		{
			numberCount = n / (nDigits);	//��nλ�����ڵڼ���nDigitsλ������
			index = n % (nDigits);			//��nλ�����ڸ�nDigitsλ���ֵĵڼ�λ��
			
			if (nDigits == 1)				//��λ��Ϊ1����nDigitsλ���־���numberCount
				numberLocate = numberCount;
			else							//��λ������1����nDigitsλ������numberCount����10^(nDigits-1)
				numberLocate = pow(10, nDigits - 1) + numberCount;

			NthDigit = GetNthDigitInNumber(numberLocate, nDigits, index);	//���nDigitsλ���ֵĵ�indexλ�ϵ�����

			return NthDigit;
		}
		else									//����nλ���ֲ���nDigitsλ������������ʱ
			n -= NextNumberOfDigit(nDigits);	
	}
}

//*************************************************************************************//
//---------------------------------------������----------------------------------------//
//*************************************************************************************//
int main()
{
	int n1 = 5;
	cout << "��" << n1 << "λ�������ǣ�" << TheNthDigit(n1) << endl;

	int n2 = 13;
	cout << "��" << n2 << "λ�������ǣ�" << TheNthDigit(n2) << endl;

	int n3 = 19;
	cout << "��" << n3 << "λ�������ǣ�" << TheNthDigit(n3) << endl;

	int n4 = 1001;
	cout << "��" << n4 << "λ�������ǣ�" << TheNthDigit(n4) << endl;

	return 0;
}