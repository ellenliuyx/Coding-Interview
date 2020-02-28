//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题55（二）：平衡二叉树
// 题目：输入一棵二叉树的根结点，判断该树是不是平衡二叉树。如果某二叉树中
// 任意结点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。

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
//--------------利用二叉树的后序遍历判断二叉树是否平衡--------------//
//******************************************************************//
bool IsBalanceTree(BinaryTreeNode* p_Root, int* depth)
{
	if (p_Root == nullptr)		//若遍历到叶子节点，则记录深度为0，返回true
	{
		*depth = 0;
		return true;
	}
	
	int left, right;			//分别记录左右子树的深度

	//若左右子树均为平衡二叉树
	if (IsBalanceTree(p_Root->p_Left, &left) && IsBalanceTree(p_Root->p_Right, &right))
	{
		if (abs(left - right) <= 1)			//且以当前节点为根节点的二叉树也是平衡的
		{
			*depth = max(left, right) + 1;	//则更新树的深度，并返回true
			return true;
		}
	}
	return false;			//否则返回false
}

//******************************************************************//
//------------------------判断二叉树是否平衡------------------------//
//******************************************************************//
bool IsBalanceTree(BinaryTreeNode* p_Root)
{
	assert(p_Root != nullptr);

	int depth = 0;
	return IsBalanceTree(p_Root, &depth);	//传入记录树的深度的变量
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