//==================================================================
// ����ָOffer������
//==================================================================

// ������49������
// ��Ŀ�����ǰ�ֻ��������2��3��5��������������Ugly Number�����󰴴�С��
// ���˳��ĵ�1500������������6��8���ǳ�������14���ǣ���Ϊ����������7��
// ϰ�������ǰ�1������һ��������

#include <iostream>
#include <assert.h>
using namespace std;

//**********************************************************************//
//--------------------------���������е���С��--------------------------//
//**********************************************************************//
int min(int num1, int num2, int num3)
{
	int temp = num1 < num2 ? num1 : num2;
	return temp < num3 ? temp : num3;
}

//**********************************************************************//
//-----------------------------���N������------------------------------//
//**********************************************************************//
int TheNthUglyNumber(int index)
{
	assert(index > 0);

	int* UglyNumber = new int[index];		//������ǰindex������

	UglyNumber[0] = 1;						//��һ��������1

	int pos_2 = 0, pos_3 = 0, pos_5 = 0;	//*2 *3 *5��õ��³�����ԭ����λ�ã�T2 T3 T5��

	for (int i = 0; i < index - 1; i++)		//��0��index������һ������
	{
		int MaxUglyNumber = UglyNumber[i];				//Ŀǰ���ĳ���
		while (UglyNumber[pos_2]*2 <= MaxUglyNumber)	//��pos_2��λ�ÿ�ʼ*2��ֱ������MaxUglyNumber������pos_2
			pos_2++;
		while (UglyNumber[pos_3]*3 <= MaxUglyNumber)	//��pos_3��λ�ÿ�ʼ*3��ֱ������MaxUglyNumber������pos_3
			pos_3++;
		while (UglyNumber[pos_5]*5 <= MaxUglyNumber)	//��pos_5��λ�ÿ�ʼ*5��ֱ������MaxUglyNumber������pos_5
			pos_5++;

		//��M2 M3 M5����Сֵ������һ������
		int nextUglyNumber = min(UglyNumber[pos_2]*2, UglyNumber[pos_3]*3, UglyNumber[pos_5]*5);
		UglyNumber[i + 1] = nextUglyNumber;
	}

	int result = UglyNumber[index - 1];		//������һ������
	delete[] UglyNumber;

	return result;
}

//**********************************************************************//
//--------------------------------������--------------------------------//
//**********************************************************************//
int main()
{
	//----------��������1��1-----------//
	int index1 = 1;
	cout << "�� "<< index1 << " �������ǣ�" << TheNthUglyNumber(index1) << endl;

	//----------��������2��3-----------//
	int index2 = 3;
	cout << "�� " << index2 << " �������ǣ�" << TheNthUglyNumber(index2) << endl;

	//----------��������3��5-----------//
	int index3 = 5;
	cout << "�� " << index3 << " �������ǣ�" << TheNthUglyNumber(index3) << endl;

	//----------��������4��8-----------//
	int index4 = 7;
	cout << "�� " << index4 << " �������ǣ�" << TheNthUglyNumber(index4) << endl;

	//----------��������5��10-----------//
	int index5 = 9;
	cout << "�� " << index5 << " �������ǣ�" << TheNthUglyNumber(index5) << endl;

	//----------��������6��15-----------//
	int index6 = 11;
	cout << "�� " << index6 << " �������ǣ�" << TheNthUglyNumber(index6) << endl;

	//----------��������7��859963392-----------//
	int index7 = 1500;
	cout << "�� " << index7 << " �������ǣ�" << TheNthUglyNumber(index7) << endl;

	return 0;
}