#include "BinaryTree.h"

//**********************************************************************************//
//-----------------------------二叉搜索树转双向链表函数-----------------------------//
//**********************************************************************************//
BinaryTreeNode* covert(BinaryTreeNode* p_Root)
{
	if (p_Root == nullptr)				//非法输入：空二叉树
		return nullptr;

	BinaryTreeNode* p_front, *p_back;	//两个指针用来表示p_Root的左右子树转换成的链表的头节点

	if (p_Root->p_Left != nullptr)			//若根节点有左子树
	{
		p_front = covert(p_Root->p_Left);	//将左子树转换成双向链表

		BinaryTreeNode* p_last = p_front;	//由左子树链表的头指针找到其最后一个元素p_last
		while (p_last->p_Right != nullptr)
		{
			p_last = p_last->p_Right;
		}
		p_last->p_Right = p_Root;			//建立p_last与p_Root的关系
		p_Root->p_Left = p_last;
	}
	else									//若根节点无左子树
	{
		p_front = p_Root;					//返回值即为根节点本身
	}

	if (p_Root->p_Right != nullptr)			//若根节点有右子树
	{                                                                                                                                                                                                                      
		p_back = covert(p_Root->p_Right);	//将右子树转换成双向链表
		p_Root->p_Right = p_back;			//建立p_back与p_Root的关系
		p_back->p_Left = p_Root;
	}										//若根结点无右子树，不会影响双向链表的头指针返回值，所以不用考虑
	
	return p_front;							//返回以p_Root为根节点的二叉树转换成的双向链表的头指针
}

//**********************************************************************************//
//-------------------------------------测试函数-------------------------------------//
//**********************************************************************************//
void Test(BinaryTreeNode* (*func)(void))
{
	BinaryTreeNode* p_Head = covert(func());
	PrintDoubleLinkedList(p_Head);
}

//**********************************************************************************//
//--------------------------------------主函数--------------------------------------//
//**********************************************************************************//
int main()
{
	Test(CreateBinaryTree_OneNode);
	Test(CreateBinaryTree_OnlyLeft);
	Test(CreateBinaryTree_OnlyRight);
	Test(CreateBinaryTree_Complete);
	Test(CreateBinaryTree_Null);

	return 0;
}

