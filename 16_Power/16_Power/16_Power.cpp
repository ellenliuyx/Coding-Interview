//==================================================================
// ����ָOffer������
//==================================================================

// ������16����ֵ�������η�
// ��Ŀ��ʵ�ֺ���double Power(double base, int exponent)����base��exponent
// �η�������ʹ�ÿ⺯����ͬʱ����Ҫ���Ǵ������⡣

#include <iostream>
using namespace std;

//**********************************************************************************************//
//------------------------------��ͳѭ���������������޷��������η�------------------------------//
//**********************************************************************************************//
double Power_traditional_unsigned(int base, int exponent)
{
	double result = 1.0;

	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}
	
	return result;
}

//**********************************************************************************************//
//---------------------------���ù�ʽ�ĸ�Ч�������������޷��������η�---------------------------//
//**********************************************************************************************//
double Power_efficient_unsigned(int base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = Power_efficient_unsigned(base, exponent >> 1);		//��������������2

	result *= result;		//��ָ��Ϊż��ʱ��a^n = a^(n/2) * a^(n/2)

	if (exponent & 1)		//�ð�λ�������������%
	{
		result *= base;		//��ָ��Ϊ����ʱ��a^n = a^((n-1)/2) * a^((n-1)/2) * a
	}

	return result;
}

//**********************************************************************************************//
//---------------------------------------�������������η�---------------------------------------//
//���룺int baseΪ���������int exponent()Ϊ����ָ����double (*Power_unsigned)(int,int)Ϊ����ָ��
//**********************************************************************************************//
double Power(int base, int exponent, double (*Power_unsigned)(int,int))
{
	if (exponent >= 0)		//��ָ������0��ֱ�ӷ���Power_unsigned�ļ�����
	{
		return Power_unsigned(base, exponent);
	}
	if (exponent < 0)
	{
		if (base == 0)		//��ָ��С��0���ҵ���Ϊ0���Ƿ�����
		{
			cout << "Invalid input!" << endl;
			throw new exception("Invalid input!");
		}
		return 1.0 / Power_unsigned(base, abs(exponent));		//��ָ��С��0������Power_unsigned�ĵ���
	}
}

//**********************************************************************************************//
//--------------------------------------------������--------------------------------------------//
//---��������1��base = 2, exponent = 3;
//---��������2��base = 2, exponent = 0;
//---��������3��base = 0, exponent = 0; �������壬���0��1���ɣ�
//---��������4��base = 0, exponent = -1; ���Ƿ����룬0����Ϊ������
//**********************************************************************************************//
int main()
{
	int base, exponent;
	double result1, result2;

	while (1)
	{
		cout << "���������:" << endl;
		cin >> base;
		cout << "������ָ��:" << endl;
		cin >> exponent;

		result1 = Power(base, exponent, &Power_traditional_unsigned);	//�ں���ָ�����λ�ô��뺯���ĵ�ַ
		result2 = Power(base, exponent, &Power_efficient_unsigned);

		cout << "�⺯�� pow() �õ��Ľ��Ϊ��" << pow(base, exponent) << endl;
		cout << "Power_traditonal �õ��Ľ��Ϊ��" << result1 << endl;
		cout << "Power_efficient �õ��Ľ��Ϊ��" << result2 << endl;
		cout << endl;
	}

	return 0;
}