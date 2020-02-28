//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题55（一）：二叉树的深度
// 题目：输入一棵二叉树的根结点，求该树的深度。从根结点到叶结点依次经过的
// 结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

#include <iostream>
#include <assert.h>
#include <algorithm>
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
//------------------------释放二叉树内存空间------------------------//
//******************************************************************//
void DestroyTree(BinaryTreeNode* p_Root)
{
	if (p_Root == nullptr)
		return;

	DestroyTree(p_Root->p_Left);
	DestroyTree(p_Root->p_Right);

	delete p_Root;
	p_Root = nullptr;
}

//******************************************************************//
//------------------------求二叉树的深度函数------------------------//
//******************************************************************//
int TreeDepth(BinaryTreeNode* p_Root)
{
	if (p_Root == nullptr)
		return 0;

	int left = TreeDepth(p_Root->p_Left);
	int right = TreeDepth(p_Root->p_Right);

	return max(left, right) + 1;
}

//******************************************************************//
//----------------利用二叉树的深度判断二叉树是否平衡----------------//
//******************************************************************//
bool IsBalanceTree(BinaryTreeNode* p_Root)
{
	assert(p_Root != nullptr);

	int left = TreeDepth(p_Root->p_Left);
	int right = TreeDepth(p_Root->p_Right);

	if (abs(left - right) <= 1)
		return true;
	else
		return false;
}

//******************************************************************//
//-----------------------测试用例1：平衡二叉树----------------------//
//******************************************************************//
void Test1()
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

	BinaryTreeNode* p_Root = p_Node1;

	if (IsBalanceTree(p_Root))
		cout << "该二叉树是平衡的" << endl;
	else
		cout << "该二叉树不是平衡的" << endl;

	DestroyTree(p_Root);
}

//******************************************************************//
//----------------------测试用例2：非平衡二叉树---------------------//
//******************************************************************//
void Test2()
{
	BinaryTreeNode* p_Node1 = CreateNode(1);
	BinaryTreeNode* p_Node2 = CreateNode(2);
	BinaryTreeNode* p_Node3 = CreateNode(3);
	BinaryTreeNode* p_Node4 = CreateNode(4);

	ConnectNodes(p_Node1, p_Node2, nullptr);
	ConnectNodes(p_Node2, p_Node3, nullptr);
	ConnectNodes(p_Node3, p_Node4, nullptr);

	BinaryTreeNode* p_Root = p_Node1;

	if (IsBalanceTree(p_Root))
		cout << "该二叉树是平衡的" << endl;
	else
		cout << "该二叉树不是平衡的" << endl;

	DestroyTree(p_Root);
}

//******************************************************************//
//------------------------测试用例3：空二叉树-----------------------//
//******************************************************************//
void Test3()
{
	BinaryTreeNode* p_Root = nullptr;

	if (IsBalanceTree(p_Root))
		cout << "该二叉树是平衡的" << endl;
	else
		cout << "该二叉树不是平衡的" << endl;

	DestroyTree(p_Root);
}

//******************************************************************//
//------------------------------主函数------------------------------//
//******************************************************************//
int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}