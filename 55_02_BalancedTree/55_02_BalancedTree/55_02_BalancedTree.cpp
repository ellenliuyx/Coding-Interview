//==================================================================
// ����ָOffer������
//==================================================================

// ������55��������ƽ�������
// ��Ŀ������һ�ö������ĸ���㣬�жϸ����ǲ���ƽ������������ĳ��������
// ��������������������������1����ô������һ��ƽ���������

#include <iostream>
#include <assert.h>
#include <algorithm>
using namespace std;

//******************************************************************//
//-------------------------�������ڵ�ṹ��-------------------------//
//******************************************************************//
struct BinaryTreeNode
{
	int value;
	BinaryTreeNode* p_Left;
	BinaryTreeNode* p_Right;
};

//******************************************************************//
//------------------------����һ���������ڵ�------------------------//
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
//------------------------���������������ڵ�------------------------//
//******************************************************************//
void ConnectNodes(BinaryTreeNode* p_Root, BinaryTreeNode* p_Left, BinaryTreeNode* p_Right)
{
	p_Root->p_Left = p_Left;
	p_Root->p_Right = p_Right;
}

//******************************************************************//
//------------------------�ͷŶ������ڴ�ռ�------------------------//
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
//--------------���ö������ĺ�������ж϶������Ƿ�ƽ��--------------//
//******************************************************************//
bool IsBalanceTree(BinaryTreeNode* p_Root, int* depth)
{
	if (p_Root == nullptr)		//��������Ҷ�ӽڵ㣬���¼���Ϊ0������true
	{
		*depth = 0;
		return true;
	}
	
	int left, right;			//�ֱ��¼�������������

	//������������Ϊƽ�������
	if (IsBalanceTree(p_Root->p_Left, &left) && IsBalanceTree(p_Root->p_Right, &right))
	{
		if (abs(left - right) <= 1)			//���Ե�ǰ�ڵ�Ϊ���ڵ�Ķ�����Ҳ��ƽ���
		{
			*depth = max(left, right) + 1;	//�����������ȣ�������true
			return true;
		}
	}
	return false;			//���򷵻�false
}

//******************************************************************//
//------------------------�ж϶������Ƿ�ƽ��------------------------//
//******************************************************************//
bool IsBalanceTree(BinaryTreeNode* p_Root)
{
	assert(p_Root != nullptr);

	int depth = 0;
	return IsBalanceTree(p_Root, &depth);	//�����¼������ȵı���
}

//******************************************************************//
//-----------------------��������1��ƽ�������----------------------//
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
		cout << "�ö�������ƽ���" << endl;
	else
		cout << "�ö���������ƽ���" << endl;

	DestroyTree(p_Root);
}

//******************************************************************//
//----------------------��������2����ƽ�������---------------------//
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
		cout << "�ö�������ƽ���" << endl;
	else
		cout << "�ö���������ƽ���" << endl;

	DestroyTree(p_Root);
}

//******************************************************************//
//------------------------��������3���ն�����-----------------------//
//******************************************************************//
void Test3()
{
	BinaryTreeNode* p_Root = nullptr;

	if (IsBalanceTree(p_Root))
		cout << "�ö�������ƽ���" << endl;
	else
		cout << "�ö���������ƽ���" << endl;

	DestroyTree(p_Root);
}

//******************************************************************//
//------------------------------������------------------------------//
//******************************************************************//
int main()
{
	Test1();
	Test2();
	Test3();
	return 0;
}