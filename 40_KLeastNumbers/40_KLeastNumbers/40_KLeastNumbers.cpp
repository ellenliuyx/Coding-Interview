//==================================================================
// ����ָOffer������
//==================================================================

// ������40����С��k����
// ��Ŀ������n���������ҳ�������С��k��������������4��5��1��6��2��7��3��8
// ��8�����֣�����С��4��������1��2��3��4��

#include <iostream>
#include <assert.h>
#include <set>
#include <vector>
using namespace std;

//********************************************************************************//
//----------------------------------���˿�������----------------------------------//
//���룺int* numbers���������飩, int start��������ʼ��, int end�����������
//********************************************************************************//
int QuickSort(int* numbers, int start, int end)
{
	int refer = numbers[0];
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
			high--;
		else
			low++;
	}

	return low;
}

//********************************************************************************//
//----------------------------���ڿ�����������С��k����---------------------------//
//���룺int* input���������飩, int n���������鳤�ȣ�, int* output��������Сk���������飩, int k
//********************************************************************************//
void GetKLeastNumbers_QuickSort(int* input, int n, int* output, int k)
{
	assert(input != nullptr && n > 0 && k > 0 && k <= n);

	int start = 0, end = n - 1;
	int index = QuickSort(input, start, end);

	while (index != k - 1)			//������������λ�ò���k-1��������ݹ���ÿ�������
	{
		if (index > k - 1)
			index = QuickSort(input, start, index - 1);
		else
			index = QuickSort(input, index + 1, end);
	}

	for (int i = 0; i < k; i++)
		output[i] = input[i];
}

//********************************************************************************//
//---------------------------���ڹ�����������С��k����----------------------------//
//���룺vector<int> input�����붯̬���飩, int n����̬���鳤�ȣ�,
//      multiset<int, greater<int>>& output���洢��Сk�����Ĺ���������, int k
//********************************************************************************//
void GetKLeastNumbers_Multiset(vector<int> input, int n, multiset<int, greater<int>>& output, int k)
{
	output.clear();		//�Ƚ������������

	assert(n > 0 && k > 0 && k < n);

	for (vector<int>::iterator itr = input.begin(); itr != input.end(); itr++)		//ÿ�ν���һ����̬����
	{
		if (output.size() < k)			//������������Ԫ�ظ���С��k����ֱ�ӽ���������ݲ����������
		{
			output.insert(*itr);
		}
		else							//������������Ԫ�ظ�������k
		{
			if (*itr < *(output.begin()))	//���������ݱȹ��������е����ֵС
			{
				output.erase(output.begin());	//��ԭ���ֵɾ��
				output.insert(*itr);			//���������ݲ����������
			}
		}
	}
}

//********************************************************************************//
//------------------------------------��ӡ����------------------------------------//
//********************************************************************************//
void PrintArray(int* numbers, int length)
{
	for (int i = 0; i < length; i++)
	{
		cout << numbers[i] << "\t";
	}
	cout << endl;
}

//********************************************************************************//
//----------------------------------��ӡ��������----------------------------------//
//********************************************************************************//
void PrintMultiset(multiset<int, greater<int>> numbers, int length)
{
	for (multiset<int, greater<int>>::iterator itr = numbers.begin(); itr != numbers.end(); itr++)
	{
		cout << *itr << "\t";
	}
	cout << endl;
}

//********************************************************************************//
//-------------------------------------������-------------------------------------//
//********************************************************************************//
int main()
{
	//------------������ʽ�洢��������-------------//
	const int length = 10;
	int input[length] = { 10,5,3,9,6,7,1,8,2,4 };
	cout << "��������Ϊ��" << endl;
	PrintArray(input, length);

	//------------������ʽ�洢��С��k��Ԫ��-------------//
	int k = 4;
	int* output = (int*)malloc(sizeof(int)*k);
	GetKLeastNumbers_QuickSort(input, length, output, k);
	cout << "���ڿ��������ҵ��� "<< k << " ����С����Ϊ��" << endl;
	PrintArray(output, k);

	delete[] output;

	//------------��̬������ʽ�洢��������-------------//
	vector<int> DataInput;
	for (int i = 0; i < length; i++)
	{
		DataInput.push_back(input[i]);
	}

	//------------����������ʽ�洢��С��k��Ԫ��-------------//
	multiset<int, greater<int>> LeastNumbers;
	GetKLeastNumbers_Multiset(DataInput, length, LeastNumbers, k);
	cout << "����multiset�ҵ��� " << k << " ����С����Ϊ��" << endl;
	PrintMultiset(LeastNumbers, k);

	return 0;
}