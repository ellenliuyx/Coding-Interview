//==================================================================
// ����ָOffer������
//==================================================================

// ������22�������е�����k�����
// ��Ŀ������һ������������������е�����k����㡣Ϊ�˷��ϴ�����˵�ϰ�ߣ�
// �����1��ʼ��������������β����ǵ�����1����㡣����һ��������6����㣬
// ��ͷ��㿪ʼ���ǵ�ֵ������1��2��3��4��5��6����������ĵ�����3�������
// ֵΪ4�Ľ�㡣

#include <iostream>
using namespace std;

//************************************************************************************************//
//-----------------------------------------�����ڵ�ṹ��-----------------------------------------//
//************************************************************************************************//
struct ListNode
{
	int value;
	ListNode* p_Next;
};

//************************************************************************************************//
//------------------------------------------���������ڵ�------------------------------------------//
//************************************************************************************************//
ListNode* CreateNode(int nodeValue)
{
	ListNode* p_Node = (ListNode*)malloc(sizeof(ListNode));
	p_Node->value = nodeValue;
	p_Node->p_Next = nullptr;

	return p_Node;
}

//************************************************************************************************//
//------------------------------------------���������ڵ�------------------------------------------//
//************************************************************************************************//
void ConnectNode(ListNode* p_Node1, ListNode* p_Node2)
{
	p_Node1->p_Next = p_Node2;
}

//************************************************************************************************//
//-------------------------------------�ҵ������ĵ�����k���ڵ�------------------------------------//
//���룺ListNode* p_Head��ͷ�ڵ㣩, int k
//����ֵ����k���ڵ�
//************************************************************************************************//
ListNode* FindKthNodeToTail(ListNode* p_Head, int k)
{
	if (p_Head == nullptr)
	{
		cout << "�Ƿ����룺������" << endl;
		return nullptr;
	}

	if (k <= 0)
	{
		cout << "�Ƿ����룺k <= 0" << endl;
		return nullptr;
	}

	ListNode* p_Ahead = p_Head;
	ListNode* p_Behind = nullptr;

	for (int i = 0; i < k - 1; i++)			//p_Ahead�߹�k-1���ڵ�
	{
		p_Ahead = p_Ahead->p_Next;
		if (p_Ahead == nullptr)				//����k-1���ڳ��ֿ�ָ�룬�������еĽڵ���С��k
		{
			cout << "�����еĽڵ���С�� " << k << endl;
			return nullptr;
		}
	}

	p_Behind = p_Head;						//p_Ahead�߹�k-1���ڵ��p_Behind��ͷ�ڵ㿪ʼ

	while (p_Ahead->p_Next != nullptr)		//p_Ahead��p_Behindһ������ߣ�ֱ������List��ĩβ
	{
		p_Ahead = p_Ahead->p_Next;
		p_Behind = p_Behind->p_Next;
	}

	return p_Behind;						//����p_Behind��Ϊ������k���ڵ�
}

//************************************************************************************************//
//---------------------------------------��ͷ��β��ӡ�����ڵ�-------------------------------------//
//************************************************************************************************//
void PrintList(ListNode* p_Head)
{
	cout << "��������:" << "\t";
	if (p_Head == nullptr)
	{
		cout << "�޷���ӡ������" << endl;
		return;
	}
	ListNode* p_current = p_Head;
	while (p_current->p_Next != nullptr)
	{
		cout << p_current->value << "\t";
		p_current = p_current->p_Next;
	}
	cout << p_current->value << endl;
}

//************************************************************************************************//
//----------------------------------������һ��������������������----------------------------------//
//************************************************************************************************//
ListNode* CreateList1()
{
	ListNode* p_Head = nullptr;
	PrintList(p_Head);
	return p_Head;
}

//************************************************************************************************//
//-----------------------------�����ڶ�������������1->2->3->4->5->6��-----------------------------//
//************************************************************************************************//
ListNode* CreateList2()
{
	ListNode* p_Node1 = CreateNode(1);
	ListNode* p_Node2 = CreateNode(2);
	ListNode* p_Node3 = CreateNode(3);
	ListNode* p_Node4 = CreateNode(4);
	ListNode* p_Node5 = CreateNode(5);
	ListNode* p_Node6 = CreateNode(6);

	ConnectNode(p_Node1, p_Node2);
	ConnectNode(p_Node2, p_Node3);
	ConnectNode(p_Node3, p_Node4);
	ConnectNode(p_Node4, p_Node5);
	ConnectNode(p_Node5, p_Node6);
	
	ListNode* p_Head = p_Node1;
	PrintList(p_Head);
	return p_Head;
}

//************************************************************************************************//
//-----------------------���Ժ��������ݴ���������������kѰ�ҵ�����k���ڵ�-------------------------//
//���룺ListNode* (*func)(void)�����������ĺ���ָ�룩��int k��Ѱ�ҵ����ڼ����ڵ㣩
//************************************************************************************************//
void Test(ListNode* (*func)(void), int k)
{
	ListNode* p_KthNode = FindKthNodeToTail(func(), k);
	if (p_KthNode != nullptr)
		cout << "�������еĵ����� " << k << " ���ڵ��ǣ�" << p_KthNode->value << endl;
	else
		cout << "��������û�е����� " << k << " ���ڵ�!" << endl;
	cout << endl;
}

//************************************************************************************************//
//---------------------------------------------������---------------------------------------------//
//************************************************************************************************//
int main()
{
	Test(CreateList1, 3);	//��������1��������
	Test(CreateList2, 0);	//��������2��k<=0
	Test(CreateList2, 3);	//��������3��������k���ڵ��������м�
	Test(CreateList2, 6);	//��������4��������k���ڵ�������ͷ��
	Test(CreateList2, 1);	//��������4��������k���ڵ�������β��
	Test(CreateList2, 8);	//��������5��k�����������ܽڵ���

	return 0;
}