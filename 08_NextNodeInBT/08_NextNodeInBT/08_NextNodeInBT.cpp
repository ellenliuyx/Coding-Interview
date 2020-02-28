//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
//==================================================================

// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

#include <stdlib.h>
#include <iostream>
#include <string.h>
using namespace std;

//**************************************************************************************//
//----------------------------------含父指针的二叉树结点--------------------------------//
//**************************************************************************************//
struct BiTreeNode
{
	int value;
	BiTreeNode* pLeft;
	BiTreeNode* pRight;
	BiTreeNode* pParent;
};

//**************************************************************************************//
//----------------------------------产生二叉树的一个结点--------------------------------//
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
//----------------------------建立三个二叉树结点之间的联系------------------------------//
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
//----------------------------------构造测试用二叉树------------------------------------//
//                       1
//                   /        \
//               2               3
//             /    \         /     \
//          4         5     6         7
//                  /    \
//               8         9
//
//中序遍历序列：4 2 8 5 9 1 6 3 7
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
//-----------------------------获得中序序列的下一个结点---------------------------------//
//输入：p_Node（输入节点）
//返回值：下一个节点
//**************************************************************************************//
BiTreeNode* GetNextNode(BiTreeNode* p_Node)
{
	if (p_Node == nullptr)					//若节点为空，则返回空节点
	{
		return nullptr;
	}

	if (p_Node->pRight != nullptr)			//若该节点有右子树，则返回右子树最左子节点
	{
		BiTreeNode* p_Next1 = p_Node->pRight;	//右子树根节点
		while (p_Next1->pLeft != nullptr)		//只要左子树不为空，就一直找左孩子
		{
			p_Next1 = p_Next1->pLeft;
		}
		return p_Next1;							//左子树为空时，返回此节点
	}

	//else									//若该节点无右子树
	//{
	//	if (p_Node->pParent->pLeft == p_Node)		//若该节点为父节点的左孩子
	//	{
	//		return p_Node->pParent;					//返回该节点的双亲结点
	//	}

	//	if (p_Node->pParent->pRight == p_Node)		//若该节点为父节点的右孩子
	//	{
	//		BiTreeNode* p_Next2 = p_Node->pParent;	
	//		while (p_Next2->pParent->pRight == p_Next2)		//一直向上寻找，直到某节点是其双亲结点的左孩子
	//		{
	//			p_Next2 = p_Next2->pParent;
	//			if (p_Next2->pParent == nullptr)			//如果找到根节点，依旧未找到，则返回空结点
	//			{
	//				return nullptr;
	//			}
	//		}
	//		return p_Next2->pParent;						//若找到该节点，返回其双亲结点
	//	}
	//}

	else if (p_Node->pParent != nullptr)					//若该节点无右子树
	{
		BiTreeNode* p_Now = p_Node;
		while (p_Now->pParent != nullptr && p_Now->pParent->pRight == p_Now)	//若搜索到根节点或者该节点为双亲结点的左孩子，则退出循环
		{
			p_Now = p_Now->pParent;
		}
		return p_Now->pParent;		//若搜索到根节点，则p_Now为空节点；若该节点为其双亲结点的左孩子，则p_Now为其双亲结点
	}
}

//**************************************************************************************//
//--------------------------------------打印结果----------------------------------------//
//**************************************************************************************//
void PrintResult(BiTreeNode* p_Node, BiTreeNode* p_NextNode)
{
	if (p_Node == nullptr)
		cout << "若输入节点为空，则无下一节点" << endl;
	else if (p_NextNode == nullptr)
		cout << "若输入节点值为：" << p_Node->value << "，则无下一节点" << endl;
	else
		cout << "若输入节点值为：" << p_Node->value << "，则下一节点值为：" << p_NextNode->value << endl;
}

//**************************************************************************************//
//---------------------------------------主函数-----------------------------------------//
//**************************************************************************************//
int main()
{
	BiTreeNode* root, *p_Node, *p_NextNode;
	root = BuildBiTree();

	//1号节点
	p_Node = root;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//2号节点
	p_Node = root->pLeft;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//3号节点
	p_Node = root->pRight;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//4号节点
	p_Node = root->pLeft->pLeft;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//5号节点
	p_Node = root->pLeft->pRight;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//6号节点
	p_Node = root->pRight->pLeft;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//7号节点
	p_Node = root->pRight->pRight;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//8号节点
	p_Node = root->pLeft->pRight->pLeft;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	//9号节点
	p_Node = root->pLeft->pRight->pRight;
	p_NextNode = GetNextNode(p_Node);
	PrintResult(p_Node, p_NextNode);

	return 0;
}