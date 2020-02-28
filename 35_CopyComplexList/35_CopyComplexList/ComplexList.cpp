//��ͷ�ļ�ͬ����.cpp�ļ�
#include <iostream>
#include "ComplexList.h"
using namespace std;

//*********************************************************//
//-----------------����һ����������ڵ�--------------------//
//*********************************************************//
ComplexListNode* CreateComplexListNode(int value)
{
	ComplexListNode* p_Node = (ComplexListNode*)malloc(sizeof(ComplexListNode));
	p_Node->value = value;
	p_Node->p_Next = nullptr;
	p_Node->p_Sibling = nullptr;
	return p_Node;
}

//*********************************************************//
//-----------��p_Nextָ������������������ڵ�--------------//
//*********************************************************//
void ConnectNext(ComplexListNode* p_Node1, ComplexListNode* p_Node2)
{
	p_Node1->p_Next = p_Node2;
}

//*********************************************************//
//----------��p_Siblingָ������������������ڵ�------------//
//*********************************************************//
void ConnectSibling(ComplexListNode* p_Node1, ComplexListNode* p_Node2)
{
	p_Node1->p_Sibling = p_Node2;
}

//*********************************************************//
//-------------------��ӡһ����������----------------------//
//*********************************************************//
void PrintComplexList(ComplexListNode* p_Head)
{
	ComplexListNode* p_Node = p_Head;
	while (p_Node != nullptr)
	{
		cout << "The value of this node is: " << p_Node->value << endl;
		if (p_Node->p_Sibling != nullptr)
			cout << "The value of its sibling is: " << p_Node->p_Sibling->value << endl;
		else
			cout << "This Node does not have a sibling!" << endl;
		p_Node = p_Node->p_Next;
	}
}