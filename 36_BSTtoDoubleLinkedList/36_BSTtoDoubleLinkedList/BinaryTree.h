#pragma once

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* p_Left;
	BinaryTreeNode* p_Right;
};

BinaryTreeNode* CreateBinaryTreeNode(int value);
void ConnectBinaryTreeNodes(BinaryTreeNode* p_Root, BinaryTreeNode* p_Left, BinaryTreeNode* p_Right);
void PrintDoubleLinkedList(BinaryTreeNode* p_Head);

BinaryTreeNode* CreateBinaryTree_Null();
BinaryTreeNode* CreateBinaryTree_OneNode();
BinaryTreeNode* CreateBinaryTree_OnlyLeft();
BinaryTreeNode* CreateBinaryTree_OnlyRight();
BinaryTreeNode* CreateBinaryTree_Complete();