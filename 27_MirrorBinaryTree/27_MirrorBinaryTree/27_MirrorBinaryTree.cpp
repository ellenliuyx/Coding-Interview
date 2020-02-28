//==================================================================
// ����ָOffer������
//==================================================================

// ������27���������ľ���
// ��Ŀ�������һ������������һ�����������ú���������ľ���

#include <iostream>
using namespace std;

//**************************************************************************************//
//-----------------------------------�������ڵ�ṹ��-----------------------------------//
//**************************************************************************************//
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* p_Left;
	BinaryTreeNode* p_Right;
};

//**************************************************************************************//
//----------------------------------����һ���������ڵ�----------------------------------//
//**************************************************************************************//
BinaryTreeNode* CreateNode(int value)
{
	BinaryTreeNode* p_Node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	p_Node->value = value;
	p_Node->p_Left = nullptr;
	p_Node->p_Right = nullptr;

	return p_Node;
}

//**************************************************************************************//
//----------------------------------���������������ڵ�----------------------------------//
//**************************************************************************************//
void ConnectNodes(BinaryTreeNode* p_Root, BinaryTreeNode* p_Left, BinaryTreeNode* p_Right)
{
	p_Root->p_Left = p_Left;
	p_Root->p_Right = p_Right;
}

//**************************************************************************************//
//---------------------------------����һ����ָ�������---------------------------------//
//**************************************************************************************//
BinaryTreeNode* CreateTree_Null()
{
	return nullptr;
}

//**************************************************************************************//
//------------------------------����һ��ֻ���������Ķ�����------------------------------//
//				1
//			   /
//            2
//			 /
//			3
//		   /
//		  4
//**************************************************************************************//
BinaryTreeNode* CreateTree_OnlyLeft()
{
	BinaryTreeNode* p_Node1 = CreateNode(1);
	BinaryTreeNode* p_Node2 = CreateNode(2);
	BinaryTreeNode* p_Node3 = CreateNode(3);
	BinaryTreeNode* p_Node4 = CreateNode(4);

	ConnectNodes(p_Node1, p_Node2, nullptr);
	ConnectNodes(p_Node2, p_Node3, nullptr);
	ConnectNodes(p_Node3, p_Node4, nullptr);

	return p_Node1;
}

//**************************************************************************************//
//------------------------------����һ��ֻ���������Ķ�����------------------------------//
//		  1
//		   \
//          2
//			 \
//			  3
//		       \
//			    4
//**************************************************************************************//
BinaryTreeNode* CreateTree_OnlyRight()
{
	BinaryTreeNode* p_Node1 = CreateNode(1);
	BinaryTreeNode* p_Node2 = CreateNode(2);
	BinaryTreeNode* p_Node3 = CreateNode(3);
	BinaryTreeNode* p_Node4 = CreateNode(4);

	ConnectNodes(p_Node1, nullptr, p_Node2);
	ConnectNodes(p_Node2, nullptr, p_Node3);
	ConnectNodes(p_Node3, nullptr, p_Node4);

	return p_Node1;
}

//**************************************************************************************//
//------------------------------����һ�������������Ķ�����------------------------------//
//				1
//			  /   \
//			2       3
//		   / \     / \
//		  4   5   6   7
//**************************************************************************************//
BinaryTreeNode* CreateTree_BothSide()
{
	BinaryTreeNode* p_Node1 = CreateNode(1);
	BinaryTreeNode* p_Node2 = CreateNode(2);
	BinaryTreeNode* p_Node3 = CreateNode(3);
	BinaryTreeNode* p_Node4 = CreateNode(4);
	BinaryTreeNode* p_Node5 = CreateNode(5);
	BinaryTreeNode* p_Node6 = CreateNode(6);
	BinaryTreeNode* p_Node7 = CreateNode(7);

	ConnectNodes(p_Node1, p_Node2, p_Node3);
	ConnectNodes(p_Node2, p_Node4, p_Node5);
	ConnectNodes(p_Node3, p_Node6, p_Node7);

	return p_Node1;
}

//**************************************************************************************//
//---------------------------------�ͷŶ��������ڴ�ռ�---------------------------------//
//**************************************************************************************//
void DestoryTree(BinaryTreeNode* p_Root)
{
	if (p_Root == nullptr)
		return;

	BinaryTreeNode* p_Left = p_Root->p_Left;
	BinaryTreeNode* p_Right = p_Root->p_Right;

	delete p_Root;
	p_Root = nullptr;

	DestoryTree(p_Left);
	DestoryTree(p_Right);
}

//**************************************************************************************//
//------------------------------------������������------------------------------------//
//**************************************************************************************//
void MirrorBinaryTree(BinaryTreeNode* p_Root)
{
	if (p_Root != nullptr)		//���ڵ�ǿգ��ն�����/����Ҷ�ӽڵ㣩
	{
		BinaryTreeNode* p_Temp = p_Root->p_Left;	//������������
		p_Root->p_Left = p_Root->p_Right;
		p_Root->p_Right = p_Temp;

		MirrorBinaryTree(p_Root->p_Left);			//�����������ݹ���þ�����
		MirrorBinaryTree(p_Root->p_Right);
	}
}

//**************************************************************************************//
//---------------------------------------���Ժ���---------------------------------------//
//**************************************************************************************//
void Test(BinaryTreeNode* (*func)(void))
{
	BinaryTreeNode* p_Root = func();
	MirrorBinaryTree(p_Root);		//�ڴ˴���ϵ�۲쾵�������
	DestoryTree(p_Root);
}

//**************************************************************************************//
//----------------------------------------������----------------------------------------//
//**************************************************************************************//
int main()
{
	Test(CreateTree_Null);			//��������1����ָ�������
	Test(CreateTree_OnlyLeft);		//��������2��ֻ���������Ķ�����
	Test(CreateTree_OnlyRight);		//��������3��ֻ���������Ķ�����
	Test(CreateTree_BothSide);		//��������4�������������Ķ�����

	return 0;
}