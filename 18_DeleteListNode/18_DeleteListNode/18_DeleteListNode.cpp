//==================================================================
// ����ָOffer������
//==================================================================

// ������18��һ������O(1)ʱ��ɾ��������
// ��Ŀ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ����
// ��㡣

// ������18��������ɾ���������ظ��Ľ��
// ��Ŀ����һ������������У����ɾ���ظ��Ľ�㣿���磬��ͼ3.4��a�����ظ�
// ��㱻ɾ��֮��������ͼ3.4��b����ʾ��

#include <iostream>
using namespace std;

//****************************************************************************************//
//--------------------------------------����ڵ�------------------------------------------//
//****************************************************************************************//
struct ListNode
{
	int value;
	ListNode* p_Next;
};

//****************************************************************************************//
//---------------------------------���������һ���ڵ�-------------------------------------//
//****************************************************************************************//
ListNode* CreateListNode(int value)
{
	ListNode* p_Node;
	p_Node = (ListNode*)malloc(sizeof(ListNode));	//Ϊһ���ڵ㿪���ڴ�ռ�
	p_Node->value = value;
	p_Node->p_Next = nullptr;

	return p_Node;
}

//****************************************************************************************//
//---------------------------------��������������ڵ�-------------------------------------//
//****************************************************************************************//
void LinkListNode(ListNode* p_Node1, ListNode* p_Node2)
{
	p_Node1->p_Next = p_Node2;
}

//****************************************************************************************//
//---------------------------------ɾ�������ĳ���ڵ�-------------------------------------//
//���룺p_Head��������p_Delete����ɾ���ڵ㣩
//****************************************************************************************//
void DeleteNode(ListNode* p_Head, ListNode* p_Delete)
{
	if (p_Delete->p_Next == nullptr)			//���ýڵ��������β�ڵ�
	{
		ListNode* p_current = p_Head;
		ListNode* p_nextnode = p_Head->p_Next;
		while (p_nextnode->p_Next != nullptr)	//��ͷ��㿪ʼ������������β�ڵ���ɾ��
		{
			p_current = p_current->p_Next;
			p_nextnode = p_nextnode->p_Next;
		}
		p_current->p_Next = nullptr;
		delete p_nextnode;
	}
	else										//���ýڵ㲻�������β�ڵ�
	{
		ListNode* p_nextnode = p_Delete->p_Next;
		p_Delete->value = p_nextnode->value;	//����ɾ�ڵ����һ���ڵ㸴�Ƶ���ɾ�ڵ���
		p_Delete->p_Next = p_nextnode->p_Next;
		delete p_nextnode;						//ɾ����ɾ�ڵ����һ���ڵ�
	}
}

//****************************************************************************************//
//---------------------------------ɾ��������ظ��ڵ�-------------------------------------//
//���룺p_Head������
//****************************************************************************************//
void DeleteDupNode(ListNode* p_Head)
{
	if (p_Head->p_Next == nullptr || p_Head->p_Next->p_Next == nullptr)	//������Ϊ�ջ�ֻ��һ���ڵ㣬ֱ�ӽ�������
		return;
	
	ListNode* p_current = p_Head;
	ListNode* p_nextnode = p_current->p_Next;
	ListNode* p_temp;
	bool needDel;			//��Ҫɾ����־λ������������һֱû���ظ��ڵ㣬����λ���ظ�������ұ߽紦�����������p_nextnode��p_nextnode->p_Next��ֵ������

	while (p_nextnode->p_Next != nullptr)		//������������βʱ������ѭ��
	{
		needDel = false;						//ɾ����־λ��ʼ��Ϊ0
		while (p_nextnode->value == p_nextnode->p_Next->value)		//�ҵ��������ظ�����
		{
			needDel = true;						//ɾ����־λ��Ϊ1
			p_temp = p_nextnode;				//p_nextnodeָ�����1λ��ɾ��p_nextnode��ǰһ���ڵ�
			p_nextnode = p_nextnode->p_Next;
			delete p_temp;
			if (p_nextnode->p_Next == nullptr)	//������������βʱ���޷������Ƚ�p_nextnode��p_nextnode->p_Next��ֵ
			{
				p_current->p_Next = nullptr;	//ֱ��ɾ��p_nextnode�ڵ㣬�޸�p_current��ָ��Ϊ�գ��������н���
				delete p_nextnode;
				return;
			}
		}
		if (needDel)							//���λ���ظ�������ұ߽紦����Ҫɾ���ڵ�
		{
			p_temp = p_nextnode;				//ɾ��p_nextnode�ڵ�
			p_nextnode = p_nextnode->p_Next;
			delete p_temp;
			p_current->p_Next = p_nextnode;		//�޸�p_current��ָ�룬ʹ��ָ���ظ��������һ���ڵ�
		}
		else									//���һֱû���ظ��ڵ㣬����Ҫɾ���ڵ�
		{
			p_current = p_current->p_Next;		//p_currentָ���p_nextnodeָ�����1λ
			p_nextnode = p_nextnode->p_Next;
		}
	}
}

//****************************************************************************************//
//------------------------------��ͷ��β���δ�ӡ����ڵ�----------------------------------//
//���룺p_Head������
//****************************************************************************************//
void PrintList(ListNode* p_Head)
{
	ListNode* p_current = p_Head;
	while (p_current->p_Next != nullptr)
	{
		cout << p_current->p_Next->value << "\t";
		p_current = p_current->p_Next;
	}
	cout << endl;
}

//****************************************************************************************//
//---------------------------------------������-------------------------------------------//
//****************************************************************************************//
int main()
{
	//--------------------------------����ڵ㹹��--------------------------------//
	ListNode* p_Head = CreateListNode(0);		//ͷ�ڵ�

	//------��������1�����ж���ظ�����
	ListNode* p_Node1 = CreateListNode(1);
	ListNode* p_Node2 = CreateListNode(2);
	ListNode* p_Node3 = CreateListNode(3);
	ListNode* p_Node4 = CreateListNode(3);
	ListNode* p_Node5 = CreateListNode(3);
	ListNode* p_Node6 = CreateListNode(4);
	ListNode* p_Node7 = CreateListNode(5);
	ListNode* p_Node8 = CreateListNode(6);
	ListNode* p_Node9 = CreateListNode(6);

	//------��������2������������Ԫ�ؾ����
	/*ListNode* p_Node1 = CreateListNode(1);
	ListNode* p_Node2 = CreateListNode(1);
	ListNode* p_Node3 = CreateListNode(1);
	ListNode* p_Node4 = CreateListNode(1);
	ListNode* p_Node5 = CreateListNode(1);
	ListNode* p_Node6 = CreateListNode(1);
	ListNode* p_Node7 = CreateListNode(1);
	ListNode* p_Node8 = CreateListNode(1);
	ListNode* p_Node9 = CreateListNode(1)*/;

	//------��������2������������Ԫ�ؾ������
	/*ListNode* p_Node1 = CreateListNode(1);
	ListNode* p_Node2 = CreateListNode(2);
	ListNode* p_Node3 = CreateListNode(3);
	ListNode* p_Node4 = CreateListNode(4);
	ListNode* p_Node5 = CreateListNode(5);
	ListNode* p_Node6 = CreateListNode(6);
	ListNode* p_Node7 = CreateListNode(7);
	ListNode* p_Node8 = CreateListNode(8);
	ListNode* p_Node9 = CreateListNode(9);*/

	//--------------------------------����ڵ�����--------------------------------//
	LinkListNode(p_Head, p_Node1);
	LinkListNode(p_Node1, p_Node2);
	LinkListNode(p_Node2, p_Node3);
	LinkListNode(p_Node3, p_Node4);
	LinkListNode(p_Node4, p_Node5);
	LinkListNode(p_Node5, p_Node6);
	LinkListNode(p_Node6, p_Node7);
	LinkListNode(p_Node7, p_Node8);
	LinkListNode(p_Node8, p_Node9);

	cout << "��ʼ����Ϊ��" << endl;
	PrintList(p_Head);

	//---------------------------ɾ��������ĳһ���ڵ�---------------------------//
	ListNode* p_Delete = p_Node2;
	cout << "ɾ���ڵ� " << p_Delete->value << " �������Ϊ��" << endl;
	DeleteNode(p_Head, p_Delete);
	PrintList(p_Head);

	//---------------------------ɾ���������ظ��Ľڵ�---------------------------//
	DeleteDupNode(p_Head);
	cout << "ɾ���ظ��ڵ�������Ϊ��" << endl;
	PrintList(p_Head);

	return 0;
}