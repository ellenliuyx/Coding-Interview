//==================================================================
// ����ָOffer������
//==================================================================

// ������68����������������͹�������
// ��Ŀ��������������㣬�����ǵ���͹������ȡ�

#include <iostream>
#include <vector>
#include <list>
#include <assert.h>
using namespace std;

//**********************************************************************//
//---------------------------��ͨ���ڵ�ṹ��---------------------------//
//**********************************************************************//
struct TreeNode
{
	int value;
	vector<TreeNode*> p_Child;		//���ö�̬����洢���ӽڵ�
};

//**********************************************************************//
//--------------------------����һ����ͨ���ڵ�--------------------------//
//**********************************************************************//
TreeNode* CreateNode(int value)
{
	TreeNode* p_Node = new TreeNode;
	p_Node->value = value;
	return p_Node;
}

//**********************************************************************//
//--------------------------����������ͨ���ڵ�--------------------------//
//**********************************************************************//
void ConnectNodes(TreeNode* p_Parent, TreeNode* p_Child)
{
	p_Parent->p_Child.push_back(p_Child);	//Ϊp_Parent����һ�����ӽڵ�p_Child
}

//**********************************************************************//
//--------------------------�ͷ�һ������ռ�ڴ�--------------------------//
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
//---------------------�ҵ��Ӹ��ڵ㵽ĳһ����·��---------------------//
//���룺p_Root�����ڵ㣩, p_Node��ĳһ��㣩, path��·����������洢��
//**********************************************************************//
bool GetNodePath(TreeNode* p_Root, TreeNode* p_Node, list<TreeNode*>& path)
{
	if (p_Root == p_Node)		//������ýڵ㣬ֱ�ӷ���1���ýڵ㲢����Ҫ����path��
		return true;
	
	path.push_back(p_Root);		//�����ڵ��������

	bool found = false;
	vector<TreeNode*>::iterator itr = p_Root->p_Child.begin();
	while (!found && itr < p_Root->p_Child.end())
	{
		found = GetNodePath(*itr, p_Node, path);	//ÿһ�����ӽڵ�ݹ����GetNodePath����
		itr++;
	}

	if (!found)
		path.pop_back();		//���δ�ҵ��ýڵ㣬��˵���ýڵ㲻����p_RootΪ���ڵ�����ϣ���p_Root��·���е���

	return found;
}

//**********************************************************************//
//----------------�ҵ�����·������������һ�������ڵ㣩----------------//
//**********************************************************************//
TreeNode* GetLastCommonNode(list<TreeNode*>& path1, list<TreeNode*>& path2)
{
	list<TreeNode*>::iterator itr1 = path1.begin();
	list<TreeNode*>::iterator itr2 = path2.begin();

	TreeNode* result = nullptr;

	while (itr1 != path1.end() && itr2 != path2.end())		//����·������������֮ǰ
	{
		if (*itr1 == *itr2)		
		{
			result = *itr1;		//�ҵ����һ����ͬ��Ԫ��
		}
		itr1++;
		itr2++;
	}
	return result;
}

//**********************************************************************//
//---------------------�ҵ��������ڵ����͹�������---------------------//
//**********************************************************************//
TreeNode* GetCommonAncestor(TreeNode* p_Root, TreeNode* p_Node1, TreeNode* p_Node2)
{
	assert(p_Root != nullptr && p_Node1 != nullptr && p_Node2 != nullptr);

	list<TreeNode*> path1, path2;
	GetNodePath(p_Root, p_Node1, path1);	//�������ڵ����ڵ�·��
	GetNodePath(p_Root, p_Node2, path2);
	return GetLastCommonNode(path1, path2);		//�����һ����ͬ��Ԫ��
}

//**********************************************************************//
//--------------------------��������1����������-------------------------//
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
	cout << "�ڵ� "<< p_Node6 ->value << " �� " << p_Node8->value << " ����͹��������� " << p_Result ->value << endl;
	DestroyTree(p_Node1);
}

//**********************************************************************//
//----------------------��������2��ֻ��һ�����ӵ���---------------------//
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
	cout << "�ڵ� " << p_Node3->value << " �� " << p_Node5->value << " ����͹��������� " << p_Result->value << endl;
	DestroyTree(p_Node1);
}

//**********************************************************************//
//--------------------------��������3����ָ����-------------------------//
//**********************************************************************//
void Test3()
{
	TreeNode* p_Result = GetCommonAncestor(nullptr, nullptr, nullptr);
	//cout << "�ڵ� " << p_Node3->value << " �� " << p_Node5->value << " ����͹��������� " << p_Result->value << endl;
}

//**********************************************************************//
//--------------------------------������--------------------------------//
//**********************************************************************//
int main()
{
	Test1();
	Test2();
	Test3();

	return 0;
}