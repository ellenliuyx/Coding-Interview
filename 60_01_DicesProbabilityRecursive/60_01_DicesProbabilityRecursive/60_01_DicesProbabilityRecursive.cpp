//==================================================================
// ����ָOffer������
//==================================================================

// ������60��n�����ӵĵ���
// ��Ŀ����n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs������n����ӡ��s
// �����п��ܵ�ֵ���ֵĸ��ʡ�

#include <iostream>
#include <assert.h>
using namespace std;

//********************************************************************//
//-------------------------�����ࣨ�ݹ�ʵ�֣�-------------------------//
//********************************************************************//
class Dices
{
public:
	int DicesNumber;		//���ӵĸ���

	Dices(int number)		//�������Ĺ��캯��
	{
		assert(number > 0);
		DicesNumber = number;		//�ò�����ʼ�����Ӹ���
		int length = 5 * number + 1;		//����֮�͵Ŀ��ܽ������
		AppearTimes = new int[length];		//�洢����֮�ͳ��ִ���������
		for (int i = 0; i < length; i++)
		{
			AppearTimes[i] = 0;		//�����ʼ��
		}
	}

	~Dices()				//��������
	{
		delete[] AppearTimes;
	}

	void PrintProbability()		//��ӡ���ʺ���
	{
		int currentSum = 0;
		SumProbability(DicesNumber, currentSum, AppearTimes);		//����ÿһ���͵ĳ��ִ���

		for (int i = 0; i < 5 * DicesNumber + 1; i++)
		{
			cout << "s = " << i + DicesNumber << "\t" << "prob = " << AppearTimes[i] / pow(6, DicesNumber) << endl;
		}
	}

private:
	int* AppearTimes;		//���ִ���ͳ������

	void SumProbability(int number, int& currentSum, int* AppearTimes)		//����ÿһ���͵ĳ��ִ���
	{
		if (number == 0)		//������n������ȫ������ʱ
		{
			int index = currentSum - DicesNumber;		//����AppearTimes����Ķ�ӦԪ��
			AppearTimes[index]++;
			return;
		}

		for (int i = 1; i <= 6; i++)
		{
			currentSum += i;		//���ϵ�ǰ���ӵ�ֵ
			SumProbability(number - 1, currentSum, AppearTimes);
			currentSum -= i;		//��ȥ��ǰ���ӵ�ֵ��׼������һ��
		}
	}
};

//********************************************************************//
//-------------------------------������-------------------------------//
//********************************************************************//
int main()
{
	Dices dices(10);
	dices.PrintProbability();
}