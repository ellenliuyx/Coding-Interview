//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题54：二叉搜索树的第k个结点
// 题目：给定一棵二叉搜索树，请找出其中的第k大的结点。

#include <iostream>
#include <assert.h>
using namespace std;

//******************************************************************//
//-------------------------二叉树节点结构体-------------------------//
//******************************************************************//
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* p_Left;
	BinaryTreeNode* p_Right;
};

//******************************************************************//
//------------------------创建一个二叉树节点------------------------//
//******************************************************************//
BinaryTreeNode* CreateNode(int value)
{
	BinaryTreeNode* p_Node = new BinaryTreeNode;
	p_Node->value = value;
	p_Node->p_Left = nullptr;
	p_Node->p_Right = nullptr;
	return p_Node;
}

//******************************************************************//
//------------------------连接三个二叉树节点------------------------//
//******************************************************************//
void ConnectNodes(BinaryTreeNode* p_Root, BinaryTreeNode* p_Left, BinaryTreeNode* p_Right)
{
	p_Root->p_Left = p_Left;
	p_Root->p_Right = p_Right;
}

//******************************************************************//
//--------------------中序遍历求第k大的二叉树节点-------------------//
//******************************************************************//
BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, int& k)
{
	BinaryTreeNode* target = nullptr;

	if (pRoot->p_Left != nullptr)				//一直向下找到最左下角的节点
		target = KthNodeCore(pRoot->p_Left, k);

	if (target == nullptr)						//若仍未找到第k个节点
	{
		if (k == 1)								//若此时k递减到1，则该节点就是第k个节点
			target = pRoot;
		k--;									//否则k--
	}

	if (target == nullptr && pRoot->p_Right != nullptr)		//若仍未找到第k个节点，且右子树不为空，则继续遍历右子树
		target = KthNodeCore(pRoot->p_Right, k);

	return target;
}

//******************************************************************//
//------------------------求第k大的二叉树节点-----------------------//
//******************************************************************//
BinaryTreeNode* KthNodeInBST(BinaryTreeNode* p_Root, int k)
{
	assert(p_Root != nullptr && k > 0);

	return KthNodeCore(p_Root, k);
}

//******************************************************************//
//--------------------------创建一个二叉树--------------------------//
//******************************************************************//
BinaryTreeNode* CreateTree()
{
	BinaryTreeNode* p_Node1 = CreateNode(5);
	BinaryTreeNode* p_Node2 = CreateNode(3);
	BinaryTreeNode* p_Node3 = CreateNode(7);
	BinaryTreeNode* p_Node4 = CreateNode(2);
	BinaryTreeNode* p_Node5 = CreateNode(4);
	BinaryTreeNode* p_Node6 = CreateNode(6);
	BinaryTreeNode* p_Node7 = CreateNode(8);

	ConnectNodes(p_Node1, p_Node2, p_Node3);
	ConnectNodes(p_Node2, p_Node4, p_Node5);
	ConnectNodes(p_Node3, p_Node6, p_Node7);

	return p_Node1;
}

//******************************************************************//
//------------------------------主函数------------------------------//
//******************************************************************//
int main()
{
	int k = 3;
	BinaryTreeNode* p_Root = CreateTree();
	BinaryTreeNode* target = KthNodeInBST(p_Root, k);
	cout << "第 " << k << " 大的节点是：" << target->value << endl;
	return 0;
}