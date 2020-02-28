//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。

#include <iostream>		//cin，cout所需头文件
#include <stdlib.h>		//malloc所需头文件
#include <algorithm>	//sort所需头文件
using namespace std;

//************************************************************************//
//------------------------------二叉树节点--------------------------------//
//************************************************************************//
struct BiTreeNode
{
	int value;
	BiTreeNode* pLeft;
	BiTreeNode* pRight;
};

//************************************************************************//
//---------------------根据先序和中序遍历序列重建二叉树-------------------//
//输入：preorder（先序序列），inorder（中序序列），length（序列长度）
//返回值：二叉树根节点
//************************************************************************//
BiTreeNode* BulidBiTree(int* preorder, int* inorder, int length)
{
	//若序列为空，返回空指针
	if (preorder == nullptr || inorder == nullptr || length == 0)
	{
		return nullptr;
	}

	//创建根节点
	BiTreeNode* root;
	root = (BiTreeNode*)malloc(sizeof(BiTreeNode));		//开辟空间
	root->value = preorder[0];							//先序序列的第一个值为根节点
	root->pLeft = root->pRight = nullptr;

	int length_left, length_right;								//左右子树节点个数
	int* preorder_left = nullptr, * preorder_right = nullptr;	//左右子树先序序列起始指针
	int* inorder_left = nullptr, * inorder_right = nullptr;		//左右子树中序序列起始指针

	for (int i = 0; i < length; i++)				//遍历中序序列，找根节点
	{
		if (inorder[i] == root->value)				//找到根节点位置
		{
			length_left = i;						//左子树长度
			preorder_left = preorder + 1;			//左子树先序序列起始指针
			inorder_left = inorder;					//左子树中序序列起始指针

			length_right = length - i - 1;			//右子树长度
			preorder_right = preorder + 1 + i;		//右子树先序序列起始指针
			inorder_right = inorder + i + 1;		//右子树中序序列起始指针

			break;									//找到根节点即可跳出循环
		}
	}

	//cout << "root: " << root->value << endl;
	root->pLeft = BulidBiTree(preorder_left, inorder_left, length_left);		//左子树递归调用，返回的左子树根节点即为根节点的左孩子
	//cout << "root: " << root->value << endl;
	root->pRight = BulidBiTree(preorder_right, inorder_right, length_right);	//右子树递归调用，返回的右子树根节点即为根节点的右孩子
	cout << "root: " << root->value << endl;

	return root;
}

//************************************************************************//
//--------------------------------主函数----------------------------------//
//************************************************************************//
int main()
{
	int inputValue;		//暂存输入数值
	int length = 8;		//序列长度
	int* preorder = (int*)malloc(sizeof(int) * length);			//根据序列长度动态分配数组
	int* inorder = (int*)malloc(sizeof(int) * length);
	int* preorder_sort = (int*)malloc(sizeof(int) * length);	//用于将序列排序后比对是否一致
	int* inorder_sort = (int*)malloc(sizeof(int) * length);

	//-----------------输入先序遍历序列---------------------//
	cout << "请输入二叉树的先序遍历序列：" << endl;
	int i = 0;
	while (i < length)
	{
		if (!(cin >> inputValue))
		{
			cout << "先序遍历序列长度小于预定长度：" << length << endl;
		return 0;
		}
		preorder[i] = inputValue;
		preorder_sort[i++] = inputValue;
	}
	sort(preorder_sort, preorder_sort + length);	//将先序遍历序列排序

	//-----------------输入中序遍历序列---------------------//
	cout << "请输入二叉树的中序遍历序列：" << endl;
	int j = 0;
	cin.clear();
	while (j < length)
	{
		if (!(cin >> inputValue))
		{
			cout << "中序遍历序列长度小于预定长度：" << length << endl;
		return 0;
		}
		inorder[j] = inputValue;
		inorder_sort[j++] = inputValue;
	}
	sort(inorder_sort, inorder_sort + length);		//将中序遍历序列排序

	//-----------判断先序和中序遍历序列是否匹配------------//
	for (int i = 0; i < length; i++)
	{
		if (preorder_sort[i] != inorder_sort[i])
		{
			cout << "先序遍历序列和中序遍历序列不匹配" << endl;
			return 0;
		}
	}

	//---------------------重建二叉树----------------------//
	BiTreeNode* root;
	root = BulidBiTree(preorder, inorder, length);

	return 0;		//在此处打断点可以看到root的结构
}