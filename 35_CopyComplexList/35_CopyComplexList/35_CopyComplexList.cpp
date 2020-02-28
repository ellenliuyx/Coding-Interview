//==================================================================
// ����ָOffer������
//==================================================================

// ������35����������ĸ���
// ��Ŀ����ʵ�ֺ���ComplexListNode* Clone(ComplexListNode* pHead)����
// ��һ�����������ڸ��������У�ÿ����������һ��m_pNextָ��ָ����һ��
// ����⣬����һ��m_pSibling ָ�������е����������nullptr��

#include <iostream>
#include "ComplexList.h"
using namespace std;

//*****************************************************************************************//
//----------------------------------����һ���յĸ�������-----------------------------------//
//*****************************************************************************************//
ComplexListNode* CreateComplexList_Null()
{
	return nullptr;
}

//*****************************************************************************************//
//---------------------------------����һ�����ڵ㸴������----------------------------------//
//       ---
//       \ /
//        1
//*****************************************************************************************//
ComplexListNode* CreateComplexList_OneNode()
{
	ComplexListNode* p_Node1 = CreateComplexListNode(1);

	ConnectSibling(p_Node1, p_Node1);

	return p_Node1;
}

//*****************************************************************************************//
//-------------------------------����һ�������ڵ�ĸ�������--------------------------------//
//        ---------
//       \|/      |
//        1 ----> 2
//*****************************************************************************************//
ComplexListNode* CreateComplexList_TwoNodes()
{
	ComplexListNode* p_Node1 = CreateComplexListNode(1);
	ComplexListNode* p_Node2 = CreateComplexListNode(2);

	ConnectNext(p_Node1, p_Node2);

	ConnectSibling(p_Node2, p_Node1);

	return p_Node1;
}

//*****************************************************************************************//
//------------------------------------����һ����������-------------------------------------//
//                -----------------
//               \|/              |
//        1 ----> 2 ----> 3 ----> 4 ----> 5
//        |       |       /|\             |
//        --------|---------              |
//                |                       |
//                -------------------------
//*****************************************************************************************//
ComplexListNode* CreateComplexList()
{
	ComplexListNode* p_Node1 = CreateComplexListNode(1);
	ComplexListNode* p_Node2 = CreateComplexListNode(2);
	ComplexListNode* p_Node3 = CreateComplexListNode(3);
	ComplexListNode* p_Node4 = CreateComplexListNode(4);
	ComplexListNode* p_Node5 = CreateComplexListNode(5);

	ConnectNext(p_Node1, p_Node2);
	ConnectNext(p_Node2, p_Node3);
	ConnectNext(p_Node3, p_Node4);
	ConnectNext(p_Node4, p_Node5);

	ConnectSibling(p_Node1, p_Node3);
	ConnectSibling(p_Node2, p_Node5);
	ConnectSibling(p_Node4, p_Node2);

	return p_Node1;
}

//*****************************************************************************************//
//-------------------------------��һ�������Ƹ�������Ľڵ�--------------------------------//
//*****************************************************************************************//
void CloneComplexListNodes(ComplexListNode* p_Head)
{
	ComplexListNode* p_Node = p_Head;
	ComplexListNode* p_Clone;
	while (p_Node != nullptr)
	{
		p_Clone = CreateComplexListNode(p_Node->value);		//���ƽڵ�
		p_Clone->p_Next = p_Node->p_Next;					//�����ƽڵ���뵽ԭ����Ľڵ�֮��
		p_Node->p_Next = p_Clone;

		p_Node = p_Clone->p_Next;
	}
}

//*****************************************************************************************//
//-----------------------------�ڶ��������Ƹ��������sibling-------------------------------//
//*****************************************************************************************//
void CloneComplexListSibling(ComplexListNode* p_Head)
{
	ComplexListNode* p_Node = p_Head;
	while (p_Node != nullptr)
	{
		if (p_Node->p_Sibling != nullptr)			//����ýڵ���sibling������
		{
			p_Node->p_Next->p_Sibling = p_Node->p_Sibling->p_Next;
		}
		p_Node = p_Node->p_Next->p_Next;
	}
}

//*****************************************************************************************//
//------------------------------�������������������ֳ�����-------------------------------//
//*****************************************************************************************//
ComplexListNode* splitComplexList(ComplexListNode* p_Head)
{
	if (p_Head == nullptr)
		return nullptr;

	ComplexListNode* p_Node = p_Head;
	ComplexListNode* p_CloneHead = p_Head->p_Next;
	ComplexListNode* p_Clone;
	while (p_Node != nullptr)
	{
		p_Clone = p_Node->p_Next;
		p_Node->p_Next = p_Clone->p_Next;
		if (p_Node->p_Next == nullptr)		//�����������β
		{
			p_Clone->p_Next = nullptr;
			break;
		}
		p_Clone->p_Next = p_Node->p_Next->p_Next;

		p_Node = p_Node->p_Next;
	}
	return p_CloneHead;
}

//*****************************************************************************************//
//----------------------------------------���Ժ���-----------------------------------------//
//*****************************************************************************************//
void Test(ComplexListNode* (*func)(void))
{
	//------��������-------//
	ComplexListNode* p_Head = func();
	cout << "@ The original complex list: " << endl;
	PrintComplexList(p_Head);
	cout << endl;

	//------���ƽڵ�-------//
	CloneComplexListNodes(p_Head);
	cout << "@ After clone nodes: " << endl;
	PrintComplexList(p_Head);
	cout << endl;

	//------����sibling----//
	CloneComplexListSibling(p_Head);
	cout << "@ After clone siblings: " << endl;
	PrintComplexList(p_Head);
	cout << endl;

	//------�������-------//
	ComplexListNode* p_CloneHead = splitComplexList(p_Head);
	cout << "@ After split two complex lists: " << endl;
	cout << "The original complex list: " << endl;
	PrintComplexList(p_Head);
	cout << "The cloned complex list: " << endl;
	PrintComplexList(p_Head);

	cout << endl << endl;

	return;
}

//*****************************************************************************************//
//------------------------------------------������-----------------------------------------//
//*****************************************************************************************//
int main()
{
	Test(CreateComplexList_Null);		//��������1���ո�������
	Test(CreateComplexList_OneNode);	//��������2�����ڵ㸴������
	Test(CreateComplexList_TwoNodes);	//��������3��˫�ڵ㸴������
	Test(CreateComplexList);			//��������4��һ�㸴������

	return 0;
}