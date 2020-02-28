//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。

// 面试题18（二）：删除链表中重复的结点
// 题目：在一个排序的链表中，如何删除重复的结点？例如，在图3.4（a）中重复
// 结点被删除之后，链表如图3.4（b）所示。

#include <iostream>
using namespace std;

//****************************************************************************************//
//--------------------------------------链表节点------------------------------------------//
//****************************************************************************************//
struct ListNode
{
	int value;
	ListNode* p_Next;
};

//****************************************************************************************//
//---------------------------------创建链表的一个节点-------------------------------------//
//****************************************************************************************//
ListNode* CreateListNode(int value)
{
	ListNode* p_Node;
	p_Node = (ListNode*)malloc(sizeof(ListNode));	//为一个节点开辟内存空间
	p_Node->value = value;
	p_Node->p_Next = nullptr;

	return p_Node;
}

//****************************************************************************************//
//---------------------------------连接链表的两个节点-------------------------------------//
//****************************************************************************************//
void LinkListNode(ListNode* p_Node1, ListNode* p_Node2)
{
	p_Node1->p_Next = p_Node2;
}

//****************************************************************************************//
//---------------------------------删除链表的某个节点-------------------------------------//
//输入：p_Head（链表），p_Delete（待删除节点）
//****************************************************************************************//
void DeleteNode(ListNode* p_Head, ListNode* p_Delete)
{
	if (p_Delete->p_Next == nullptr)			//若该节点是链表的尾节点
	{
		ListNode* p_current = p_Head;
		ListNode* p_nextnode = p_Head->p_Next;
		while (p_nextnode->p_Next != nullptr)	//从头结点开始向后遍历，发现尾节点则删除
		{
			p_current = p_current->p_Next;
			p_nextnode = p_nextnode->p_Next;
		}
		p_current->p_Next = nullptr;
		delete p_nextnode;
	}
	else										//若该节点不是链表的尾节点
	{
		ListNode* p_nextnode = p_Delete->p_Next;
		p_Delete->value = p_nextnode->value;	//将待删节点的下一个节点复制到待删节点上
		p_Delete->p_Next = p_nextnode->p_Next;
		delete p_nextnode;						//删除待删节点的下一个节点
	}
}

//****************************************************************************************//
//---------------------------------删除链表的重复节点-------------------------------------//
//输入：p_Head（链表）
//****************************************************************************************//
void DeleteDupNode(ListNode* p_Head)
{
	if (p_Head->p_Next == nullptr || p_Head->p_Next->p_Next == nullptr)	//若链表为空或只有一个节点，直接结束函数
		return;
	
	ListNode* p_current = p_Head;
	ListNode* p_nextnode = p_current->p_Next;
	ListNode* p_temp;
	bool needDel;			//需要删除标志位，用于区分是一直没有重复节点，还是位于重复区域的右边界处，这两种情况p_nextnode和p_nextnode->p_Next的值均不等

	while (p_nextnode->p_Next != nullptr)		//当遍历到链表尾时，结束循环
	{
		needDel = false;						//删除标志位初始化为0
		while (p_nextnode->value == p_nextnode->p_Next->value)		//找到连续的重复数字
		{
			needDel = true;						//删除标志位置为1
			p_temp = p_nextnode;				//p_nextnode指针后移1位，删除p_nextnode的前一个节点
			p_nextnode = p_nextnode->p_Next;
			delete p_temp;
			if (p_nextnode->p_Next == nullptr)	//当遍历到链表尾时，无法继续比较p_nextnode和p_nextnode->p_Next的值
			{
				p_current->p_Next = nullptr;	//直接删除p_nextnode节点，修改p_current的指针为空，函数运行结束
				delete p_nextnode;
				return;
			}
		}
		if (needDel)							//如果位于重复区域的右边界处，需要删除节点
		{
			p_temp = p_nextnode;				//删除p_nextnode节点
			p_nextnode = p_nextnode->p_Next;
			delete p_temp;
			p_current->p_Next = p_nextnode;		//修改p_current的指针，使其指向重复区域的下一个节点
		}
		else									//如果一直没有重复节点，不需要删除节点
		{
			p_current = p_current->p_Next;		//p_current指针和p_nextnode指针后移1位
			p_nextnode = p_nextnode->p_Next;
		}
	}
}

//****************************************************************************************//
//------------------------------从头至尾依次打印链表节点----------------------------------//
//输入：p_Head（链表）
//****************************************************************************************//
void PrintList(ListNode* p_Head)
{
	ListNode* p_current = p_Head;
	while (p_current->p_Next != nullptr)
	{
		cout << p_current->p_Next->value << "\t";
		p_current = p_current->p_Next;
	}
	cout << endl;
}

//****************************************************************************************//
//---------------------------------------主函数-------------------------------------------//
//****************************************************************************************//
int main()
{
	//--------------------------------链表节点构造--------------------------------//
	ListNode* p_Head = CreateListNode(0);		//头节点

	//------测试用例1：含有多个重复区间
	ListNode* p_Node1 = CreateListNode(1);
	ListNode* p_Node2 = CreateListNode(2);
	ListNode* p_Node3 = CreateListNode(3);
	ListNode* p_Node4 = CreateListNode(3);
	ListNode* p_Node5 = CreateListNode(3);
	ListNode* p_Node6 = CreateListNode(4);
	ListNode* p_Node7 = CreateListNode(5);
	ListNode* p_Node8 = CreateListNode(6);
	ListNode* p_Node9 = CreateListNode(6);

	//------测试用例2：链表中所有元素均相等
	/*ListNode* p_Node1 = CreateListNode(1);
	ListNode* p_Node2 = CreateListNode(1);
	ListNode* p_Node3 = CreateListNode(1);
	ListNode* p_Node4 = CreateListNode(1);
	ListNode* p_Node5 = CreateListNode(1);
	ListNode* p_Node6 = CreateListNode(1);
	ListNode* p_Node7 = CreateListNode(1);
	ListNode* p_Node8 = CreateListNode(1);
	ListNode* p_Node9 = CreateListNode(1)*/;

	//------测试用例2：链表中所有元素均不相等
	/*ListNode* p_Node1 = CreateListNode(1);
	ListNode* p_Node2 = CreateListNode(2);
	ListNode* p_Node3 = CreateListNode(3);
	ListNode* p_Node4 = CreateListNode(4);
	ListNode* p_Node5 = CreateListNode(5);
	ListNode* p_Node6 = CreateListNode(6);
	ListNode* p_Node7 = CreateListNode(7);
	ListNode* p_Node8 = CreateListNode(8);
	ListNode* p_Node9 = CreateListNode(9);*/

	//--------------------------------链表节点连接--------------------------------//
	LinkListNode(p_Head, p_Node1);
	LinkListNode(p_Node1, p_Node2);
	LinkListNode(p_Node2, p_Node3);
	LinkListNode(p_Node3, p_Node4);
	LinkListNode(p_Node4, p_Node5);
	LinkListNode(p_Node5, p_Node6);
	LinkListNode(p_Node6, p_Node7);
	LinkListNode(p_Node7, p_Node8);
	LinkListNode(p_Node8, p_Node9);

	cout << "初始链表为：" << endl;
	PrintList(p_Head);

	//---------------------------删除链表中某一个节点---------------------------//
	ListNode* p_Delete = p_Node2;
	cout << "删除节点 " << p_Delete->value << " 后的链表为：" << endl;
	DeleteNode(p_Head, p_Delete);
	PrintList(p_Head);

	//---------------------------删除链表中重复的节点---------------------------//
	DeleteDupNode(p_Head);
	cout << "删除重复节点后的链表为：" << endl;
	PrintList(p_Head);

	return 0;
}