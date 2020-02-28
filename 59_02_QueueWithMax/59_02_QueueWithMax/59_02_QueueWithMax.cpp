//==================================================================
// ����ָOffer������
//==================================================================

// ������59�����������е����ֵ
// ��Ŀ���붨��һ�����в�ʵ�ֺ���max�õ����е����ֵ��Ҫ����max��push_back
// ��pop_front��ʱ�临�Ӷȶ���O(1)

#include <deque>
#include <iostream>
#include <exception>
using namespace std;

//****************************************************************************//
//-------------------------�������ֵ�����Ķ���ģ����-------------------------//
//****************************************************************************//
template <typename T> class QueueWithMax
{
public:
	//------���캯������currentIndex��ʼ��Ϊ0------//
	QueueWithMax() :currentIndex(0) {}

	//------push_back����------//
	void push_back(T value)
	{
		InternalData inData = { value, currentIndex };		//����InternalData��inData

		data.push_back(inData);			//�������ݶ��У�ֱ��push_back����

		//�������ֵ����
		while (!maxValue.empty() && value >= maxValue.back().number)	//���ǿ��ҵ�ǰԪ��ֵ���ڶ�βԪ��
			maxValue.pop_back();		//������βԪ��
		maxValue.push_back(inData);		//����ǰԪ�����

		currentIndex++;			//��ǰԪ���±�+1
	}

	//------pop_front����------//
	void pop_front()
	{
		if (maxValue.empty())		//������Ϊ�գ��׳��쳣
			throw new exception("The queue is empty!");

		if (maxValue.front().index == data.front().index)	//�����ֵ���ж�ͷԪ���±� �� ���ݶ��ж�ͷԪ���±���ͬ����Ҳ��Ҫ����
			maxValue.pop_front();

		data.pop_front();			//���ݶ�����ֱ�ӵ���
	}

	//------max����------//
	T max()
	{
		if (maxValue.empty())		//������Ϊ�գ��׳��쳣
			throw new exception("The queue is empty!");

		return maxValue.front().number;		//���򣬷������ֵ���еĶ�ͷԪ��ֵ
	}

private:
	struct InternalData		//���ݶ��к����ֵ�����е��������Ͱ�������ֵ������Ԫ���±�������
	{
		T number;
		int index;
	};

	deque<InternalData> data;		//���ݶ���
	deque<InternalData> maxValue;	//���ֵ����

	int currentIndex;		//��ǰԪ���±�
};

int main()
{
	QueueWithMax<int> myQueue;

	myQueue.push_back(2);			//{2}
	cout << myQueue.max() << '\t';
	myQueue.push_back(3);			//{2,3}
	cout << myQueue.max() << '\t';
	myQueue.push_back(4);			//{2,3,4}
	cout << myQueue.max() << '\t';
	myQueue.push_back(2);			//{2,3,4,2}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{3,4,2}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{4,2}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{2}
	cout << myQueue.max() << '\t';
	myQueue.push_back(6);			//{2,6}
	cout << myQueue.max() << '\t';
	myQueue.push_back(2);			//{2,6,2}
	cout << myQueue.max() << '\t';
	myQueue.push_back(5);			//{2,6,2,5}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{6,2,5}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{2,5}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{5}
	cout << myQueue.max() << '\t';
	myQueue.push_back(1);			//{5,1}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{1}
	cout << myQueue.max() << '\t';
	myQueue.pop_front();			//{}
	cout << myQueue.max() << '\t';
}