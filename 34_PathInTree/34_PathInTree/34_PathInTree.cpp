//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题34：二叉树中和为某一值的路径
// 题目：输入一棵二叉树和一个整数，打印出二叉树中结点值的和为输入整数的所
// 有路径。从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。

#include <iostream>
#include <assert.h>
#include <vector>		//顺序容器：动态数组
using namespace std;

//************************************************************************************************//
//----------------------------------------二叉树节点结构体----------------------------------------//
//************************************************************************************************//
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* p_Left;
	BinaryTreeNode* p_Right;
};

//************************************************************************************************//
//---------------------------------------创建一个二叉树节点---------------------------------------//
//************************************************************************************************//
BinaryTreeNode* CreateNode(int value)
{
	BinaryTreeNode* p_Node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	p_Node->value = value;
	p_Node->p_Left = nullptr;
	p_Node->p_Right = nullptr;

	return p_Node;
}

//************************************************************************************************//
//---------------------------------------连接三个二叉树节点---------------------------------------//
//************************************************************************************************//
void ConnectNodes(BinaryTreeNode* p_Root, BinaryTreeNode* p_Left, BinaryTreeNode* p_Right)
{
	p_Root->p_Left = p_Left;
	p_Root->p_Right = p_Right;
}

//************************************************************************************************//
//---------------------------------------创建一个空的二叉树---------------------------------------//
//************************************************************************************************//
BinaryTreeNode* CreateTree_NULL()
{
	return nullptr;
}

//************************************************************************************************//
//-----------------------------------------创建一个二叉树-----------------------------------------//
//                   10
//                  /  \
//                 5   12
//                / \
//               4   7
//************************************************************************************************//
BinaryTreeNode* CreateTree_Original()
{
	BinaryTreeNode* p_Node1 = CreateNode(10);
	BinaryTreeNode* p_Node2 = CreateNode(5);
	BinaryTreeNode* p_Node3 = CreateNode(12);
	BinaryTreeNode* p_Node4 = CreateNode(4);
	BinaryTreeNode* p_Node5 = CreateNode(7);

	ConnectNodes(p_Node1, p_Node2, p_Node3);
	ConnectNodes(p_Node2, p_Node4, p_Node5);

	return p_Node1;
}

//************************************************************************************************//
//----------------------------------打印二叉树中和为某一只的路径----------------------------------//
//输入：p_Root（二叉树的根节点），vector<int> & path（存储路径上各个节点的动态数组），
//		InputSum（输入的路径之和），CurrentSum（当前的路径之和）
//************************************************************************************************//
void PrintPathInTree(BinaryTreeNode* p_Root, vector<int> & path, int InputSum, int CurrentSum)
{
	if (p_Root == nullptr)		//非法输入
		return;

	path.push_back(p_Root->value);		//将根节点入栈
	CurrentSum += p_Root->value;		//更新当前节点之和

	//若当前节点之和与输入的路径之和相等，且到达叶子节点时，打印vector模拟的栈中的路径
	if (CurrentSum == InputSum && p_Root->p_Left == nullptr && p_Root->p_Right == nullptr)
	{
		cout << "A path has been found: " << endl;

		//这里使用vector<int>类的iterator（迭代器，即为指针）index
		//path.begin()为path中的第一个元素的位置，path.end()为path中最后一个元素的后面一个位置
		for (vector<int>::iterator index = path.begin(); index < path.end(); index++)
		{
			cout<< *index <<"\t";	//打印index指针处的元素值
		}
		cout << endl;
	}

	//如果左右子树不为空，则递归前序遍历左右子树
	if (p_Root->p_Left != nullptr)
		PrintPathInTree(p_Root->p_Left, path, InputSum, CurrentSum);
	if (p_Root->p_Right != nullptr)
		PrintPathInTree(p_Root->p_Right, path, InputSum, CurrentSum);

	path.pop_back();			//将path栈的栈顶元素出栈
}

//************************************************************************************************//
//--------------------------------------------测试函数--------------------------------------------//
//************************************************************************************************//
void Test(BinaryTreeNode* (*func)(void), int InputSum)
{
	BinaryTreeNode* p_Root = func();

	assert(p_Root != nullptr);		//防御式编程

	vector<int> path;		//用vector动态数组模拟栈，方便路径的打印

	int CurrentSum = 0;

	PrintPathInTree(p_Root, path, InputSum, CurrentSum);

	cout << endl;
}

//************************************************************************************************//
//---------------------------------------------主函数---------------------------------------------//
//************************************************************************************************//
int main()
{
	Test(CreateTree_Original, 22);		//测试用例1：二叉树中有两条符合条件的路径
	Test(CreateTree_Original, 30);		//测试用例2：二叉树中没有符合条件的路径
	Test(CreateTree_NULL, 0);			//测试用例3：二叉树为空

	return 0;
}