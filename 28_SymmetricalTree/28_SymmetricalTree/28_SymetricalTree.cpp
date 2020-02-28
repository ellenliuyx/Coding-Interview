//==================================================================
// ����ָOffer������
//==================================================================

// ������28���ԳƵĶ�����
// ��Ŀ����ʵ��һ�������������ж�һ�ö������ǲ��ǶԳƵġ����һ�ö�������
// ���ľ���һ������ô���ǶԳƵġ�

#include <iostream>
using namespace std;

//**************************************************************************************//
//-----------------------------------�������ڵ�ṹ��-----------------------------------//
//**************************************************************************************//
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* p_Left;
	BinaryTreeNode* p_Right;
};

//**************************************************************************************//
//----------------------------------����һ���������ڵ�----------------------------------//
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
//----------------------------------���������������ڵ�----------------------------------//
//**************************************************************************************//
void ConnectNodes(BinaryTreeNode* p_Root, BinaryTreeNode* p_Left, BinaryTreeNode* p_Right)
{
	p_Root->p_Left = p_Left;
	p_Root->p_Right = p_Right;
}

//**************************************************************************************//
//---------------------------------����һ����ָ�������---------------------------------//
//**************************************************************************************//
BinaryTreeNode* CreateTree_Null()
{
	return nullptr;
}

//**************************************************************************************//
//---------------------------------����һ���ԳƵĶ�����---------------------------------//
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
//---------------------------����һ���ṹ�Գ�ֵ���ԳƵĶ�����---------------------------//
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
//------------------------------����һ���ṹ���ԳƵĶ�����------------------------------//
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
//-------------------------����һ�����н�����ȵĲ��Գƶ�����-------------------------//
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
//---------------------------------�ͷŶ��������ڴ�ռ�---------------------------------//
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
//----------------------------------�ж϶������Ƿ�Գ�----------------------------------//
//**************************************************************************************//
bool IsSymetrical(BinaryTreeNode* p_Root1, BinaryTreeNode* p_Root2)
{
	if (p_Root1 == nullptr && p_Root2 == nullptr)		//����Ϊ��ָ�룬��һ�𵽴�Ҷ�ӽڵ㣬����true
		return true;

	if (p_Root1 == nullptr || p_Root2 == nullptr)		//������һ��Ϊ��ָ�룬����ͬ������false
		return false;

	if (p_Root1->value != p_Root2->value)				//�����������ĸ��ڵ�ֵ��ͬ������ͬ������flase
		return false;

	return IsSymetrical(p_Root1->p_Left, p_Root2->p_Right)		//��������1���������Ͷ�����2����������ͬ
		&& IsSymetrical(p_Root1->p_Right, p_Root2->p_Left);		//�Ҷ�����1���������Ͷ�����2����������ͬʱ������true
}

//**************************************************************************************//
//----------------------------------�ж϶������Ƿ�Գ�----------------------------------//
//**************************************************************************************//
bool IsSymetrical(BinaryTreeNode* p_Root)
{
	if (p_Root == nullptr)
		return false;

	return IsSymetrical(p_Root, p_Root);		//���������˺���������
}

//**************************************************************************************//
//---------------------------------------���Ժ���---------------------------------------//
//**************************************************************************************//
void Test(BinaryTreeNode* (*func)(void))
{
	BinaryTreeNode* p_Root = func();

	if (IsSymetrical(p_Root))
		cout << "�ö������ǶԳƵ�" << endl;
	else
		cout << "�ö������ǲ��ԳƵ�" << endl;

	DestoryTree(p_Root);
}

//**************************************************************************************//
//----------------------------------------������----------------------------------------//
//**************************************************************************************//
int main()
{
	Test(CreateTree_Null);					//��������1���ն�����
	Test(CreateTree_Symetrical);			//��������2���ԳƵĶ�����
	Test(CreateTree_NotSymetrical_1);		//��������3���ṹ�Գ�ֵ���ԳƵĶ�����
	Test(CreateTree_NotSymetrical_2);		//��������4���ṹ���ԳƵĶ�����
	Test(CreateTree_NotSymetrical_3);		//��������5�����нڵ��ֵ��ȵĲ��Գƶ�����

	return 0;
}