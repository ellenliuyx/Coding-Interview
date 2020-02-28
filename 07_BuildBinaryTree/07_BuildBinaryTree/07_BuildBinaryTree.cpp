//==================================================================
// ����ָOffer������
//==================================================================

// ������7���ؽ�������
// ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������������
// ���ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,
// 2, 4, 7, 3, 5, 6, 8}�������������{4, 7, 2, 1, 5, 3, 8, 6}�����ؽ���
// ͼ2.6��ʾ�Ķ��������������ͷ��㡣

#include <iostream>		//cin��cout����ͷ�ļ�
#include <stdlib.h>		//malloc����ͷ�ļ�
#include <algorithm>	//sort����ͷ�ļ�
using namespace std;

//************************************************************************//
//------------------------------�������ڵ�--------------------------------//
//************************************************************************//
struct BiTreeNode
{
	int value;
	BiTreeNode* pLeft;
	BiTreeNode* pRight;
};

//************************************************************************//
//---------------------���������������������ؽ�������-------------------//
//���룺preorder���������У���inorder���������У���length�����г��ȣ�
//����ֵ�����������ڵ�
//************************************************************************//
BiTreeNode* BulidBiTree(int* preorder, int* inorder, int length)
{
	//������Ϊ�գ����ؿ�ָ��
	if (preorder == nullptr || inorder == nullptr || length == 0)
	{
		return nullptr;
	}

	//�������ڵ�
	BiTreeNode* root;
	root = (BiTreeNode*)malloc(sizeof(BiTreeNode));		//���ٿռ�
	root->value = preorder[0];							//�������еĵ�һ��ֵΪ���ڵ�
	root->pLeft = root->pRight = nullptr;

	int length_left, length_right;								//���������ڵ����
	int* preorder_left = nullptr, * preorder_right = nullptr;	//������������������ʼָ��
	int* inorder_left = nullptr, * inorder_right = nullptr;		//������������������ʼָ��

	for (int i = 0; i < length; i++)				//�����������У��Ҹ��ڵ�
	{
		if (inorder[i] == root->value)				//�ҵ����ڵ�λ��
		{
			length_left = i;						//����������
			preorder_left = preorder + 1;			//����������������ʼָ��
			inorder_left = inorder;					//����������������ʼָ��

			length_right = length - i - 1;			//����������
			preorder_right = preorder + 1 + i;		//����������������ʼָ��
			inorder_right = inorder + i + 1;		//����������������ʼָ��

			break;									//�ҵ����ڵ㼴������ѭ��
		}
	}

	//cout << "root: " << root->value << endl;
	root->pLeft = BulidBiTree(preorder_left, inorder_left, length_left);		//�������ݹ���ã����ص����������ڵ㼴Ϊ���ڵ������
	//cout << "root: " << root->value << endl;
	root->pRight = BulidBiTree(preorder_right, inorder_right, length_right);	//�������ݹ���ã����ص����������ڵ㼴Ϊ���ڵ���Һ���
	cout << "root: " << root->value << endl;

	return root;
}

//************************************************************************//
//--------------------------------������----------------------------------//
//************************************************************************//
int main()
{
	int inputValue;		//�ݴ�������ֵ
	int length = 8;		//���г���
	int* preorder = (int*)malloc(sizeof(int) * length);			//�������г��ȶ�̬��������
	int* inorder = (int*)malloc(sizeof(int) * length);
	int* preorder_sort = (int*)malloc(sizeof(int) * length);	//���ڽ����������ȶ��Ƿ�һ��
	int* inorder_sort = (int*)malloc(sizeof(int) * length);

	//-----------------���������������---------------------//
	cout << "�����������������������У�" << endl;
	int i = 0;
	while (i < length)
	{
		if (!(cin >> inputValue))
		{
			cout << "����������г���С��Ԥ�����ȣ�" << length << endl;
		return 0;
		}
		preorder[i] = inputValue;
		preorder_sort[i++] = inputValue;
	}
	sort(preorder_sort, preorder_sort + length);	//�����������������

	//-----------------���������������---------------------//
	cout << "�����������������������У�" << endl;
	int j = 0;
	cin.clear();
	while (j < length)
	{
		if (!(cin >> inputValue))
		{
			cout << "����������г���С��Ԥ�����ȣ�" << length << endl;
		return 0;
		}
		inorder[j] = inputValue;
		inorder_sort[j++] = inputValue;
	}
	sort(inorder_sort, inorder_sort + length);		//�����������������

	//-----------�ж������������������Ƿ�ƥ��------------//
	for (int i = 0; i < length; i++)
	{
		if (preorder_sort[i] != inorder_sort[i])
		{
			cout << "����������к�����������в�ƥ��" << endl;
			return 0;
		}
	}

	//---------------------�ؽ�������----------------------//
	BiTreeNode* root;
	root = BulidBiTree(preorder, inorder, length);

	return 0;		//�ڴ˴���ϵ���Կ���root�Ľṹ
}