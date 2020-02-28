//==================================================================
// ����ָOffer������
//==================================================================

// ������14��������
// ��Ŀ������һ������Ϊn���ӣ�������Ӽ���m�Σ�m��n����������n>1����m��1����
// ÿ�ε����ӵĳ��ȼ�Ϊk[0]��k[1]��������k[m]��k[0]*k[1]*��*k[m]���ܵ�����
// ���Ƕ��٣����統���ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���
// ʱ�õ����ĳ˻�18��

#include <iostream>
using namespace std;

//*****************************************************************************************//
//------------------------------------��̬�滮������---------------------------------------//
//*****************************************************************************************//
int CuttingRope_Dynamic(int RopeLength)
{
	//��n<4ʱ�����
	if (RopeLength < 2)	 return 0;
	if (RopeLength == 2) return 1;
	if (RopeLength == 3) return 2;

	//��������Ϊ RopeLength + 1 ������洢���ӳ���Ϊ 0-RopeLength �����˻�
	int* MaxProduct = new int[RopeLength + 1];

	//ֱ�ӳ�ʼ�����ӳ���Ϊ 0-3 �����˻�
	MaxProduct[0] = 0;
	MaxProduct[1] = 1;
	MaxProduct[2] = 2;
	MaxProduct[3] = 3;

	int max = 0;

	for (int i = 4; i <= RopeLength; i++)		//�ֱ�������ӳ���Ϊ 4-RopeLength �����˻�
	{
		int max = 0;
		for (int j = 1; j <= i / 2; j++)		//�Ƚϸ�����ϵļ����ӣ���1����������������˻�
		{
			int product = MaxProduct[j] * MaxProduct[i - j];
			if (product > max)
				max = product;
		}
		MaxProduct[i] = max;
	}

	max = MaxProduct[RopeLength];
	delete[] MaxProduct;

	return max;
}

//*****************************************************************************************//
//------------------------------------̰�����Լ�����---------------------------------------//
//*****************************************************************************************//
int CuttingRope_Greedy(int RopeLength)
{
	//˼�룺��n>=5ʱ�������ܶ�ļ�����Ϊ3�����ӣ���ʣ�µĳ���Ϊ4ʱ���������γ���Ϊ2������

	int timeof3 = 0;		//���ɵĳ���Ϊ3����������
	int MaxProduct = 0;		//�洢���˻�

	//��n<4ʱ�����
	if (RopeLength < 2)	 return 0;
	if (RopeLength == 2) return 1;
	if (RopeLength == 3) return 2;

	//���ӳ��ȳ�3��1����Ҫ�����ĳ���Ϊ4�����Ӽ���2*2
	if (RopeLength % 3 == 1)
	{
		timeof3 = RopeLength / 3 - 1;
		MaxProduct = pow(3, timeof3) * 2 * 2;
	}

	//���ӳ��ȳ�3��2�����ʣ�µ����ӳ���Ϊ2
	if (RopeLength % 3 == 2)
	{
		timeof3 = RopeLength / 3;
		MaxProduct = pow(3, timeof3) * 2;
	}

	//���ӳ��ȳ�3��0������ȫ�����ɳ���Ϊ3������
	if (RopeLength % 3 == 0)
	{
		timeof3 = RopeLength / 3;
		MaxProduct = pow(3, timeof3);
	}

	return MaxProduct;
}

//*****************************************************************************************//
//----------------------------------------������-------------------------------------------//
//*****************************************************************************************//
int main()
{
	int RopeLength, MaxProduct_Dynamic, MaxProduct_Greedy;
	while (1)
	{
		cout << "�����������ܳ��ȣ�" << endl;
		cin >> RopeLength;

		if (RopeLength < 0)			//���������ӳ���С��0ʱ������while(1)ѭ��
			break;

		MaxProduct_Dynamic = CuttingRope_Dynamic(RopeLength);	//�ö�̬�滮������
		MaxProduct_Greedy = CuttingRope_Greedy(RopeLength);		//��̰�����Լ�����

		cout << "����̬�滮�����Ӷγ��ȵ����˻�Ϊ��" << MaxProduct_Dynamic << endl;
		cout << "��̰���㷨�����Ӷγ��ȵ����˻�Ϊ��" << MaxProduct_Greedy <<endl;
	}
}