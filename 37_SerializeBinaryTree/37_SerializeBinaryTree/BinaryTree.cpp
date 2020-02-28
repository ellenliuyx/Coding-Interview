#include "BinaryTree.h"
#include <iostream>
#include <assert.h>
using namespace std;

BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* p_Node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	p_Node->value = value;
	p_Node->p_Left = nullptr;
	p_Node->p_Right = nullptr;

	return p_Node;
}

void ConnectBinaryTreeNodes(BinaryTreeNode* p_Root, BinaryTreeNode* p_Left, BinaryTreeNode* p_Right)
{
	p_Root->p_Left = p_Left;
	p_Root->p_Right = p_Right;
}

BinaryTreeNode* CreateBinaryTree_Null()
{
	return nullptr;
}

BinaryTreeNode* CreateBinaryTree_OneNode()
{
	BinaryTreeNode* p_Node1 = CreateBinaryTreeNode(1);

	return p_Node1;
}

BinaryTreeNode* CreateBinaryTree_OnlyLeft()
{
	BinaryTreeNode* p_Node1 = CreateBinaryTreeNode(4);
	BinaryTreeNode* p_Node2 = CreateBinaryTreeNode(3);
	BinaryTreeNode* p_Node3 = CreateBinaryTreeNode(2);
	BinaryTreeNode* p_Node4 = CreateBinaryTreeNode(1);

	ConnectBinaryTreeNodes(p_Node1, p_Node2, nullptr);
	ConnectBinaryTreeNodes(p_Node2, p_Node3, nullptr);
	ConnectBinaryTreeNodes(p_Node3, p_Node4, nullptr);

	return p_Node1;
}

BinaryTreeNode* CreateBinaryTree_OnlyRight()
{
	BinaryTreeNode* p_Node1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* p_Node2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* p_Node3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* p_Node4 = CreateBinaryTreeNode(4);

	ConnectBinaryTreeNodes(p_Node1, nullptr, p_Node2);
	ConnectBinaryTreeNodes(p_Node2, nullptr, p_Node3);
	ConnectBinaryTreeNodes(p_Node3, nullptr, p_Node4);

	return p_Node1;
}

BinaryTreeNode* CreateBinaryTree_Complete()
{
	BinaryTreeNode* p_Node1 = CreateBinaryTreeNode(10);
	BinaryTreeNode* p_Node2 = CreateBinaryTreeNode(6);
	BinaryTreeNode* p_Node3 = CreateBinaryTreeNode(14);
	BinaryTreeNode* p_Node4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* p_Node5 = CreateBinaryTreeNode(8);
	BinaryTreeNode* p_Node6 = CreateBinaryTreeNode(12);
	BinaryTreeNode* p_Node7 = CreateBinaryTreeNode(16);

	ConnectBinaryTreeNodes(p_Node1, p_Node2, p_Node3);
	ConnectBinaryTreeNodes(p_Node2, p_Node4, p_Node5);
	ConnectBinaryTreeNodes(p_Node3, p_Node6, p_Node7);

	return p_Node1;
}

void PrintDoubleLinkedList(BinaryTreeNode* p_Head)
{
	assert(p_Head != nullptr);

	BinaryTreeNode* p_Node = p_Head;

	cout << "从头至尾打印链表：" << endl;
	cout << p_Node->value << "\t";
	while (p_Node->p_Right != nullptr)
	{
		p_Node = p_Node->p_Right;
		cout<< p_Node->value << "\t";
	}
	cout << endl;

	cout << "从尾至头打印链表：" << endl;
	while (p_Node != nullptr)
	{
		cout << p_Node->value << "\t";
		p_Node = p_Node->p_Left;
	}
	cout << endl << endl;
}