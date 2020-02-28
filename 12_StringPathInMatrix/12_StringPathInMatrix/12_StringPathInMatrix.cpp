//==================================================================
// ����ָOffer������
//==================================================================

// ������12�������е�·��
// ��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
// �ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
// �ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
// �ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
// ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
// �ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
// A B T G
// C F C S
// J D E H

#include <string.h>
#include <iostream>
#include <exception>
using namespace std;

//*******************************************************************************************//
//-------------------------------------��ӡ�����е�Ԫ��--------------------------------------//
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
//----------------------------���ݷ���ĳһ�㿪ʼѰ�Ҿ����е�·��-----------------------------//
//���룺matrix���������, rows����������, columns����������, 
//      row_idx�������ߵ��ڼ��У�, col_idx�������ߵ��ڼ��У�, 
//      str�������ַ�����, str_idx�������ߵ��ַ����ĵڼ���λ�ã�, visited�����ʹ��ı�ǣ�
//����ֵ����ǰλ���Ƿ����
//*******************************************************************************************//
bool FindPathCore(char* matrix, int rows, int columns, int row_idx, int col_idx, char* str, int str_idx, bool* visited)
{
	int matrix_idx = row_idx * columns + col_idx;	//��ά�����˳��洢

	//�����г��ޡ���ǰ����Ԫ�����ַ���Ԫ�ز��ȡ��õ��Ѿ����ʹ�ʱ������false
	if (row_idx < 0 || row_idx >= rows || col_idx < 0 || col_idx >= columns || matrix[matrix_idx] != str[str_idx] || visited[matrix_idx] == 1)
		return false;

	//���򣬷��ʹ������1
	visited[matrix_idx] = 1;

	//����ǰԪ���Ѿ����ַ��������һ����ЧԪ�أ�����true
	if (str[str_idx + 1] == '\0')
	{
		cout << "[" << row_idx << "," << col_idx << "] " << matrix[matrix_idx] << "����" << endl;
		return true;
	}

	//ͳ�Ƶ�ǰλ�õ����������ĸ������Ƿ���У����ַ�����һ��Ԫ����ȣ�
	bool results[4] = { 0,0,0,0 };
	results[0] = FindPathCore(matrix, rows, columns, row_idx + 1, col_idx, str, str_idx + 1, visited);
	results[1] = FindPathCore(matrix, rows, columns, row_idx, col_idx + 1, str, str_idx + 1, visited);
	results[2] = FindPathCore(matrix, rows, columns, row_idx - 1, col_idx, str, str_idx + 1, visited);
	results[3] = FindPathCore(matrix, rows, columns, row_idx, col_idx - 1, str, str_idx + 1, visited);

	//����һ��������У�����true
	if (results[0] || results[1] || results[2] || results[3])
	{
		cout << "[" << row_idx << "," << col_idx << "] " << matrix[matrix_idx] << "����" << endl;
		return true;
	}

	//���򣬷��ʹ������0���ַ�����ǰλ�ü�1
	visited[matrix_idx] = 0;
	str_idx--;
	cout << "[" << row_idx << "," << col_idx << "] " << matrix[matrix_idx] << "������" << endl;
	return false;

}

//*******************************************************************************************//
//--------------------------------�Ӿ����ĳһ�㿪ʼѰ��·��---------------------------------//
//*******************************************************************************************//
bool FindPath(char* matrix, int rows, int columns, char* str)
{
	if (matrix == nullptr || rows <= 0 || columns <= 0 || str == nullptr)	//�Ƿ�����
	{
		throw new exception("Invalid input");
		return false;
	}
		
	//�������ʾ���visited����С�����������ͬ����ֵΪ1�������õ��ѱ����ʹ�����ֵΪ0����δ�����ʹ�
	bool* visited = new bool[rows * columns];
	memset(visited, 0, rows * columns);

	//����������󣬴�ÿһ�㿪ʼ��ͼѰ���ַ�����Ӧ��·��
	for (int row_idx = 0; row_idx < rows; row_idx++)
	{
		for (int col_idx = 0; col_idx < columns; col_idx++)
		{
			cout << "Ѱ�Ҵ� [" << row_idx << ","<< col_idx << "] "<< matrix[row_idx, col_idx] << "��ʼ��·��" << endl;
			if (FindPathCore(matrix, rows, columns, row_idx, col_idx, str, 0, visited))
			{
				cout << "���ʹ���·��Ϊ��" << endl;
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
		cout << "����������ַ���·��" << endl;
	else 
		cout << "���󲻺����ַ���·��" << endl;

	return 0;
}