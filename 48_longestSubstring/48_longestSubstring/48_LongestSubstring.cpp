//==================================================================
// ����ָOffer������
//==================================================================

// ������48��������ظ��ַ������ַ���
// ��Ŀ������ַ������ҳ�һ����Ĳ������ظ��ַ������ַ�������������
// �ַ����ĳ��ȡ������ַ�����ֻ������'a'��'z'���ַ���

#include <iostream>
using namespace std;

//************************************************************************************//
//----------------------------��������ظ��ַ������ַ���----------------------------//
//************************************************************************************//
int LongestSubstringWithoutDup(const string& str)
{
	int* position = new int[26];				//���������ڴ��ÿһ���ַ���һ�����ַ����г��ֵ�λ��
	for (int i = 0; i < 26; i++)	//��ʼʱ�����ʼ��Ϊ-1����ʾ�����ַ���δ���ֹ�
		position[i] = -1;

	if (str.length() == 0)		//���ַ���Ϊ�գ��򷵻�0
		return 0;

	int curLength = 0;			//���ڴ洢f(i-1)
	int maxLength = 0;			//���ڴ洢f(i)
	
	for (int i = 0; i < str.length(); i++)		//��ͷ�����ַ�����ÿһ���ַ�Ԫ��
	{
		int index = str[i] - 'a';				//�����i���ַ���Ӧposition�����е�λ��
		if (position[index] == -1)				//����i���ַ�δ���ֹ�
		{
			if (i == 0)							//���ǵ�һ���ַ�����f(i)=1
				maxLength = 1;
			else								//�����ǵ�һ���ַ�����f(i)=f(i-1)+1
				maxLength = curLength + 1;
		}
		else									//����i���ַ��Ѿ����ֹ�
		{
			int distance = i - position[index];	//��i���ַ������ϴγ������ַ����е�λ�ü�ľ���
			if (distance <= curLength)			//���ϴγ��ֵ�λ����f(i-1)���������ַ����ڣ���f(i)=d
			{
				maxLength = distance;
			}
			else								//���ϴγ��ֵ�λ����f(i-1)���������ַ���֮ǰ����f(i)=f(i-1)+1
			{
				maxLength = curLength + 1;
			}
		}
		position[index] = i;					//����position�����е�i���ַ����ֵ�λ��
		curLength = maxLength;					//f(i-1) = f(i)��ѭ������
	}
	delete[] position;

	return maxLength;
}

//************************************************************************************//
//---------------------------------------������---------------------------------------//
//************************************************************************************//
int main()
{
	//------------��������1��4------------//
	string str1 = "arabcacfr";
	int subStrLen1 = LongestSubstringWithoutDup(str1);
	cout << "�ַ��� " << str1 << " ����С���ظ����ַ����ĳ���Ϊ��" << subStrLen1 << endl;

	//------------��������2��1------------//
	string str2 = "aaaa";
	int subStrLen2 = LongestSubstringWithoutDup(str2);
	cout << "�ַ��� " << str2 << " ����С���ظ����ַ����ĳ���Ϊ��" << subStrLen2 << endl;

	//------------��������3��7------------//
	string str3 = "abcdefg";
	int subStrLen3 = LongestSubstringWithoutDup(str3);
	cout << "�ַ��� " << str3 << " ����С���ظ����ַ����ĳ���Ϊ��" << subStrLen3 << endl;

	//------------��������4��4------------//
	string str4 = "abcdcba";
	int subStrLen4 = LongestSubstringWithoutDup(str4);
	cout << "�ַ��� " << str4 << " ����С���ظ����ַ����ĳ���Ϊ��" << subStrLen4 << endl;

	//------------��������5��6------------//
	string str5 = "abcdaef";
	int subStrLen5 = LongestSubstringWithoutDup(str5);
	cout << "�ַ��� " << str5 << " ����С���ظ����ַ����ĳ���Ϊ��" << subStrLen5 << endl;

	//------------��������6��1------------//
	string str6 = "a";
	int subStrLen6 = LongestSubstringWithoutDup(str6);
	cout << "�ַ��� " << str6 << " ����С���ظ����ַ����ĳ���Ϊ��" << subStrLen6 << endl;

	//------------��������7��0------------//
	string str7 = "";
	int subStrLen7 = LongestSubstringWithoutDup(str7);
	cout << "�ַ��� " << str7 << " ����С���ظ����ַ����ĳ���Ϊ��" << subStrLen7 << endl;

	return 0;
}