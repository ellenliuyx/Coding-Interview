//==================================================================
// ����ָOffer������
//==================================================================

// ������53��һ�������������������г��ֵĴ���
// ��Ŀ��ͳ��һ�����������������г��ֵĴ���������������������{1, 2, 3, 3,
// 3, 3, 4, 5}������3������3����������г�����4�Σ�������4��

#include <iostream>
#include <assert.h>
using namespace std;

//*********************************************************************************//
//--------------------------�������е�һ��k�������е��±�--------------------------//
//*********************************************************************************//
int GetFirstK(int* array, int k, int start, int end)
{
	assert(array != nullptr);		//�Ƿ����룺��ָ��

	if (start > end)				//������ͷ��������βʱ��˵��δ�ҵ���һ��k���򷵻�-1
		return -1;

	int middle = (start + end) / 2;
	if (array[middle] == k && array[middle - 1] != k)	//����ǰԪ��Ϊk��ǰһ��Ԫ�ز�Ϊk�����ҵ���һ��k
		return middle;
	else							//����
	{
		//����ǰԪ�ش���k�����ߵ�ǰԪ�غ�ǰһ��Ԫ�ؾ�����k����ǰ��μ���Ѱ��
		if (array[middle] > k || (array[middle] == k && array[middle - 1] == k))
			return GetFirstK(array, k, start, middle - 1);

		//����ǰԪ��С��k�����ߵ�ǰԪ�غ�ǰһ��Ԫ�ؾ�����k���ں��μ���Ѱ��
		if (array[middle] < k)
			return GetFirstK(array, k, middle + 1, end);
	}
}

//*********************************************************************************//
//-------------------------�����������һ��k�������е��±�-------------------------//
//*********************************************************************************//
int GetLastK(int* array, int k, int start, int end)
{
	assert(array != nullptr);

	if (start > end)
		return -1;

	int middle = (start + end) / 2;
	if (array[middle] == k && array[middle + 1] != k)
		return middle;
	else
	{
		if (array[middle] < k || (array[middle] == k && array[middle + 1] == k))
			return GetLastK(array, k, middle + 1, end);
		if (array[middle] > k)
			return GetLastK(array, k, start, middle - 1);
	}
}

//*********************************************************************************//
//--------------------------���Ժ���1��k�������г��ֹ����-------------------------//
//*********************************************************************************//
void Test1()
{
	const int length = 8;
	int array[length] = { 1,2,3,3,3,3,4,5 };
	int k = 3;
	int indexFirstK = GetFirstK(array, k, 0, length - 1);
	int indexLastK = GetLastK(array, k, 0, length - 1);
	if (indexFirstK >= 0 && indexLastK >= 0)		//��indexFirstK��indexLastKΪ-1ʱ��������û��k
		cout << k << " �������еĸ���Ϊ��" << indexLastK - indexFirstK + 1 << endl;
	else
		cout << "������û�� " << k << endl;
}

//*********************************************************************************//
//--------------------���Ժ���2��k��������ֻ����1�Σ���Ϊ��Сֵ--------------------//
//*********************************************************************************//
void Test2()
{
	const int length = 8;
	int array[length] = { 1,2,3,3,3,3,4,5 };
	int k = 1;
	int indexFirstK = GetFirstK(array, k, 0, length - 1);
	int indexLastK = GetLastK(array, k, 0, length - 1);
	if (indexFirstK >= 0 && indexLastK >= 0)
		cout << k << " �������еĸ���Ϊ��" << indexLastK - indexFirstK + 1 << endl;
	else
		cout << "������û�� " << k << endl;
}

//*********************************************************************************//
//--------------------���Ժ���3��k��������ֻ����1�Σ���Ϊ���ֵ--------------------//
//*********************************************************************************//
void Test3()
{
	const int length = 8;
	int array[length] = { 1,2,3,3,3,3,4,5 };
	int k = 5;
	int indexFirstK = GetFirstK(array, k, 0, length - 1);
	int indexLastK = GetLastK(array, k, 0, length - 1);
	if (indexFirstK >= 0 && indexLastK >= 0)
		cout << k << " �������еĸ���Ϊ��" << indexLastK - indexFirstK + 1 << endl;
	else
		cout << "������û�� " << k << endl;
}

//*********************************************************************************//
//---------------------------���Ժ���4��k��������δ���ֹ�--------------------------//
//*********************************************************************************//
void Test4()
{
	const int length = 8;
	int array[length] = { 1,2,3,3,3,3,4,5 };
	int k = 0;
	int indexFirstK = GetFirstK(array, k, 0, length - 1);
	int indexLastK = GetLastK(array, k, 0, length - 1);
	if (indexFirstK >= 0 && indexLastK >= 0)
		cout << k << " �������еĸ���Ϊ��" << indexLastK - indexFirstK + 1 << endl;
	else
		cout << "������û�� " << k << endl;
}

//*********************************************************************************//
//-----------------------------���Ժ���5������Ϊ��ָ��-----------------------------//
//*********************************************************************************//
void Test5()
{
	const int length = 0;
	int* array = nullptr;
	int k = 5;
	int indexFirstK = GetFirstK(array, k, 0, length - 1);
	int indexLastK = GetLastK(array, k, 0, length - 1);
	if (indexFirstK >= 0 && indexLastK >= 0)
		cout << k << " �������еĸ���Ϊ��" << indexLastK - indexFirstK + 1 << endl;
	else
		cout << "������û�� " << k << endl;
}

//*********************************************************************************//
//-------------------------------------������--------------------------------------//
//*********************************************************************************//
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;
}