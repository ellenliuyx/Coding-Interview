//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。

#include <iostream>
using namespace std;

//Find函数，寻找二维数组中是否含有某元素值
//输入：MatrixInput(二维数组), Row(行数), Column(列数), duplication(待查元素值)
//返回值：result(含有此元素返回1，否则返回0)
bool Find(int ** matrix, int row, int column, int dup)
{
	//判断输入的二维数组是否为空
	if(matrix == nullptr || row == 0 || column == 0)
	{
		cout << "输入的数组为空" << endl;
		return false;
	}

	//检查数组中是否包含某个元素
	int row_index = 0, column_index = column - 1;		//二维数组的右上角元素的行列下标
	while ((row_index < row) && (column_index >= 0))	//检索到二维数组的最左下角元素时，停止循环
	{
		if (matrix[row_index][column_index] == dup)		//若右上角元素与dup相等，则数组中包含dup
		{
			cout << "数组中包含此整数" << endl;
			return true;
		}
		else if (matrix[row_index][column_index] > dup)	//若右上角元素大于dup，则剔除最右列
		{
			column_index--;
		}
		else											//若右上角元素小于dup，则剔除最上行
		{
			row_index++;
		}
	}
	cout << "数组中不含此整数" << endl;
	return false;
}

int main()
{
	//键盘输入二维数组的行数和列数
	int Row, Column;
	cout << "请输入二维数组的行数和列数:" << endl;
	cin >> Row >> Column;

	//根据行数和列数动态创建并初始化二维数组
	int** MatrixInput = (int**)malloc(sizeof(int*) * Row);
	for (int i = 0; i < Row; i++)
	{
		MatrixInput[i] = (int*)malloc(sizeof(int) * Column);
		cout << "请输入二维数组的第" << i+1 << "行元素：" << endl;
		for (int j = 0; j < Column; j++)
		{
			cin >> MatrixInput[i][j];	//初始化二维数组的一行
		}
	}
	
	//键盘输入需要查找的整数
	bool result = false;
	int duplication;
	cout << "请输入需要查找的元素:" << endl;
	cin >> duplication;

	//调用Find函数
	result = Find(MatrixInput, Row, Column, duplication);
	
	//释放二维数组内存空间
	for (int i = 0; i < Row; i++)
	{
		free(MatrixInput[i]);
	}
	free(MatrixInput);

	return 0;
}