//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题56（二）：数组中唯一只出现一次的数字
// 题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请
// 找出那个吃出现一次的数字。

#include <iostream>
#include <assert.h>
using namespace std;

//**********************************************************************//
//--------------------------找只出现一次的数字--------------------------//
//**********************************************************************//
int FindNumberAppearOnce(int* array, const int length)
{
	assert(array != nullptr && length != 0);		//非法输入

	int* bitSum = new int[32];				//32位辅助数组，用于存储数组元素每一位之和
	int result = 0;							//最终找到的只出现一次的数字

	for (int i = 31; i >= 0; i--)			//遍历数组元素的每一位
	{
		bitSum[i] = 0;						//辅助数组初始化为0
		for (int j = 0; j < length; j++)	//遍历每一个数组元素
		{
			bitSum[i] += (array[j] & 1);	//累加当前为的二进制数字
			array[j] = array[j] >> 1;		//数组元素右移一位
		}
	}

	for (int i = 0; i < 32; i++)			//遍历辅助数组的每一个元素，注意这里的遍历方向和之前的相反
	{
		result = result << 1;				//若数位之和能被3整除，则result的对应位为0，否则对应位为1
		result += bitSum[i] % 3;
	}
	
	delete[] bitSum;
	return result;
}

//**********************************************************************//
//--------------------------------主函数--------------------------------//
int main()
{
	const int length = 8;

	//-----测试用例1：只出现一次数字：3-----//
	int array1[length] = { 1,1,2,2,2,1,3 };
	cout << "只出现一次的数字是：" << FindNumberAppearOnce(array1, length) << endl;

	//-----测试用例2：只出现一次数字：4-----//
	int array2[length] = { 4,3,3,2,2,2,3 };
	cout << "只出现一次的数字是：" << FindNumberAppearOnce(array2, length) << endl;

	//-----测试用例3：只出现一次数字：1023-----//
	int array3[length] = { 1024,-1025,1024,-1025,1024,-1025,1023 };
	cout << "只出现一次的数字是：" << FindNumberAppearOnce(array3, length) << endl;

	//-----测试用例4：只出现一次数字：0-----//
	int array4[length] = { -23, 0, 214, -23, 214, -23, 214 };
	cout << "只出现一次的数字是：" << FindNumberAppearOnce(array4, length) << endl;
	
	//-----测试用例5：只出现一次数字：-3467-----//
	int array5[length] = { 0, -3467, 0, 0, 0, 0, 0, 0 };
	cout << "只出现一次的数字是：" << FindNumberAppearOnce(array5, length) << endl;
		
}