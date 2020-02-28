//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
//==================================================================

// ������8������������һ�����
// ��Ŀ������һ�ö����������е�һ����㣬����ҳ��������˳�����һ����㣿
// ���еĽ������������ֱ�ָ�������ӽ���ָ�����⣬����һ��ָ�򸸽���ָ�롣

#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

//**************************************************************************************//
//----------------------------------����ָ��Ķ��������--------------------------------//
//**************************************************************************************//
struct BiTreeNode
{
	int value;
	BiTreeNode* pLeft;
	BiTreeNode* pRight;
	BiTreeNode* pParent;
};

//**************************************************************************************//
//----------------------------------������������һ�����--------------------------------//
//**************************************************************************************//
BiTreeNode* CreateBiTreeNode(int value)
{
	BiTreeNode* pNode;
	pNode = (BiTreeNode*)malloc(sizeof(BiTreeNode));
	pNode->value = value;
	pNode->pParent = nullptr;
	pNode->pLeft = nullptr;
	pNode->pRight = nullptr;

	return pNode;
}

//**************************************************************************************//
//----------------------------�����������������֮�����ϵ------------------------------//
//**************************************************************************************//
void ConnectNodes(BiTreeNode* p_Parent, BiTreeNode* p_Left, BiTreeNode* p_Right)
{
	if (p_Parent != nullptr)
	{
		p_Parent->pLeft = p_Left;
		p_Parent->pRight = p_Right;
	}
	if (p_Left != nullptr)
		p_Left->pParent = p_Parent;
	if (p_Right != nullptr)
		p_Right->pParent = p_Parent;
}

//**************************************************************************************//
//----------------------------------��������ö�����------------------------------------//
//                       1
//                   /        \
//               2               3
//             /    \         /     \
//          4         5     6         7
//                  /    \
//               8         9
//
//����������У�4 2 8 5 9 1 6 3 7
//**************************************************************************************//
BiTreeNode* BuildBiTree()
{
	BiTreeNode* pNode1 = CreateBiTreeNode(1);
	BiTreeNode* pNode2 = CreateBiTreeNode(2);
	BiTreeNode* pNode3 = CreateBiTreeNode(3);
	BiTreeNode* pNode4 = CreateBiTreeNode(4);
	BiTreeNode* pNode5 = CreateBiTreeNode(5);
	BiTreeNode* pNode6 = CreateBiTreeNode(6);
	BiTreeNode* pNode7 = CreateBiTreeNode(7);
	BiTreeNode* pNode8 = CreateBiTreeNode(8);
	BiTreeNode* pNode9 = CreateBiTreeNode(9);

	ConnectNodes(pNode1, pNode2, pNode3);
	ConnectNodes(pNode2, pNode4, pNode5);
	ConnectNodes(pNode3, pNode6, pNode7);
	ConnectNodes(pNode5, pNode8, pNode9);

	return pNode1;
}

//**************************************************************************************//
//-----------------------------����������е���һ�����---------------------------------//
//���룺p_Node������ڵ㣩
//����ֵ����һ���ڵ�
//**************************************************************************************//
BiTreeNode* GetNextNode(BiTreeNode* p_Node)
{
	if (p_Node == nullptr)					//���ڵ�Ϊ�գ��򷵻ؿսڵ�
	{
		return nullptr;
	}

	if (p_Node->pRight != nullptr)			//���ýڵ������������򷵻������������ӽڵ�
	{
		BiTreeNode* p_Next1 = p_Node->pRight;	//���������ڵ�
		while (p_Next1->pLeft != nullptr)		//ֻҪ��������Ϊ�գ���һֱ������
		{
			p_Next1 = p_Next1->pLeft;
		}
		return p_Next1;							//������Ϊ��ʱ�����ش˽ڵ�
	}

	//else									//���ýڵ���������
	//{
	//	if (p_Node->pParent->pLeft == p_Node)		//���ýڵ�Ϊ���ڵ������
	//	{
	//		return p_Node->pParent;					//���ظýڵ��˫�׽��
	//	}

	//	if (p_Node->pParent->pRight == p_Node)		//���ýڵ�Ϊ���ڵ���Һ���
	//	{
	//		BiTreeNode* p_Next2 = p_Node->pParent;	
	//		while (p_Next2->pParent->pRight == p_Next2)		//һֱ����Ѱ�ң�ֱ��ĳ�ڵ�����˫�׽�������
	//		{
	//			p_Next2 = p_Next2->pParent;
	//			if (p_Next2->pParent == nullptr)			//����ҵ����ڵ㣬����δ�ҵ����򷵻ؿս��
	//			{
	//				return nullptr;
	//			}
	//		}
	//		return p_Next2->pParent;						//���ҵ��ýڵ㣬������˫�׽��
	//	}
	//}

	else if (p_Node->pParent != nullptr)					//���ýڵ���������
	{
		BiTreeNode* p_Now = p_Node;
		while (p_Now->pParent != nullptr && p_Now->pParent->pRight == p_Now)	//�����������ڵ���߸ýڵ�Ϊ˫�׽������ӣ����˳�ѭ��
		{
			p_Now = p_Now->pParent;
		}
		return p_Now->pParent;		//�����������ڵ㣬��p_NowΪ�սڵ㣻���ýڵ�Ϊ��˫�׽������ӣ���p_NowΪ��˫�׽��
	}
}

//**************************************************************************************//
//--------------------------------------��ӡ���----------------------------------------//
//**************************************************************************************//
void PrintResult(BiTreeNode* p_Node, BiTreeNode* p_NextNode)
{
	if (p_Node == nullptr)
		cout << "������ڵ�Ϊ�գ�������һ�ڵ�" << endl;
	else if (p_NextNode == nullptr)
		cout << "������ڵ�ֵΪ��" << p_Node->value << "��������һ�ڵ�" << endl;
	else
		cout << "������ڵ�ֵΪ��" << p_Node->value << "������һ�ڵ�ֵΪ��" << p_NextNode->value << endl;
}

//**************************************************************************************//
//---------------------------------------������-----------------------------------------//
//**************************************************************************************//
int main()
{
	BiTreeNode* root, *p_Node, *p_NextNode;
	root = BuildBiTree();

	//1�Žڵ�
	p_Node = root;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//2�Žڵ�
	p_Node = root->pLeft;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//3�Žڵ�
	p_Node = root->pRight;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//4�Žڵ�
	p_Node = root->pLeft->pLeft;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//5�Žڵ�
	p_Node = root->pLeft->pRight;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//6�Žڵ�
	p_Node = root->pRight->pLeft;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//7�Žڵ�
	p_Node = root->pRight->pRight;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//8�Žڵ�
	p_Node = root->pLeft->pRight->pLeft;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//9�Žڵ�
	p_Node = root->pLeft->pRight->pRight;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	return 0;
}