//==================================================================
// ����ָOffer������
//==================================================================

// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��

#include <iostream>
using namespace std;

bool duplicate(int arrayinput[], int len, int* duplication)
{
	//�ж����������Ƿ�Ϊ��
	if (arrayinput == nullptr)
	{
		cout << "��������Ϊ��" << endl;
		return false;
	}
	
	//�ж����������Ƿ�Ϸ�: �Ƿ��������ֶ���0��n-1�ķ�Χ��
	for (int i = 0; i < len; i++)
	{
		if (arrayinput[i]<0 || arrayinput[i]>(len - 1))
		{
			cout << "���������ֵ�Ƿ�" << endl;
			return false;
		}
	}

	//�ҳ��ظ�������
	for (int i = 0; i < len; i++)
	{
		while(arrayinput[i] != i)
		{
			if(arrayinput[i] != arrayinput[arrayinput[i]])
				swap(arrayinput[i], arrayinput[arrayinput[i]]);
			else
			{
				*duplication = arrayinput[i];		//ָ����ʽ��Ϊ�������
				cout << "�ҵ��ظ����֣�" << *duplication << endl;
				return true;
			}		
		}
	}

	return false;
}

int main()
{
	bool result = 0;
	int number, duplication;
	cout << "�����������Ԫ�ظ���:" << endl;
	cin >> number;
	int* arraytest = (int*)malloc(sizeof(int) * number);	//����Ԫ�ظ�����̬��������
	while (!result)
	{
		cout << "������" << number << "����:" << endl;
		for (int i = 0; i < number; i++)
		{
			cin >> arraytest[i];
		}
		result = duplicate(arraytest, number, &duplication);	
	}
	free(arraytest);
	return 0;
}