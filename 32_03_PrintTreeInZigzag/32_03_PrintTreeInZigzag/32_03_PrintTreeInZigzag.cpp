//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题32（三）：之字形打印二叉树
// 题目：请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺
// 序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，
// 其他行以此类推。

#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

//*******************************************************************************************//
//--------------------------------------二叉树节点结构体-------------------------------------//
//*******************************************************************************************//
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* p_Left;
	BinaryTreeNode* p_Right;
};

//*******************************************************************************************//
//-------------------------------------创建一个二叉树节点------------------------------------//
//*******************************************************************************************//
BinaryTreeNode* CreateBinaryTreeNode(int value)
{
	BinaryTreeNode* p_Node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	p_Node->value = value;
	p_Node->p_Left = nullptr;
	p_Node->p_Right = nullptr;

	return p_Node;
}

//*******************************************************************************************//
//-------------------------------------连接三个二叉树节点------------------------------------//
//*******************************************************************************************//
void ConnectNodes(BinaryTreeNode* p_Root, BinaryTreeNode* p_Left, BinaryTreeNode* p_Right)
{
	p_Root->p_Left = p_Left;
	p_Root->p_Right = p_Right;
}

//*******************************************************************************************//
//-------------------------------------创建一个空的二叉树------------------------------------//
//*******************************************************************************************//
BinaryTreeNode* CreateTree_Null()
{
	return nullptr;
}

//*******************************************************************************************//
//------------------------------------创建一个单节点二叉树-----------------------------------//
//              1
//*******************************************************************************************//
BinaryTreeNode* CreateTree_OneNode()
{
	BinaryTreeNode* p_Root = CreateBinaryTreeNode(1);

	return p_Root;
}

//*******************************************************************************************//
//---------------------------------创建一个只有左子树的二叉树--------------------------------//
//                      1
//                     /
//                    2
//                   /
//                  3
//                 /
//                4
//*******************************************************************************************//
BinaryTreeNode* CreateTree_OnlyLeft()
{
	BinaryTreeNode* p_Node1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* p_Node2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* p_Node3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* p_Node4 = CreateBinaryTreeNode(4);

	ConnectNodes(p_Node1, p_Node2, nullptr);
	ConnectNodes(p_Node2, p_Node3, nullptr);
	ConnectNodes(p_Node3, p_Node4, nullptr);

	return p_Node1;
}

//*******************************************************************************************//
//---------------------------------创建一个只有右子树的二叉树--------------------------------//
//                1
//                 \
//                  2
//                   \
//                    3
//                     \
//                      4
//*******************************************************************************************//
BinaryTreeNode* CreateTree_OnlyRight()
{
	BinaryTreeNode* p_Node1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* p_Node2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* p_Node3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* p_Node4 = CreateBinaryTreeNode(4);

	ConnectNodes(p_Node1, nullptr, p_Node2);
	ConnectNodes(p_Node2, nullptr, p_Node3);
	ConnectNodes(p_Node3, nullptr, p_Node4);

	return p_Node1;
}

//*******************************************************************************************//
//-------------------------------------创建一个完全二叉树------------------------------------//
//                           1
//                       /       \
//                     2           3
//                   /   \       /   \
//                  4     5     6     7
//                 / \   / \   / \   / \
//                8   9 10 11 12 13 14 15
//*******************************************************************************************//
BinaryTreeNode* CreateTree_Complete()
{
	BinaryTreeNode* p_Node1 = CreateBinaryTreeNode(1);
	BinaryTreeNode* p_Node2 = CreateBinaryTreeNode(2);
	BinaryTreeNode* p_Node3 = CreateBinaryTreeNode(3);
	BinaryTreeNode* p_Node4 = CreateBinaryTreeNode(4);
	BinaryTreeNode* p_Node5 = CreateBinaryTreeNode(5);
	BinaryTreeNode* p_Node6 = CreateBinaryTreeNode(6);
	BinaryTreeNode* p_Node7 = CreateBinaryTreeNode(7);
	BinaryTreeNode* p_Node8 = CreateBinaryTreeNode(8);
	BinaryTreeNode* p_Node9 = CreateBinaryTreeNode(9);
	BinaryTreeNode* p_Node10 = CreateBinaryTreeNode(10);
	BinaryTreeNode* p_Node11 = CreateBinaryTreeNode(11);
	BinaryTreeNode* p_Node12 = CreateBinaryTreeNode(12);
	BinaryTreeNode* p_Node13 = CreateBinaryTreeNode(13);
	BinaryTreeNode* p_Node14 = CreateBinaryTreeNode(14);
	BinaryTreeNode* p_Node15 = CreateBinaryTreeNode(15);

	ConnectNodes(p_Node1, p_Node2, p_Node3);
	ConnectNodes(p_Node2, p_Node4, p_Node5);
	ConnectNodes(p_Node3, p_Node6, p_Node7);
	ConnectNodes(p_Node4, p_Node8, p_Node9);
	ConnectNodes(p_Node5, p_Node10, p_Node11);
	ConnectNodes(p_Node6, p_Node12, p_Node13);
	ConnectNodes(p_Node7, p_Node14, p_Node15);

	return p_Node1;
}

//*******************************************************************************************//
//--------------------------------从上到下按层之字形打印二叉树-------------------------------//
//*******************************************************************************************//
void PrintTree(BinaryTreeNode* p_Root)
{
	assert(p_Root != nullptr);			//防御式编程

	stack<BinaryTreeNode*> myStack[2];	//用数组的形式创建两个栈，栈的下标方便其切换

	int current = 0, next = 1;			//当前层节点使用的栈下标，及下一层节点使用的栈下标

	myStack[current].push(p_Root);		//先把根节点入current栈

	while (!myStack[0].empty() || !myStack[1].empty())		//当两个栈都为空时，结束循环
	{
		cout << myStack[current].top()->value << '\t';		//输出current栈的栈顶节点
		if (current == 0)									//如果current栈是0号栈，当前层为奇数层
		{
			if (myStack[current].top()->p_Left != nullptr)	//按照先左后右的顺序将孩子节点入next栈
			{
				myStack[next].push(myStack[current].top()->p_Left);
			}
			if (myStack[current].top()->p_Right != nullptr)
			{
				myStack[next].push(myStack[current].top()->p_Right);
			}
		}
		else												//如果current栈是1号栈
		{
			if (myStack[current].top()->p_Right != nullptr)	//按照先左后右的顺序将孩子节点入next栈
			{
				myStack[next].push(myStack[current].top()->p_Right);
			}
			if (myStack[current].top()->p_Left != nullptr)
			{
				myStack[next].push(myStack[current].top()->p_Left);
			}
		}
		myStack[current].pop();								//弹出当前栈的栈顶节点
		if (myStack[current].empty())						//如果当前栈为空，则说明本层节点已经打印完成
		{
			cout << endl;									//打印换行符
			swap(current, next);							//交换current栈和next栈的下标
		}
	}
}

//*******************************************************************************************//
//------------------------------------------测试函数-----------------------------------------//
//*******************************************************************************************//
void Test(BinaryTreeNode* (*func)(void))
{
	PrintTree(func());
	cout << endl << endl;
}

//*******************************************************************************************//
//-------------------------------------------主函数------------------------------------------//
//*******************************************************************************************//
int main()
{
	Test(CreateTree_OneNode);		//测试用例1：单节点二叉树
	Test(CreateTree_OnlyLeft);		//测试用例2：只有左子树的二叉树
	Test(CreateTree_OnlyRight);		//测试用例3：只有右子树的二叉树
	Test(CreateTree_Complete);		//测试用例4：完全二叉树
	Test(CreateTree_Null);			//测试用例5：空二叉树

	return 0;
}
