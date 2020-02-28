//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题32（一）：不分行从上往下打印二叉树
// 题目：从上往下打印出二叉树的每个结点，同一层的结点按照从左到右的顺序打印。

#include <iostream>
#include <queue>
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
//                        1
//                      /   \
//                    2       3
//                   / \     / \
//                  4   5   6   7
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

	ConnectNodes(p_Node1, p_Node2, p_Node3);
	ConnectNodes(p_Node2, p_Node4, p_Node5);
	ConnectNodes(p_Node3, p_Node6, p_Node7);

	return p_Node1;
}

//*******************************************************************************************//
//-----------------------------------从上到下按层打印二叉树----------------------------------//
//*******************************************************************************************//
void PrintTree(BinaryTreeNode* p_Root)
{
	assert(p_Root != nullptr);			//防御式编程

	queue<BinaryTreeNode*> myQueue;		//新建队列类，每一个元素是一个二叉树节点
	myQueue.push(p_Root);				//将根节点入队

	while (!myQueue.empty())			//直到队列为空是结束循环
	{
		cout << myQueue.front()->value << '\t';			//打印对头元素
		if (myQueue.front()->p_Left != nullptr)			//若对头元素有左孩子，则将左孩子节点入队
		{
			myQueue.push(myQueue.front()->p_Left);
		}
		if (myQueue.front()->p_Right != nullptr)		//若对头元素有右孩子，则将右孩子节点入队
		{
			myQueue.push(myQueue.front()->p_Right);
		}
		myQueue.pop();									//将对头元素出队
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
