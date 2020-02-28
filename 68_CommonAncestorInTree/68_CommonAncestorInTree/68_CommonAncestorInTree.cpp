//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题68：树中两个结点的最低公共祖先
// 题目：输入两个树结点，求它们的最低公共祖先。

#include <iostream>
#include <vector>
#include <list>
#include <assert.h>
using namespace std;

//**********************************************************************//
//---------------------------普通树节点结构体---------------------------//
//**********************************************************************//
struct TreeNode
{
	int value;
	vector<TreeNode*> p_Child;		//利用动态数组存储孩子节点
};

//**********************************************************************//
//--------------------------创建一个普通树节点--------------------------//
//**********************************************************************//
TreeNode* CreateNode(int value)
{
	TreeNode* p_Node = new TreeNode;
	p_Node->value = value;
	return p_Node;
}

//**********************************************************************//
//--------------------------连接两个普通树节点--------------------------//
//**********************************************************************//
void ConnectNodes(TreeNode* p_Parent, TreeNode* p_Child)
{
	p_Parent->p_Child.push_back(p_Child);	//为p_Parent增加一个孩子节点p_Child
}

//**********************************************************************//
//--------------------------释放一棵树所占内存--------------------------//
//**********************************************************************//
void DestroyTree(TreeNode* p_Root)
{
	vector<TreeNode*>::iterator itr = p_Root->p_Child.begin();
	while (itr != p_Root->p_Child.end())
	{
		DestroyTree(*itr);
		itr++;
	}
	delete p_Root;
	p_Root = nullptr;
}

//**********************************************************************//
//---------------------找到从根节点到某一结点的路径---------------------//
//输入：p_Root（根节点）, p_Node（某一结点）, path（路径，用链表存储）
//**********************************************************************//
bool GetNodePath(TreeNode* p_Root, TreeNode* p_Node, list<TreeNode*>& path)
{
	if (p_Root == p_Node)		//若到达该节点，直接返回1，该节点并不需要存入path中
		return true;
	
	path.push_back(p_Root);		//将根节点加入链表

	bool found = false;
	vector<TreeNode*>::iterator itr = p_Root->p_Child.begin();
	while (!found && itr < p_Root->p_Child.end())
	{
		found = GetNodePath(*itr, p_Node, path);	//每一个孩子节点递归调用GetNodePath函数
		itr++;
	}

	if (!found)
		path.pop_back();		//如果未找到该节点，则说明该节点不在以p_Root为根节点的树上，则将p_Root从路径中弹出

	return found;
}

//**********************************************************************//
//----------------找到两条路径（链表的最后一个公共节点）----------------//
//**********************************************************************//
TreeNode* GetLastCommonNode(list<TreeNode*>& path1, list<TreeNode*>& path2)
{
	list<TreeNode*>::iterator itr1 = path1.begin();
	list<TreeNode*>::iterator itr2 = path2.begin();

	TreeNode* result = nullptr;

	while (itr1 != path1.end() && itr2 != path2.end())		//在两路径链表遍历完成之前
	{
		if (*itr1 == *itr2)		
		{
			result = *itr1;		//找到最后一个相同的元素
		}
		itr1++;
		itr2++;
	}
	return result;
}

//**********************************************************************//
//---------------------找到树中两节点的最低公共祖先---------------------//
//**********************************************************************//
TreeNode* GetCommonAncestor(TreeNode* p_Root, TreeNode* p_Node1, TreeNode* p_Node2)
{
	assert(p_Root != nullptr && p_Node1 != nullptr && p_Node2 != nullptr);

	list<TreeNode*> path1, path2;
	GetNodePath(p_Root, p_Node1, path1);	//找两个节点所在的路径
	GetNodePath(p_Root, p_Node2, path2);
	return GetLastCommonNode(path1, path2);		//找最后一个相同的元素
}

//**********************************************************************//
//--------------------------测试用例1：正常的树-------------------------//
//				1
//			  /   \
//           2     3
//         /   \
//       4       5
//      / \    / | \
//     6   7  8  9  10
//**********************************************************************//
void Test1()
{
	TreeNode* p_Node1 = CreateNode(1);
	TreeNode* p_Node2 = CreateNode(2);
	TreeNode* p_Node3 = CreateNode(3);
	TreeNode* p_Node4 = CreateNode(4);
	TreeNode* p_Node5 = CreateNode(5);
	TreeNode* p_Node6 = CreateNode(6);
	TreeNode* p_Node7 = CreateNode(7);
	TreeNode* p_Node8 = CreateNode(8);
	TreeNode* p_Node9 = CreateNode(9);
	TreeNode* p_Node10 = CreateNode(10);

	ConnectNodes(p_Node1, p_Node2);
	ConnectNodes(p_Node1, p_Node3);
	ConnectNodes(p_Node2, p_Node4);
	ConnectNodes(p_Node2, p_Node5);
	ConnectNodes(p_Node4, p_Node6);
	ConnectNodes(p_Node4, p_Node7);
	ConnectNodes(p_Node5, p_Node8);
	ConnectNodes(p_Node5, p_Node9);
	ConnectNodes(p_Node5, p_Node10);

	TreeNode* p_Result = GetCommonAncestor(p_Node1, p_Node6, p_Node8);
	cout << "节点 "<< p_Node6 ->value << " 和 " << p_Node8->value << " 的最低公共祖先是 " << p_Result ->value << endl;
	DestroyTree(p_Node1);
}

//**********************************************************************//
//----------------------测试用例2：只有一个孩子的树---------------------//
//			   1
//			  /   
//           2     
//          /   
//         3       
//        / 
//       4
//      /
//     5
//**********************************************************************//
void Test2()
{
	TreeNode* p_Node1 = CreateNode(1);
	TreeNode* p_Node2 = CreateNode(2);
	TreeNode* p_Node3 = CreateNode(3);
	TreeNode* p_Node4 = CreateNode(4);
	TreeNode* p_Node5 = CreateNode(5);

	ConnectNodes(p_Node1, p_Node2);
	ConnectNodes(p_Node2, p_Node3);
	ConnectNodes(p_Node3, p_Node4);
	ConnectNodes(p_Node4, p_Node5);

	TreeNode* p_Result = GetCommonAncestor(p_Node1, p_Node3, p_Node5);
	cout << "节点 " << p_Node3->value << " 和 " << p_Node5->value << " 的最低公共祖先是 " << p_Result->value << endl;
	DestroyTree(p_Node1);
}

//**********************************************************************//
//--------------------------测试用例3：空指针树-------------------------//
//**********************************************************************//
void Test3()
{
	TreeNode* p_Result = GetCommonAncestor(nullptr, nullptr, nullptr);
	//cout << "节点 " << p_Node3->value << " 和 " << p_Node5->value << " 的最低公共祖先是 " << p_Result->value << endl;
}

//**********************************************************************//
//--------------------------------主函数--------------------------------//
//**********************************************************************//
int main()
{
	Test1();
	Test2();
	Test3();

	return 0;
}