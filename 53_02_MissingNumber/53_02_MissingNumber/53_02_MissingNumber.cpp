//==================================================================
// ����ָOffer������
//==================================================================

// ������53��������0��n-1��ȱʧ������
// ��Ŀ��һ������Ϊn-1�ĵ������������е��������ֶ���Ψһ�ģ�����ÿ������
// ���ڷ�Χ0��n-1֮�ڡ��ڷ�Χ0��n-1��n������������ֻ��һ�����ֲ��ڸ�����
// �У����ҳ�������֡�

#include <iostream>
#include <assert.h>
using namespace std;

//********************************************************************//
//--------------------------��ȱʧ�����ֺ���--------------------------//
//********************************************************************//
int GetMissingNumber(int* array, int start, int end)
{
	assert(array != nullptr);		//�Ƿ�����

	if (start > end)				//������ͷ��������βʱ��û���ҵ�ȱʧ���ַ���-1
		return -1;

	int middle = (start + end) / 2;

	//����ǰԪ��ֵ���±겻������һ��Ԫ��ֵ���±���ȣ��򷵻ص�ǰԪ���±꼴ΪȱʧԪ��
	if (array[middle] == middle + 1 && array[middle - 1] == middle - 1)
		return middle;
	else
	{
		//����ǰԪ��ֵ���±겻������һ��Ԫ��ֵҲ���±겻�ȣ��������ǰ�����ȱʧԪ��
		if (array[middle] == middle + 1 && array[middle - 1] == middle)
			return GetMissingNumber(array, start, middle - 1);

		//����ǰԪ��ֵ���±���ȣ�������ں�����ȱʧԪ��
		if (array[middle] == middle)
			return GetMissingNumber(array, middle + 1, end);
	}
}

//********************************************************************//
//-----------------���Ժ���1��ȱʧ���ֳ����������м�------------------//
//********************************************************************//
void Test1()
{
	const int length = 8;
	int array[length] = { 0,1,2,4,5,6,7,8 };
	int MissingNumber = GetMissingNumber(array, 0, length - 1);
	if (MissingNumber >= 0)
		cout << "������ȱʧ�������ǣ�" << MissingNumber << endl;
	else
		cout << "������û��ȱʧ������" << endl;
}

//********************************************************************//
//-----------------���Ժ���2��ȱʧ���ֳ��������鿪ͷ------------------//
//********************************************************************//
void Test2()
{
	const int length = 8;
	int array[length] = { 1,2,3,4,5,6,7,8 };
	int MissingNumber = GetMissingNumber(array, 0, length - 1);
	if (MissingNumber >= 0)
		cout << "������ȱʧ�������ǣ�" << MissingNumber << endl;
	else
		cout << "������û��ȱʧ������" << endl;
}

//********************************************************************//
//-----------------���Ժ���3��ȱʧ���ֳ���������ĩβ------------------//
//********************************************************************//
void Test3()
{
	const int length = 8;
	int array[length] = { 0,1,2,3,4,5,6,8 };
	int MissingNumber = GetMissingNumber(array, 0, length - 1);
	if (MissingNumber >= 0)
		cout << "������ȱʧ�������ǣ�" << MissingNumber << endl;
	else
		cout << "������û��ȱʧ������" << endl;
}

//********************************************************************//
//-----------------���Ժ���4����Ԫ����������ȱʧ����------------------//
//********************************************************************//
void Test4()
{
	const int length = 1;
	int array[length] = { 0 };
	int MissingNumber = GetMissingNumber(array, 0, length - 1);
	if (MissingNumber >= 0)
		cout << "������ȱʧ�������ǣ�" << MissingNumber << endl;
	else
		cout << "������û��ȱʧ������" << endl;
}

//********************************************************************//
//-------------------------���Ժ���5��������--------------------------//
//********************************************************************//
void Test5()
{
	const int length = 0;
	int *array = nullptr;
	int MissingNumber = GetMissingNumber(array, 0, length - 1);
	if (MissingNumber >= 0)
		cout << "������ȱʧ�������ǣ�" << MissingNumber << endl;
	else
		cout << "������û��ȱʧ������" << endl;
}

//********************************************************************//
//------------------------------������--------------------------------//
//********************************************************************//
int main()
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	return 0;
}