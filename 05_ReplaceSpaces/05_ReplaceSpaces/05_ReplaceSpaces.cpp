//==================================================================
// ����ָOffer������
//==================================================================

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����

#include <stdio.h>			//printf������ͷ�ļ�

//���룺String(����ԭ�ַ���)�� SpaceLen(���õ��ڴ�ռ�)
void ReplaceSpaces(char String[], int SpaceLen)
{
	int length = 0;		//ԭ�ַ�������
	int length_after = 0;	//���ַ�������
	int blank_num = 0;	//�ո�����
	int i = 0;

	while(String[i] != '\0')
	{
		if (String[i] == ' ')
		{
			blank_num++;	//����ԭ�ַ����еĿո�����
		}
		i++;
		length++;			//����ԭ�ַ����ĳ���
	}
	length_after = length + blank_num * 2;	//�������ַ����ĳ���

	if (length_after > SpaceLen)	//�����ַ������ȴ��ڿ��õ��ڴ�ռ䣬��ֱ���˳�����
		return;

	int index = length_after;			//�����ַ���ĩβ����ָ��
	for (int j = length; j >= 0; j--)	//��β��ͷ����ԭ�ַ���
	{
		if (String[j] != ' ')			//���ǿո�����ɸ�ֵ����
		{
			String[index] = String[j];
			index--;
		}
		else							//��Ϊ�ո�������滻����
		{
			String[index--] = '0';
			String[index--] = '2';
			String[index--] = '%';
		}
	}
	printf("%s\n", String);
}

int main()
{
	const int length = 100;					//���ַ����������õĿռ�

	char str1[length] = "Hello world";		//ֻ��һ���ո�
	ReplaceSpaces(str1,length);

	char str2[length] = "We are happy!";		//���ж���ո�
	ReplaceSpaces(str2, length);

	char str3[length] = "     ";				//ֻ�ж���ո�
	ReplaceSpaces(str3, length);

	char str4[length] = "Interesting!";		//û�пո�
	ReplaceSpaces(str4, length);

	char str5[length] = "";					//���ַ���
	ReplaceSpaces(str5, length);

	return 0;
}