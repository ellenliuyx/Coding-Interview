//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

#include <iostream>
#include <stack>		//栈的头文件（STL容器适配器）
using namespace std;

//******************************************************************
//链表节点
//******************************************************************
struct ListNode
{
	int value;
	ListNode * pNext;
};

//******************************************************************
//向链表末尾插入一个元素值
//输入：pTail(指向链表末尾元素的指针)，InsertValue(需要插入的元素值)
//返回值：pTemp（指向链表新末尾元素的指针）
//******************************************************************
ListNode* AddToTail(ListNode* pTail, int InsertValue)
{
	ListNode* pTemp;
	pTemp = (ListNode*)malloc(sizeof(ListNode));
	pTemp->value = InsertValue;
	pTemp->pNext = NULL;
	pTail->pNext = pTemp;

	return pTemp;
}

//******************************************************************
//从头至尾打印链表中元素
//输入：pHead(链表头指针)
//******************************************************************
void PrintList(ListNode* pHead)
{
	ListNode* pTemp;
	pTemp = pHead->pNext;	//链表中的第一个元素
	cout << "Head->";
	if (pTemp == NULL)		//若第一个元素为空，则直接退出函数
	{
		cout << endl;
		return;
	}
	while (pTemp->pNext != NULL)	//若当前元素的指针不为空
	{
		cout << pTemp->value << "->";	//输出当前元素值
		pTemp = pTemp->pNext;			//指针指向下一元素
	}
	cout << pTemp->value << endl;		//输出链表末尾元素
}

//******************************************************************
//从尾至头打印链表中元素（用栈实现）
//输入：pHead(链表头指针)
//******************************************************************
void PrintListRev_Stack(ListNode* pHead)
{
	stack<int> St;				//定义一个栈对象
	ListNode* pTemp;
	pTemp = pHead->pNext;		//链表中的第一个元素
	if (pTemp == NULL)			//若第一个元素为空，则直接退出函数
	{
		cout << "<-Head" << endl;
		return;
	}

	//----------------------链表元素顺序入栈----------------------------//
	while (pTemp->pNext != NULL)	//若当前元素的指针不为空
	{
		St.push(pTemp->value);		//将当前元素值入栈
		pTemp = pTemp->pNext;		//指针指向下一元素
	}
	St.push(pTemp->value);			//将链表最后一个元素值入栈

	//-------------------链表元素逆序出栈并输出-------------------------//
	while (!St.empty())				//若栈不空
	{
		cout << St.top() << "<-";	//输出栈顶元素
		St.pop();					//弹出栈顶元素
	}
	cout << "Head" << endl;
}

//******************************************************************
//从尾至头打印链表中元素（用递归实现）
//输入：pHead(链表头指针)
//******************************************************************
void PrintListRev_Recurse(ListNode* pHead)
{
	ListNode* pTemp;
	pTemp = pHead->pNext;		//链表中的第一个元素
	if (pTemp == NULL)			//元素为空，退出函数
	{
		return;
	}

	PrintListRev_Recurse(pTemp);
	cout << pTemp->value << "<-";
}

//******************************************************************
//主函数
//******************************************************************
int main()
{
	ListNode * pHead, * pTail;		//定义头指针和尾指针
	pHead = (ListNode*)malloc(sizeof(ListNode));	//为头指针开辟空间
	pHead->value = 0;
	pHead->pNext = NULL;
	pTail = pHead;					//对于空链表，尾指针与头指针处于同一位置

	//--------------------从键盘输入向链表中插入的元素-----------------------
	int ValueInput;
	cout << "请输入链表中元素：" << endl;
	while (cin >> ValueInput)
	{
		pTail = AddToTail(pTail, ValueInput);
	}

	//-------------------------向屏幕打印链表元素----------------------------
	cout << "顺序输出链表元素：" << endl;
	PrintList(pHead);
	cout << "逆序输出链表元素（用栈实现）：" << endl;
	PrintListRev_Stack(pHead);
	cout << "逆序输出链表元素（用递归实现）：" << endl;
	PrintListRev_Recurse(pHead);
	cout << "Head" << endl;

	return 0;
}