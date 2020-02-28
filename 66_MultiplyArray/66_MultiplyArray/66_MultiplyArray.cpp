//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题66：构建乘积数组
// 题目：给定一个数组A[0, 1, …, n-1]，请构建一个数组B[0, 1, …, n-1]，其
// 中B中的元素B[i] =A[0]×A[1]×… ×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。

#include <iostream>
using namespace std;

//******************************************************************//
//---------------------------构建乘积数组---------------------------//
//******************************************************************//
double* MultiplyArray(double* inputArray, int length)
{
	double* D_Array = new double[length];		//D[i]=A[i+1]*...*A[n-1]
	D_Array[length - 1] = 1;
	for (int i = length - 2; i >= 0; i--)
	{
		D_Array[i] = D_Array[i + 1] * inputArray[i + 1];	//求出矩阵D的各个项
	}

	double* C_Array = new double[length];		//C[i]=A[0]*...*A[i-1]
	C_Array[0] = 1;
	double* B_Array = new double[length];		//B[i] = C[i]*D[i]
	B_Array[0] = D_Array[0];
	for (int j = 1; j <= length - 1; j++)		//求出矩阵B和C的各个项
	{
		C_Array[j] = C_Array[j - 1] * inputArray[j - 1];
		B_Array[j] = C_Array[j] * D_Array[j];
	}
	return B_Array;
}

//******************************************************************//
//------------------------------主函数------------------------------//
//******************************************************************//
int main()
{
	int length = 5;
	double* A_Array = new double[length];
	for (int i = 0; i < length; i++)
	{
		A_Array[i] = i + 1;
	}
	double* B_Array = MultiplyArray(A_Array, length);

	for (int j = 0; j < length; j++)
	{
		cout << B_Array[j] << "\t";
	}
	return 0;
}