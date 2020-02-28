//==================================================================
// ����ָOffer������
//==================================================================

// ������54�������������ĵ�k�����
// ��Ŀ������һ�ö��������������ҳ����еĵ�k��Ľ�㡣

#include <iostream>
#include <assert.h>
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
//--------------------����������k��Ķ������ڵ�-------------------//
//******************************************************************//
BinaryTreeNode* KthNodeCore(BinaryTreeNode* pRoot, int& k)
{
	BinaryTreeNode* target = nullptr;

	if (pRoot->p_Left != nullptr)				//һֱ�����ҵ������½ǵĽڵ�
		target = KthNodeCore(pRoot->p_Left, k);

	if (target == nullptr)						//����δ�ҵ���k���ڵ�
	{
		if (k == 1)								//����ʱk�ݼ���1����ýڵ���ǵ�k���ڵ�
			target = pRoot;
		k--;									//����k--
	}

	if (target == nullptr && pRoot->p_Right != nullptr)		//����δ�ҵ���k���ڵ㣬����������Ϊ�գ����������������
		target = KthNodeCore(pRoot->p_Right, k);

	return target;
}

//******************************************************************//
//------------------------���k��Ķ������ڵ�-----------------------//
//******************************************************************//
BinaryTreeNode* KthNodeInBST(BinaryTreeNode* p_Root, int k)
{
	assert(p_Root != nullptr && k > 0);

	return KthNodeCore(p_Root, k);
}

//******************************************************************//
//--------------------------����һ��������--------------------------//
//******************************************************************//
BinaryTreeNode* CreateTree()
{
	BinaryTreeNode* p_Node1 = CreateNode(5);
	BinaryTreeNode* p_Node2 = CreateNode(3);
	BinaryTreeNode* p_Node3 = CreateNode(7);
	BinaryTreeNode* p_Node4 = CreateNode(2);
	BinaryTreeNode* p_Node5 = CreateNode(4);
	BinaryTreeNode* p_Node6 = CreateNode(6);
	BinaryTreeNode* p_Node7 = CreateNode(8);

	ConnectNodes(p_Node1, p_Node2, p_Node3);
	ConnectNodes(p_Node2, p_Node4, p_Node5);
	ConnectNodes(p_Node3, p_Node6, p_Node7);

	return p_Node1;
}

//******************************************************************//
//------------------------------������------------------------------//
//******************************************************************//
int main()
{
	int k = 3;
	BinaryTreeNode* p_Root = CreateTree();
	BinaryTreeNode* target = KthNodeInBST(p_Root, k);
	cout << "�� " << k << " ��Ľڵ��ǣ�" << target->value << endl;
	return 0;
}