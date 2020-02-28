//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点？例如，在图3.8的链表中，
// 环的入口结点是结点3。

#include <iostream>
using namespace std;

//************************************************************************************************//
//-----------------------------------------链表节点结构体-----------------------------------------//
//************************************************************************************************//
struct ListNode
{
	int value;
	ListNode* p_Next;
};

//************************************************************************************************//
//------------------------------------------创建链表节点------------------------------------------//
//************************************************************************************************//
ListNode* CreateNode(int nodeValue)
{
	ListNode* p_Node = (ListNode*)malloc(sizeof(ListNode));
	p_Node->value = nodeValue;
	p_Node->p_Next = nullptr;

	return p_Node;
}

//************************************************************************************************//
//------------------------------------------连接链表节点------------------------------------------//
//************************************************************************************************//
void ConnectNode(ListNode* p_Node1, ListNode* p_Node2)
{
	p_Node1->p_Next = p_Node2;
}

//************************************************************************************************//
//--------------------------------------判断链表中是否含有环--------------------------------------//
//思路：设置两个同时从头结点出发的指针，一个每次走一步，一个每次走两步，若快指针追上慢指针则含有环
//输入：p_Head（链表的头结点）
//返回：快慢指针相遇的节点（环中的某一个节点）
//************************************************************************************************//
ListNode* IsLoop(ListNode* p_Head)
{
	if (p_Head == nullptr)
	{
		cout << "非法输入：空链表" << endl;
		return nullptr;
	}
	if (p_Head->p_Next == nullptr)
	{
		cout << "链表仅含1个节点" << endl;
		return nullptr;
	}

	ListNode* p_NodeFast = p_Head->p_Next->p_Next;		//快指针每次走两步
	ListNode* p_NodeSlow = p_Head->p_Next;				//慢指针每次走一步

	while (p_NodeFast != p_NodeSlow)					//循环直到快指针慢指针相遇结束
	{
		p_NodeSlow = p_NodeSlow->p_Next;
		if (p_NodeFast == nullptr || p_NodeFast->p_Next == nullptr)		//若快指针到达链表尾部，则链表不包含环
		{
			cout << "链表不包含环" << endl;
			return nullptr;
		}
		p_NodeFast = p_NodeFast->p_Next->p_Next;
	}

	cout << "链表包含环" << endl;						//否则，链表包含环，且返回环中相遇节点
	return p_NodeFast;
}

//************************************************************************************************//
//---------------------------------------计算环中节点的个数---------------------------------------//
//思路：从环中相遇节点开始，设置自增1指针，直到再次到达相遇节点
//输入：p_Meet（环中相遇节点点）
//返回：环中节点的个数
//************************************************************************************************//
int NodeNumberInLoop(ListNode* p_Meet)
{
	int NodeNumberCount = 0;
	if (p_Meet != nullptr)						//若链表包含环
	{
		NodeNumberCount++;
		ListNode* p_Temp = p_Meet->p_Next;		//p_Temp指针从p_Meet节点开始，每次走一步
		while (p_Temp != p_Meet)				//循环直到p_Temp与p_Meet相遇结束
		{
			NodeNumberCount++;					//每走一步环中节点计数器+！
			p_Temp = p_Temp->p_Next;
		}	
	}

	return NodeNumberCount;
}

//************************************************************************************************//
//-------------------------------------得到链表中环的入口节点-------------------------------------//
//思路：设置两个从头结点开始的指针，一个先走k步（k=环中节点个数），之后两个同时走，相遇处为环的入口节点
//输入：p_Head（链表的头结点），LoopNodeNum（环中节点个数）
//返回：环的入口节点
//*****************************************LoopNodeNum*******************************************************//
ListNode* FindEntryInLoop(ListNode* p_Head, int LoopNodeNum)
{
	if (p_Head == nullptr || LoopNodeNum == 0)			//若链表为空或者不包含环
	{
		return nullptr;
	}

	ListNode* p_Ahead = p_Head;
	ListNode* p_Behind = p_Head;

	for (int i = 0; i < LoopNodeNum; i++)				//p_Ahead指针从头指针开始，走LoopNodeNum步
	{
		p_Ahead = p_Ahead->p_Next;
	}
	
	while (p_Ahead != p_Behind)							//之后p_Ahead指针和p_Behind指针一起走，直到两指针相遇
	{
		p_Ahead = p_Ahead->p_Next;
		p_Behind = p_Behind->p_Next;
	}

	return p_Ahead;										//相遇处节点为环的入口节点
}

//************************************************************************************************//
//----------------------------------创建第一个测试链表（空链表）----------------------------------//
//************************************************************************************************//
ListNode* CreateList1()
{
	ListNode* p_Head = nullptr;
	return p_Head;
}
//************************************************************************************************//
//--------------------------------创建第二个测试链表（单节点链表）--------------------------------//
//************************************************************************************************//
ListNode* CreateList2()
{
	ListNode* p_Node1 = CreateNode(1);
	ListNode* p_Head = p_Node1;
	return p_Head;
}

//************************************************************************************************//
//---------------------创建第三个测试链表（不包含环）（1->2->3->4->5->6->7）----------------------//
//************************************************************************************************//
ListNode* CreateList3()
{
	ListNode* p_Node1 = CreateNode(1);
	ListNode* p_Node2 = CreateNode(2);
	ListNode* p_Node3 = CreateNode(3);
	ListNode* p_Node4 = CreateNode(4);
	ListNode* p_Node5 = CreateNode(5);
	ListNode* p_Node6 = CreateNode(6);
	ListNode* p_Node7 = CreateNode(7);

	ConnectNode(p_Node1, p_Node2);
	ConnectNode(p_Node2, p_Node3);
	ConnectNode(p_Node3, p_Node4);
	ConnectNode(p_Node4, p_Node5);
	ConnectNode(p_Node5, p_Node6);
	ConnectNode(p_Node6, p_Node7);

	ListNode* p_Head = p_Node1;
	return p_Head;
}

//************************************************************************************************//
//-----------------------创建第四个测试链表（包含环）（1->2->3->4->5->6->3）----------------------//
//************************************************************************************************//
ListNode* CreateList4()
{
	ListNode* p_Node1 = CreateNode(1);
	ListNode* p_Node2 = CreateNode(2);
	ListNode* p_Node3 = CreateNode(3);
	ListNode* p_Node4 = CreateNode(4);
	ListNode* p_Node5 = CreateNode(5);
	ListNode* p_Node6 = CreateNode(6);

	ConnectNode(p_Node1, p_Node2);
	ConnectNode(p_Node2, p_Node3);
	ConnectNode(p_Node3, p_Node4);
	ConnectNode(p_Node4, p_Node5);
	ConnectNode(p_Node5, p_Node6);
	ConnectNode(p_Node6, p_Node3);

	ListNode* p_Head = p_Node1;
	return p_Head;
}

//************************************************************************************************//
//--------------------------------------------测试函数--------------------------------------------//
//输入：ListNode* (*func)(void)（创建链表的函数指针）
//************************************************************************************************//
void Test(ListNode* (*func)(void))
{
	ListNode* p_Head = func();
	ListNode* p_Meet = IsLoop(p_Head);
	if (p_Meet != nullptr)
	{
		cout << "相遇节点为：" << p_Meet->value << endl;
		int NodeCount = NodeNumberInLoop(p_Meet);
		cout << "环中节点个数：" << NodeCount << endl;
		ListNode* p_Entry = FindEntryInLoop(p_Head, NodeCount);
		cout << "环的入口节点为：" << p_Entry->value << endl;
	}
	cout << endl;
}

//************************************************************************************************//
//---------------------------------------------主函数---------------------------------------------//
//************************************************************************************************//
int main()
{
	Test(CreateList1);		//测试用例1：空链表
	Test(CreateList2);		//测试用例2：链表只含1个节点
	Test(CreateList3);		//测试用例3：链表不包含环
	Test(CreateList4);		//测试用例4：链表包含环
}
