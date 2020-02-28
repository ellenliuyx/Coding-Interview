//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。

#include <iostream>
#include <assert.h>
using namespace std;

//**********************************************************************//
//--------------------------求三个数中的最小数--------------------------//
//**********************************************************************//
int min(int num1, int num2, int num3)
{
	int temp = num1 < num2 ? num1 : num2;
	return temp < num3 ? temp : num3;
}

//**********************************************************************//
//-----------------------------求第N个丑数------------------------------//
//**********************************************************************//
int TheNthUglyNumber(int index)
{
	assert(index > 0);

	int* UglyNumber = new int[index];		//用来存前index个丑数

	UglyNumber[0] = 1;						//第一个丑数是1

	int pos_2 = 0, pos_3 = 0, pos_5 = 0;	//*2 *3 *5后得到新丑数的原丑数位置（T2 T3 T5）

	for (int i = 0; i < index - 1; i++)		//从0到index计算下一个丑数
	{
		int MaxUglyNumber = UglyNumber[i];				//目前最大的丑数
		while (UglyNumber[pos_2]*2 <= MaxUglyNumber)	//从pos_2的位置开始*2，直到超过MaxUglyNumber，更新pos_2
			pos_2++;
		while (UglyNumber[pos_3]*3 <= MaxUglyNumber)	//从pos_3的位置开始*3，直到超过MaxUglyNumber，更新pos_3
			pos_3++;
		while (UglyNumber[pos_5]*5 <= MaxUglyNumber)	//从pos_5的位置开始*5，直到超过MaxUglyNumber，更新pos_5
			pos_5++;

		//将M2 M3 M5的最小值当作下一个丑数
		int nextUglyNumber = min(UglyNumber[pos_2]*2, UglyNumber[pos_3]*3, UglyNumber[pos_5]*5);
		UglyNumber[i + 1] = nextUglyNumber;
	}

	int result = UglyNumber[index - 1];		//输出最后一个丑数
	delete[] UglyNumber;

	return result;
}

//**********************************************************************//
//--------------------------------主函数--------------------------------//
//**********************************************************************//
int main()
{
	//----------测试用例1：1-----------//
	int index1 = 1;
	cout << "第 "<< index1 << " 个丑数是：" << TheNthUglyNumber(index1) << endl;

	//----------测试用例2：3-----------//
	int index2 = 3;
	cout << "第 " << index2 << " 个丑数是：" << TheNthUglyNumber(index2) << endl;

	//----------测试用例3：5-----------//
	int index3 = 5;
	cout << "第 " << index3 << " 个丑数是：" << TheNthUglyNumber(index3) << endl;

	//----------测试用例4：8-----------//
	int index4 = 7;
	cout << "第 " << index4 << " 个丑数是：" << TheNthUglyNumber(index4) << endl;

	//----------测试用例5：10-----------//
	int index5 = 9;
	cout << "第 " << index5 << " 个丑数是：" << TheNthUglyNumber(index5) << endl;

	//----------测试用例6：15-----------//
	int index6 = 11;
	cout << "第 " << index6 << " 个丑数是：" << TheNthUglyNumber(index6) << endl;

	//----------测试用例7：859963392-----------//
	int index7 = 1500;
	cout << "第 " << index7 << " 个丑数是：" << TheNthUglyNumber(index7) << endl;

	return 0;
}