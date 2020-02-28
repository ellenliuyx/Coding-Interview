//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题28：对称的二叉树
// 题目：请实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和
// 它的镜像一样，那么它是对称的。

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
//---------------------------------创建一个对称的二叉树---------------------------------//
//				8
//			  /   \
//			6       6
//		   / \     / \
//		  5   7   7   5
//**************************************************************************************//
BinaryTreeNode* CreateTree_Symetrical()
{
	BinaryTreeNode* p_Node1 = CreateNode(8);
	BinaryTreeNode* p_Node2 = CreateNode(6);
	BinaryTreeNode* p_Node3 = CreateNode(6);
	BinaryTreeNode* p_Node4 = CreateNode(5);
	BinaryTreeNode* p_Node5 = CreateNode(7);
	BinaryTreeNode* p_Node6 = CreateNode(7);
	BinaryTreeNode* p_Node7 = CreateNode(5);

	ConnectNodes(p_Node1, p_Node2, p_Node3);
	ConnectNodes(p_Node2, p_Node4, p_Node5);
	ConnectNodes(p_Node3, p_Node6, p_Node7);

	return p_Node1;
}

//**************************************************************************************//
//---------------------------创建一个结构对称值不对称的二叉树---------------------------//
//				8
//			  /   \
//			6       9
//		   / \     / \
//		  5   7   7   5
//**************************************************************************************//
BinaryTreeNode* CreateTree_NotSymetrical_1()
{
	BinaryTreeNode* p_Node1 = CreateNode(8);
	BinaryTreeNode* p_Node2 = CreateNode(6);
	BinaryTreeNode* p_Node3 = CreateNode(9);
	BinaryTreeNode* p_Node4 = CreateNode(5);
	BinaryTreeNode* p_Node5 = CreateNode(7);
	BinaryTreeNode* p_Node6 = CreateNode(7);
	BinaryTreeNode* p_Node7 = CreateNode(5);

	ConnectNodes(p_Node1, p_Node2, p_Node3);
	ConnectNodes(p_Node2, p_Node4, p_Node5);
	ConnectNodes(p_Node3, p_Node6, p_Node7);

	return p_Node1;
}

//**************************************************************************************//
//------------------------------创建一个结构不对称的二叉树------------------------------//
//				8
//			  /   \
//			6       6
//		   / \     / 
//		  5   7   7   
//**************************************************************************************//
BinaryTreeNode* CreateTree_NotSymetrical_2()
{
	BinaryTreeNode* p_Node1 = CreateNode(8);
	BinaryTreeNode* p_Node2 = CreateNode(6);
	BinaryTreeNode* p_Node3 = CreateNode(6);
	BinaryTreeNode* p_Node4 = CreateNode(5);
	BinaryTreeNode* p_Node5 = CreateNode(7);
	BinaryTreeNode* p_Node6 = CreateNode(7);

	ConnectNodes(p_Node1, p_Node2, p_Node3);
	ConnectNodes(p_Node2, p_Node4, p_Node5);
	ConnectNodes(p_Node3, p_Node6, nullptr);

	return p_Node1;
}

//**************************************************************************************//
//-------------------------创建一个所有结点均相等的不对称二叉树-------------------------//
//				7
//			  /   \
//			7       7
//		   / \     / 
//		  7   7   7   
//**************************************************************************************//
BinaryTreeNode* CreateTree_NotSymetrical_3()
{
	BinaryTreeNode* p_Node1 = CreateNode(7);
	BinaryTreeNode* p_Node2 = CreateNode(7);
	BinaryTreeNode* p_Node3 = CreateNode(7);
	BinaryTreeNode* p_Node4 = CreateNode(7);
	BinaryTreeNode* p_Node5 = CreateNode(7);
	BinaryTreeNode* p_Node6 = CreateNode(7);

	ConnectNodes(p_Node1, p_Node2, p_Node3);
	ConnectNodes(p_Node2, p_Node4, p_Node5);
	ConnectNodes(p_Node3, p_Node6, nullptr);

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
//----------------------------------判断二叉树是否对称----------------------------------//
//**************************************************************************************//
bool IsSymetrical(BinaryTreeNode* p_Root1, BinaryTreeNode* p_Root2)
{
	if (p_Root1 == nullptr && p_Root2 == nullptr)		//若都为空指针，则一起到达叶子节点，返回true
		return true;

	if (p_Root1 == nullptr || p_Root2 == nullptr)		//若仅有一个为空指针，则不相同，返回false
		return false;

	if (p_Root1->value != p_Root2->value)				//若两二叉树的根节点值不同，则不相同，返回flase
		return false;

	return IsSymetrical(p_Root1->p_Left, p_Root2->p_Right)		//当二叉树1的左子树和二叉树2的右子树相同
		&& IsSymetrical(p_Root1->p_Right, p_Root2->p_Left);		//且二叉树1的右子树和二叉树2的左子树相同时，返回true
}

//**************************************************************************************//
//----------------------------------判断二叉树是否对称----------------------------------//
//**************************************************************************************//
bool IsSymetrical(BinaryTreeNode* p_Root)
{
	if (p_Root == nullptr)
		return false;

	return IsSymetrical(p_Root, p_Root);		//这里利用了函数的重载
}

//**************************************************************************************//
//---------------------------------------测试函数---------------------------------------//
//**************************************************************************************//
void Test(BinaryTreeNode* (*func)(void))
{
	BinaryTreeNode* p_Root = func();

	if (IsSymetrical(p_Root))
		cout << "该二叉树是对称的" << endl;
	else
		cout << "该二叉树是不对称的" << endl;

	DestoryTree(p_Root);
}

//**************************************************************************************//
//----------------------------------------主函数----------------------------------------//
//**************************************************************************************//
int main()
{
	Test(CreateTree_Null);					//测试用例1：空二叉树
	Test(CreateTree_Symetrical);			//测试用例2：对称的二叉树
	Test(CreateTree_NotSymetrical_1);		//测试用例3：结构对称值不对称的二叉树
	Test(CreateTree_NotSymetrical_2);		//测试用例4：结构不对称的二叉树
	Test(CreateTree_NotSymetrical_3);		//测试用例5：所有节点的值相等的不对称二叉树

	return 0;
}