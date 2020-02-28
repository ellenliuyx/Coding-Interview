//==================================================================
// ����ָOffer������
//==================================================================

// ������47�����������ֵ
// ��Ŀ����һ��m��n�����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ
// ����ֵ����0��������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�������
// �������ƶ�һ��ֱ���������̵����½ǡ�����һ�����̼��������������
// ����������õ����ټ�ֵ�����

#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

//*********************************************************************************************//
//---------------------------�ö�ά����洢���i,j������������ֵ---------------------------//
//*********************************************************************************************//
int MaxValueOfGift_TwoDimension(const int* matrix, const int rows, const int columns)
{
	assert(matrix != nullptr && rows > 0 && columns > 0);

	int** MaxValue = new int*[rows];	//����һ�������������С��ȵĶ�ά�������ڴ�ŵ���ÿһ�����������ֵ
	for (int i = 0; i < rows; i++)
	{
		MaxValue[i] = new int[columns];
	}

	//��С����̬�Ż�
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int up = 0, left = 0;
			if (i > 0)		//���ڵ�һ����˵��MaxValue[i-1][j] = 0
			{
				up = MaxValue[i - 1][j];
			}
			if (j > 0)		//���ڵ�һ����˵��MaxValue[i][j-1] = 0
			{
				left = MaxValue[i][j - 1];
			}
			MaxValue[i][j] = max(up, left) + matrix[i * columns + j];	//��ά�����˳��洢
		}
	}

	int result = MaxValue[rows-1][columns-1];
	for (int i = 0; i < rows; i++)		//�ͷŶ�ά������ڴ�ռ�
	{
		delete[] MaxValue[i];
	}
	delete MaxValue;
	
	return result;
}

//*********************************************************************************************//
//---------------------------��һά����洢���i,j������������ֵ---------------------------//
//*********************************************************************************************//
int MaxValueOfGift_OneDimension(const int* matrix, const int rows, const int columns)
{
	assert(matrix != nullptr && rows > 0 && columns > 0);

	int* MaxValue = new int[columns];	//����һ������������������ȵ�һά�������ڴ��
										//(i,0)-(i,j-1);(i-1,j)-(columns-1,j)ÿһ�����������ֵ
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int up = 0, left = 0;
			if (i > 0)
			{
				up = MaxValue[j];
			}
			if (j > 0)
			{
				left = MaxValue[j - 1];
			}
			MaxValue[j] = max(up, left) + matrix[i * columns + j];
		}
	}

	int result = MaxValue[columns - 1];

	delete MaxValue;

	return result;
}

//*********************************************************************************************//
//--------------------------------------------������-------------------------------------------//
//*********************************************************************************************//
int main()
{
	//---------------��������1��4x4 ��ά����----------------//
	const int rows1 = 4;
	const int columns1 = 4;
	int matrix1[rows1][columns1] = { {1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5} };

	int max11 = MaxValueOfGift_TwoDimension((const int*)matrix1, rows1, columns1);
	cout << "���������ֵΪ��" << max11 << endl;

	int max12 = MaxValueOfGift_OneDimension((const int*)matrix1, rows1, columns1);
	cout << "���������ֵΪ��" << max12 << endl << endl;

	//---------------��������2��1x5 ���о���----------------//
	const int rows2 = 1;
	const int columns2 = 5;
	int matrix2[rows2][columns2] = {1,10,3,8,5};

	int max21 = MaxValueOfGift_TwoDimension((const int*)matrix2, rows2, columns2);
	cout << "���������ֵΪ��" << max21 << endl;

	int max22 = MaxValueOfGift_OneDimension((const int*)matrix2, rows2, columns2);
	cout << "���������ֵΪ��" << max22 << endl << endl;

	//---------------��������3��5x1 ���о���----------------//
	const int rows3 = 5;
	const int columns3 = 1;
	int matrix3[rows3][columns3] = { {1},{10},{3},{8},{5} };

	int max31 = MaxValueOfGift_TwoDimension((const int*)matrix3, rows3, columns3);
	cout << "���������ֵΪ��" << max31 << endl;

	int max32 = MaxValueOfGift_OneDimension((const int*)matrix3, rows3, columns3);
	cout << "���������ֵΪ��" << max32 << endl << endl;

	//---------------��������4��0x0 �վ���----------------//
	const int rows4 = 0;
	const int columns4 = 0;
	int* matrix4 = nullptr;

	int max41 = MaxValueOfGift_TwoDimension((const int*)matrix4, rows4, columns4);
	cout << "���������ֵΪ��" << max41 << endl;

	int max42 = MaxValueOfGift_OneDimension((const int*)matrix4, rows4, columns4);
	cout << "���������ֵΪ��" << max42 << endl << endl;

	return 0;
}