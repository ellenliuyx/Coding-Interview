//==================================================================
// ����ָOffer������
//==================================================================

// ������10��쳲���������
// ��Ŀ��дһ������������n����쳲�������Fibonacci�����еĵ�n�

#include <iostream>
using namespace std;

//******************************************************************************//
//----------------------------�ݹ�ʵ��쳲���������------------------------------//
//******************************************************************************//
long long Fibonacci_Rucursive(const int& n)
{
	if (n == 0)	return 0;
	else if (n == 1) return 1;
	else
	{
		return Fibonacci_Rucursive(n - 1) + Fibonacci_Rucursive(n - 2);
	}
}

//******************************************************************************//
//----------------------------ѭ��ʵ��쳲���������------------------------------//
//******************************************************************************//
long long Fibonacci_Iterative(const int& n)
{
	long long FibN = 0, FibN_1 = 1, FibN_2 = 0;
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else 
	{
		for (int i = 2; i <= n; i++)
		{
			FibN = FibN_1 + FibN_2;
			FibN_2 = FibN_1;
			FibN_1 = FibN;
		}
	}

	return FibN;
}

//******************************************************************************//
//-----------------------------------������-------------------------------------//
//******************************************************************************//
int main()
{
	int index;
	long long FibN_Recursive, FibN_Iterative;
	while (1)
	{
		cout << "������Fibonacci��������" << endl;
		cin >> index;
		if (index == -1)							//����-1ʱ�������˳�while(1)ѭ��
			break;
		FibN_Recursive = Fibonacci_Rucursive(index);
		FibN_Iterative = Fibonacci_Iterative(index);
		cout << "�ݹ�ʵ�ֵ�Fibonacci�ĵ� " << index << " ��Ϊ��" << FibN_Recursive << endl;
		cout << "ѭ��ʵ�ֵ�Fibonacci�ĵ� " << index << " ��Ϊ��" << FibN_Iterative << endl;
	}
	return 0;
}