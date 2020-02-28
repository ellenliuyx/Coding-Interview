//==================================================================
// ����ָOffer������
//==================================================================

// ������6����β��ͷ��ӡ����
// ��Ŀ������һ�������ͷ��㣬��β��ͷ��������ӡ��ÿ������ֵ��

#include <iostream>
#include <stack>		//ջ��ͷ�ļ���STL������������
using namespace std;

//******************************************************************
//����ڵ�
//******************************************************************
struct ListNode
{
	int value;
	ListNode * pNext;
};

//******************************************************************
//������ĩβ����һ��Ԫ��ֵ
//���룺pTail(ָ������ĩβԪ�ص�ָ��)��InsertValue(��Ҫ�����Ԫ��ֵ)
//����ֵ��pTemp��ָ��������ĩβԪ�ص�ָ�룩
//******************************************************************
ListNode* AddToTail(ListNode* pTail, int InsertValue)
{
	ListNode* pTemp;
	pTemp = (ListNode*)malloc(sizeof(ListNode));
	pTemp->value = InsertValue;
	pTemp->pNext = NULL;
	pTail->pNext = pTemp;

	return pTemp;
}

//******************************************************************
//��ͷ��β��ӡ������Ԫ��
//���룺pHead(����ͷָ��)
//******************************************************************
void PrintList(ListNode* pHead)
{
	ListNode* pTemp;
	pTemp = pHead->pNext;	//�����еĵ�һ��Ԫ��
	cout << "Head->";
	if (pTemp == NULL)		//����һ��Ԫ��Ϊ�գ���ֱ���˳�����
	{
		cout << endl;
		return;
	}
	while (pTemp->pNext != NULL)	//����ǰԪ�ص�ָ�벻Ϊ��
	{
		cout << pTemp->value << "->";	//�����ǰԪ��ֵ
		pTemp = pTemp->pNext;			//ָ��ָ����һԪ��
	}
	cout << pTemp->value << endl;		//�������ĩβԪ��
}

//******************************************************************
//��β��ͷ��ӡ������Ԫ�أ���ջʵ�֣�
//���룺pHead(����ͷָ��)
//******************************************************************
void PrintListRev_Stack(ListNode* pHead)
{
	stack<int> St;				//����һ��ջ����
	ListNode* pTemp;
	pTemp = pHead->pNext;		//�����еĵ�һ��Ԫ��
	if (pTemp == NULL)			//����һ��Ԫ��Ϊ�գ���ֱ���˳�����
	{
		cout << "<-Head" << endl;
		return;
	}

	//----------------------����Ԫ��˳����ջ----------------------------//
	while (pTemp->pNext != NULL)	//����ǰԪ�ص�ָ�벻Ϊ��
	{
		St.push(pTemp->value);		//����ǰԪ��ֵ��ջ
		pTemp = pTemp->pNext;		//ָ��ָ����һԪ��
	}
	St.push(pTemp->value);			//���������һ��Ԫ��ֵ��ջ

	//-------------------����Ԫ�������ջ�����-------------------------//
	while (!St.empty())				//��ջ����
	{
		cout << St.top() << "<-";	//���ջ��Ԫ��
		St.pop();					//����ջ��Ԫ��
	}
	cout << "Head" << endl;
}

//******************************************************************
//��β��ͷ��ӡ������Ԫ�أ��õݹ�ʵ�֣�
//���룺pHead(����ͷָ��)
//******************************************************************
void PrintListRev_Recurse(ListNode* pHead)
{
	ListNode* pTemp;
	pTemp = pHead->pNext;		//�����еĵ�һ��Ԫ��
	if (pTemp == NULL)			//Ԫ��Ϊ�գ��˳�����
	{
		return;
	}

	PrintListRev_Recurse(pTemp);
	cout << pTemp->value << "<-";
}

//******************************************************************
//������
//******************************************************************
int main()
{
	ListNode * pHead, * pTail;		//����ͷָ���βָ��
	pHead = (ListNode*)malloc(sizeof(ListNode));	//Ϊͷָ�뿪�ٿռ�
	pHead->value = 0;
	pHead->pNext = NULL;
	pTail = pHead;					//���ڿ�����βָ����ͷָ�봦��ͬһλ��

	//--------------------�Ӽ��������������в����Ԫ��-----------------------
	int ValueInput;
	cout << "������������Ԫ�أ�" << endl;
	while (cin >> ValueInput)
	{
		pTail = AddToTail(pTail, ValueInput);
	}

	//-------------------------����Ļ��ӡ����Ԫ��----------------------------
	cout << "˳���������Ԫ�أ�" << endl;
	PrintList(pHead);
	cout << "�����������Ԫ�أ���ջʵ�֣���" << endl;
	PrintListRev_Stack(pHead);
	cout << "�����������Ԫ�أ��õݹ�ʵ�֣���" << endl;
	PrintListRev_Recurse(pHead);
	cout << "Head" << endl;

	return 0;
}