//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

#include <iostream>
#include <assert.h>
using namespace std;

//*******************************************************************//
//---------------从低位至高位找到value中第一个是1的位----------------//
//*******************************************************************//
int FindFirstOne(int value)
{
	int FirstOneBit = 0;			//第一个为1的数位

	//当前位不为1，且当前位小于int的最高位32
	while (((value & 1) == 0) && (FirstOneBit < 8 * sizeof(int)))
	{
		value = value >> 1;		//value右移一位
		FirstOneBit++;			//位数计数器加一
	}
	return FirstOneBit;
}

//*******************************************************************//
//-------------------在数组中找到两个只出现一次的数------------------//
//*******************************************************************//
void FindNumbersAppearOnce(int* array, const int length)
{
	assert(array != nullptr && length != 0);

	int NorResult = 0;					//数组依次异或的结果，初始化为0，0和任何数异或均为该数本身
	for (int i = 0; i < length; i++)	
	{
		NorResult ^= array[i];			//数组依次异或
	}

	int FirstOneBit = FindFirstOne(NorResult);		//找到数组异或结果中的第一个为1的位：FirstOneBit

	int num1 = 0, num2 = 0;				//只出现一次的两个数
	for (int i = 0; i < length; i++)	//遍历数组
	{
		if (((array[i] >> FirstOneBit) & 1) == 1)	//若FirstOneBit位为1，则分到子数组1，并进行依次异或
			num1 ^= array[i];
		else										//若FirstOneBit位为0，则分到子数组2，并进行依次异或
			num2 ^= array[i];
	}
	//打印输出两个数字
	cout << "数组中只出现一次的两个数字是：" << num1 << " 和 " << num2 << endl;
}

//*******************************************************************//
//------------------------------主函数-------------------------------//
//*******************************************************************//
int main()
{
	//-------测试用例1：有多对不同的重复数字-------//
	const int length1 = 8;
	int array1[length1] = { 2,4,3,6,3,2,5,5 };
	FindNumbersAppearOnce(array1, length1);

	//-------测试用例2：没有重复数字-------//
	const int length2 = 2;
	int array2[length2] = { 1,2 };
	FindNumbersAppearOnce(array2, length2);

	//-------测试用例3：有多对相同的重复数字-------//
	const int length3 = 6;
	int array3[length3] = { 3,4,1,1,1,1 };
	FindNumbersAppearOnce(array3, length3);
}