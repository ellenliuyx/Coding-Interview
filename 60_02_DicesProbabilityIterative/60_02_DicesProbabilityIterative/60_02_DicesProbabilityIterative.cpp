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
//-------------------------骰子类（循环实现）-------------------------//
//********************************************************************//
class Dices
{
public:
	int DicesNumber;		//骰子的个数

	Dices(int number)		//带参数的构造函数
	{
		assert(number > 0);
		DicesNumber = number;					//用参数初始化骰子个数
		int length = 6 * DicesNumber + 1;		//每一步点数之和的可能结果个数（下标为0的元素空置不用）
		AppearTimes[0] = new int[length];		//两个数组交替存储每多一个骰子点数之和出现次数
		AppearTimes[1] = new int[length];
		for (int i = 0; i < length; i++)
		{
			AppearTimes[0][i] = 0;		//数组初始化
			AppearTimes[1][i] = 0;		//数组初始化
		}
	}

	~Dices()				//析构函数
	{
		delete[] AppearTimes[0];
		delete[] AppearTimes[1];
	}

	void PrintProbability()		//打印概率函数
	{
		int flag = 0;			//标志位——用哪个数组存储点出之和出现的次数
		SumProbability(DicesNumber, flag, AppearTimes);		//计算每一个和的出现次数

		for (int i = 0; i < 5 * DicesNumber + 1; i++)
		{
			cout << "s = " << i + DicesNumber << "\t" << "prob = " << AppearTimes[!flag][i + DicesNumber] / pow(6, DicesNumber) << endl;
		}
	}

private:
	int* AppearTimes[2];		//出现次数统计数组

	void SumProbability(int number, int& flag, int** AppearTimes)		//计算每一个和的出现次数
	{
		for (int i = 1; i <= 6; i++)		//只有一个骰子时，点数之和为1-6出现的次数均为1
		{
			AppearTimes[flag][i]++;
		}
		flag = !flag;						//交换记录点数之和的数组

		for (int j = 2; j <= number; j++)	//当骰子数目从2增加到DicesNumber时
		{
			for (int p = j; p <= j * 6; p++)	//p为可能出现的点数之和，当j=2时，p取值范围2~12
			{
				for (int k = p - 6; k <= p - 1; k++)	//将上一步点数之和为p-6~p-1的出现次数相加
				{
					if (k > 0)					//若上一步的点数之和大于0
					{
						AppearTimes[flag][p] += AppearTimes[!flag][k];
					}
				}
			}
			flag = !flag;						//交换记录点数之和的数组
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