//==================================================================
// 《剑指Offer》代码
//==================================================================

// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

#define _CRT_SECURE_NO_WARNINGS			//避免出现用strcpy_s替换strcpy的错误提示
#include <iostream>						//流输入输出操作（cout）用到的头文件
#include <string>						//字符串操作（strcpy）用到的头文件
using namespace std;					//命名空间，省略str::

//CMyString 类
class CMyString
{
public:
	//各个函数声明
	CMyString(char* pData = nullptr);		//构造函数
	CMyString(const CMyString& str);		//复制构造函数
	~CMyString(void);						//析构函数

	CMyString& operator=(const CMyString& str);
	friend ostream& operator<<(ostream& o, const CMyString& str);

private:
	char* m_pData;
};

//构造函数定义
CMyString::CMyString(char* pData)
{
	if (pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0]= '\0';
	}
	else
	{
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
}

//复制构造函数定义
CMyString::CMyString(const CMyString& str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}

//析构函数定义
CMyString::~CMyString(void)
{
	delete[] m_pData;
}

//赋值运算符重载
CMyString& CMyString::operator=(const CMyString& str)
{
	if (this == &str)
		return *this;									//若为自身赋值，则直接返回this指针

	delete[] m_pData;									//先释放内存，以免造成内存泄露
	m_pData = new char[strlen(str.m_pData) + 1];		//根据str大小开辟一块新的内存空间
	strcpy(m_pData, str.m_pData);						//将内容拷贝
	return *this;										//返回实例自身的引用
}

//流输出运算符重载
ostream& operator<<(ostream & o, const CMyString& str)		//参数和返回值均为 ostream& 类
{
	o << str.m_pData;
	return o;
}

//测试函数
int main()
{
	char* a1 = (char*)"the";
	char* a2 = (char*)"this";
	char* a3 = (char*)"these";

	CMyString s1(a1), s2(a2), s3(a3);		//利用构造函数定义几个 CMyString 对象
	
	cout << "s1=" << s1 << "," << "s2=" << s2 << "," << "s3=" << s3 << endl;
	s1 = s1;			//自身赋值操作
	cout << "s1=" << s1 << endl;
	s2 = s1;			//基本赋值操作
	cout << "s1=" << s1 << "," << "s2=" << s2 << endl;
	s1 = s2 = s3;		//连续赋值操作
	cout << "s1=" << s1 << "," << "s2=" << s2 << "," << "s3=" << s3 << endl;
}