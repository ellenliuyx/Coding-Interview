//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题26：树的子结构
// 题目：输入两棵二叉树A和B，判断B是不是A的子结构。

#include <iostream>
using namespace std;

//***********************************************************************************************//
//----------------------------------------二叉树节点结构体---------------------------------------//
//***********************************************************************************************//
struct BinaryTreeNode
{
	double value;
	BinaryTreeNode* p_Left;
	BinaryTreeNode* p_Right;
};

//***********************************************************************************************//
//---------------------------------------创建一个二叉树节点--------------------------------------//
//***********************************************************************************************//
BinaryTreeNode* CreateNode(double value)
{
	BinaryTreeNode* p_Node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	p_Node->value = value;
	p_Node->p_Left = nullptr;
	p_Node->p_Right = nullptr;

	return p_Node;
}

//***********************************************************************************************//
//---------------------------------------连接三个二叉树节点--------------------------------------//
//***********************************************************************************************//
void ConnectNodes(BinaryTreeNode* p_Root, BinaryTreeNode* p_Left, BinaryTreeNode* p_Right)
{
	p_Root->p_Left = p_Left;
	p_Root->p_Right = p_Right;
}

//***********************************************************************************************//
//---------------------------------------创建一个空的二叉树--------------------------------------//
//***********************************************************************************************//
BinaryTreeNode* CreateBinaryTreeNull()
{
	return nullptr;
}

//***********************************************************************************************//
//----------------------------------------创建一个二叉树A----------------------------------------//
//                8
//              /   \
//             8     7
//           /   \
//          9     2
//              /   \
//             4     7
//***********************************************************************************************//
BinaryTreeNode* CreateBinaryTreeA()
{
	BinaryTreeNode* p_Node1 = CreateNode(8.0);
	BinaryTreeNode* p_Node2 = CreateNode(8.0);
	BinaryTreeNode* p_Node3 = CreateNode(7.0);
	BinaryTreeNode* p_Node4 = CreateNode(9.0);
	BinaryTreeNode* p_Node5 = CreateNode(2.0);
	BinaryTreeNode* p_Node6 = CreateNode(4.0);
	BinaryTreeNode* p_Node7 = CreateNode(7.0);

	ConnectNodes(p_Node1, p_Node2, p_Node3);
	ConnectNodes(p_Node2, p_Node4, p_Node5);
	ConnectNodes(p_Node5, p_Node6, p_Node7);

	return p_Node1;
}

//***********************************************************************************************//
//--------------------------------创建一个二叉树B（B是A的子结构）--------------------------------//
//             8     
//           /   \
//          9     2
//***********************************************************************************************//
BinaryTreeNode* CreateBinaryTreeB_Contain()
{
	BinaryTreeNode* p_Node1 = CreateNode(8.0);
	BinaryTreeNode* p_Node2 = CreateNode(9.0);
	BinaryTreeNode* p_Node3 = CreateNode(2.0);
	
	ConnectNodes(p_Node1, p_Node2, p_Node3);

	return p_Node1;
}

//***********************************************************************************************//
//-------------------------------创建一个二叉树B（B不是A的子结构）-------------------------------//
//             8     
//           /   \
//          9     7
//***********************************************************************************************//
BinaryTreeNode* CreateBinaryTreeB_NotContain()
{
	BinaryTreeNode* p_Node1 = CreateNode(8.0);
	BinaryTreeNode* p_Node2 = CreateNode(9.0);
	BinaryTreeNode* p_Node3 = CreateNode(7.0);

	ConnectNodes(p_Node1, p_Node2, p_Node3);

	return p_Node1;
}

//***********************************************************************************************//
//------------------------------------释放一个二叉树所占的内存-----------------------------------//
//***********************************************************************************************//
void DestroyTree(BinaryTreeNode* p_Root)
{
	if (p_Root == nullptr)
		return;

	BinaryTreeNode* p_Left = p_Root->p_Left;		//用指针指向左右子树
	BinaryTreeNode* p_Right = p_Root->p_Right;

	delete p_Root;									//释放根节点内存

	DestroyTree(p_Left);							//递归释放左右子树内存
	DestroyTree(p_Right);
}

//***********************************************************************************************//
//-------------------------------------判断两个浮点数是否相等------------------------------------//
//***********************************************************************************************//
bool Equal(double a, double b)
{
	return abs(a - b) < 0.0000001;
}

//***********************************************************************************************//
//----------------------------从根节点开始判断两个二叉树是否为包含关系---------------------------//
//***********************************************************************************************//
bool DoesTree1HasTree2(BinaryTreeNode* p_Root1, BinaryTreeNode* p_Root2)
{
	if (p_Root2 == nullptr)			//若p_Root2为空，则说明已经到达B树的叶子节点，则匹配成功
		return true;

	if (p_Root1 == nullptr)			//若p_Root1为空，则说明已经到达A树的叶子节点，则匹配失败
		return false;

	if (Equal(p_Root1->value, p_Root2->value))		//若根结点值相等，则继续判断左右子树的根节点是否相等
		return DoesTree1HasTree2(p_Root1->p_Left, p_Root2->p_Left) 
			&& DoesTree1HasTree2(p_Root1->p_Right, p_Root2->p_Right);

	else							//若根结点值不相等，则匹配失败
		return false;
}

//***********************************************************************************************//
//---------------------------从A树的根节点开始寻找与B树根节点相等的节点--------------------------//
//***********************************************************************************************//
bool HasSubTree(BinaryTreeNode* p_Root1, BinaryTreeNode* p_Root2)
{
	if (p_Root1 == nullptr || p_Root2 == nullptr)		//若p_Root1或p_Root2为空，则说明到达A树或B树的叶子节点，则匹配失败
		return false;

	if (Equal(p_Root1->value, p_Root2->value))			//如果根节点值相等，则调用DoesTree1HasTree2函数从根节点开始判断两个二叉树是否为包含关系
	{
		if (DoesTree1HasTree2(p_Root1, p_Root2))
			return true;
	}
	return HasSubTree(p_Root1->p_Left, p_Root2)			//若根结点值不相等，或者从相等的根节点开始的两个二叉树不为包含关系
		|| HasSubTree(p_Root1->p_Right, p_Root2);		//则继续判断左右子树，左右子树有一支满足包含关系即可
}

//***********************************************************************************************//
//---------------------------------------测试并打印结果函数--------------------------------------//
//***********************************************************************************************//
void TestAndPrint(BinaryTreeNode* (*func1)(void), BinaryTreeNode* (*func2)(void))
{
	BinaryTreeNode* p_Root1 = func1();
	BinaryTreeNode* p_Root2 = func2();

	if (HasSubTree(p_Root1, p_Root2))
		cout << "树A包含树B" << endl;
	else
		cout << "树A不包含树B" << endl;

	DestroyTree(p_Root1);
	DestroyTree(p_Root2);
}

//***********************************************************************************************//
//---------------------------------------------主函数--------------------------------------------//
//***********************************************************************************************//
int main()
{
	TestAndPrint(CreateBinaryTreeNull, CreateBinaryTreeNull);		//测试用例1：两个树均为空
	TestAndPrint(CreateBinaryTreeA, CreateBinaryTreeNull);			//测试用例2：一个树为空，另一个树非空
	TestAndPrint(CreateBinaryTreeA, CreateBinaryTreeB_Contain);		//测试用例3：两个树均非空且满足包含关系
	TestAndPrint(CreateBinaryTreeA, CreateBinaryTreeB_NotContain);	//测试用例4：两个树均非空且不满足包含关系

	return 0;
}