//==================================================================
// ����ָOffer������
//==================================================================

// ������3�����������޸������ҳ��ظ�������
// ��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
// ����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
// ���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
// ������ظ�������2����3��

#include <iostream>
#include <math.h>
using namespace std;

bool duplicate_noedit(int arrayinput[], int len, int* duplication)
{
	//�ж����������Ƿ�Ϊ��
	if (arrayinput == nullptr)
	{
		cout << "��������Ϊ��" << endl;
		return false;
	}

	//�ж����������Ƿ�Ϸ�: �Ƿ��������ֶ���1��n�ķ�Χ��
	for (int i = 0; i < len; i++)
	{
		if (arrayinput[i]<1 || arrayinput[i]>(len - 1))
		{
			cout << "���������ֵ�Ƿ�" << endl;
			return false;
		}
	}

	//�ҳ��ظ�������
	int begin = 1, end = len - 1;				//���ַ�������ʼ�����ֹ��
	int middle = floor((end + begin) / 2);		//�����е㣨����ȡ����
	int count_i = middle - begin + 1;			//�����������ظ������Ԫ�ظ�����������Ϊ1-n����count_iӦΪn��
	int count_r = 0;							//������������ͳ��������ʵ���е�Ԫ�ظ���
	while (end > begin)							//��end<=beginʱ��ֹͣ����ѭ��
	{
		//������������ͳ��ֵ��[begin,middle]�����ڵ�Ԫ�ظ���count_r
		for (int i = 0; i < len; i++)
		{
			if (arrayinput[i] >= begin && arrayinput[i] <= middle)
			{
				count_r++;
			}
		}
		//��count_r > count_i,��[begin,middle]�����ں����ظ�Ԫ�أ�����[middle,end]�����ں����ظ�Ԫ��
		if (count_r > count_i)
		{
			end = middle;
		}
		else 
		{
			begin = middle + 1;
		}
		//������С����ע���䳤��
		middle = floor((end + begin) / 2);
		count_i = middle - begin + 1;
		count_r = 0;
	}
	//begin=end����ѭ��ʱ���ظ���Ԫ�ؼ�Ϊbegin
	*duplication = begin;
	cout << "�ظ���Ԫ��Ϊ:" << begin << endl;
	return true;
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
		result = duplicate_noedit(arraytest, number, &duplication);
	}
	free(arraytest);
	return 0;
}