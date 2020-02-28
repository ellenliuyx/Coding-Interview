//==================================================================
// ����ָOffer������
//==================================================================

// ������9��������ջʵ�ֶ���
// ��Ŀ��������ջʵ��һ�����С����е��������£���ʵ��������������appendTail
// ��deleteHead���ֱ�����ڶ���β����������ڶ���ͷ��ɾ�����Ĺ��ܡ�

#include <iostream>
#include <stack>
#include <exception>
using namespace std;

//*******************************************************************************//
//-------------------------------����ģ���������--------------------------------//
//*******************************************************************************//
template <typename T> class CQueue		//template <���Ͳ�����> classs ����
{
public:
	CQueue(void);		//���캯��
	~CQueue(void);		//��������

	void appendTail(const T& node);		//���
	T deleteHead();						//����

private:
	stack<T> stack1;
	stack<T> stack2;
};

//*******************************************************************************//
//-------------------------------����ģ���ຯ������------------------------------//
//-----template <���Ͳ�����> ����ֵ���� ����<���Ͳ�����>::������(����������)-----//
//*******************************************************************************//
template <typename T> CQueue<T>::CQueue(void){}		//���캯��

template <typename T> CQueue<T>::~CQueue(void){}	//��������

template <typename T> void CQueue<T>::appendTail(const T& node)		//��Ӻ���
{
	stack1.push(node);
}

template <typename T> T CQueue<T>::deleteHead()						//���Ӻ���
{
	if (stack2.empty())								//��stack2Ϊ��
	{
		T temp;
		if (stack1.empty())							//��stack1ҲΪ�գ������Ϊ�գ��׳��쳣
		{
			cout << "queue is empty" << endl;
			throw new exception("queue is empty");
		}
		while (!stack1.empty())						//��stack1��Ϊ�գ���stack1ȫ��Ԫ�ص���������stack2
		{
			temp = stack1.top();
			stack1.pop();
			stack2.push(temp);
		}
	}
	T head = stack2.top();							//��stack2ջ��Ԫ�ص���
	stack2.pop();
	
	return head;
}

//*******************************************************************************//
//-------------------------------------������------------------------------------//
//*******************************************************************************//
int main()
{
	CQueue<int> MyQueue;			//�Ǿ�̬��Ա������Ҫ����������ʹ��

	//��0��1��2���
	for (int i = 0; i < 3; i++)
	{
		MyQueue.appendTail(i);
		cout << "push:" << i << endl;
	}

	//��0��1����
	int head;
	for (int j = 0; j < 2; j++)
	{
		head = MyQueue.deleteHead();
		cout << "pop:" << head << endl;
	}
	
	//��3���
	MyQueue.appendTail(3);
	cout << "push:" << 3 << endl;

	//��2��3���Ӻ�������������׳��쳣
	for (int j = 0; j < 3; j++)
	{
		head = MyQueue.deleteHead();
		cout << "pop:" << head << endl;
	}
}