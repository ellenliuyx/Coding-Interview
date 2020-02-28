//==================================================================
// ����ָOffer������
//==================================================================

// ������32��������֮���δ�ӡ������
// ��Ŀ����ʵ��һ����������֮����˳���ӡ������������һ�а��մ����ҵ�˳
// ���ӡ���ڶ��㰴�մ��ҵ����˳���ӡ���������ٰ��մ����ҵ�˳���ӡ��
// �������Դ����ơ�

#include <iostream>
#include <stack>
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
//--------------------------------���ϵ��°���֮���δ�ӡ������-------------------------------//
//*******************************************************************************************//
void PrintTree(BinaryTreeNode* p_Root)
{
	assert(p_Root != nullptr);			//����ʽ���

	stack<BinaryTreeNode*> myStack[2];	//���������ʽ��������ջ��ջ���±귽�����л�

	int current = 0, next = 1;			//��ǰ��ڵ�ʹ�õ�ջ�±꣬����һ��ڵ�ʹ�õ�ջ�±�

	myStack[current].push(p_Root);		//�ȰѸ��ڵ���currentջ

	while (!myStack[0].empty() || !myStack[1].empty())		//������ջ��Ϊ��ʱ������ѭ��
	{
		cout << myStack[current].top()->value << '\t';		//���currentջ��ջ���ڵ�
		if (current == 0)									//���currentջ��0��ջ����ǰ��Ϊ������
		{
			if (myStack[current].top()->p_Left != nullptr)	//����������ҵ�˳�򽫺��ӽڵ���nextջ
			{
				myStack[next].push(myStack[current].top()->p_Left);
			}
			if (myStack[current].top()->p_Right != nullptr)
			{
				myStack[next].push(myStack[current].top()->p_Right);
			}
		}
		else												//���currentջ��1��ջ
		{
			if (myStack[current].top()->p_Right != nullptr)	//����������ҵ�˳�򽫺��ӽڵ���nextջ
			{
				myStack[next].push(myStack[current].top()->p_Right);
			}
			if (myStack[current].top()->p_Left != nullptr)
			{
				myStack[next].push(myStack[current].top()->p_Left);
			}
		}
		myStack[current].pop();								//������ǰջ��ջ���ڵ�
		if (myStack[current].empty())						//�����ǰջΪ�գ���˵������ڵ��Ѿ���ӡ���
		{
			cout << endl;									//��ӡ���з�
			swap(current, next);							//����currentջ��nextջ���±�
		}
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
