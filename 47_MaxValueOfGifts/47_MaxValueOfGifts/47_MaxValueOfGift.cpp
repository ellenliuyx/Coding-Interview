//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
// （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或
// 者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
// 算你最多能拿到多少价值的礼物？

#include <iostream>
#include <algorithm>
#include <assert.h>
using namespace std;

//*********************************************************************************************//
//---------------------------用二维数组存储到达（i,j）的最大礼物价值---------------------------//
//*********************************************************************************************//
int MaxValueOfGift_TwoDimension(const int* matrix, const int rows, const int columns)
{
	assert(matrix != nullptr && rows > 0 && columns > 0);

	int** MaxValue = new int*[rows];	//建立一个与输入数组大小相等的二维数组用于存放到达每一点的最大礼物价值
	for (int i = 0; i < rows; i++)
	{
		MaxValue[i] = new int[columns];
	}

	//从小到大动态优化
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			int up = 0, left = 0;
			if (i > 0)		//对于第一行来说，MaxValue[i-1][j] = 0
			{
				up = MaxValue[i - 1][j];
			}
			if (j > 0)		//对于第一列来说，MaxValue[i][j-1] = 0
			{
				left = MaxValue[i][j - 1];
			}
			MaxValue[i][j] = max(up, left) + matrix[i * columns + j];	//二维矩阵的顺序存储
		}
	}

	int result = MaxValue[rows-1][columns-1];
	for (int i = 0; i < rows; i++)		//释放二维数组的内存空间
	{
		delete[] MaxValue[i];
	}
	delete MaxValue;
	
	return result;
}

//*********************************************************************************************//
//---------------------------用一维数组存储到达（i,j）的最大礼物价值---------------------------//
//*********************************************************************************************//
int MaxValueOfGift_OneDimension(const int* matrix, const int rows, const int columns)
{
	assert(matrix != nullptr && rows > 0 && columns > 0);

	int* MaxValue = new int[columns];	//建立一个与输入数组列数相等的一维数组用于存放
										//(i,0)-(i,j-1);(i-1,j)-(columns-1,j)每一点的最大礼物价值
	
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
//--------------------------------------------主函数-------------------------------------------//
//*********************************************************************************************//
int main()
{
	//---------------测试用例1：4x4 二维矩阵----------------//
	const int rows1 = 4;
	const int columns1 = 4;
	int matrix1[rows1][columns1] = { {1,10,3,8},{12,2,9,6},{5,7,4,11},{3,7,16,5} };

	int max11 = MaxValueOfGift_TwoDimension((const int*)matrix1, rows1, columns1);
	cout << "礼物的最大价值为：" << max11 << endl;

	int max12 = MaxValueOfGift_OneDimension((const int*)matrix1, rows1, columns1);
	cout << "礼物的最大价值为：" << max12 << endl << endl;

	//---------------测试用例2：1x5 单行矩阵----------------//
	const int rows2 = 1;
	const int columns2 = 5;
	int matrix2[rows2][columns2] = {1,10,3,8,5};

	int max21 = MaxValueOfGift_TwoDimension((const int*)matrix2, rows2, columns2);
	cout << "礼物的最大价值为：" << max21 << endl;

	int max22 = MaxValueOfGift_OneDimension((const int*)matrix2, rows2, columns2);
	cout << "礼物的最大价值为：" << max22 << endl << endl;

	//---------------测试用例3：5x1 单列矩阵----------------//
	const int rows3 = 5;
	const int columns3 = 1;
	int matrix3[rows3][columns3] = { {1},{10},{3},{8},{5} };

	int max31 = MaxValueOfGift_TwoDimension((const int*)matrix3, rows3, columns3);
	cout << "礼物的最大价值为：" << max31 << endl;

	int max32 = MaxValueOfGift_OneDimension((const int*)matrix3, rows3, columns3);
	cout << "礼物的最大价值为：" << max32 << endl << endl;

	//---------------测试用例4：0x0 空矩阵----------------//
	const int rows4 = 0;
	const int columns4 = 0;
	int* matrix4 = nullptr;

	int max41 = MaxValueOfGift_TwoDimension((const int*)matrix4, rows4, columns4);
	cout << "礼物的最大价值为：" << max41 << endl;

	int max42 = MaxValueOfGift_OneDimension((const int*)matrix4, rows4, columns4);
	cout << "礼物的最大价值为：" << max42 << endl << endl;

	return 0;
}