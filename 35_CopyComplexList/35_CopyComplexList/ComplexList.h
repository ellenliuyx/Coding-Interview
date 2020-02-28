//头文件

#pragma once

//*********************************************************//
//------------------复杂链表节点结构体---------------------//
//*********************************************************//
struct ComplexListNode
{
	int value;
	ComplexListNode* p_Next;
	ComplexListNode* p_Sibling;
};

//*********************************************************//
//-----此处声明的函数均在与该头文件同名的.cpp文件中定义----//
//----------这样所有的函数相当于在该头文件中定义-----------//
//*********************************************************//
ComplexListNode* CreateComplexListNode(int value);
void ConnectNext(ComplexListNode* p_Node1, ComplexListNode* p_Node2);
void ConnectSibling(ComplexListNode* p_Node1, ComplexListNode* p_Node2);
void PrintComplexList(ComplexListNode* p_Head);