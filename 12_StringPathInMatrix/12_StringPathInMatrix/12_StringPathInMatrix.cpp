//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
// 字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
// 上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
// 该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
// 母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
// 字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
// A B T G
// C F C S
// J D E H

#include <string.h>
#include <iostream>
#include <exception>
using namespace std;

//*******************************************************************************************//
//-------------------------------------打印矩阵中的元素--------------------------------------//
//*******************************************************************************************//
void PrintMatrix(bool* m, int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			cout << m[i*columns+j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

//*******************************************************************************************//
//----------------------------回溯法从某一点开始寻找矩阵中的路径-----------------------------//
//输入：matrix（输入矩阵）, rows（总行数）, columns（总列数）, 
//      row_idx（现在走到第几行）, col_idx（现在走到第几列）, 
//      str（输入字符串）, str_idx（现在走到字符串的第几个位置）, visited（访问过的标记）
//返回值：当前位置是否可行
//*******************************************************************************************//
bool FindPathCore(char* matrix, int rows, int columns, int row_idx, int col_idx, char* str, int str_idx, bool* visited)
{
	int matrix_idx = row_idx * columns + col_idx;	//二维数组的顺序存储

	//当行列超限、当前数组元素与字符串元素不等、该点已经访问过时，返回false
	if (row_idx < 0 || row_idx >= rows || col_idx < 0 || col_idx >= columns || matrix[matrix_idx] != str[str_idx] || visited[matrix_idx] == 1)
		return false;

	//否则，访问过标记置1
	visited[matrix_idx] = 1;

	//若当前元素已经是字符串的最后一个有效元素，返回true
	if (str[str_idx + 1] == '\0')
	{
		cout << "[" << row_idx << "," << col_idx << "] " << matrix[matrix_idx] << "可行" << endl;
		return true;
	}

	//统计当前位置的上下左右四个方向是否可行（与字符串下一个元素相等）
	bool results[4] = { 0,0,0,0 };
	results[0] = FindPathCore(matrix, rows, columns, row_idx + 1, col_idx, str, str_idx + 1, visited);
	results[1] = FindPathCore(matrix, rows, columns, row_idx, col_idx + 1, str, str_idx + 1, visited);
	results[2] = FindPathCore(matrix, rows, columns, row_idx - 1, col_idx, str, str_idx + 1, visited);
	results[3] = FindPathCore(matrix, rows, columns, row_idx, col_idx - 1, str, str_idx + 1, visited);

	//若有一个方向可行，返回true
	if (results[0] || results[1] || results[2] || results[3])
	{
		cout << "[" << row_idx << "," << col_idx << "] " << matrix[matrix_idx] << "可行" << endl;
		return true;
	}

	//否则，访问过标记置0，字符串当前位置减1
	visited[matrix_idx] = 0;
	str_idx--;
	cout << "[" << row_idx << "," << col_idx << "] " << matrix[matrix_idx] << "不可行" << endl;
	return false;

}

//*******************************************************************************************//
//--------------------------------从矩阵的某一点开始寻找路径---------------------------------//
//*******************************************************************************************//
bool FindPath(char* matrix, int rows, int columns, char* str)
{
	if (matrix == nullptr || rows <= 0 || columns <= 0 || str == nullptr)	//非法输入
	{
		throw new exception("Invalid input");
		return false;
	}
		
	//建立访问矩阵visited，大小与输入矩阵相同。若值为1，则代表该点已被访问过；若值为0，则未被访问过
	bool* visited = new bool[rows * columns];
	memset(visited, 0, rows * columns);

	//遍历输入矩阵，从每一点开始试图寻找字符串对应的路径
	for (int row_idx = 0; row_idx < rows; row_idx++)
	{
		for (int col_idx = 0; col_idx < columns; col_idx++)
		{
			cout << "寻找从 [" << row_idx << ","<< col_idx << "] "<< matrix[row_idx, col_idx] << "开始的路径" << endl;
			if (FindPathCore(matrix, rows, columns, row_idx, col_idx, str, 0, visited))
			{
				cout << "访问过的路径为：" << endl;
				PrintMatrix(visited, rows, columns);
				return true;
			}
		}
	}
	delete[] visited;

	return false;
}

int main()
{
	int rows = 3, columns = 4;
	char matrix[] = "abtgcfcsjdeh";
	//char str[13] = "abtgscfcjdeh";
	//char str[5] = "abfb";
	char str[5] = "bfce";
	bool result = FindPath(matrix, rows, columns, str);
	if (result)
		cout << "矩阵包含此字符串路径" << endl;
	else 
		cout << "矩阵不含此字符串路径" << endl;

	return 0;
}