//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题35：复杂链表的复制
// 题目：请实现函数ComplexListNode* Clone(ComplexListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

#include <iostream>
#include "ComplexList.h"
using namespace std;

//*****************************************************************************************//
//----------------------------------创建一个空的复杂链表-----------------------------------//
//*****************************************************************************************//
ComplexListNode* CreateComplexList_Null()
{
	return nullptr;
}

//*****************************************************************************************//
//---------------------------------创建一个单节点复杂链表----------------------------------//
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
//-------------------------------创建一个两个节点的复杂链表--------------------------------//
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
//------------------------------------创建一个复杂链表-------------------------------------//
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
//-------------------------------第一步：复制复杂链表的节点--------------------------------//
//*****************************************************************************************//
void CloneComplexListNodes(ComplexListNode* p_Head)
{
	ComplexListNode* p_Node = p_Head;
	ComplexListNode* p_Clone;
	while (p_Node != nullptr)
	{
		p_Clone = CreateComplexListNode(p_Node->value);		//复制节点
		p_Clone->p_Next = p_Node->p_Next;					//将复制节点插入到原链表的节点之后
		p_Node->p_Next = p_Clone;

		p_Node = p_Clone->p_Next;
	}
}

//*****************************************************************************************//
//-----------------------------第二步：复制复杂链表的sibling-------------------------------//
//*****************************************************************************************//
void CloneComplexListSibling(ComplexListNode* p_Head)
{
	ComplexListNode* p_Node = p_Head;
	while (p_Node != nullptr)
	{
		if (p_Node->p_Sibling != nullptr)			//如果该节点有sibling，则复制
		{
			p_Node->p_Next->p_Sibling = p_Node->p_Sibling->p_Next;
		}
		p_Node = p_Node->p_Next->p_Next;
	}
}

//*****************************************************************************************//
//------------------------------第三步：将复杂链表拆分成两个-------------------------------//
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
		if (p_Node->p_Next == nullptr)		//到复杂链表结尾
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
//----------------------------------------测试函数-----------------------------------------//
//*****************************************************************************************//
void Test(ComplexListNode* (*func)(void))
{
	//------创建链表-------//
	ComplexListNode* p_Head = func();
	cout << "@ The original complex list: " << endl;
	PrintComplexList(p_Head);
	cout << endl;

	//------复制节点-------//
	CloneComplexListNodes(p_Head);
	cout << "@ After clone nodes: " << endl;
	PrintComplexList(p_Head);
	cout << endl;

	//------复制sibling----//
	CloneComplexListSibling(p_Head);
	cout << "@ After clone siblings: " << endl;
	PrintComplexList(p_Head);
	cout << endl;

	//------拆分链表-------//
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
//------------------------------------------主函数-----------------------------------------//
//*****************************************************************************************//
int main()
{
	Test(CreateComplexList_Null);		//测试用例1：空复杂链表
	Test(CreateComplexList_OneNode);	//测试用例2：单节点复杂链表
	Test(CreateComplexList_TwoNodes);	//测试用例3：双节点复杂链表
	Test(CreateComplexList);			//测试用例4：一般复杂链表

	return 0;
}