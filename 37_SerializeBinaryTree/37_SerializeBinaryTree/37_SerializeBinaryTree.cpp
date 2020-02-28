//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题37：序列化二叉树
// 题目：请实现两个函数，分别用来序列化和反序列化二叉树。

#include "BinaryTree.h"
#include <iostream>
#include <fstream>
using namespace std;

//********************************************************************//
//----------------------------序列化二叉树----------------------------//
//********************************************************************//
void Serialize(BinaryTreeNode* p_Root, ostream& stream)
{
	if (p_Root == nullptr)
	{
		stream << "$,";
		return;
	}
	stream << p_Root->value << ",";
	Serialize(p_Root->p_Left, stream);
	Serialize(p_Root->p_Right, stream);
}

//********************************************************************//
//---------------从流中读出一个数字或者一个字符“$”------------------//
//------------当读出的是数字时，返回true，否则为false-----------------//
//********************************************************************//
bool ReadStream(istream& stream, int* number)
{
	if (stream.eof())
		return false;

	char buffer[32];
	buffer[0] = '\0';

	char ch;
	stream >> ch;
	int i = 0;
	while (!stream.eof() && ch != ',')
	{
		buffer[i++] = ch;
		stream >> ch;
	}

	bool isNumeric = false;
	if (i > 0 && buffer[0] != '$')
	{
		*number = atoi(buffer);
		isNumeric = true;
	}

	return isNumeric;
}

//********************************************************************//
//---------------------------反序列化二叉树---------------------------//
//********************************************************************//
void Deserialize(BinaryTreeNode** p_Root, istream& stream)	//需要修改p_Root节点，所以用指针的指针类型作为形参
{
	int number;
	if (ReadStream(stream, &number))
	{
		(*p_Root) = new BinaryTreeNode;
		(*p_Root)->value = number;
		(*p_Root)->p_Left = nullptr;
		(*p_Root)->p_Right = nullptr;

		Deserialize(&((*p_Root)->p_Left), stream);		//传入的实参需为一个地址
		Deserialize(&((*p_Root)->p_Right), stream);
	}
}

//********************************************************************//
//------------------------------测试函数------------------------------//
//********************************************************************//
void Test(BinaryTreeNode* (*func)(void))
{
	//-------创建测试用二叉树-------//
	BinaryTreeNode* p_Root = func();

	//-------序列化二叉树并存文件-------//
	const char* filename = "text.txt";
	ofstream fileOut;
	fileOut.open(filename);
	Serialize(p_Root, fileOut);
	fileOut.close();

	//-------读文件并打印-------//
	ifstream fileIn1;
	fileIn1.open(filename);
	char ch;
	while (!fileIn1.eof())
	{
		fileIn1 >> ch;
		cout << ch;
	}
	cout << endl;
	fileIn1.close();

	//-------读文件并反序列化二叉树-------//
	ifstream fileIn2;
	fileIn2.open(filename);
	BinaryTreeNode* p_NewRoot = nullptr;
	Deserialize(&p_NewRoot, fileIn2);
	fileIn2.close();
}

//********************************************************************//
//-------------------------------主函数-------------------------------//
//********************************************************************//
int main()
{
	Test(CreateBinaryTree_Complete);
	//Test(CreateBinaryTree_OneNode);
	//Test(CreateBinaryTree_OnlyLeft);
	//Test(CreateBinaryTree_OnlyRight);
	//Test(CreateBinaryTree_Null);

	return 0;
}