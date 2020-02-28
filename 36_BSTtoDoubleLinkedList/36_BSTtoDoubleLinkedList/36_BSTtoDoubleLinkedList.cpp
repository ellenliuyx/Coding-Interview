#include "BinaryTree.h"

//**********************************************************************************//
//-----------------------------����������ת˫��������-----------------------------//
//**********************************************************************************//
BinaryTreeNode* covert(BinaryTreeNode* p_Root)
{
	if (p_Root == nullptr)				//�Ƿ����룺�ն�����
		return nullptr;

	BinaryTreeNode* p_front, *p_back;	//����ָ��������ʾp_Root����������ת���ɵ������ͷ�ڵ�

	if (p_Root->p_Left != nullptr)			//�����ڵ���������
	{
		p_front = covert(p_Root->p_Left);	//��������ת����˫������

		BinaryTreeNode* p_last = p_front;	//�������������ͷָ���ҵ������һ��Ԫ��p_last
		while (p_last->p_Right != nullptr)
		{
			p_last = p_last->p_Right;
		}
		p_last->p_Right = p_Root;			//����p_last��p_Root�Ĺ�ϵ
		p_Root->p_Left = p_last;
	}
	else									//�����ڵ���������
	{
		p_front = p_Root;					//����ֵ��Ϊ���ڵ㱾��
	}

	if (p_Root->p_Right != nullptr)			//�����ڵ���������
	{                                                                                                                                                                                                                      
		p_back = covert(p_Root->p_Right);	//��������ת����˫������
		p_Root->p_Right = p_back;			//����p_back��p_Root�Ĺ�ϵ
		p_back->p_Left = p_Root;
	}										//���������������������Ӱ��˫�������ͷָ�뷵��ֵ�����Բ��ÿ���
	
	return p_front;							//������p_RootΪ���ڵ�Ķ�����ת���ɵ�˫�������ͷָ��
}

//**********************************************************************************//
//-------------------------------------���Ժ���-------------------------------------//
//**********************************************************************************//
void Test(BinaryTreeNode* (*func)(void))
{
	BinaryTreeNode* p_Head = covert(func());
	PrintDoubleLinkedList(p_Head);
}

//**********************************************************************************//
//--------------------------------------������--------------------------------------//
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

