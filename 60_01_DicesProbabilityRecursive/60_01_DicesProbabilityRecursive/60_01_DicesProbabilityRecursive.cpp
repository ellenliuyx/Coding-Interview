//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
// 的所有可能的值出现的概率。

#include <iostream>
#include <assert.h>
using namespace std;

//********************************************************************//
//-------------------------骰子类（递归实现）-------------------------//
//********************************************************************//
class Dices
{
public:
	int DicesNumber;		//骰子的个数

	Dices(int number)		//带参数的构造函数
	{
		assert(number > 0);
		DicesNumber = number;		//用参数初始化骰子个数
		int length = 5 * number + 1;		//点数之和的可能结果个数
		AppearTimes = new int[length];		//存储点数之和出现次数的数组
		for (int i = 0; i < length; i++)
		{
			AppearTimes[i] = 0;		//数组初始化
		}
	}

	~Dices()				//析构函数
	{
		delete[] AppearTimes;
	}

	void PrintProbability()		//打印概率函数
	{
		int currentSum = 0;
		SumProbability(DicesNumber, currentSum, AppearTimes);		//计算每一个和的出现次数

		for (int i = 0; i < 5 * DicesNumber + 1; i++)
		{
			cout << "s = " << i + DicesNumber << "\t" << "prob = " << AppearTimes[i] / pow(6, DicesNumber) << endl;
		}
	}

private:
	int* AppearTimes;		//出现次数统计数组

	void SumProbability(int number, int& currentSum, int* AppearTimes)		//计算每一个和的出现次数
	{
		if (number == 0)		//当所有n的骰子全部加完时
		{
			int index = currentSum - DicesNumber;		//更新AppearTimes矩阵的对应元素
			AppearTimes[index]++;
			return;
		}

		for (int i = 1; i <= 6; i++)
		{
			currentSum += i;		//加上当前骰子的值
			SumProbability(number - 1, currentSum, AppearTimes);
			currentSum -= i;		//减去当前骰子的值，准备加下一个
		}
	}
};

//********************************************************************//
//-------------------------------主函数-------------------------------//
//********************************************************************//
int main()
{
	Dices dices(10);
	dices.PrintProbability();
}