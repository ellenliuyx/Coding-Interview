//ͷ�ļ�

#pragma once

//*********************************************************//
//------------------��������ڵ�ṹ��---------------------//
//*********************************************************//
struct ComplexListNode
{
	int value;
	ComplexListNode* p_Next;
	ComplexListNode* p_Sibling;
};

//*********************************************************//
//-----�˴������ĺ����������ͷ�ļ�ͬ����.cpp�ļ��ж���----//
//----------�������еĺ����൱���ڸ�ͷ�ļ��ж���-----------//
//*********************************************************//
ComplexListNode* CreateComplexListNode(int value);
void ConnectNext(ComplexListNode* p_Node1, ComplexListNode* p_Node2);
void ConnectSibling(ComplexListNode* p_Node1, ComplexListNode* p_Node2);
void PrintComplexList(ComplexListNode* p_Head);