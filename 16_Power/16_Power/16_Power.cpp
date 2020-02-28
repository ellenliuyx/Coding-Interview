//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。

#include <iostream>
using namespace std;

//**********************************************************************************************//
//------------------------------传统循环方法求整数的无符号整数次方------------------------------//
//**********************************************************************************************//
double Power_traditional_unsigned(int base, int exponent)
{
	double result = 1.0;

	for (int i = 0; i < exponent; i++)
	{
		result *= base;
	}
	
	return result;
}

//**********************************************************************************************//
//---------------------------利用公式的高效方法求整数的无符号整数次方---------------------------//
//**********************************************************************************************//
double Power_efficient_unsigned(int base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = Power_efficient_unsigned(base, exponent >> 1);		//用右移运算代替除2

	result *= result;		//当指数为偶数时，a^n = a^(n/2) * a^(n/2)

	if (exponent & 1)		//用按位与运算代替求余%
	{
		result *= base;		//当指数为奇数时，a^n = a^((n-1)/2) * a^((n-1)/2) * a
	}

	return result;
}

//**********************************************************************************************//
//---------------------------------------求整数的整数次方---------------------------------------//
//输入：int base为输入底数，int exponent()为输入指数，double (*Power_unsigned)(int,int)为函数指针
//**********************************************************************************************//
double Power(int base, int exponent, double (*Power_unsigned)(int,int))
{
	if (exponent >= 0)		//若指数大于0，直接返回Power_unsigned的计算结果
	{
		return Power_unsigned(base, exponent);
	}
	if (exponent < 0)
	{
		if (base == 0)		//若指数小于0，且底数为0，非法输入
		{
			cout << "Invalid input!" << endl;
			throw new exception("Invalid input!");
		}
		return 1.0 / Power_unsigned(base, abs(exponent));		//若指数小于0，返回Power_unsigned的倒数
	}
}

//**********************************************************************************************//
//--------------------------------------------主函数--------------------------------------------//
//---测试用例1：base = 2, exponent = 3;
//---测试用例2：base = 2, exponent = 0;
//---测试用例3：base = 0, exponent = 0; （无意义，输出0或1均可）
//---测试用例4：base = 0, exponent = -1; （非法输入，0不能为除数）
//**********************************************************************************************//
int main()
{
	int base, exponent;
	double result1, result2;

	while (1)
	{
		cout << "请输入底数:" << endl;
		cin >> base;
		cout << "请输入指数:" << endl;
		cin >> exponent;

		result1 = Power(base, exponent, &Power_traditional_unsigned);	//在函数指针参数位置传入函数的地址
		result2 = Power(base, exponent, &Power_efficient_unsigned);

		cout << "库函数 pow() 得到的结果为：" << pow(base, exponent) << endl;
		cout << "Power_traditonal 得到的结果为：" << result1 << endl;
		cout << "Power_efficient 得到的结果为：" << result2 << endl;
		cout << endl;
	}

	return 0;
}