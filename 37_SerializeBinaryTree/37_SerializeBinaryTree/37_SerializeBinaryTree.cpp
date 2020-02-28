//==================================================================
// ����ָOffer������
//==================================================================

// ������37�����л�������
// ��Ŀ����ʵ�������������ֱ��������л��ͷ����л���������

#include "BinaryTree.h"
#include <iostream>
#include <fstream>
using namespace std;

//********************************************************************//
//----------------------------���л�������----------------------------//
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
//---------------�����ж���һ�����ֻ���һ���ַ���$��------------------//
//------------��������������ʱ������true������Ϊfalse-----------------//
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
//---------------------------�����л�������---------------------------//
//********************************************************************//
void Deserialize(BinaryTreeNode** p_Root, istream& stream)	//��Ҫ�޸�p_Root�ڵ㣬������ָ���ָ��������Ϊ�β�
{
	int number;
	if (ReadStream(stream, &number))
	{
		(*p_Root) = new BinaryTreeNode;
		(*p_Root)->value = number;
		(*p_Root)->p_Left = nullptr;
		(*p_Root)->p_Right = nullptr;

		Deserialize(&((*p_Root)->p_Left), stream);		//�����ʵ����Ϊһ����ַ
		Deserialize(&((*p_Root)->p_Right), stream);
	}
}

//********************************************************************//
//------------------------------���Ժ���------------------------------//
//********************************************************************//
void Test(BinaryTreeNode* (*func)(void))
{
	//-------���������ö�����-------//
	BinaryTreeNode* p_Root = func();

	//-------���л������������ļ�-------//
	const char* filename = "text.txt";
	ofstream fileOut;
	fileOut.open(filename);
	Serialize(p_Root, fileOut);
	fileOut.close();

	//-------���ļ�����ӡ-------//
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

	//-------���ļ��������л�������-------//
	ifstream fileIn2;
	fileIn2.open(filename);
	BinaryTreeNode* p_NewRoot = nullptr;
	Deserialize(&p_NewRoot, fileIn2);
	fileIn2.close();
}

//********************************************************************//
//-------------------------------������-------------------------------//
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