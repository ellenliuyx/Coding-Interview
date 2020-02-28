//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

#include <string.h>
#include <iostream>
using namespace std;

//********************************************************************************************//
//-----------------------------------求一个数字的数位之和-------------------------------------//
//********************************************************************************************//
int GetDigitSum(int n)
{
	int sum = 0;
	while (n != 0)			//从个位往前逐个数位剥离，直至某一数位为0
	{
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}

//********************************************************************************************//
//--------------------------------------机器人移动函数----------------------------------------//
//********************************************************************************************//
int RobotMove(int rows, int columns, int row_idx, int col_idx, int k, bool* visited)
{
	int count = 0;										//机器人能够到达的格子数
	int matrix_idx = row_idx * columns + col_idx;		//二维数组中当前元素的索引

	if (row_idx >= 0 && row_idx < rows && col_idx >= 0 && col_idx < columns 
		&& GetDigitSum(row_idx) + GetDigitSum(col_idx) <= k && visited[matrix_idx] == 0)	//判断机器人能否进入当前格子
	{
		//若能进入，访问标志置1；count为上下左右的count之和再加1
		visited[matrix_idx] = 1;
		count = 1 + RobotMove(rows, columns, row_idx + 1, col_idx, k, visited)
				  + RobotMove(rows, columns, row_idx - 1, col_idx, k, visited)
		          + RobotMove(rows, columns, row_idx, col_idx + 1, k, visited)
				  + RobotMove(rows, columns, row_idx, col_idx - 1, k, visited);
		cout << "当前位置：[" << row_idx << "," << col_idx << "], count = " << count << endl;
	}
	
	return count;
}

//********************************************************************************************//
//------------------------------------------主函数--------------------------------------------//
//********************************************************************************************//
int main()
{
	int rows = 4, columns = 4, k = 3;

	if (rows < 0 || columns < 0 || k < 0)		//非法输入判断
	{
		throw new exception("Invalid input");
	}

	bool* visited = new bool[rows * columns];	//访问标志数组
	memset(visited, 0, rows * columns);

	int count = RobotMove(rows, columns, 0, 0, k, visited);		//机器人从（0，0）开始移动
	cout << "方格大小为：" << rows << " * " << columns << endl;
	cout << "k = " << k << endl;
	cout << "机器人能到达 " << count << " 个格子" << endl;

	delete[] visited;

	return count;
}