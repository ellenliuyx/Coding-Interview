//==================================================================
// ����ָOffer������
//==================================================================

// ������52����������ĵ�һ���������
// ��Ŀ���������������ҳ����ǵĵ�һ��������㡣

#include <iostream>
using namespace std;

//******************************************************************//
//--------------------------����ڵ�ṹ��--------------------------//
//******************************************************************//
struct ListNode
{
	int value;
	ListNode* p_Next;
};

//******************************************************************//
//-------------------------����һ������ڵ�-------------------------//
//******************************************************************//
ListNode* CreateNode(int value)
{
	ListNode* p_Node = new ListNode;
	p_Node->value = value;
	p_Node->p_Next = nullptr;
	return p_Node;
}

//******************************************************************//
//-------------------------������������ڵ�-------------------------//
//******************************************************************//
void ConnectNodes(ListNode* p_Node1, ListNode* p_Node2)
{
	p_Node1->p_Next = p_Node2;
}

//******************************************************************//
//---------------------------����������---------------------------//
//******************************************************************//
int CountListLength(ListNode* p_Head)
{
	ListNode* p_Node = p_Head;
	int ListLen = 0;
	while (p_Node != nullptr)
	{
		ListLen++;
		p_Node = p_Node->p_Next;
	}
	return ListLen;
}

//******************************************************************//
//----------------------���������һ�������ڵ�----------------------//
//******************************************************************//
ListNode* TheFirstCommonNode(ListNode* p_Head1, ListNode* p_Head2)
{
	int ListLen1 = CountListLength(p_Head1);		//������������
	int ListLen2 = CountListLength(p_Head2);

	int distance = abs(ListLen1 - ListLen2);		//������������֮��

	ListNode* p_HeadLong = p_Head1;					//�ҵ��������нϳ��ĺͽ϶̵�����
	ListNode* p_HeadShort = p_Head2;
	if (ListLen1 < ListLen2)
	{
		p_HeadLong = p_Head2;
		p_HeadShort = p_Head1;
	}

	for (int i = 0; i < distance; i++)				//���ڳ���������distance��
	{
		p_HeadLong = p_HeadLong->p_Next;
	}

	while (p_HeadLong != nullptr && p_HeadShort != nullptr)		//���������ϱ�����ֱ���ҵ���ͬ�Ľڵ���ߵ�������ĩβ
	{
		if (p_HeadLong->value == p_HeadShort->value)
		{
			return p_HeadLong;
		}
		p_HeadLong = p_HeadLong->p_Next;
		p_HeadShort = p_HeadShort->p_Next;
	}

	return nullptr;
}

//******************************************************************//
//-----------------------------��ӡ����-----------------------------//
//******************************************************************//
void PrintList(ListNode* p_Head)
{
	if (p_Head == nullptr)
	{
		cout << "empty list!" << endl;
		return;
	}
		
	while (p_Head != nullptr)
	{
		cout << p_Head->value << '\t';
		p_Head = p_Head->p_Next;
	}
	cout << endl;
}
//******************************************************************//
//--------------------���Ժ���1�������������ڵ�-------------------//
//����1��1->2->3->6->7
//����2��   4->5->6->7
//******************************************************************//
void Test1()
{
	ListNode* p_List1_Node1 = CreateNode(1);
	ListNode* p_List1_Node2 = CreateNode(2);
	ListNode* p_List1_Node3 = CreateNode(3);
	ListNode* p_List2_Node1 = CreateNode(4);
	ListNode* p_List2_Node2 = CreateNode(5);
	ListNode* p_CommonNode1 = CreateNode(6);
	ListNode* p_CommonNode2 = CreateNode(7);
	ConnectNodes(p_List1_Node1, p_List1_Node2);
	ConnectNodes(p_List1_Node2, p_List1_Node3);
	ConnectNodes(p_List1_Node3, p_CommonNode1);
	ConnectNodes(p_CommonNode1, p_CommonNode2);
	ConnectNodes(p_List2_Node1, p_List2_Node2);
	ConnectNodes(p_List2_Node2, p_CommonNode1);

	ListNode* p_Head1 = p_List1_Node1;
	ListNode* p_Head2 = p_List2_Node1;

	cout << "The 1st list: " << endl;
	PrintList(p_Head1);
	cout << "The 2nd list: " << endl;
	PrintList(p_Head2);

	ListNode* p_FirstCommonNode = TheFirstCommonNode(p_Head1, p_Head2);
	if (p_FirstCommonNode != nullptr)
		cout << "The first common node is: " << p_FirstCommonNode->value << endl << endl;
	else
		cout << "There is no common node" << endl << endl;
}

//******************************************************************//
//-------------------���Ժ���2���������������ڵ�------------------//
//����1��1->2->3
//����2��4->5->6->7
//******************************************************************//
void Test2()
{
	ListNode* p_List1_Node1 = CreateNode(1);
	ListNode* p_List1_Node2 = CreateNode(2);
	ListNode* p_List1_Node3 = CreateNode(3);
	ConnectNodes(p_List1_Node1, p_List1_Node2);
	ConnectNodes(p_List1_Node2, p_List1_Node3);

	ListNode* p_List2_Node1 = CreateNode(4);
	ListNode* p_List2_Node2 = CreateNode(5);
	ListNode* p_List2_Node3 = CreateNode(6);
	ListNode* p_List2_Node4 = CreateNode(7);
	ConnectNodes(p_List2_Node1, p_List2_Node2);
	ConnectNodes(p_List2_Node2, p_List2_Node3);
	ConnectNodes(p_List2_Node3, p_List2_Node4);

	ListNode* p_Head1 = p_List1_Node1;
	ListNode* p_Head2 = p_List2_Node1;

	cout << "The 1st list: " << endl;
	PrintList(p_Head1);
	cout << "The 2nd list: " << endl;
	PrintList(p_Head2);

	ListNode* p_FirstCommonNode = TheFirstCommonNode(p_Head1, p_Head2);
	if (p_FirstCommonNode != nullptr)
		cout << "The first common node is: " << p_FirstCommonNode->value << endl << endl;
	else
		cout << "There is no common node" << endl << endl;
}

//******************************************************************//
//-----------------------���Ժ���3������������----------------------//
//******************************************************************//
void Test3()
{
	ListNode* p_Head1 = nullptr;
	ListNode* p_Head2 = nullptr;

	cout << "The 1st list: " << endl;
	PrintList(p_Head1);
	cout << "The 2nd list: " << endl;
	PrintList(p_Head2);

	ListNode* p_FirstCommonNode = TheFirstCommonNode(p_Head1, p_Head2);
	if (p_FirstCommonNode != nullptr)
		cout << "The first common node is: " << p_FirstCommonNode->value << endl << endl;
	else
		cout << "There is no common node" << endl << endl;
}

//******************************************************************//
//------------------------------������------------------------------//
//******************************************************************//
int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}