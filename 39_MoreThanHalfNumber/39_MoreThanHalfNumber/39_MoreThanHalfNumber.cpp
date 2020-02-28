//==================================================================
// ����ָOffer������
//==================================================================

// ������39�������г��ִ�������һ�������
// ��Ŀ����������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���
// ������һ������Ϊ9������{1, 2, 3, 2, 2, 2, 5, 4, 2}����������2��������
// ������5�Σ��������鳤�ȵ�һ�룬������2��

#include <iostream>
#include <assert.h>
using namespace std;

//**********************************************************************************//
//-----------------�ж������ҵ��������Ƿ�������ִ�������һ���Ҫ��-----------------//
//���룺int* numbers���������飩, int length�����鳤�ȣ�, int number���Ѽ��������֣�
//**********************************************************************************//
bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] == number)			//ͳ��number��numbers�г��ֵĴ���
			times++;
	}

	if (times * 2 < length)					//�����������鳤�ȵ�һ��Ƚ�
		return false;
	else
		return true;
}

//**********************************************************************************//
//----------------------------------���˿�������------------------------------------//
//���룺int* numbers���������飩, int start��������ʼ��, int end��������ֹ��
//**********************************************************************************//
int QuickSort(int* numbers, int start, int end)
{
	int refer = numbers[start];
	int low = start, high = end;
	bool flag = 0;
	while (low < high)
	{
		if (numbers[low] > numbers[high])
		{
			swap(numbers[low], numbers[high]);
			flag = !flag;
		}
		if (flag == 0)
		{
			high--;
		}
		else
		{
			low++;
		}
	}
	return low;
}

//**********************************************************************************//
//----------------------���ڿ��������ҵ����ִ�������һ�������----------------------//
//���룺int* numbers���������飩, int length�����鳤�ȣ�
//**********************************************************************************//
int MoreThanHalfNumber_QuickSort(int* numbers, int length)
{
	assert(numbers != nullptr && length != 0);

	int start = 0, end = length - 1, middle = length >> 1;		//middleΪ��λ����λ��

	int index = QuickSort(numbers, start, end);					//���˿��������ҵ�һ������

	while (index != middle)										//ֱ������λ��Ϊmiddle��ֹͣѭ��
	{
		if (index < middle)										//������λ��С��middle���ں�벿�ּ����ݹ�
		{
			index = QuickSort(numbers, index + 1, end);
		}
		else													//������λ�ô���middle����ǰ�벿�ּ����ݹ�
		{
			index = QuickSort(numbers, start, index - 1);
		}
	}

	if (CheckMoreThanHalf(numbers, length, numbers[middle]))	//�ж��ҵ��������Ƿ��������Ƶ�ʴ������鳤�ȵ�һ�������
		return numbers[middle];
	else
		return 0;
}

//**********************************************************************************//
//----------------------���ڴ���ͳ���ҵ����ִ�������һ�������----------------------//
//���룺int* numbers���������飩, int length�����鳤�ȣ�
//**********************************************************************************//
int MoreThanHalfNumber_TimesCount(int* numbers, int length)
{
	assert(numbers != nullptr && length != 0);

	int count = 1;				//����
	int number = numbers[0];	//��ǰ���������

	for (int i = 1; i < length; i++)	//������������
	{
		if (numbers[i] == number)		//����һ�����ֺ͵�ǰ����������ͬ��������1
			count++;
		else							//����һ�����ֺ͵�ǰ�������ֲ�ͬ��������1
			count--;

		if (count == 0)					//��������Ϊ0ʱ���޸ĵ�ǰ��������֣�����������1
		{
			number = numbers[i];
			count = 1;
		}
	}

	if (CheckMoreThanHalf(numbers, length, number))		//�ж��ҵ��������Ƿ��������Ƶ�ʴ������鳤�ȵ�һ�������
		return number;
	else
		return 0;
}

//**********************************************************************************//
//-------------------------------------���Ժ���-------------------------------------//
//���룺int(*func)(int*,int)���ҳ��ִ�������һ������ֵĺ���ָ�룩
//      int* numbers���������飩, int length�����鳤�ȣ�
//**********************************************************************************//
void Test(int(*func)(int*,int),int* numbers, int length)
{
	int result = func(numbers, length);
	if (result)
		cout << "�����г��ִ�������һ��������ǣ�" << result << endl;
	else
		cout << "������û�г��ִ�������һ�������" << endl;
	cout << endl;
}

//**********************************************************************************//
//--------------------------------------������--------------------------------------//
//**********************************************************************************//
int main()
{
	//---------��������1���г��ִ�������һ������ֵ�����-----------//
	const int length1 = 9;
	int numbers1[length1] = { 1,2,3,2,2,2,5,4,2 };
	Test(MoreThanHalfNumber_QuickSort, numbers1, length1);
	Test(MoreThanHalfNumber_TimesCount,numbers1, length1);
	cout << endl;

	//---------��������2��û�г��ִ�������һ������ֵ�����-----------//
	const int length2 = 9;
	int numbers2[length2] = { 1,2,3,3,2,1,5,4,2 };
	Test(MoreThanHalfNumber_QuickSort, numbers2, length2);
	Test(MoreThanHalfNumber_TimesCount, numbers2, length2);
	cout << endl;

	//---------��������3��������-------------//
	const int length3 = 0;
	int * numbers3 = nullptr;
	Test(MoreThanHalfNumber_QuickSort, numbers3, length3);
	Test(MoreThanHalfNumber_TimesCount, numbers3, length3);
	cout << endl;

	return 0;
}