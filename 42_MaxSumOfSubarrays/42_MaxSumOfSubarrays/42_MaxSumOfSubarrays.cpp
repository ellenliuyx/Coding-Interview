#include <iostream>
#include <assert.h>
using namespace std;

int FindMaxSumOfSubarray(int* numbers, int length)
{
	assert(numbers != nullptr && length != 0);

	int currentSum = 0, maxSum = 0;
	for (int i = 0; i < length; i++)
	{
		currentSum += numbers[i];

		if (currentSum < 0)
		{
			maxSum = 0;
			currentSum = 0;
		}
		else
		{
			if (currentSum > maxSum)
			{
				maxSum = currentSum;
			}
		}
	}
	return maxSum;
}

void PrintArray(int* numbers, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << numbers[i] << "\t";
	}
	cout << endl;
}
int main()
{
	const int length = 8;
	int numbers[length] = { 1,-2,3,10,-4,7,2,-5 };
	cout << "输入数组为：" << endl;
	PrintArray(numbers, length);
	int maxSum = FindMaxSumOfSubarray(numbers, length);
	cout << "连续子数组的最大和为：" << maxSum << endl;

	return 0;
}