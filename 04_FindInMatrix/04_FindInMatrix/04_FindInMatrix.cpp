//==================================================================
// ����ָOffer������
//==================================================================

// ������4����ά�����еĲ���
// ��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж���
// �մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��
// �������ж��������Ƿ��и�������

#include <iostream>
using namespace std;

//Find������Ѱ�Ҷ�ά�������Ƿ���ĳԪ��ֵ
//���룺MatrixInput(��ά����), Row(����), Column(����), duplication(����Ԫ��ֵ)
//����ֵ��result(���д�Ԫ�ط���1�����򷵻�0)
bool Find(int ** matrix, int row, int column, int dup)
{
	//�ж�����Ķ�ά�����Ƿ�Ϊ��
	if(matrix == nullptr || row == 0 || column == 0)
	{
		cout << "���������Ϊ��" << endl;
		return false;
	}

	//����������Ƿ����ĳ��Ԫ��
	int row_index = 0, column_index = column - 1;		//��ά��������Ͻ�Ԫ�ص������±�
	while ((row_index < row) && (column_index >= 0))	//��������ά����������½�Ԫ��ʱ��ֹͣѭ��
	{
		if (matrix[row_index][column_index] == dup)		//�����Ͻ�Ԫ����dup��ȣ��������а���dup
		{
			cout << "�����а���������" << endl;
			return true;
		}
		else if (matrix[row_index][column_index] > dup)	//�����Ͻ�Ԫ�ش���dup�����޳�������
		{
			column_index--;
		}
		else											//�����Ͻ�Ԫ��С��dup�����޳�������
		{
			row_index++;
		}
	}
	cout << "�����в���������" << endl;
	return false;
}

int main()
{
	//���������ά���������������
	int Row, Column;
	cout << "�������ά���������������:" << endl;
	cin >> Row >> Column;

	//����������������̬��������ʼ����ά����
	int** MatrixInput = (int**)malloc(sizeof(int*) * Row);
	for (int i = 0; i < Row; i++)
	{
		MatrixInput[i] = (int*)malloc(sizeof(int) * Column);
		cout << "�������ά����ĵ�" << i+1 << "��Ԫ�أ�" << endl;
		for (int j = 0; j < Column; j++)
		{
			cin >> MatrixInput[i][j];	//��ʼ����ά�����һ��
		}
	}
	
	//����������Ҫ���ҵ�����
	bool result = false;
	int duplication;
	cout << "��������Ҫ���ҵ�Ԫ��:" << endl;
	cin >> duplication;

	//����Find����
	result = Find(MatrixInput, Row, Column, duplication);
	
	//�ͷŶ�ά�����ڴ�ռ�
	for (int i = 0; i < Row; i++)
	{
		free(MatrixInput[i]);
	}
	free(MatrixInput);

	return 0;
}