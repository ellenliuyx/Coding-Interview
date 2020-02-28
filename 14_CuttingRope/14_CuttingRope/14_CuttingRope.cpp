//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
// 每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
// 积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
// 时得到最大的乘积18。

#include <iostream>
using namespace std;

//*****************************************************************************************//
//------------------------------------动态规划剪绳子---------------------------------------//
//*****************************************************************************************//
int CuttingRope_Dynamic(int RopeLength)
{
	//当n<4时的情况
	if (RopeLength < 2)	 return 0;
	if (RopeLength == 2) return 1;
	if (RopeLength == 3) return 2;

	//建立长度为 RopeLength + 1 的数组存储绳子长度为 0-RopeLength 的最大乘积
	int* MaxProduct = new int[RopeLength + 1];

	//直接初始化绳子长度为 0-3 的最大乘积
	MaxProduct[0] = 0;
	MaxProduct[1] = 1;
	MaxProduct[2] = 2;
	MaxProduct[3] = 3;

	int max = 0;

	for (int i = 4; i <= RopeLength; i++)		//分别计算绳子长度为 4-RopeLength 的最大乘积
	{
		int max = 0;
		for (int j = 1; j <= i / 2; j++)		//比较各种组合的剪绳子（剪1刀）方法，求出最大乘积
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
//------------------------------------贪婪策略剪绳子---------------------------------------//
//*****************************************************************************************//
int CuttingRope_Greedy(int RopeLength)
{
	//思想：当n>=5时，尽可能多的剪长度为3的绳子，当剩下的长度为4时，剪成两段长度为2的绳子

	int timeof3 = 0;		//剪成的长度为3的绳子数量
	int MaxProduct = 0;		//存储最大乘积

	//当n<4时的情况
	if (RopeLength < 2)	 return 0;
	if (RopeLength == 2) return 1;
	if (RopeLength == 3) return 2;

	//绳子长度除3余1，需要将最后的长度为4的绳子剪成2*2
	if (RopeLength % 3 == 1)
	{
		timeof3 = RopeLength / 3 - 1;
		MaxProduct = pow(3, timeof3) * 2 * 2;
	}

	//绳子长度除3余2，最后剩下的绳子长度为2
	if (RopeLength % 3 == 2)
	{
		timeof3 = RopeLength / 3;
		MaxProduct = pow(3, timeof3) * 2;
	}

	//绳子长度除3余0，正好全部剪成长度为3的绳子
	if (RopeLength % 3 == 0)
	{
		timeof3 = RopeLength / 3;
		MaxProduct = pow(3, timeof3);
	}

	return MaxProduct;
}

//*****************************************************************************************//
//----------------------------------------主函数-------------------------------------------//
//*****************************************************************************************//
int main()
{
	int RopeLength, MaxProduct_Dynamic, MaxProduct_Greedy;
	while (1)
	{
		cout << "请输入绳子总长度：" << endl;
		cin >> RopeLength;

		if (RopeLength < 0)			//当输入绳子长度小于0时，跳出while(1)循环
			break;

		MaxProduct_Dynamic = CuttingRope_Dynamic(RopeLength);	//用动态规划剪绳子
		MaxProduct_Greedy = CuttingRope_Greedy(RopeLength);		//用贪婪策略剪绳子

		cout << "（动态规划）绳子段长度的最大乘积为：" << MaxProduct_Dynamic << endl;
		cout << "（贪婪算法）绳子段长度的最大乘积为：" << MaxProduct_Greedy <<endl;
	}
}