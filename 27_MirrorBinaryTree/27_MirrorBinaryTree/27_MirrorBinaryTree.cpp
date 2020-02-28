//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题27：二叉树的镜像
// 题目：请完成一个函数，输入一个二叉树，该函数输出它的镜像。

#include <iostream>
using namespace std;

//**************************************************************************************//
//-----------------------------------二叉树节点结构体-----------------------------------//
//**************************************************************************************//
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* p_Left;
	BinaryTreeNode* p_Right;
};

//**************************************************************************************//
//----------------------------------创建一个二叉树节点----------------------------------//
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
//----------------------------------连接三个二叉树节点----------------------------------//
//**************************************************************************************//
void ConnectNodes(BinaryTreeNode* p_Root, BinaryTreeNode* p_Left, BinaryTreeNode* p_Right)
{
	p_Root->p_Left = p_Left;
	p_Root->p_Right = p_Right;
}

//**************************************************************************************//
//---------------------------------创建一个空指针二叉树---------------------------------//
//**************************************************************************************//
BinaryTreeNode* CreateTree_Null()
{
	return nullptr;
}

//**************************************************************************************//
//------------------------------创建一个只有左子树的二叉树------------------------------//
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
//------------------------------创建一个只有右子树的二叉树------------------------------//
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
//------------------------------创建一个有左右子树的二叉树------------------------------//
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
//---------------------------------释放二叉树的内存空间---------------------------------//
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
//------------------------------------二叉树镜像函数------------------------------------//
//**************************************************************************************//
void MirrorBinaryTree(BinaryTreeNode* p_Root)
{
	if (p_Root != nullptr)		//根节点非空（空二叉树/到达叶子节点）
	{
		BinaryTreeNode* p_Temp = p_Root->p_Left;	//交换左右子树
		p_Root->p_Left = p_Root->p_Right;
		p_Root->p_Right = p_Temp;

		MirrorBinaryTree(p_Root->p_Left);			//对左右子树递归调用镜像函数
		MirrorBinaryTree(p_Root->p_Right);
	}
}

//**************************************************************************************//
//---------------------------------------测试函数---------------------------------------//
//**************************************************************************************//
void Test(BinaryTreeNode* (*func)(void))
{
	BinaryTreeNode* p_Root = func();
	MirrorBinaryTree(p_Root);		//在此处打断点观察镜像二叉树
	DestoryTree(p_Root);
}

//**************************************************************************************//
//----------------------------------------主函数----------------------------------------//
//**************************************************************************************//
int main()
{
	Test(CreateTree_Null);			//测试用例1：空指针二叉树
	Test(CreateTree_OnlyLeft);		//测试用例2：只有左子树的二叉树
	Test(CreateTree_OnlyRight);		//测试用例3：只有右子树的二叉树
	Test(CreateTree_BothSide);		//测试用例4：有左右子树的二叉树

	return 0;
}