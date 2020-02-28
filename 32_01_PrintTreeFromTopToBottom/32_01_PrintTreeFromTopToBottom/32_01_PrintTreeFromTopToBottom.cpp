//==================================================================
// ����ָOffer������
//==================================================================

// ������32��һ���������д������´�ӡ������
// ��Ŀ���������´�ӡ����������ÿ����㣬ͬһ��Ľ�㰴�մ����ҵ�˳���ӡ��

#include <iostream>
#include <queue>
#include <assert.h>
using namespace std;

//*******************************************************************************************//
//--------------------------------------�������ڵ�ṹ��-------------------------------------//
//*******************************************************************************************//
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* p_Left;
	BinaryTreeNode* p_Right;
};

//*******************************************************************************************//
//-------------------------------------����һ���������ڵ�------------------------------------//
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
//-------------------------------------���������������ڵ�------------------------------------//
//*******************************************************************************************//
void ConnectNodes(BinaryTreeNode* p_Root, BinaryTreeNode* p_Left, BinaryTreeNode* p_Right)
{
	p_Root->p_Left = p_Left;
	p_Root->p_Right = p_Right;
}

//*******************************************************************************************//
//-------------------------------------����һ���յĶ�����------------------------------------//
//*******************************************************************************************//
BinaryTreeNode* CreateTree_Null()
{
	return nullptr;
}

//*******************************************************************************************//
//------------------------------------����һ�����ڵ������-----------------------------------//
//              1
//*******************************************************************************************//
BinaryTreeNode* CreateTree_OneNode()
{
	BinaryTreeNode* p_Root = CreateBinaryTreeNode(1);

	return p_Root;
}

//*******************************************************************************************//
//---------------------------------����һ��ֻ���������Ķ�����--------------------------------//
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
//---------------------------------����һ��ֻ���������Ķ�����--------------------------------//
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
//-------------------------------------����һ����ȫ������------------------------------------//
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
//-----------------------------------���ϵ��°����ӡ������----------------------------------//
//*******************************************************************************************//
void PrintTree(BinaryTreeNode* p_Root)
{
	assert(p_Root != nullptr);			//����ʽ���

	queue<BinaryTreeNode*> myQueue;		//�½������࣬ÿһ��Ԫ����һ���������ڵ�
	myQueue.push(p_Root);				//�����ڵ����

	while (!myQueue.empty())			//ֱ������Ϊ���ǽ���ѭ��
	{
		cout << myQueue.front()->value << '\t';			//��ӡ��ͷԪ��
		if (myQueue.front()->p_Left != nullptr)			//����ͷԪ�������ӣ������ӽڵ����
		{
			myQueue.push(myQueue.front()->p_Left);
		}
		if (myQueue.front()->p_Right != nullptr)		//����ͷԪ�����Һ��ӣ����Һ��ӽڵ����
		{
			myQueue.push(myQueue.front()->p_Right);
		}
		myQueue.pop();									//����ͷԪ�س���
	}
}

//*******************************************************************************************//
//------------------------------------------���Ժ���-----------------------------------------//
//*******************************************************************************************//
void Test(BinaryTreeNode* (*func)(void))
{
	PrintTree(func());
	cout << endl << endl;
}

//*******************************************************************************************//
//-------------------------------------------������------------------------------------------//
//*******************************************************************************************//
int main()
{
	Test(CreateTree_OneNode);		//��������1�����ڵ������
	Test(CreateTree_OnlyLeft);		//��������2��ֻ���������Ķ�����
	Test(CreateTree_OnlyRight);		//��������3��ֻ���������Ķ�����
	Test(CreateTree_Complete);		//��������4����ȫ������
	Test(CreateTree_Null);			//��������5���ն�����

	return 0;
}
