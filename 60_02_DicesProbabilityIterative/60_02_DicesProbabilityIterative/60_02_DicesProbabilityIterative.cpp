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
//-------------------------�����ࣨѭ��ʵ�֣�-------------------------//
//********************************************************************//
class Dices
{
public:
	int DicesNumber;		//���ӵĸ���

	Dices(int number)		//�������Ĺ��캯��
	{
		assert(number > 0);
		DicesNumber = number;					//�ò�����ʼ�����Ӹ���
		int length = 6 * DicesNumber + 1;		//ÿһ������֮�͵Ŀ��ܽ���������±�Ϊ0��Ԫ�ؿ��ò��ã�
		AppearTimes[0] = new int[length];		//�������齻��洢ÿ��һ�����ӵ���֮�ͳ��ִ���
		AppearTimes[1] = new int[length];
		for (int i = 0; i < length; i++)
		{
			AppearTimes[0][i] = 0;		//�����ʼ��
			AppearTimes[1][i] = 0;		//�����ʼ��
		}
	}

	~Dices()				//��������
	{
		delete[] AppearTimes[0];
		delete[] AppearTimes[1];
	}

	void PrintProbability()		//��ӡ���ʺ���
	{
		int flag = 0;			//��־λ�������ĸ�����洢���֮�ͳ��ֵĴ���
		SumProbability(DicesNumber, flag, AppearTimes);		//����ÿһ���͵ĳ��ִ���

		for (int i = 0; i < 5 * DicesNumber + 1; i++)
		{
			cout << "s = " << i + DicesNumber << "\t" << "prob = " << AppearTimes[!flag][i + DicesNumber] / pow(6, DicesNumber) << endl;
		}
	}

private:
	int* AppearTimes[2];		//���ִ���ͳ������

	void SumProbability(int number, int& flag, int** AppearTimes)		//����ÿһ���͵ĳ��ִ���
	{
		for (int i = 1; i <= 6; i++)		//ֻ��һ������ʱ������֮��Ϊ1-6���ֵĴ�����Ϊ1
		{
			AppearTimes[flag][i]++;
		}
		flag = !flag;						//������¼����֮�͵�����

		for (int j = 2; j <= number; j++)	//��������Ŀ��2���ӵ�DicesNumberʱ
		{
			for (int p = j; p <= j * 6; p++)	//pΪ���ܳ��ֵĵ���֮�ͣ���j=2ʱ��pȡֵ��Χ2~12
			{
				for (int k = p - 6; k <= p - 1; k++)	//����һ������֮��Ϊp-6~p-1�ĳ��ִ������
				{
					if (k > 0)					//����һ���ĵ���֮�ʹ���0
					{
						AppearTimes[flag][p] += AppearTimes[!flag][k];
					}
				}
			}
			flag = !flag;						//������¼����֮�͵�����
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